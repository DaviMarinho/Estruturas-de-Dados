#include <stdio.h>

int main(){
    int base=0, base2=0, i, k=1, asteriscos, espacos, d=0, impares[10];

    scanf("%d", &base);
    base2 = base;
    base = base*2;
    for(i=1; i<=base2; i++)
    {
        k += 2;
        for(espacos=base2-i; espacos>=1; espacos--){ 
            printf(" ");
        }
        for(asteriscos=1;asteriscos<k;asteriscos+=2){
            printf("*");
        }
        if(k%2!=0){
                k = k + 2;
            }
        printf("\n"); 
    }  

    return 0;
}