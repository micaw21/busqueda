#include <stdio.h>
#define COL 4
#define FIL 5

//Definicion de Tipos
typedef int tVector[FIL][COL];

//Variables Globales
tVector vector;
int minimo = 9999;
int maximo = 0;
int filaMenor;
int columnaMenor;
int filaMayor;
int columnaMayor;

//Prototipo de Funciones
void cargarMatriz();
void visualizarMatriz();
void buscarMayor();
void buscarMenor();
void informarMayor();
void informarMenor();


//Funcion Principal
int main() {
    cargarMatriz();
    visualizarMatriz();
    buscarMenor();
    buscarMayor();
    informarMayor();
    informarMenor();
    return 0;
}

void cargarMatriz() {
    int i;
    int j;
    for(i=0;i<FIL;i++){
        for(j=0;j<COL;j++){
            printf("Ingrese un numero entero: ");
            scanf("%d",&vector[i][j]);
        }
    }
}

void visualizarMatriz() {
    int i;
    int j;
    for(i=0;i<FIL;i++){
        for(j=0;j<COL;j++){
            printf("\t%d ",vector[i][j]);
        }
        printf("\n");
    }
}

void buscarMayor(){
    int i;
    int j;
    for(i=0;i<FIL;i++){
        for(j=0;j<COL;j++){
            if(vector[i][j] >= maximo){
                maximo = vector[i][j];
                filaMayor = i+1;
                columnaMayor = j+1;
            }
        }
    }
}

void buscarMenor(){
    int i;
    int j;
    for(i=0;i<FIL;i++){
        for(j=0;j<COL;j++){
            if(vector[i][j] <= minimo){
                minimo = vector[i][j];
                filaMenor = i+1;
                columnaMenor = j+1;
            }
        }
    }
}

void informarMayor(){
    printf("\nEl mayor numero encontrado es %d en la fila %d columna %d\n",maximo,filaMayor,columnaMayor);
}

void informarMenor(){
    printf("\nEl menor numero encontrado es %d en la fila %d columna %d\n",minimo,filaMenor,columnaMenor);
}
