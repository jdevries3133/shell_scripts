#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRNCMP_SIZE_LIMIT 30

void print_usage() {
    printf("USAGE\n\n");
    printf("\tfactor [integer] [integer] ...\n\n");
    printf("Print all the factors for the given integers.\t");
}

/* Prints all factors for a given integer and also returns number of factors */
int factor(int num) {
    int num_factors = 0;
    for (int i = 1; i < num / 2; i++) {
        if (num % i == 0) {
            // break on first duplicate factor
            if (i > num / i) {
                break;
            }
            printf("    %d x %d = %d\n", i, num / i, num);
            num_factors++;
        }
    }
    return num_factors;
}

int is_help_request(char *arg) {
    if (
        strncmp(arg, "-h", STRNCMP_SIZE_LIMIT) == 0
        || strncmp(arg, "--help", STRNCMP_SIZE_LIMIT) == 0
        ) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: Incorrect number of arguments.\n");
        print_usage();
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        if (is_help_request(argv[i])) {
            print_usage();
            return 0;
        }
        int num = atoi(argv[i]);
        printf("--- Factors of %d ---\n", num);
        int num_factors = factor(num);
        printf("--- %d has %d factors.\n", num, num_factors);
        if (num_factors == 1) {
            printf("%d is a prime number!\n", num);
        }
    }
    return 0;
}
