/** @file sim10.c
 *
 *	@date 5 de noviembre de 2019
 *	@version 1.4
 *
 *	@authors Vera, Pablo Martín.
 *	@authors Vazquez Saraullo, Federico Alejandro.
 *
 *	@brief  Archivo fuente que simula al puerto 0x400 y se utiliza para validar
 *		 	el programa del ejercicio 10. Los resultados esperados son:
 *						Molinete	Personas
 *							0			0
 * 							1			2
 *							2			0
 *							3			0
 *							4			3
 *							5			0
 *							6			1
 *							7			0
 *
 *	@note Solo se puede habilitar el puerto con dirección 0x400. Los demás 
 *	      puertos se toman como que no están disponibles en la PC.
 *
 *	@example  
 *		#include<stdio.h>
 *		#include<stdlib.h>
 *		
 *		int main()
 *		{
 *			//Error por cant.
 *			printf("%d\n",ioperm(0x400,0,0));
 *			printf("%d\n",ioperm(0x400,0,1));
 *			
 *			//Error por habilitación/deshabilitación.
 *			printf("%d\n",ioperm(0x400,1,-1));
 *			printf("%d\n",ioperm(0x400,1,2));
 *			
 *			//Error en dirección de puerto.
 *			printf("%d\n",ioperm(0x100,1,1));
 *			
 *			//Error en direcciones consecutivas de puertos.
 *			printf("%d\n",ioperm(0x400,3,1));
 *			
 *			//Habilitación y deshabilitación OK de un puerto.
 *			printf("%d\n",ioperm(0x400,1,1));
 *			printf("%d\n",ioperm(0x400,1,0));
 *			getchar();
 *			
 *			//Error en inb por puerto inexistente.
 *			inb(0x100);
 *			getchar();
 *			
 *			//Error en inb por puerto no habilitado.
 *			inb(0x400);
 *			getchar();
 *			
 *			//Uso correcto de inb.
 *			ioperm(0x400,1,1);
 *			printf("%x",inb(0x400));
 *			printf("%x",inb(0x400));
 *			ioperm(0x400,1,0);
 *		}
 *
 */

/** \addtogroup Simulador para ejercicio 10 de puertos.
 * @{
 */

/*==================[inclusiones]============================================*/
#include <stdio.h>
#include <stdlib.h>

/*==================[macros]=================================================*/
/**	@def PUERTO_BASE
 *	@brief Dirección base del puerto disponible según este simulador.*/
#define PUERTO_BASE 0x400

/**	@def CANT_ELEM_VEC(x)
 *	@brief Macro para calcular la cantidad de elementos de un vector "X".*/
#define CANT_ELEM_VEC(x) (sizeof(x) / sizeof(x[0]))

/*==============================[Tipos de datos]=============================*/
typedef enum{
	MOLINETE0,
	MOLINETE1,
	MOLINETE2,
	MOLINETE3,
	MOLINETE4,
	MOLINETE5,
	MOLINETE6,
	MOLINETE7	
}molinete_t;

typedef enum{
	SINC_OFF,
	SINC_ON
}sincStatus_t;

typedef enum{
	FIN_OFF,
	FIN_ON
}finStatus_t;

