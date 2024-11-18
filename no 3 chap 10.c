
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    double fraction;
    int exponent;
} sci_not_t;

void scan_sci(sci_not_t *sn, const char *input){
    sscanf(input, "%lf%e", &sn->fraction, &sn->exponent);
    
    while (sn->fraction >= 1.0){
        sn->fraction /= 10.0;
        sn->exponent += 1;
    }
    while (sn->fraction < 0.1){
        sn->fraction *= 10.0;
        sn->exponent -= 1;
    }
}

void print_sci(sci_not_t sn){
    printf("%.5fe%d\n", sn.fraction, sn.exponent);
}

sci_not_t add_sci(sci_not_t a, sci_not_t b){
    if (a.exponent > b.exponent) {
        b.fraction *= pow(10, a.exponent - b.exponent);
        b.exponent = a.exponent;
    } else if (b.exponent > a.exponent) {
        a.fraction *= pow(10, b.exponent - a.exponent);
        a.exponent = b.exponent;
    }

    sci_not_t result;
    result.fraction = a.fraction + b.fraction;
    result.exponent = a.exponent;

    while (result.fraction >= 1.0) {
        result.fraction /= 10.0;
        result.exponent += 1;
    }
    while (result.fraction < 0.1) {
        result.fraction *= 10.0;
        result.exponent -= 1;
    }
    return result;
}

int main(){
    char input1[50], input2[50];
    sci_not_t num1, num2, sum;

    printf("Enter first number in scientific notation (e.g., 0.25000e3): ");
    scanf("%s", input1);
    scan_sci(&num1, input1);

    printf("Enter second number in scientific notation (e.g., 0.20000e1): ");
    scanf("%s", input2);
    scan_sci(&num2, input2);

    printf("Values input:  ");
    print_sci(num1);
    print_sci(num2);

    sum = add_sci(num1, num2);

    printf("Sum:  ");
    print_sci(sum);

    return 0;
}