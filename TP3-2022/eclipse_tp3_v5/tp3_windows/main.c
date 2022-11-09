#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"

int main()
{
	/*setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaJugadores = ll_newLinkedList();

    puts("funciona ok");

    do{
        switch(option)
        {
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);

                break;
        }
    }while(option != 10);

    return 0;*/


	 setbuf(stdout,NULL);
	 char seguir = 's';
	 int opcion;
	 char salir;
	 LinkedList* listaJugadores = ll_newLinkedList();
	 LinkedList* listaSelecciones = ll_newLinkedList();
	    do
	    {
	    	opcion = 0;
	    	opcion = menu();
	        switch (opcion)
	        {
	        case 1:
	            if ( controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores) != 0 )
	            {
	                printf("Error al cargar desde texto\n");
	            }
	            break;
	        case 2:
	            if ( controller_cargarJugadoresDesdeBinario("jugadores.csv", listaJugadores) != 0 )
	            {
	                printf("Error al cargar desde binario\n");
	            }
	            break;
	        case 3:
	          if ( controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones) != 0 )
	            {
	                printf("Error al cargar selecciones.csv desde texto\n");
	            }
	            break;

	        case 4:
	            if ( !controller_editarJugador(listaJugadores) )
	            {
	                printf("Error en edicion de empleado\n");
	            }
	            break;
	        case 5:
	        	  if ( controller_agregarJugador(listaJugadores) != 0)
					{
						printf("Error en alta de jugador\n");
					}
					break;

	       case 6:
	            if ( controller_editarJugador(listaJugadores) != 0 )
	            {
	                printf("Error en baja de jugador\n");
	            }
	            break;
	        case 7:
	            if ( controller_removerJugador(listaJugadores) != 0 )
	            {
	                printf("Error en la baja de jugadores\n");
	            }
	            break;
	        case 8:
	            if ( controller_listarJugadores(listaJugadores) != 0 )
	            {
	                printf("Error en el listado de jugadores\n");
	            }

	            break;
	            /* case 9:
	            if ( !controller_saveAsBinary("data.bin", listaJugadores) )
	            {
	                printf("Error al guardar en modo binario\n");
	            }


	            break;
	        case 10:
	            printf("Esta seguro que quiere salir? (S/N)\n");
	            fflush(stdin);
	            scanf("%c", &salir);
	            salir = toupper(salir);
	            if (salir == 'S')
	            {
	                seguir = 'n';
	            }
	            else
	            {
	                break;
	            }
	            break;

	        case 11:

	        	break;
	        case 12:

	        	break;
	        case 13:

	        	break;*/
	        case 14:
	        	printf("\nSaliendo del programa...\n");
	        	break;

	       /* default:
	            printf("Opcion invalida\n");*/
	        }
	        system("pause");
	    } while(opcion != 14);

	    return 0;
}

