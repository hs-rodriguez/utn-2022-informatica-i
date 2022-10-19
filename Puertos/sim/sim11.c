/** @file sim11.c
 *
 *	@date 5 de noviembre de 2019
 *	@version 1.3
 *
 *	@authors Vera, Pablo Martín.
 *	@authors Vazquez Saraullo, Federico Alejandro.
 *
 *	@brief  Archivo fuente que simula los puertos 0x300 y 0x301, y se utiliza 
 *			para validar el programa del ejercicio 11. Los resultados esperados
 *			son:
 *						  Codigo	Promedio
 *							7			5
 *							8		   240
 *
 *	@note Solo se pueden habilitar los puertos 0x300 y 0x301. Los demás puertos
 *		  se toman como que no están disponibles en la PC.
*/

/** \addtogroup Simulador para ejercicio 11 de puertos.
 * @{
 */

/*==================[inclusiones]============================================*/
#include <stdio.h>
#include <stdlib.h>

/*==================[macros]=================================================*/
/**	@def PUERTO_BASE
 *	@brief Dirección base del puerto disponible según este simulador.*/
#define PUERTO_BASE 0x300

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
	RAD0,
	RAD3 = 3,
	RAD7 = 7,
	RAD240 = 240		
}nivelRad_t;

typedef enum{
	COD0,
	COD1,
	COD2,
	COD3,
	COD4,
	COD5,
	COD6,
	COD7,
	COD8,
	COD9,
	COD10,
	COD11,
	COD12,
	COD13,
	COD14,
	COD15	 
}codigoPart_t;

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
 * @brief Vector que almacena la dirección y estado de los puertos 0x300 y 
 *		  0x301, los cuales están inicialmente deshabilitados.*/
static puerto_t dirPuertos[] = {
	{ .dir = PUERTO_BASE,     .estado = DESHABILITADO},
	{ .dir = PUERTO_BASE + 1, .estado = DESHABILITADO}
};

/*==================[definición de funciones internas]=======================*/
/** @fn unsigned char ArmarDatoPuerto (unsigned int port, codigoPart_t cod, 
									   nivelRad_t nr, sincStatus_t sinc, 
									   finStatus_t fin )
 * 	@brief Permite armar un valor de 8 bits según el puerto que se desea leer.
 *		   Se piden los datos de bits de fin, sincronismo, código de partícula
 *		   y nivel de radiación, aunque devuelve solo lo necesario para el 
 *		   puerto solicitado.
 *	@return unsigned char Dato armado para ser enviado al puerto.
 */
