#include <stdio.h>

main(){
    int n, i, f = 1;

    puts("N: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        f *= i;
    }

    printf("%d! = %d\n", n, f);

    return 0;
}