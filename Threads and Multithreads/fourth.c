#include <stdio.h>
#include <time.h>

int main() {
    int odd[50], even[50];
    int o = 0, e = 0;

    clock_t start = clock();

    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0)
            even[e++] = i;
        else
            odd[o++] = i;
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Even numbers:\n");
    for (int i = 0; i < e; i++)
        printf("%d ", even[i]);

    printf("\n\nOdd numbers:\n");
    for (int i = 0; i < o; i++)
        printf("%d ", odd[i]);

    printf("\n\nTime taken: %f seconds\n", time_taken);

    return 0;
}
