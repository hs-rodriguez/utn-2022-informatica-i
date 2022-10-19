/** @file simledsWin.c
 *
 *	@date 1 de octubre de 2019
 *	@version 1.1
 *
 *	@authors Vera, Pablo Martín.
 *	@authors Vazquez Saraullo, Federico Alejandro.
 *
 *	@brief  Archivo fuente que simula al puerto paralelo 0x378 con 8 LEDs 
 *		conectados en su registro de datos.
 *
 *	@note Solo se puede habilitar el puerto paralelo con dirección base 
 *	      igual a 0x378. Los demás puertos paralelos posibles se toman como
 *	      que no están disponibles en la PC.
 */

/** \addtogroup Simulador de LEDs en Windows.
 * @{
 */

/*==================[inclusiones]============================================*/
#include <stdio.h>
#include <stdlib.h>

/*==================[macros]=================================================*/
/**	@def ENCENDIDO
 *	@brief Hexadecimal del caracter para simular a un LED encendido.*/
#define ENCENDIDO 219

/**	@def APAGADO
 *	@brief Hexadecimal del caracter para simular a un LED apagado.*/
#define APAGADO 176

/**	@def PUERTO_BASE
 *	@brief Dirección base del puerto paralelo disponible según este
	       simulador.*/
#define PUERTO_BASE 0x378

/**	@def CANT_ELEM_VEC(x)
 *	@brief Macro para calcular la cantidad de elementos de un vector "X".*/
#define CANT_ELEM_VEC(x) (sizeof(x) / sizeof(x[0]))

/*==============================[Tipos de datos]=============================*/
typedef enum{
	DESHABILITADO,
	HABILITADO 
}portStatus_t;

typedef struct{
	unsigned int dir;
	portStatus_t estado;
}puerto_t;

typedef enum{
	OK,
	ERROR1,
	ERROR2,
	ERROR3
}estadoActivacion_t;

/*==================[declaración de variables internas]======================*/
/**@var dirPuertos
 * @brief Vector que almacena las direcciones de los registros del puerto 
 *	  paralelo cuya dirrección base es 0x378. Inicialmente, todos los
 *	  registros están deshabilitados.*/
static puerto_t dirPuertos[] = {
	{ .dir = PUERTO_BASE, .estado = DESHABILITADO},
	{ .dir = PUERTO_BASE + 1, .estado = DESHABILITADO},
	{ .dir = PUERTO_BASE + 2, .estado = DESHABILITADO}
};

/*==================[definición de funciones internas]=======================*/
/** @fn int BuscarPuerto (puerto_t portVec[], int cnt, unsigned int port)
 * 	@brief Permite buscar en forma secuencial la dirección "port" dentro del
	       vector "portVec" el cual tiene "cnt" elementos.
 *	@return int que vale:
 *		-1: No se encontró al "port" en "porVec".
 *		otro valor: Se encontró.
 */
int BuscarPuerto (puerto_t portVec[], int cnt, unsigned int port)
{
	/* Declaraciones locales */
	unsigned int i = 0;
	int pos = -1;
	
	/* Cuerpo de la funci�n*/	
	while(i < cnt && pos == -1){
		if(portVec[i].dir == port){
			pos = i;
		}
		else{
			i++;
		}
	}
	return pos;
}
					   					  
/** @fn int ioperm (unsigned int port, unsigned int cant, int accion)
 * 	@brief Permite habilitar o deshabilitar una cantidad entera de puertos consecutivos.
 *	@return estadoActivacion_t que vale:
 *		OK: Se habilita/deshabilita correctamente.
 *		ERROR1: Error por valores de cant y/o accion.
 *		ERROR2: Error por dirección del puerto.
 *		ERROR3: Error por direcciones consecutivas de puertos.
 */
int ioperm (unsigned int port, unsigned int cant, int accion)
{
	/* Declaraciones locales */
	unsigned int i = 0;
	int pos;
	estadoActivacion_t activacion; 
	portStatus_t estadoASetear;
	
	/* Cuerpo de la funci�n*/
	
	/*Se guarda el estado a setear. Aunque "estadoASetear" sea enum, admite 
	 *valores negativos y mayores a 1.*/
	estadoASetear = (estadoActivacion_t) accion;
	
	/*Se validan los par�metros formales.*/
	if(cant > 0 && (estadoASetear == HABILITADO || estadoASetear == DESHABILITADO) ){
		/*Se hace primero una búsqueda secuencial de la dirección "port" en el 
		 *vector "dirPuertos".*/
		pos = BuscarPuerto(dirPuertos, CANT_ELEM_VEC(dirPuertos), port);
		
		/*Si se encuentra el puerto, se chequea que los puertos consecutivos se 
		 *puedan habilitar. Por defecto, se supone que se pueden habilitar hasta
		 *que se demuestre lo contrario.*/
		if(pos != -1){
			i = 1;
			activacion = OK;
			/*Se buscan los puertos consecutivos en el vector "dirPuertos".*/
			while(i < cant && activacion == OK){
				if((port + i) != dirPuertos[pos + i].dir){ 
					activacion = ERROR3;
				}
				else{
					i++;
				}
			}
			/*Se habilitan/deshabilitan si es posible.*/
			if(activacion == OK){
				for (i = 0; i < cant; i++){
					dirPuertos[pos + i].estado = estadoASetear;
				}
			}
		}
		else{
			activacion = ERROR2;
		}
	}
	else{
		activacion = ERROR1;
	}
	
	return activacion;
}

/** @fn void MostrarError()
 * 	@brief Muestra un mensaje de error en caso de que existe uno cuando se usa la función "outb".
 */
void MostrarError()
{
	/* Declaraciones locales */

	/* Cuerpo de la funci�n*/	
	printf("\n\n****************************************************************************************\n");
	printf("ERROR. El puerto, por el que desea enviar un dato, no existe o no esta habilitado.\n");
	printf("****************************************************************************************\n");
}

unsigned char outb ( unsigned char dato, unsigned short int port)
{
	/* Declaraciones locales */
	unsigned char mask = 0x80;
	int pos;

	/* Cuerpo de la funci�n*/
	
	/*Se verifica que el puerto est� habilitado*/
	pos = BuscarPuerto(dirPuertos, CANT_ELEM_VEC(dirPuertos), port);
	
	if( pos == -1 || dirPuertos[pos].estado == DESHABILITADO){
		MostrarError();
	}
	else
	{
		system("cls");
		while (mask)
		{
			if (mask&dato)
				printf (" %c ",ENCENDIDO);
			else
				printf (" %c ",APAGADO);
			mask>>=1;
		}
		printf("\n\n");
	}
}
/** @} doxygen end group definition */
/*==================[fin del archivo]============================================*/
