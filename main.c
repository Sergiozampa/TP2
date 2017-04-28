#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define P 32


int main()
{
    char seguir='s';
    int opcion=0;
    char nombre[P][50];
    int edad[P];
    int dni[P];
    int espacioLibre;
    int flagDni;
    int i;
    int tamanio=P;
    int menorde18=0;
    int de18a35=0;
    int mayorde35=0;

    EPersona personas[P];

    while(seguir=='s')
    {
        printf("\nTP2 - ALTAS, BAJAS, MODIFICACIONES, Y LISTADO\n\n");
        printf("MENU\n");
        printf("1. Agregar persona\n");
        printf("2. Borrar persona\n");
        printf("3. Imprimir lista ordenada por nombre\n");
        printf("4. Imprimir grafico de edades\n");
        printf("5. Salir\n\n");
        printf("Elija una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:

            system("cls");

            espacioLibre=obtenerEspacioLibre(personas);
            flagDni=0;
            if(espacioLibre!=-1)
            {
                printf("\n\nIngrese el nombre de la persona: ");
                fflush(stdin);
                gets(nombre[espacioLibre]);
                system("cls");

                printf("\n\nIngrese la edad de la persona (1-100): ");
                scanf("%d",&edad[espacioLibre]);

                while(edad[espacioLibre]<1||edad[espacioLibre]>100)
                {
                    system("cls");
                    printf("La edad ingresada esta fuera del rango permitido.\n\nIngrese la edad de la persona (1-100): ");
                    scanf("%d",&edad[espacioLibre]);
                    system("cls");
                }
                if(edad[espacioLibre]<18)
                {
                    menorde18++;
                }
                else if(edad[espacioLibre]>35)
                {
                    mayorde35++;
                }
                else
                {
                    de18a35++;
                }

                system("cls");

                printf("\n\nIngrese el DNI de la persona (1 Millon - 99 Millones): ");
                scanf("%d",&dni[espacioLibre]);

                while(dni[espacioLibre]<1000000||dni[espacioLibre]>99999999)
                {
                    system("cls");
                    printf("El DNI ingresado esta fuera del rango permitido.\n\nIngrese el DNI de la persona (1 Millon - 99 Millones): ");
                    scanf("%d",&dni[espacioLibre]);
                }

                system("cls");

                for(i=0; i<tamanio; i++)
                {
                    while(personas[i].dni==dni[espacioLibre])
                    {
                        system("cls");
                        printf("El DNI ingresado pertenece a una persona activa.\n\nIngrese el DNI de la persona (1 Millon - 99 Millones): ");
                        scanf("%d",&dni[espacioLibre]);
                    }
                }

                system("cls");

                printf("\nPersona agregada a la lista.\n\n");

                if(flagDni==0)
                {
                    personas[espacioLibre]=cargarPersona(nombre[espacioLibre],edad[espacioLibre],dni[espacioLibre]);
                }
                break;
            }
            if(espacioLibre==-1)
            {
                printf("No hay mas espacio.\n");
                system("pause");
                system("cls");
                break;
            }
            break;
        case 2:
            borrarPersona(personas);
            break;
        case 3:
            ordenarPersonas(personas, tamanio);
            break;
        case 4:
            graficoBarras(menorde18, de18a35, mayorde35);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            system("cls");
        }
    }
    return 0;
}
