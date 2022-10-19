/** @file sim12.c
 *
 *	@date 5 de noviembre de 2019
 *	@version 1.3
 *
 *	@authors Vera, Pablo Martín.
 *	@authors Vazquez Saraullo, Federico Alejandro.
 *
 *	@brief  Archivo fuente que simula los puertos 0x200 y 0x201, y se utiliza 
 *			para validar el programa del ejercicio 12. Los resultados esperados
 *			son:
 *				Voltímetro		Tensión Promedio		Tensión Mínima
 *					1				355.50					195
 *					2				sin datos				sin datos
 *					3				sin datos				sin datos
 *					4				264.00					128
 *					5				sin datos				sin datos
 *					6				sin datos				sin datos
 *					7				sin datos				sin datos
 *					8				sin datos				sin datos
 *					9				256						256
 *					10				sin datos				sin datos
 *					11				sin datos				sin datos
 *					12				sin datos				sin datos
 *					13				sin datos				sin datos
 *					14				sin datos				sin datos
 *					15 				sin datos				sin datos
 *
 *				Cantidad de voltímetros con más de 50 mediciones registradas: 0.
 *
 *	@note Solo se pueden habilitar los puertos 0x200 y 0x201. Los demás puertos
 *		  se toman como que no están disponibles en la PC.
*/

/** \addtogroup Simulador para ejercicio 12 de puertos.
 * @{
 */

/*==================[inclusiones]============================================*/
#include <stdio.h>
#include <stdlib.h>

/*==================[macros]=================================================*/
/**	@def PUERTO_BASE
 *	@brief Dirección base del puerto disponible según este simulador.*/
#define PUERTO_BASE 0x200

/**	@def CANT_ELEM_VEC(x)
 *	@brief Macro para calcular la cantidad de elementos de un vector "X".*/
#define CANT_ELEM_VEC(x) (sizeof(x) / sizeof(x[0]))

/*==============================[Tipos de datos]=============================*/
typedef enum{
	FIN_OFF,
	FIN_ON
}finStatus_t;

typedef enum{
	SINC_OFF,
	SINC_ON
}sincStatus_t;

typedef enum{
	VOL1 = 1,
	VOL2,
	VOL3,
	VOL4,
	VOL5,
	VOL6,
	VOL7,
	VOL8,
	VOL9,
	VOL10,
	VOL11,
	VOL12,
	VOL13,
	VOL14,
	VOL15	 
}nVolt_t;

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
 * @brief Vector que almacena la dirección y estado de los puertos 0x200 y 
 *		  0x201, los cuales están inicialmente deshabilitados.*/
static puerto_t dirPuertos[] = {
	{ .dir = PUERTO_BASE,     .estado = DESHABILITADO},
	{ .dir = PUERTO_BASE + 1, .estado = DESHABILITADO}
};

/*==================[definición de funciones internas]=======================*/
/** @fn unsigned char ArmarDatoPuerto (unsigned int port, unsigned int ten, 
							  nVolt_t nv, sincStatus_t sinc, finStatus_t fin )
 * 	@brief Permite armar un valor de 8 bits según el puerto que se desea leer.
 *		   Se piden los datos de bits de fin, sincronismo, número de voltímetro
 *		   y tensión, aunque devuelve solo lo necesario para el puerto 
 * 		   solicitado.
 *	@return unsigned char Dato armado para ser enviado al puerto.
 */
