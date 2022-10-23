#include <stdio.h>
#include <stdbool.h>
#define MAX 10

//Definicion de Tipos
typedef float tVector[MAX];

//Variables Globales
tVector numeros = {0,0,0,0,0,0,0,0,0,0};
int inferior;
int superior;
int mitad;

//Prototipo de Funciones
void cargarVector();
void visualizarVector();
void busquedaBinaria();
bool existe(int);
void numeroExiste();

//Funcion Principal
int main() {
    cargarVector();
    visualizarVector();
    busquedaBinaria();
    return 0;
}

//Implementacion
void cargarVector() {
    int i;
    printf("Cargando vector...\n");
    for(i=0;i<MAX;i++){
        printf("Ingrese un numero real: ");
        scanf("%f",&numeros[i]);
    }
    printf("Vector cargado!\n");
}

void visualizarVector() {
    int i;
    printf("***Elementos en vector***\n");
    for(i=0;i<MAX;i++){
        printf("%.2f ",numeros[i]);
    }
}

void busquedaBinaria() {
    int aux;
    int dato = -1;
    printf("\nIngrese un numero a buscar: ");
    scanf("%d",&aux);
    inferior = 0;
    superior = MAX;
    while(inferior <= superior){
        mitad = (inferior + superior) / 2;
        if(numeros[mitad] == aux){
            dato = 1;
            break;
        }
        if(numeros[mitad] > aux){
            superior = mitad;
            mitad = (inferior + superior) / 2;
        }
        if(numeros[mitad] < aux) {
            inferior = mitad;
            mitad = (inferior + superior) / 2;
        }
    }

    if (existe(dato)){
        printf("Elemento encontrado!\n");
    } else {
        printf("Elemento no encontrado!\n");
    }
}

bool existe(int pDato){
    return(pDato == 1);
}

