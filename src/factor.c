#include <stdio.h>
#include <stdlib.h>

void print_usage() {
    printf("USAGE\n\n");
    printf("\tfactor [integer] [integer] ...\n\n");
    printf("Print all the factors for the given integers.\t");
}

void factor(int num) {
    int iter_range;
    if (num > 2) {
        iter_range = num / 2;
    } else {
        iter_range = 1;
    }
    for (int i = 1; i <= iter_range / 2; i++) {
        if (num % i == 0) {
            printf("    %d x %d = %d\n", i, num / i, num);
        }
    }
}

int main(int argc, char *argv[]) {
    // I am getting command line args; now need to type cast or something.
    if (argc < 2) {
        printf("Error: Incorrect number of arguments.\n");
        print_usage();
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        printf("--- Factors of %d ---\n", num);
        factor(num);
    }
    printf("---------------------\n");
    return 0;
}
