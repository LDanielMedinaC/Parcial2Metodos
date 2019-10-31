#pragma once
#include <stdio.h>

#define lli unsigned long long 
//seed number
#define SN 10 
#define MTEN 100000000000 

//seeds to make more random the algorithm. 
lli seeds[] = {5915587277, 1500450271, 3267000013, 5754853343, 4093082899, 9576890767, 3628273133, 2860486313, 5463458053, 3367900313};

lli getD(lli x){
    lli count = 0; 
    while(x > 0 ){
        x /= 10;
        count++;
    }
    return count;
}

lli getDMiddleNumbers(lli x, lli d){
    lli halfD = d/2;
    lli pot = 1;
    lli number = 0; 
    for(lli i = 0; i < halfD; i++){
        x /= 10; 
    }

    for(lli i = 0; i < d; i++){
        number += pot * (x % 10);
        x /= 10;
        pot *= 10; 
    }
    return number; 
}

void getNumber(lli x, lli n){
    FILE * fp;
    fp = fopen("cuadradoMedio.txt", "w");
    lli d = getD(x);
    for(int i = 0; i < n; i++){
        x = getDMiddleNumbers(x*x, d);
        fprintf(fp, "%lld\n",x);
    }
    fclose(fp);
}

lli readN(){
    lli n;
    FILE *period = fopen("periodNumber.txt","r");
    fscanf(period, "%lld", & n);
    fclose(period);
    return n;
}

void cuadradoMedio(){
    lli x = 3, n;
    n = readN(); 
    printf("introduce a number\n");
    scanf("%d", &x);
    x = (x * seeds[x%SN])%MTEN;
    getNumber(x, n);
}