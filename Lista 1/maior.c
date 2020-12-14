#include <stdio.h>
#include <limits.h>

int main(){
    int n=0, maior=INT_MIN;

    while(scanf("%d", &n)!=EOF){
        if(n>maior){
            maior=n;
        }
    }
    printf("%d\n", maior);

    return 0;
}
