#include <stdio.h>
#include <stdbool.h>
#define MAX 10

//Definicion de Tipos
typedef int tVector[MAX];

//Variables Globales
tVector vectorEnteros = {0,0,0,0,0,0,0,0,0,0};
//bool existe;

//Prototipo de Funciones
void cargarVector();
void visualizarVector();
void buscarNumero();
//void numeroExiste(int);
bool numeroExiste(int);

int main() {
    cargarVector();
    visualizarVector();
    buscarNumero();
    return 0;
}

//Implementacion
void cargarVector() {
    int i;
    printf("Cargando vector...\n");
    for(i=0;i<MAX;i++){
        printf("Ingrese un numero entero: ");
        scanf("%d",&vectorEnteros[i]);
    }
    printf("Vector cargado!\n");
}

void visualizarVector() {
    int i;
    printf("***Elementos en vector***\n");
    for(i=0;i<MAX;i++){
        printf("%d ",vectorEnteros[i]);
    }
}

void buscarNumero() {
    int numero;
    int aux;

    printf("\nIngrese numero a buscar en vector: ");
    scanf("%d",&numero);
    int i;
    for(i=0;i<MAX;i++){
        if(numero == vectorEnteros[i]){
            aux = 1;
        } 
    }
    if(numeroExiste(aux)){
        printf("Numero encontrado!\n");
    } else {
        printf("Numero no encontrado!\n");
    }
}

bool numeroExiste(int pAux){
    return(pAux == 1);
}