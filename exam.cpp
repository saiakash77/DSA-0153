#include <stdio.h>

int main() {
    int num1, num2, mul, div;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

   
    mul = num1 * num2;
    printf("Product = %d\n", mul);

    
    div = num1 / num2;

   
    if (num2 == 0) {
        printf("Error: Division by zero\n");
    } else {
        printf("Quotient= %d\n", div);
    }

    return 0;
}

