/** @file sim7segWin.c
 *
 *	@date 30 de septiembre de 2019
 *	@version 1.1
 *
 *	@authors Vera, Pablo Martín.
 *	@authors Vazquez Saraullo, Federico Alejandro.
 *
 *	@brief  Archivo fuente que simula al puerto paralelo 0x378 con un
 *		display de 7 segmentos conectado al registro de datos.
 *
 *	@note Solo se puede habilitar el puerto paralelo con dirección base 
 *	      igual a 0x378. Los demás puertos paralelos posibles se toman como
 *	      que no están disponibles en la PC.
 */

/** \addtogroup Simulador de display de 7 segmentos en Windows.
 * @{
 */

/*==================[inclusiones]============================================*/
#include <stdio.h>
#include <stdlib.h>

/*==================[macros]=================================================*/
/**	@def ESPACIO
 *	@brief Decimal del caracter para el espacio.*/
#define ESPACIO 32

/**	@def SIMBOLO
 *	@brief Decimal del caracter para un segmento.*/
#define SIMBOLO 219

/**	@def LARGO
 *	@brief Largo del segmento.*/
#define LARGO 15

/**	@def ESPACIO
 *	@brief Alto del segmento.*/
#define ALTO 7

/**	@def SEGMENTO_HORIZONTAL 
 *	@brief Crea un segmento horizontal.*/
#define SEGMENTO_HORIZONTAL { int i;\
							 printf("\n     ");\
							for (i=0;i<LARGO;i++)\
								 printf ("%c",SIMBOLO);}
				
/**	@def SEGMENTO_VERTICAL_DOBLE 
 *	@brief Crea dos segmentos verticales.*/				
#define SEGMENTO_VERTICAL_DOBLE(s1,s2) {\
				int j,i; \
				for (i=0;i<ALTO;i++) \
				{  	\
					printf("\n    "); \
					printf ("%c",s1);	\
					for (j=0;j<LARGO+1;j++) \
						printf (" "); \
					printf ("%c",s2);	\
				}}

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
	
	/* Cuerpo de la función*/	
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
 *	@return estadoActivación_t que vale:
 *		OK: Se habilitó/deshabilitó correctamente.
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
	
	/* Cuerpo de la función*/
	
	/*Se guarda el estado a setear. Aunque "estadoASetear" sea enum, admite 
	 *valores negativos y mayores a 1.*/
	estadoASetear = (estadoActivacion_t) accion;
	
	/*Se validan los parámetros formales.*/
	if(cant > 0 && (estadoASetear == HABILITADO || estadoASetear == DESHABILITADO) ){
		/*Se hace primero una búsqueda secuencial de la dirección "port" en el 
		 *vector "dirPuertos".*/
		pos = BuscarPuerto(dirPuertos, CANT_ELEM_VEC(dirPuertos), port);
		
		/*Si se encontró el puerto, se chequea que los puertos consecutivos se 
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

	/* Cuerpo de la función*/	
	printf("\n\n****************************************************************************************\n");
	printf("ERROR. El puerto, por el que desea enviar un dato, no existe o no está habilitado.\n");
	printf("****************************************************************************************\n");
}


unsigned char outb ( unsigned char dato, unsigned short int port)
{
	/* Declaraciones locales */
	struct sbits 
	{
		unsigned int a:1;
		unsigned int b:1;
		unsigned int c:1;
		unsigned int d:1;
		unsigned int e:1;
		unsigned int f:1;
		unsigned int g:1;
	};	

	union un
	{
		struct sbits bits;
		unsigned char dato;
	};

	union un u;
	u.dato = dato;
	char s1,s2;
	int pos;
	
	/* Cuerpo de la función*/
	
	/*Se verifica que el puerto esté habilitado*/
	pos = BuscarPuerto(dirPuertos, CANT_ELEM_VEC(dirPuertos), port);
	
	if( pos == -1 || dirPuertos[pos].estado == DESHABILITADO){
		MostrarError();
	}
	else
	{
		system("cls");

		if (u.bits.a)
			SEGMENTO_HORIZONTAL

		if (u.bits.f)	
			s1=SIMBOLO;
		else
			s1=ESPACIO;

		if (u.bits.b)
			s2=SIMBOLO;
		else
			s2=ESPACIO;
			
		SEGMENTO_VERTICAL_DOBLE(s1,s2)

		if (u.bits.g)
			SEGMENTO_HORIZONTAL
		else
			printf("\n");

		  if (u.bits.e)	
			s1=SIMBOLO;
		else
			s1=ESPACIO;

		if (u.bits.c)
			s2=SIMBOLO;
		else
			s2=ESPACIO;
			
		SEGMENTO_VERTICAL_DOBLE(s1,s2)	
			
		if (u.bits.d)
			SEGMENTO_HORIZONTAL  	

		printf("\n\n");	
	}
}
