
#include <stdlib.h>                                                               /* Librerias del programa */
#include <stdio.h>                                                                /* Para utilizar la entrada y salida de datos */
#include <string.h>                                                               /* Para utilizar el metodo strcpy() */
#include <conio.h>                                                                /* Para utilizar el metodo getche() */

#define TERM_INT -999                                                             /* Terminador para la matriz de enteros */
#define TERM_CHAR '\0'                                                            /* Terminador para la matriz de caracteres */
#define FILA 15                                                                   /* Fila generica para las matrices */
#define COLUMNA 20                                                                /* Columna generica para las matrices */

void procedimientoSwitch(char _titulos[FILA][COLUMNA], char _equipos[FILA][COLUMNA], int _datos[FILA][COLUMNA]);      /* Prototipado de las funciones */

int leerArchTitulos(char matT [FILA][COLUMNA]);

int leerArchEquiposDatos(char matE [FILA][COLUMNA]);

int leerArchDatos(int matD [FILA][COLUMNA]);

void cargarMat(char matT [FILA][COLUMNA], char matE [FILA][COLUMNA], int matD [FILA][COLUMNA]);

void imprimirTitulo(char matT [FILA][COLUMNA]);

void imprimirEquipo(char matE [FILA][COLUMNA], int fila);

void imprimirDato(int matD [FILA][COLUMNA], int x);

void imprimirContenido(char matE [FILA][COLUMNA], int matD [FILA][COLUMNA]);

void ordenarPor(char matE[FILA][COLUMNA], int matD[FILA][COLUMNA], int x);

void mostrarMenu();

int ingresarChar();

char validarIntentosEnter(char caracter,  char msj[]);

char validarIntentosSN(char caracter, char msj[]);

void mostrarCantIntentos(char msj[], int cantIntentos);                           

int validarBoolTestigo(int BoolTestigo1, int BoolTestigo2);

void mostrarError(int OpcionError);


int main(int argc, char * argv[]) {
	
	char titulos[FILA][COLUMNA] = {0}, equipos[FILA][COLUMNA] = {0};              /* Se declaran las matrices de carecteres para realizar la tabla */      
	
	int datos[FILA][COLUMNA] = {0};                                               /* Se declararan las matrices de enteros para realizar la tabla */      
	
	procedimientoSwitch(titulos, equipos, datos);                                 /* Se invoca al procedimientoSwitch() para realizar las opciones que brinda el menú */      
	
    return 0;
}

/* ----------------------------------------------  FUNCION SWITCH  ------------------------------------------------------------------------------------------------ */

