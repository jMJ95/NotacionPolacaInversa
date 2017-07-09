/*
	6x04-Notacion_postfija_con_pilas
	07/02/2012

	Escribe un programa que lea de teclado una expresi�n en notaci�n postfija y la eval�e,
	mostrando su resultado por pantalla. Para ello implementa y utiliza una pila.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
struct NODO
{
	int valor;
	struct NODO *puntero;
};



// FUNCI�N QUE PASA UNA CADENA CON NUMEROS A ENTERO:
int pasaCadenaAEntero( char cadena[20] )
{
	/*
	Precondici�n:
					Se ha de recibir una cadena de caracteres terminada en fin de linea que contenga solo un numero entero de m�ximo 20 d�gitos.
	Poscondici�n:
					Se pasa esa cadena al tipo entero y se devuelve el valor.
	*/


	int longCadena=strlen(cadena), numero=0, i;

	for( i=0; i<longCadena; i++ )
	{
		numero *= 10;
		numero += cadena[i]-48;
	};

	return numero;
};



// FUNCI�N QUE INTRODUCE UN NUMERO EN UNA PILA:
void insertaDatoEnLaPila( struct NODO **pila, int num )
{
	/*
	Precondici�n:
					Se ha de recibir un doble puntero de tipo struct NODO para una pila, y un par�metro de tipo entero.
	Poscondici�n:
					Se introduce el numero recibido en la pila.
	*/


	struct NODO *temp = (struct NODO *) malloc(sizeof(struct NODO));


	temp->valor		= num;
	temp->puntero	= *pila;
	*pila			= temp;

};



// FUNCI�N QUE EXTRAE EL PRIMER ELEMENTO DE LA PILA Y BORRA EL NODO VACIO:
int extraeDatoDeLaPila( struct NODO **pila )
{
	/*
	Precondici�n:
					Se ha de recibir un doble puntero de tipo struct NODO para una pila.
	Poscondici�n:
					Se devuelve el primer par�metro de tipo entero almacenado en la pila.
	*/


	struct NODO *siguiente;
	int resp;

	// Se copia el valor a la variable que va a ser retornada por la funci�n:
	resp = (*pila)->valor;


	// Se elimina el primer Nodo (el vaciado):
	siguiente = (*pila)->puntero;
	free(*pila);
	*pila = siguiente;


	return resp;
};



// FUNCI�N QUE LIBERA LA MEMORIA USADA POR UNA LISTA:
void listaLiberaRam( struct NODO **lista )
{
	/*
	Precondici�n:
					Se ha de recibir un puntero de tipo struct NODO al primer nodo de la lista.
	Poscondici�n:
					Se borran todos los nodos de esa lista hasta llegar a NULL.
	*/


	struct NODO *actual, *siguiente;
	actual = *lista;

	while(actual != NULL)
	{
		siguiente = actual->puntero;
		free(actual);
		actual = siguiente;
	};

	*lista = NULL;

};



main()
{

    int opcion = 0;

    struct NODO *pila;
    char cad[20];
    int val1, val2;


    printf("NOTACION POLACA INVERSA \n \n");
    printf("Poner espacios entre los numeros y operandos \n ");
    printf("Luego escribir el simbolo  �=� seguido de un enter \n");
    printf( "Indique la expresion:\n\n" );



     do{



       // Se lee un valor o operador:
       scanf( "%s", cad );





       // Dependiendo de lo leido se hace una operacion u otra:
       switch( cad[0] )
       {
        case '+':
        // En el caso de la: '+', '-', '*' y '/', se sacan dos valores de la pila, se opera con ellos seg�n el operador elegido y se guarda el resultado en la pila.

          val1 = extraeDatoDeLaPila( &pila );
          val2 = extraeDatoDeLaPila( &pila );
          insertaDatoEnLaPila( &pila, val1 + val2 );
          break;

        case '-':
           val1 = extraeDatoDeLaPila( &pila );
           val2 = extraeDatoDeLaPila( &pila );
           insertaDatoEnLaPila( &pila, val1 - val2 );
        break;

        case '*':
            val1 = extraeDatoDeLaPila( &pila );
            val2 = extraeDatoDeLaPila( &pila );
            insertaDatoEnLaPila( &pila, val1 * val2 );
        break;


            case '/':
                val1 = extraeDatoDeLaPila( &pila );
                val2 = extraeDatoDeLaPila( &pila );
                insertaDatoEnLaPila( &pila, val1 / val2 );
            break;


            case '=':
            // Se imprime por pantalla el ultimo y �nico elemento de la pila.
                printf( "\nEl resultado es: %i\n\n", extraeDatoDeLaPila( &pila ) /*pila->valor*/ );
            break;

            default:

            // Se introduce un nuevo dato en la pila:
                insertaDatoEnLaPila( &pila, pasaCadenaAEntero(cad) );
            break;
            };
    } while( cad[0] != '=' );

        cout << "Desea?" << endl;
        cout << "1. \t Salir." << endl;
        cout << "2. \t Insertar otra ecuacion." << endl;
        cin >> opcion;
        switch(opcion)
            {
             case 1:
                cout << "Bye!!!" << endl;
                system("pause");
            break;
              case 2:
                system("cls");

                main();
            break;
            default:
                cout << "Digite una opcion correcta por favor" << endl;
                system("cls");
                main();
            break;
            };

        }

