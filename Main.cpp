#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "cuadradoMedio.c"
#include "congruenciaLineal.c"
int n;

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

int main(){

    printf("give me the number of period\n");
    scanf("%d",&n);
    FILE *fp = fopen("periodNumber.txt", "w");
    fprintf(fp, "%d\n",n);
    fclose(fp);
    cuadradoMedio();
    congruenciaLineal();
    sumFile();
    return 0;
}