void procedimientoSwitch(char _titulos[FILA][COLUMNA], char _equipos[FILA][COLUMNA], int _datos[FILA][COLUMNA]) {
	
	int opcionError = 0, boolTestigo1 = 0,  boolTestigo2 = 0, cantidadIntentos = 3;  /* Se declaran las variables de tipo entero que se van  a utilizar en el programa */      
	char caracter = ' ', opcionMenu = ' ';                                           /* Se declaran  las variables de tipo caracter que se van  a utilizar en el programa */  
	
	for (;;) {                                                                       /* un for sin cuerpo */
		
		mostrarMenu();                                                               /* Se invoca al  procedimiento mostrar menú */ 
		opcionMenu = ingresarChar();                                                 /* Se pide una opción del menú al usuario */
		system("cls");                                                               /* Se realiza un "CLS" para que deje toda la pantalla de trabajo limpia */
		
    	switch (opcionMenu) {                                                        /* Se toma  la opción seleccionada y se la paso al swich. Según la opción se ejecuta el case correspondiente. */
    	    case '1': {
     		    cargarMat(_titulos, _equipos, _datos);                               /* Se realiza la lectura de archivos y cargan las matrices */
				
	    	    boolTestigo1 = 1;
		        break;
    		}
	        case '2': {
				opcionError = validarBoolTestigo(boolTestigo1, 1);                   /* Se valida la opción mostrar tabla para saber si previamente ya se cargó la tabla */
				
		        if (opcionError == 0) {
					
					imprimirTitulo(_titulos);                                     
					imprimirContenido(_equipos, _datos);
					boolTestigo2 = 1;                                               /* Se le  asigna un 1 a boolTestigo2 para avisar que la tabla ya se visualizó */
					caracter = validarIntentosEnter(ingresarChar(), "\nSi desea ir al MENU PRINCIPAL presione enter -> ");
					if (caracter == '\r') system("cls");                             /* Se realiza un "CLS" de pantalla y se muestra el menú */                                                          
					else opcionMenu = '7';                                            
					
				} else mostrarError(opcionError);                                     
				
		        break;
		    }
     		case '3': {
				opcionError = validarBoolTestigo(boolTestigo1, boolTestigo2);        /* Se valida la opción Ordenar para saber si previamente ya se cargó y se visualizó la tabla */
				
				if (opcionError == 0) {
					
					printf("\nLa tabla ha sido ordenada por PTS exitosamente :)\n"); /* Se muestra un mensaje avisando que la tabla se ordenó con éxito */
					ordenarPor(_equipos, _datos, 3);                                 /* Se realiza un ordenamiento por la columna PTS */
					
				} else mostrarError(opcionError);                                    /* De lo contrario se muestra un mensaje de error */
				
    		    break;
         	}
         	case '4': {
				opcionError = validarBoolTestigo(boolTestigo1, boolTestigo2);
				
				if (opcionError == 0) {
					
					printf("\nLa tabla ha sido ordenada por DIF exitosamente :)\n"); /* Se muestra un mensaje avisando que la tabla se Ordeno con exito */
					ordenarPor(_equipos, _datos, 4);                                 /* Se realiza un ordenamiento por la columna DIF */
					
				} else mostrarError(opcionError);                                   
				
        		break;
        	}
	        case '5': {
				opcionError = validarBoolTestigo(boolTestigo1, boolTestigo2);
				
				if (opcionError == 0) {
					
					printf("\nLa tabla ha sido ordenada por PTS y por DIF exitosamente :)\n");  /* Muestra un mensaje avisando que la tabla se ordenó con éxito */
					ordenarPor(_equipos, _datos, 4);                                 /* Se realiza un ordenamiento por la columna DIF */
					ordenarPor(_equipos, _datos, 3);                                 /* Se realiza un ordenamiento por la columna PTS */
				} else mostrarError(opcionError);                                    /* De lo contrario se muestra un mensaje de error */
				
     	    	break;                                                           
		    }
     	    case '6': {                                                              /* Caso que pregunta si sale del programa */
				
				printf("Desea salir del programa? (S/N)\n");
				printf("\nRespuesta -> ");
				caracter = validarIntentosSN(ingresarChar(), "\nRespuesta -> ");     /* Valida el caracter ingresado y da tres posibilidades de error */
				if (caracter == 'S' || caracter == 'N') system("cls");               /* Se realiza un "CLS" para que deje toda la pantalla de trabajo limpia */                                                                           
				else opcionMenu = '7';                                               /* De lo contrario finaliza el programa */
    		    break;                                                            
				
			}
		    default: {
				
				if (cantidadIntentos > 0) mostrarCantIntentos("\n", cantidadIntentos--);   /* El usuario tiene tres intentos de error si no finaliza el programa */
				else opcionMenu = '7';
			}
		}
	    if (caracter == 'S' || opcionMenu == '7') {
			system("cls");                                                         /* Se realiza un "CLS" para que deje toda la pantalla de trabajo limpia */
			printf("\n\n\tHa salido del programa :(\n");                           /* Muestra un mensaje de salida del programa */
			break;                                                                 /* Si se  ingresó una S o la opcionMenu fue 7 sale del programa */
		}
	}
}

