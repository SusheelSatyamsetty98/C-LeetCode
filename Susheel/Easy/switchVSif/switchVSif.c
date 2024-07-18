#include <stdio.h>
#include <time.h>

#define TEST_ITERATIONS 10000000

int switch_case(int choice) {
    switch(choice) {
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 4;
        case 5: return 5;
        case 6: return 6;
        case 7: return 7;
        case 8: return 8;
        case 9: return 9;
        case 10: return 10;
        default: return -1;
    }
}

int if_else(int choice) {
    if (choice == 1) return 1;
    else if (choice == 2) return 2;
    else if (choice == 3) return 3;
    else if (choice == 4) return 4;
    else if (choice == 5) return 5;
    else if (choice == 6) return 6;
    else if (choice == 7) return 7;
    else if (choice == 8) return 8;
    else if (choice == 9) return 9;
    else if (choice == 10) return 10;
    else return -1;
}

int main() {
    int result;
    clock_t start, end;
    double cpu_time_used;

    // Test switch-case
    start = clock();
    for (int i = 0; i < TEST_ITERATIONS; i++) {
        result = switch_case(i % 11);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Switch-case time: %f seconds\n", cpu_time_used);

    // Test if-else
    start = clock();
    for (int i = 0; i < TEST_ITERATIONS; i++) {
        result = if_else(i % 11);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("If-else time: %f seconds\n", cpu_time_used);

    return 0;
}

