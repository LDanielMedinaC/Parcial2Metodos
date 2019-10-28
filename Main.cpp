#include <stdio.h>
#include <stdlib.h>
#include "cuadradoMedio.c"
int n;

int main(){

    printf("give me the number of period\n");
    scanf("%d",&n);
    FILE *fp = fopen("periodNumber.txt", "w");
    fprintf(fp, "%d\n",n);
    fclose(fp);
    cuadradoMedio();
    return 0;
}