unsigned char ArmarDatoPuerto (unsigned int port, codigoPart_t cod, nivelRad_t nr, \
							  sincStatus_t sinc, finStatus_t fin )
{
	/* Declaraciones locales */
	unsigned char valor;
	/* Cuerpo de la función*/
	switch(port){
		case PUERTO_BASE:
				valor = ( ((((unsigned int) nr) & 0x03F) << 2 ) + \
						(((unsigned int) sinc) << 1) + (unsigned int) fin);
				break;
		
		case (PUERTO_BASE + 1):
				valor = ( (((unsigned int) cod) << 4) + ((((unsigned int) nr) & 0x3C0) >> 6) );
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
 *	-Datos válidos de partículas de código 7 y 8.
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
	else
	{
	    switch(port)
	    {
	        case PUERTO_BASE:
	            switch(orden)
	            {
	                case 0:
	                case 1:
	                case 2:
	                case 3:
	                case 4: dato = ArmarDatoPuerto(PUERTO_BASE, COD0, RAD0, SINC_OFF, FIN_ON);
	                    	break;
	                case 5:
					case 6:
	                case 7:
	                case 8:
	                case 9: dato = ArmarDatoPuerto(PUERTO_BASE, COD7, RAD7, SINC_ON, FIN_OFF);
	                    	break;
	                case 10:
	                case 11:
	                case 12:
	                case 13:
					case 14: dato = ArmarDatoPuerto(PUERTO_BASE, COD0, RAD0, SINC_OFF, FIN_ON);
	                    	 break;
	                    	
	                case 15:
	                case 16:
	                case 17:
					case 18:	
	                case 19: dato = ArmarDatoPuerto(PUERTO_BASE, COD8, RAD240, SINC_ON, FIN_OFF);
	                    	 break;
	                    	
	                case 20:
	                case 21:
	                case 22:
	                case 23:
	                case 24: dato = ArmarDatoPuerto(PUERTO_BASE, COD0, RAD0, SINC_OFF, FIN_ON);
	                    	 break;
	                    	
	                case 25:
	                case 26:
	                case 27:
	                case 28:
	                case 29: dato = ArmarDatoPuerto(PUERTO_BASE, COD7, RAD3, SINC_ON, FIN_OFF);
	                    	 break;
	                    	 
	                case 30:
	                case 31:
	                case 32:
	                case 33:
	                case 34: dato = ArmarDatoPuerto(PUERTO_BASE, COD0, RAD0, SINC_OFF, FIN_ON);
	                    	 break;
	                
					case 35:
					case 36:
					case 37:
					case 38:    	 
	                case 39: dato = ArmarDatoPuerto(PUERTO_BASE, COD0, RAD0, SINC_ON, FIN_ON);
			    			 break;
			
					default: dato = ArmarDatoPuerto(PUERTO_BASE, COD0, RAD0, SINC_ON, FIN_ON);
	            }
	            break;
	        
			case (PUERTO_BASE + 1): 
				switch(orden){
	                case 0:
	                case 1:
	                case 2:
	                case 3:
	                case 4: dato = ArmarDatoPuerto(PUERTO_BASE + 1, COD0, RAD0, SINC_OFF, FIN_ON);
                			break;
                			
	                case 5:
	                case 6:
	                case 7:
	                case 8:
	                case 9: dato = ArmarDatoPuerto(PUERTO_BASE + 1, COD7, RAD7, SINC_ON, FIN_OFF);
	                    	break;
	                    	
	                case 10:
	                case 11:
	                case 12:
	                case 13:
	                case 14: dato = ArmarDatoPuerto(PUERTO_BASE + 1, COD0, RAD0, SINC_OFF, FIN_ON);
	                    	break;
	                    	
	                case 15:
	                case 16:
	                case 17:
	                case 18:
	                case 19: dato = ArmarDatoPuerto(PUERTO_BASE + 1, COD8, RAD240, SINC_ON, FIN_OFF);
	                    	break;
	                    	
	                case 20:
	                case 21:
	                case 22:
	                case 23:
	                case 24: dato = ArmarDatoPuerto(PUERTO_BASE + 1, COD0, RAD0, SINC_OFF, FIN_ON);
	                    	 break;
	                    	 
	                case 25:
	                case 26:
	                case 27:
	                case 28:
	                case 29: dato = ArmarDatoPuerto(PUERTO_BASE + 1, COD7, RAD3, SINC_ON, FIN_OFF);  //valor de radiacion 7
	                    	 break;
	                    	 
	                case 30:
	                case 31:
	                case 32:
	                case 33:
	                case 34: dato = ArmarDatoPuerto(PUERTO_BASE + 1, COD0, RAD0, SINC_OFF, FIN_ON);
	                    	 break;
	                    	 
	                case 35:
	                case 36:
	                case 37:
	                case 38:
					case 39: dato = ArmarDatoPuerto(PUERTO_BASE + 1, COD0, RAD0, SINC_ON, FIN_ON);
							 break;
			
					default: dato = ArmarDatoPuerto(PUERTO_BASE + 1, COD0, RAD0, SINC_ON, FIN_ON);
	            }
	            break;
	
        	default: dato = 0x00; /*En el caso de que existiese otro puerto 
									habilitado, se devuelve 0.*/
            		 break;
	    }
	
	    orden ++; 
	}
	return dato;
}

/** @} doxygen end group definition */
/*==================[fin del archivo]============================================*/
