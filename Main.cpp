#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "cuadradoMedio.c"
#include "congruenciaLineal.c"
int n;
int *nurses;
void sumFile(){
    FILE * cl = fopen("congruenciaLineal.ctxt","r");
    FILE * cm = fopen("cuadradoMedio.txt","r");
    FILE * numbers = fopen("numbers.txt", "w");
    for(int i = 0; i < n; i++){
        lli a,b,c;
        fscanf(cl,"%lld", & a);
        fscanf(cm, "%lld", &b);
        c = (a + b) % MTEN;
        fprintf(numbers,"%lld", c); 
    }
}

void generateNumbers(){
    printf("give me the number of period\n");
    scanf("%d",&n);
    FILE *fp = fopen("periodNumber.txt", "w");
    fprintf(fp, "%d\n",n);
    fclose(fp);
    cuadradoMedio();
    printf("is it here?");
    congruenciaLineal();
    sumFile();
}



int * getArrives(){
    int nurse;
    printf("Which number beetween 0 and 9 represents a nurse arrive\n");
    scanf("%d", &nurse);
    int cont = 0;
    int * nurses = (int * )malloc(n * sizeof(int));
    FILE * numbers = fopen("periodNumber.txt","r");
    for(int i = 0; i < n; i++){
        lli number;
        fscanf(numbers, "%d", &number);
        for(int i =0; i < 10; i++){
            if(nurse == number%10){
                cont++;
            }
        }
        nurses[i] = cont; 
    }
    return nurses;
} 

int getAvgWaitTime(){
    int waitingTime[] = {8,9,9,10,10,10,11,11,11,11};
    
}

int main(){

    generateNumbers();    
    nurses = getArrives();

    return 0;
}