/* ------------------------------------------  FIN FUNCION SWITCH  ---------------------------------------------------------------------------------------- */

/* ------------------------------------------ FUNCION MENU ----------------------------------------------------------------------------------*/

void mostrarMenu() {                                                              /* Se muestra el menú con las opciones */

	printf("\nMENU PRINCIPAL\n");                                                
	printf("1 - Cargar Tabla\n");                                                
	printf("2 - Mostrar Tabla\n");
	printf("3 - Ordenar por PTS\n");	
	printf("4 - Ordenar por DIF\n");
	printf("5 - Ordenar por PTS y por DIF\n");
	printf("6 - Salir del programa.\n");	
	
	printf("\nOpcion -> ");                                                       
}

/* ----------------------------------------- FIN FUNCION MENU ----------------------------------------------------------------------------------*/

/* ----------------------------------------- FUNCION PEDIR CARACTER ----------------------------------------------------------------------------*/	

int ingresarChar(){                                                               
	
	return getche();                                                              /* Invoco al método getche para pedir las entradas de datos */
}
	
/* ----------------------------------------- FIN FUNCION PEDIR CARACTER ------------------------------------------------------------------------*/	
	
/* ----------------------------------------- FUNCION MOSTRAR CANTIDAD INTENTOS -----------------------------------------------------------------*/

void mostrarCantIntentos(char msj[], int cantIntentos) {                         
	
	printf("\n\n\t[%d]ERROR! La opcion no es válida. Intente nuevamente!\n", cantIntentos);  /* Se muestra la cantidad de intentos que le queda al usuario */
	printf("%s", msj);
}

/* -----------------------------------------FIN FUNCION MOSTRAR CANTIDAD INTENTOS --------------------------------------------------------------*/

/* ----------------------------------------- FUNCION VALIDAR ENTER -----------------------------------------------------------------------------*/
	
char validarIntentosEnter(char caracter, char msj[]) {
	
    int cantidadIntentos = 3;

	while(caracter != '\r' && cantidadIntentos > 0) {
		
		mostrarCantIntentos(msj, cantidadIntentos--);
		caracter = ingresarChar();
	}
	
	return caracter;
}
	
/* ----------------------------------------- FIN FUNCION VALIDAR ENTER -------------------------------------------------------------------------*/

/* ----------------------------------------- FUNCION VALIDAR (S/N) -----------------------------------------------------------------------------*/
	
char validarIntentosSN(char caracter, char msj[]) {
	
	int cantidadIntentos = 3;
	
	while((caracter != 'S' && caracter != 'N') && cantidadIntentos > 0) {
		
		mostrarCantIntentos(msj, cantidadIntentos--);
		caracter = ingresarChar();
	}
	
	return caracter;
}
	
/* ----------------------------------------- FIN FUNCION VALIDAR (S/N) --------------------------------------------------------------------------*/

/* ----------------------------------------- FUNCION VALIDAR BOOL TESTIGO  ----------------------------------------------------------------------*/
	
int validarBoolTestigo(int BoolTestigo1, int BoolTestigo2) {
	
	int error = 0;
	
	if (BoolTestigo1 == 0 && BoolTestigo2 == 0) { 
		
		error = 1;
		
	} else if (BoolTestigo1 == 0) {
		
		error = 2;
		
	} else if (BoolTestigo2 == 0) {
		
		error = 3;
		
	} else {
		
		error = 0;
	}
	
	return error;
}
	
void mostrarError(int opcionError) {
		
	if (opcionError == 1) {
		
		printf("\n\tERROR! La tabla no ha sido cargada y visualizada!\n");
		
	} else if (opcionError == 2) {
		
		printf("\n\tERROR! La tabla no ha sido cargada!\n");
		
	} else {
		
		printf("\n\tERROR! La tabla no ha sido visualizada!\n");
	}
}              

/* ------------------------------------------ FIN FUNCION VALIDAR BOOL TESTIGO  -----------------------------------------------------------------*/

