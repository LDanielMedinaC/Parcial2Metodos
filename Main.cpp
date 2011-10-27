#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "cuadradoMedio.c"
#include "congruenciaLineal.c"
int n;
int *nurses;
void sumFile(){
    FILE * cl = fopen("congruenciaLineal.txt","r");
    FILE * cm = fopen("cuadradoMedio.txt","r");
    FILE * numbers = fopen("numbers.txt", "w");
    for(int i = 0; i < n; i++){
        lli a,b,c;
        fscanf(cl,"%lld", & a);
        fscanf(cm, "%lld", &b);
        c = (a + b) % MTEN;
        fprintf(numbers,"%lld\n", c); 
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
<<<<<<< HEAD
    int * nurses = (int*)malloc(n * sizeof(int));
    FILE * numbers = fopen("numbers.txt","r");
    for(int i = 0; i < n; i++){
        lli number;
        fscanf(numbers, "%lld", &number);
        for(int i =0; i < 10; i++){
            if(nurse == number%(lli)10){
                cont++;
            }
            number/=(lli)10;
        }
        nurses[i] = cont; 
    }
    return nurses;
} 
int getIthNumber(lli num, int pos){
    int ans;
    for(int i = 0; i <= pos; i++){
        ans = num%10;
        num/=10; 
    }
    return ans;
}

float getAvgWaitTime(){
    int waitingTime[] = {8,9,9,10,10,10,11,11,11,11};
    FILE * numbers = fopen("periodNumber.txt","r");
    int avg = 0;
    int tot = 0;
    int lineA = 0;
    int lineB = 0;
    for(int i = 0; i < n; i++){
        lli number;
        fscanf(numbers, "%lld", &number);
        int x = nurses[i];
        tot += x;
        for(int i = 0; i < x; i++){
            if(i&1){
                lineA += waitingTime[getIthNumber(number, 10 - i)];
                avg += lineA;
            }else{
                lineB += waitingTime[getIthNumber(number, 10 - i)];
                avg += lineB; 
            }
            lineA -= 5;
            lineB -= 5;
        } 
    }
    fclose(numbers);
    if(tot == 0)
    {
        return 0; 
    }
    return (float)avg/(float) tot;
}

float getPromedioDeLlegadas(){
    int tot = 0;
    for(int i = 0; i < n; i++){
        tot += nurses[i];
    }
    return (float)tot/(float)n;
}

int getTotalLlegadas(){
    int tot = 0;
    for(int i = 0; i < n; i++){
        tot += nurses[i];
    }
    return tot;
}

int main(){

    generateNumbers();    
    nurses = getArrives();
    float promedioDeLlegadas = getPromedioDeLlegadas();
    int tot = getTotalLlegadas();
    float avgTiempoEspera = getAvgWaitTime();
    printf("Tiempo promedio de llegadas: %.4f\n", (float)tot/(float)n*5);
    float numeroPeticiones = 60.0/((float)tot/(float)(n*5));
    float numeroSalidas = 60.0/avgTiempoEspera;
    printf("Tiempo promedio de llegada %.4f\n", promedioDeLlegadas);
    float numeroPeticiones1 = 60/promedioDeLlegadas;
    printf("enfermeras en la farmacia : %.4f\n",numeroPeticiones1/numeroSalidas);
    printf("tiempo de espera: %.4f\n", tot/numeroSalidas);
    printf("el numero optimo para contratar es de 4 personas\n");
    return 0;
}