typedef enum{
	DESHABILITADO,
	HABILITADO,
	ERROR_ESTADO 
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
 * @brief Vector que almacena la dirección y estado del puerto 0x400, el cual 
 *		  inicialmente está deshabilitado.*/
static puerto_t dirPuertos[] = {
	{ .dir = PUERTO_BASE, .estado = DESHABILITADO}
};

/*==================[definición de funciones internas]=======================*/
/** @fn unsigned char ArmarDatoPuerto (finStatus_t fin, 
									   molinete_t mol, 
									   sincStatus_t sinc)
 * 	@brief Permite armar un valor de 8 bits según los datos del bit de fin, de
 *		   sincronismo y de los bits de molinete.
 *	@return unsigned char Dato armado para ser enviado al puerto.
 */
unsigned char ArmarDatoPuerto (finStatus_t fin, molinete_t mol, sincStatus_t sinc)
{
	/* Declaraciones locales */
	
	/* Cuerpo de la función*/
	return ( (((unsigned int) fin) << 7 ) + (((unsigned int) mol) << 1) + \
		   (unsigned int) sinc);
}
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
	int i = 0;
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
	
	/* Cuerpo de la función*/
	
	/*Se guarda el estado a setear. Aunque "estadoASetear" sea enum, admite 
	 *valores negativos y mayores a 1.*/
	switch(accion){
		case 0: estadoASetear = DESHABILITADO;
				break;
		
		case 1: estadoASetear = HABILITADO;
				break;
		
		default: estadoASetear = ERROR_ESTADO;
	}
	
	/*Se validan los parámetros formales.*/
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
 * 	@brief Muestra un mensaje de error en caso de que existe uno cuando se usa la función "inb".
 */
void MostrarError()
{
	/* Declaraciones locales */

	/* Cuerpo de la función*/	
	printf("\n\n****************************************************************************************\n");
	printf("ERROR. El puerto, por el que desea leer un dato, no existe o no esta habilitado.\n");
	printf("****************************************************************************************\n");
}

/*Para esta función se consideraron los siguientes casos:
 *	-Datos válidos de los molinetes 1, 4 y 6.
 *	-Recibir en forma consecutiva el mismo dato válido, para que se contemple
 *	 la situación de error en la que no se espere que el bit S pase de 1 a 0.
 *	-Bit F en 1 cuando el dato NO es válido para que el usuario solo analice
 *	 ese bit si el dato es válido. De no hacerlo, el programa se cierra.
 *	-Bit F en 1 en caso de agotarse los casos. En otras palabras, si se lee más
 *   de 16 veces, se tiene siempre luego la condición de fin. */
unsigned char inb( int port)
{
	/* Declaraciones locales */
	static int orden =1;
	int pos;
	unsigned char valor = 0;
	
	/* Cuerpo de la función*/
	
	/*Se verifica que el puerto está habilitado*/
	pos = BuscarPuerto(dirPuertos, CANT_ELEM_VEC(dirPuertos), port);
	
	if( pos == -1 || dirPuertos[pos].estado == DESHABILITADO){
		MostrarError();
	}
	else
	{
		switch(orden)
		{
			case 1: valor= ArmarDatoPuerto(FIN_ON, MOLINETE0, SINC_OFF);
					break;
					
			case 2: valor = ArmarDatoPuerto(FIN_OFF, MOLINETE1, SINC_ON);
					break;
					
			case 3: valor = ArmarDatoPuerto(FIN_OFF, MOLINETE1, SINC_ON);
					break;
					
			case 4: valor = ArmarDatoPuerto(FIN_ON, MOLINETE0, SINC_OFF);
					break;
					
			case 5: valor = ArmarDatoPuerto(FIN_OFF, MOLINETE1, SINC_ON);
					break;
					
			case 6: valor = ArmarDatoPuerto(FIN_ON, MOLINETE0, SINC_OFF);
					break;
	
			case 7: valor = ArmarDatoPuerto(FIN_OFF, MOLINETE4, SINC_ON);
					break;
	
			case 8: valor = ArmarDatoPuerto(FIN_OFF, MOLINETE4, SINC_ON);
					break;
	
			case 9: valor = ArmarDatoPuerto(FIN_ON, MOLINETE0, SINC_OFF);
					break;
	
			case 10: valor = ArmarDatoPuerto(FIN_OFF, MOLINETE4, SINC_ON);
					 break;
	
			case 11: valor = ArmarDatoPuerto(FIN_ON, MOLINETE0, SINC_OFF);
					 break;
	
			case 12: valor = ArmarDatoPuerto(FIN_OFF, MOLINETE4, SINC_ON);
					 break;
	
			case 13: valor = ArmarDatoPuerto(FIN_ON, MOLINETE0, SINC_OFF);
					 break;
					
			case 14: valor = ArmarDatoPuerto(FIN_OFF, MOLINETE6, SINC_ON);
					 break;
					
			case 15: valor = ArmarDatoPuerto(FIN_ON, MOLINETE0, SINC_OFF);
					 break;
					
			case 16: valor = ArmarDatoPuerto(FIN_ON, MOLINETE0, SINC_ON);
					 break;
					 
			default: valor = ArmarDatoPuerto(FIN_ON, MOLINETE0, SINC_ON);
					 break;
		}
		orden++;
	}
	return valor;
}
/** @} doxygen end group definition */
/*==================[fin del archivo]============================================*/
