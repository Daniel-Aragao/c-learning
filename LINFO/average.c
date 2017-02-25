#include <stdio.h>

main(){
    float x, y, z;

    printf("First number: ");
    scanf("%f", &x);

    printf("Second number: ");
    scanf("%f", &y);

    printf("Third number: ");
    scanf("%f", &z);

    printf("The average is %f\n", (x + y + z)/3);
}