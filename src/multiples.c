#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


struct Arguments {
    bool valid;
    int base;
    int count;
};

void parse_args(struct Arguments *args, char *input[], int num_args) {

    bool found_base = false;
    bool found_count = false;

    // simplest usage with unnamed positional args
    if (num_args == 3) {
        args->base = atoi(input[1]);
        args->count = atoi(input[2]);
        args->valid = true;
        return;
    }

    // start i at 1 and stop when there is no more args ahead, because we
    // are looking for flags, then grabbing the next arg.
    for (int i = 1; i + 1 < num_args; i++) {
        if (strncmp(input[i], "--base", 30) == 0) {
            args->base = atoi(input[i + 1]);
            found_base = true;
        } else if (strncmp(input[i], "--count", 40) == 0) {
            args->count = atoi(input[i + 1]);
            found_count = true;
        }
    }

    if (found_base && found_count) {
        args->valid = true;
    }
}

void print_multiples(int *base, int *num) {
    printf("First %d multiples of %d\n", *num, *base);
    for (int i = 1; i <= *num; i++) {
        printf("%d x %d = %d\n", *base, i, *base * i);
    }
}

void print_help() {
    printf("USAGE\n\n");
    printf("\tmultiples (--base)? [number] (--count)? [number]\n\n");
    printf("Base is the number to find the multiples of. Count is the number\n");
    printf("of multiples to be printed.\n");
}

int main(int argc, char *argv[]) {
    struct Arguments args;
    parse_args(&args, argv, argc);
    if (!args.valid) {
        print_help();
        return 0;
    }
    print_multiples(&args.base, &args.count);
    return 0;
}
