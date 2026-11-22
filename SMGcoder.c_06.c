#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int lower, upper;

    printf("=========================================\n");
    printf(" PRIME NUMBERS FINDER USING WHILE LOOP \n");
    printf("=========================================\n");

    printf("Enter lower and upper limits: ");
    if (scanf("%d %d", &lower, &upper) != 2) {
        printf("Invalid input. Please enter two integers.\n");
        return 1;
    }

    // Normalize range if lower limit exceeds upper limit
    if (lower > upper) {
        int temp = lower;
        lower = upper;
        upper = temp;
    }

    printf("\nPrime numbers between %d and %d:\n", lower, upper);

    int current = lower;
    int prime_count = 0;

    while (current <= upper) {
        bool is_prime = (current > 1);
        int divisor = 2;

        // Only test divisors up to sqrt(current)
        while (is_prime && divisor * divisor <= current) {
            if (current % divisor == 0) {
                is_prime = false;
                break;
            }
            divisor++;
        }

        if (is_prime) {
            printf("%d ", current);
            prime_count++;
        }

        current++;
    }

    if (prime_count == 0) {
        printf("None found.");
    }

    printf("\n-----------------------------------------\n");
    printf("Total primes found: %d\n", prime_count);
    printf("\n-----------------------------------------\n");
    return 0;
}
