#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main(){
    
    int vt[N], *pvt;

    pvt=vt;

    srand((int)time(NULL));

    for (int i = 0; i < N; i++)
    {
        *pvt = 1 + rand()%100;
        printf(" %d ", *pvt);
        pvt++;
    }
}
