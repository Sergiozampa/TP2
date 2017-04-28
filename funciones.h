#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

void inicializarArrayPersonas(EPersona[], int);

void borrarPersona(EPersona[]);

void ordenarPersonas(EPersona[],int);

void graficoBarras(int,int,int);

EPersona cargarPersona(char[],int, int);

void mostrarPersonas(EPersona[],int);

int obtenerEspacioLibre(EPersona lista[]);

int buscarPorDni(EPersona lista[], int dni);

#endif // FUNCIONES_H_INCLUDED
