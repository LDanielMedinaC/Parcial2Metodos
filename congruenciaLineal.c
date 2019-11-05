#pragma once
#include <stdio.h>

#define lli unsigned long long int 
#define SN 10 
#define MTEN 10000000000

//lli seeds[] = {5915587277, 1500450271, 3267000013, 5754853343, 4093082899, 9576890767, 3628273133, 2860486313, 5463458053, 3367900313};

void CongruenciaLineal(lli seed, lli n, lli a, lli c){
    FILE * fp = fopen("congruenciaLineal.txt", "w");
    
    // = fopen("congruenciaLineal.txt", "w");
    fprintf(fp, "%lld\n", seed);
    printf("---->\n");
    int i = 0;
    for(i = 1; i <= n; i++){
        seed = (((a * seed)%MTEN) + c) % MTEN;
        fprintf(fp, "%lld\n", seed);
        printf("%d\n",i);
        break;
    }
    printf("+++++>");
    fclose(fp);
} 

// lli readN(){
//     lli n;
//     FILE *period = fopen("periodNumber.txt","r");
//     fscanf(period, "%lld", & n);
//     fclose(period);
//     return n;
// }

void congruenciaLineal(){
    lli seed, n, a, c, m;
    n = readN();
    printf("Introduce a seed\n");
    scanf("%lld", &seed);
    seed = seeds[seed%SN];
    printf("Introduce a and c. they must be greater than 0\n");
    scanf("%lld %lld", &a, &c);
    
    CongruenciaLineal(seed, n, seeds[a%SN], seeds[c%SN]);
}