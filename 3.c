#include <stdio.h>
#define MAX 10

//Definicion de Tipos
typedef int tVector [MAX];

//Variables Globales
tVector vector;

//Prototipo de Funciones
void visualizarVector();
void cargarVector();
int buscarMaximo();
int buscarMinimo();
float acumularVector();
float calcularMedia(int, float);
float calcularSemisuma(int, int);

void mostrarMaximo();
void mostrarMinimo();
void mostrarMedia();
void mostrarSemisuma();

//Funcion Principal
int main(){
    cargarVector();
    visualizarVector();
    mostrarMaximo();
    mostrarMinimo();
    mostrarMedia();
    mostrarSemisuma();
    return 0;
}
//Implementacion
void cargarVector(){
    int i;
    for(i=0;i<MAX;i++){
        printf("Ingresar valores del vector: ");
        scanf("%d",&vector[i]);
    }
}

void visualizarVector() {
    int i;
    for(i=0;i<MAX;i++){
        printf("%d ",vector[i]);
    }
}

int buscarMaximo() {
    int maximo = 0;
    int i;
    for(i=0;i<MAX;i++){
        if(vector[i] > maximo) {
            maximo = vector[i]; 
        }
    }
    return maximo;
}

int buscarMinimo() {
    int i;
    int minimo = 99999;
    for(i=0;i<MAX;i++) {
        if(vector[i] < minimo) {
            minimo = vector[i];
        }
    }
    return minimo;
}

float acumularVector() {
    int i;
    float acumulador = 0;
    for(i=0;i<MAX;i++){
        acumulador = acumulador + vector[i];
    }
    return acumulador;
}

float calcularMedia(int pContador, float pAcumulador) {
    float media = 0;
    media = pAcumulador / pContador;
    return media;
}

float calcularSemisuma(int pMinimo, int pMaximo) {
    float semisuma = 0;
    semisuma = pMaximo / pMinimo;
    return semisuma;
}

void mostrarMaximo() {
    int maximo = buscarMaximo();
    printf("\nEl maximo numero encontrado es: %d\n",maximo);
}

void mostrarMinimo() {
    int minimo = buscarMinimo();
    printf("El minimo numero encontrado es: %d\n",minimo);
}

void mostrarMedia(){
    float acumulador = acumularVector();
    float media = calcularMedia(MAX,acumulador);
    printf("La media es de: %.2f\n",media);
}

void mostrarSemisuma() {
    int minimo = buscarMinimo();
    int maximo = buscarMaximo();
    float semisuma = calcularSemisuma(minimo, maximo);
    printf("La semisuma es de: %.2f\n",semisuma);
}