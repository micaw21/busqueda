#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define FILA 10
#define COL 7

//Definicion de Tipos
typedef float tVector[FILA][COL];
typedef float tVector2[10];

//Variables Globales
tVector participantes;
tVector2 puntuaciones = {0,0,0,0,0,0,0,0,0,0};
tVector2 mayores;
tVector2 menores;
float ganador = 0;

//Prototipo de Funciones
void generarMatriz();
void buscarMayor();
void buscarMenor();
void sumarPuntuaciones();
void informarGanador();
void visualizarMatriz();
void visualizarPuntajes();


//Funcion Principal
int main() {
    generarMatriz();
    visualizarMatriz();
    buscarMayor();
    buscarMenor();
    sumarPuntuaciones();
    visualizarPuntajes();
    informarGanador();
    return 0;
}

//Implementacion
void visualizarPuntajes() {
    int i;
    printf("\n***PUNTAJE FINAL***\n");
    for(i=0;i<FILA;i++){
        printf("\t %.1f ",puntuaciones[i]);
    }
}
void visualizarMatriz() {
    int i,j;
    for(i=0;i<FILA;i++) {
        printf("\n\t***Participante %d ***\n",i+1);
        for(j=0;j<COL;j++) {
            printf("\t %.1f ",participantes[i][j]);
        }
        printf("\n");
    }
}
void generarMatriz(){
    int i,j;
    srand(time(NULL));
    for(i=0;i<FILA;i++){
        for(j=0;j<COL;j++){
            participantes[i][j] = (rand() % 9) + 1;
        }
    }
}

void buscarMayor() {
    int i,j;
    float mayor = 0;
    int cambio;
    for(i=0;i<FILA;i++) {
        for(j=0;i<COL;i++) {
            if(participantes[i][j] > mayor){
                mayor = participantes[i][j];
                mayores[i] = mayor;            
            }
        }
    }
}

void buscarMenor() {
    int i,j;
    float menor = 9999;
    for(i=0;i<FILA;i++) {
        for(j=0;i<COL;i++) {
            if(participantes[i][j] < menor){
                menor = participantes[i][j];
                menores[i] = menor;            
            }
        }
    }
}

void sumarPuntuaciones() {
    int i,j;
    float ganador = 0;
    for(i=0;i<FILA;i++){
        for(j=0;j<COL;j++){
            if(participantes[i][j] != menores[i] && participantes[i][j] != mayores[i]){
                puntuaciones[i] = puntuaciones[i] + participantes[i][j];
            }
        }
    }
}
void informarGanador() {
    int i;
    int participante;
    for(i=0;i<FILA;i++) {
        if(puntuaciones[i] > ganador){
            ganador = puntuaciones[i];
            participante = i+1;
        }
    }

    printf("\nGanador: Participante %d con un puntaje de %.1f!\n",participante,ganador);
}