/* ---------------------------------------  PROCEDIMIENTOS PARA IMPRIMIR TABLA ------------------------------------------------------------------*/

void imprimirEquipo(char matE [FILA][COLUMNA], int fila) {
	
    printf("%-21s", matE[fila]);                                                 /* Imprimi por fila porque los equipos entan cargados línea por línea*/
}
	
void imprimirDato(int matD [FILA][COLUMNA], int fila){
	
    int c, dif;
	
    for(c = 0; matD [fila][c + 1] != TERM_INT; c++){                                                
		
        printf("%6d", matD[fila][c]);                                             
    }
    // Cargo la columna DIF de cada equipo
	dif = matD[fila][c-2] - matD[fila][c-1];                                     // resta GF - GC = dif y  se va cargando.
	
	if (dif > 0) {
		
		matD[fila][c] = dif;                                                      
		printf("%5c%-6d",'+',matD[fila][c]);                                     // Se concatena un '+' al DIF positivo
		
	} else {
		
		matD[fila][c] = dif;                                                     // la variable 'dif' se carga en la columna DIF
		printf("%6d", matD[fila][c]);
	}  
}

void imprimirContenido(char matE [FILA][COLUMNA], int matD [FILA][COLUMNA]){
	
    int fila;                                                                       
	
    for(fila = 0 ; matE [fila][0] != TERM_CHAR; fila++){    
		
        imprimirEquipo(matE, fila);                                               // Imprime por linea un equipo y sus datos
        imprimirDato(matD, fila);
        printf("\n");
    }
	printf("\nIngrese enter para ir al MENU PRINCIPAL -> ");
}

void imprimirTitulo(char matT [FILA][COLUMNA]) {
	
    int fila;                                                                   
	
    for (fila = 0; matT[fila][0] != TERM_CHAR; fila++){
		
		if (fila == 0) {
			
			printf("%-21s", matT[0]);                                            // Imprime 'Equipo'
		} else {
			
			printf("%6s", matT[fila]);                                           // Imprime 'Pts''PJ', 'PG', 'PE', 'PP', 'GF', 'GC', 'DIF' 
		}
    }
	
    printf("\n---------------------------------------------------------------------\n");
}

/* --------------------------------------------FIN PROCEDIMIENTOS PARA IMPRIMIR TABLA -------------------------------------------------------------------*/

/* ----------------------------------------------------- CARGA DE ARCHIVOS ------------------------------------------------------------------------------*/

int leerArchTitulos(char matT [FILA][COLUMNA]) {
	
	int f = 0, i = 0;
	
	FILE* archTitulo = fopen("titulos.txt","r");                                 /* abrir archivo de escritura*/
	
	if (archTitulo == NULL) {
		
		return -1;
	} else {
		
		f = fscanf(archTitulo,"%[a-zA-Z0-9 ]\n", matT[i]); 
		
		while (f != EOF){
			
			i++;
			f = fscanf(archTitulo,"%[a-zA-Z0-9 ]\n", matT[i]);                   /* Equipo', 'Pts', 'PJ', 'PG', 'PE', 'PP', 'GF', 'GC', 'DIF' */
		}
		
		matT[i][0] = TERM_CHAR;
		
		fclose(archTitulo);                                                      /* cerrar archivo*/
		return 0;
	}
}

int leerArchEquipos(char matE [FILA][COLUMNA]) {
	
	int f = 0, i = 0;
	
	FILE* archEquipos = fopen("equipos.txt","r");                                /* abrir archivo de escritura*/
	
	if (archEquipos == NULL){
		
		return -2;
	} else {
		
		f = fscanf(archEquipos,"%[a-zA-Z0-9 ]\n", matE[i]); 
		
		while (f != EOF){
			i++;
			f = fscanf(archEquipos,"%[a-zA-Z0-9 ]\n", matE[i]);
		}
		
		matE[i][0] = TERM_CHAR;
		
		fclose(archEquipos);                                                      /* cerrar archivo*/
		return 0;
	}
}