unsigned char ArmarDatoPuerto (unsigned int port, unsigned int ten, nVolt_t nv,\
							  sincStatus_t sinc, finStatus_t fin )
{
	/* Declaraciones locales */
	unsigned char valor;
	
	/* Cuerpo de la función*/
	switch(port){
		case PUERTO_BASE:
				valor = ( ((((unsigned int) ten) & 0x03) << 6 ) + \
						((((unsigned int) nv) & 0x03F) << 2 ) + \
						(((unsigned int) sinc) << 1) + (unsigned int) fin);
				break;
		
		case (PUERTO_BASE + 1):
				valor = ( (((unsigned int) ten) >> 2) );
				break;
		
		default:valor = 0;
	}
	return valor;
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
 *	-Datos válidos de voltímetros 1, 4 y 9.
 *	-Poner varios casos para cada valor para así tener en cuenta la posible 
 * 	 doble lectura innecesaria en el programa de aplicación.
 *	-Bit F en 1 cuando el dato NO es válido para que el usuario solo analice
 *	 ese bit si el dato es válido. De no hacerlo, el programa se cierra.
 *	-Bit F en 1 en caso de agotarse los casos.*/
unsigned char inb( int port)
{
    /* Declaraciones locales */
	static int orden=0;
	int pos;
    unsigned char dato = 0;
	
	/*Se verifica que el puerto está habilitado*/
	pos = BuscarPuerto(dirPuertos, CANT_ELEM_VEC(dirPuertos), port);
	
	if( pos == -1 || dirPuertos[pos].estado == DESHABILITADO){
		MostrarError();
	}
	else{
	    switch(port)
	    {
	        case PUERTO_BASE:
	            switch(orden)
	            {
	            	case 0:
	                case 1:
	                case 2:
	                case 3:
	                case 4: dato = ArmarDatoPuerto(PUERTO_BASE, 0, VOL1, SINC_ON, FIN_ON);
	                    	break;
	                
					case 5:
	                case 6:
	                case 7:
	                case 8:
	                case 9: dato = ArmarDatoPuerto(PUERTO_BASE, 148, VOL4, SINC_OFF, FIN_OFF);  //voltimetro 4 tension 148
	                    	break;
	                    	
	                case 10:
	                case 11:
	                case 12:
	                case 13:
	                case 14: dato = ArmarDatoPuerto(PUERTO_BASE, 0, VOL1, SINC_ON, FIN_ON);
	                    	 break;
	                    	
	                case 15:
	                case 16:
	                case 17:
	                case 18:
	                case 19: dato = ArmarDatoPuerto(PUERTO_BASE, 256, VOL9, SINC_OFF, FIN_OFF);  //voltimetro 9 tension 256
	                    	 break;
	                    	
	                case 20:
	                case 21:
	                case 22:
	                case 23:
	                case 24: dato = ArmarDatoPuerto(PUERTO_BASE, 0, VOL1, SINC_ON, FIN_ON);
	                    	 break;
	                    	 
	                case 25:
	                case 26:
	                case 27:	
	                case 28:
	                case 29: dato = ArmarDatoPuerto(PUERTO_BASE, 516, VOL4, SINC_OFF, FIN_OFF);  //voltimetro 4 tension 516
	                    	 break;
	                    	 
	                case 30:
	                case 31:
	                case 32:
	                case 33:
	                case 34: dato = ArmarDatoPuerto(PUERTO_BASE, 0, VOL1, SINC_ON, FIN_ON);
	                    	 break;
	                    	 
	                case 35:
	                case 36:
	                case 37:
	                case 38:
	                case 39: dato = ArmarDatoPuerto(PUERTO_BASE, 195, VOL1, SINC_OFF, FIN_OFF); //voltimetro 1 tension 195.
							 break;
							 
	                case 40:
	                case 41:
	                case 42:
	                case 43:	
	                case 44: dato = ArmarDatoPuerto(PUERTO_BASE, 0, VOL1, SINC_ON, FIN_ON);
	                    	 break;    
	                    	
	                case 45:
	                case 46:
	                case 47:
	                case 48:
	                case 49: dato = ArmarDatoPuerto(PUERTO_BASE, 516, VOL1, SINC_OFF, FIN_OFF);//voltimetro 1 tension 516    
							 break;
							 
	                case 50:
	                case 51:
	                case 52:
	                case 53:
	                case 54: dato = ArmarDatoPuerto(PUERTO_BASE, 0, VOL1, SINC_ON, FIN_ON);
	                    	 break;
	                    	 
	                case 55:
	                case 56:
	                case 57:
	                case 58:
	                case 59: dato = ArmarDatoPuerto(PUERTO_BASE, 128, VOL4, SINC_OFF, FIN_OFF);  //voltimetro 4 tension 128
	                    	 break;    
	                    	 
					case 60:
					case 61:
	                case 62:
	                case 63:
	                case 64: dato = ArmarDatoPuerto(PUERTO_BASE, 0, VOL1, SINC_ON, FIN_ON);
	                    	 break;
							                     
	                case 65:
	                case 66:
	                case 67:
	                case 68:
					case 69: dato = ArmarDatoPuerto(PUERTO_BASE, 0, VOL1, SINC_OFF, FIN_ON);
			    			 break;
			    			 
					default: dato = ArmarDatoPuerto(PUERTO_BASE, 0, VOL1, SINC_OFF, FIN_ON);
	            }
	            break;
	            
	        case (PUERTO_BASE + 1):
	 			switch(orden)
	            {
	                case 0:
	                case 1:
	                case 2:
	                case 3:
	                case 4: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 0, VOL1, SINC_ON, FIN_ON);
	                    	break;
	                    	
	                case 5:
	                case 6:
	                case 7:
	                case 8:
	                case 9: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 148, VOL4, SINC_OFF, FIN_OFF);   //voltimetro 4 tension 148
	                    	break;
	                    	
	                case 10:
	                case 11:
					case 12:
					case 13:	
	                case 14: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 0, VOL1, SINC_ON, FIN_ON);
	                    	break;
	                    	
	                case 15:
	                case 16:
	                case 17:
	                case 18:
	                case 19: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 256, VOL9, SINC_OFF, FIN_OFF);  //voltimetro 9 tension 256
	                    	 break;
	                    	
	                case 20:
	                case 21:
	                case 22:
	                case 23:
	                case 24: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 0, VOL1, SINC_ON, FIN_ON);
	                    	 break;
	                    	 
	                case 25:
	                case 26:
	                case 27:
	                case 28:
	                case 29: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 516, VOL4, SINC_OFF, FIN_OFF);   //voltimetro 4 tension 516
	                    	 break;
	                    	 
	                case 30:
	                case 31:
	                case 32:
	                case 33:
	                case 34: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 0, VOL1, SINC_ON, FIN_ON);
	                    	 break;
	                    	 
	                case 35:
	                case 36:
	                case 37:
	                case 38:
	                case 39: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 195, VOL1, SINC_OFF, FIN_OFF);  //voltimetro 1 tension 195
							 break;
							 
	                case 40:
	                case 41:
	                case 42:
	                case 43:
	                case 44: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 0, VOL1, SINC_ON, FIN_ON);
	                    	 break;   
							  
	                case 45:
	                case 46:
	                case 47:
	                case 48:
	                case 49: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 516, VOL1, SINC_OFF, FIN_OFF);  //voltimetro 1 tension 516    
							 break;
							 
	                case 50:
	                case 51:
	                case 52:
	                case 53:
	                case 54: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 0, VOL1, SINC_ON, FIN_ON);
	                     	 break;
	                     	 
	                case 55:
	                case 56:
	                case 57:
	                case 58:
	                case 59: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 128, VOL4, SINC_OFF, FIN_OFF);  //voltimetro 4 tension 128
	                    	 break;    
	                    	 
					case 60:
					case 61:
	                case 62:
	                case 63:
	                case 64: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 0, VOL1, SINC_ON, FIN_ON);
	                    	 break;                    
	                    	 
	                case 65:
	                case 66:
	                case 67:
	                case 68:
					case 69: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 0, VOL1, SINC_OFF, FIN_ON);
							 break;
							 
					default: dato = ArmarDatoPuerto(PUERTO_BASE + 1, 0, VOL1, SINC_OFF, FIN_ON);
	            }
	            break;
	
	        default: dato=0; /*En el caso de que existiese otro puerto 
							habilitado, se devuelve 0.*/
					break;
	    }
	
	    orden ++; 
	}
	return dato;
}

/** @} doxygen end group definition */
/*==================[fin del archivo]============================================*/

