#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"


void inicializarArrayPersonas(EPersona persona[], int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        persona[i].estado=0;
        persona[i].dni=0;
        persona[i].edad=0;

    }
}

void borrarPersona(EPersona persona[])
{
    int dni;
    char seguir;
    int posicion;


    system("cls");
    printf("\n\nIngrese el DNI de la persona que desea borrar: ");
    scanf("%d",&dni);
    posicion=buscarPorDni(persona, dni);

    if (posicion!=-1)
    {
        system("cls");
        printf("\nEsta seguro que desea eliminar a: \n\nNOMBRE--EDAD--DNI\n\n%s---%d---%d\n", persona[posicion].nombre, persona[posicion].edad, persona[posicion].dni);
        printf("\nSI (pulse 's')/NO (pulse 'n'): \n");
        seguir=(char)tolower(getche());

        while(seguir!='s'&&seguir!='n')
        {
            system("cls");
            printf("\nEsta seguro que desea eliminar a: \n\nNOMBRE--EDAD--DNI\n\n%s---%d---%d\n", persona[posicion].nombre, persona[posicion].edad, persona[posicion].dni);
            printf("\nSI (pulse 's')/NO (pulse 'n'): \n");
            seguir=(char)tolower(getche());
        }
        if(seguir=='s')
        {
            system("cls");
            printf("\nLa persona ha sido eliminada.\n\n");
            persona[posicion].estado=0;
        }
        else
        {
            system("cls");
            printf("\nLa operacion ha sido cancelada.\n\n");
        }
    }
    if(posicion==-1)
    {
        printf("\nEl DNI que ingreso no existe.\n");
    }
    system("pause");
    system("cls");
}




void ordenarPersonas(EPersona persona[],int tamanio)
{
    system("cls");
    int i;
    int j;
    int ordenPersonas;
    EPersona auxiliar;

    printf("\n");
    printf("1- Imprimir lista ordenada de la A a la Z\n");
    printf("2- Imprimir lista ordenada de la Z a la A\n\n");
    printf("Elija una opcion: ");
    scanf("%d",&ordenPersonas);

    while(ordenPersonas!=1&&ordenPersonas!=2)
    {
        system("cls");
        printf("\n");
        printf("1- Imprimir lista ordenada de la A a la Z\n");
        printf("2- Imprimir lista ordenada de la Z a la A\n\n");
        printf("Elija una opcion: ");
        scanf("%d",&ordenPersonas);
    }

    system("cls");

    if(ordenPersonas==1)
    {
        for(i=0; i<tamanio-1; i++)
        {
            for(j=i+1; j<tamanio; j++)
            {
                if(strcmp(persona[i].nombre,persona[j].nombre)==1)
                {
                    auxiliar=persona[i];
                    persona[i]=persona[j];
                    persona[j]=auxiliar;
                }
            }
        }
    }
    else
    {
        if(ordenPersonas==2)
        {
            for(i=0; i<tamanio-1; i++)
            {
                for(j=i+1; j<tamanio; j++)
                {
                    if(strcmp(persona[i].nombre,persona[j].nombre)==-1)
                    {
                        auxiliar=persona[i];
                        persona[i]=persona[j];
                        persona[j]=auxiliar;
                    }
                }
            }
        }
    }
    printf("\nNOMBRE--EDAD--DNI\n\n");
    mostrarPersonas(persona, tamanio);
    printf("\n");
    system("pause");
    system("cls");
}




void graficoBarras(int menorde18, int de18a35, int mayorde35)
{
    system("cls");
    int i;
    int j;
    int mayor=0;
    int barras[3]= {menorde18, de18a35, mayorde35};

    for(i=0; i<3; i++)
    {
        if(barras[i] > mayor)
        {
            mayor = barras[i];
        }
    }
    for(i=mayor; i>0; i--)
    {
        printf("%d",i);
        for(j=0; j<3; j++)
        {
            if(barras[j] >= i)
            {
                printf("\t*");
            }
            else
            {
                printf("\t ");
            }
        }
        printf("\n");
    }
    printf("\t<18\t19-35\t>35\n");
    system("pause");
    system("cls");
}




EPersona cargarPersona(char nombre[], int edad, int dni)
{
    EPersona personas;
    strcpy(personas.nombre, nombre);
    personas.edad=edad;
    personas.dni=dni;
    personas.estado=1;
    system("pause");
    system("cls");
    return personas;
}




void mostrarPersonas(EPersona persona[],int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(persona[i].estado==1)
        {
            printf("%s---%d---%d\n",persona[i].nombre, persona[i].edad, persona[i].dni);
        }
    }
}




int obtenerEspacioLibre(EPersona lista[])
{
    int i;
    int flagEspL=0;
    int posicion;
    for(i=0; i<20; i++)
    {
        if(lista[i].estado==0)
        {
            flagEspL=1;
            posicion=i;
            break;
        }
    }
    if(flagEspL==0)
    {
        posicion=-1;
    }
    return posicion;
}




int buscarPorDni(EPersona lista[], int dni)
{
    int i;
    int flagDni=0;
    int posicion;
    for(i=0; i<20; i++)
    {
        if(lista[i].dni==dni)
        {
            flagDni=1;
            posicion=i;
        }
    }
    if(flagDni==0)
    {
        posicion=-1;
    }
    return posicion;
}