int leerArchDatos(int matD [FILA][COLUMNA]) {
	
	int f = 0, i = 0;
	
	FILE* archDatos = fopen("datos.txt","r");                                    /* abrir archivo de escritura*/
	
	if (archDatos == NULL){
		
		return -3;
		
	} else {
		
		f = fscanf(archDatos,"%d,%d,%d,%d,%d,%d,%d\n", &matD[i][0], &matD[i][1], &matD[i][2], &matD[i][3], &matD[i][4], &matD[i][5], &matD[i][6]);
		matD[i][8] = TERM_INT;
		
		while (f != EOF){
			
			i++;
		    f = fscanf(archDatos,"%d,%d,%d,%d,%d,%d,%d\n", &matD[i][0], &matD[i][1], &matD[i][2], &matD[i][3], &matD[i][4], &matD[i][5], &matD[i][6]);
			matD[i][8] = TERM_INT;
		}
		
		matD[i][0] = TERM_INT;
		
		fclose(archDatos);                                                       /* cerrar archivo*/
		return 0;
	}
}
	
void cargarMat(char matT [FILA][COLUMNA], char matE [FILA][COLUMNA], int matD [FILA][COLUMNA]) {
	
	int contadorOK = 0, errorLectura = 0;
	
	errorLectura = leerArchTitulos(matT);
	if (errorLectura == -1) {
		
		printf("\n\t[%d]ERROR! La lectura del archivo ha sido incorrecta!\n", errorLectura);
		
	} else {
		
		contadorOK++;
	}
	
	errorLectura = leerArchEquipos(matE);
	if (errorLectura == -2) {
		
		printf("\n\t[%d]ERROR! La lectura del archivo ha sido incorrecta!\n", errorLectura);
		
	} else { 
		
		contadorOK++;
	}
	
	errorLectura = leerArchDatos(matD);
	if (errorLectura == -3) { 
		
		printf("\n\t[%d]ERROR! La lectura del archivo ha sido incorrecta!\n", errorLectura);
		
	} else {
		
		contadorOK++;
	}
	
	if (contadorOK == 3) { 
		
		printf("\nLa tabla ha sido cargada con exito :)\n");
		
	} else { 
		
		printf("\n\t La tabla ha sido cargada sin exito :(\n"); 
	}
}

/*---------------------------------------------------- FIN CARGA DE ARCHIVOS  ---------------------------------------------------------------------------*/

/*---------------------------------------------------- FIN FUNCION ORDENAR MATRIZ  ----------------------------------------------------------------------*/

void ordenarPor(char matE[FILA][COLUMNA], int matD[FILA][COLUMNA], int x) {          

	int i, c, j, longEquipos, opcionalMenu, auxInt= 0; 
	char auxStr[COLUMNA] = {0};
	
    if (x == 3) { 
		
		opcionalMenu = 0;
		
	} else {
		
		opcionalMenu = 7;
	}

	for(longEquipos = 0; matE[longEquipos][0] != TERM_CHAR; longEquipos++); 
	
	for(i = 0; i < longEquipos - 1 ; i++) {
		
		for(j = i + 1; j < longEquipos; j++) {
			
			if(matD[i][opcionalMenu] > matD[j][opcionalMenu]) {     
				
				strcpy(auxStr, matE[i]);
				strcpy(matE[i], matE[j]);
				strcpy(matE[j], auxStr);
				
				for (c = 0 ; matD [i][c + 1] != TERM_INT ; c++) {
					
					auxInt = matD[i][c];
					matD[i][c] = matD[j][c];
					matD[j][c] = auxInt;
				}
			}
		}
	}
}
/*---------------------------------------------------- FIN FUNCION ORDENAR MATRIZ  ------------------------------------------------------------------------*/
