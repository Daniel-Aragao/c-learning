#include <stdio.h>

main(){
    int x, i, f1 = 1, f2 = 0;

    printf("Mostrar ate o elemento: ");
    scanf("%d", &x);

    puts("0");
    for(i = 1; i < x; i++){
        int f3 = f1 + f2;
        printf("%d \n", f3);
        f1 = f2;
        f2 = f3;
    }
    return 0;
}