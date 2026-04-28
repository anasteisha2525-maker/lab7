#include <stdio.h>

int main() {
    int i, j, simple;

    for (i = 2; i <= 98; i++) {   // до 98, бо перевіряємо i і i+2
        simple = 1;
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                simple = 0;
                break;
            }
        }

        if (simple) {
            // перевірка чи i+2 просте
            simple = 1;
            for (j = 2; j * j <= i + 2; j++) {
                if ((i + 2) % j == 0) {
                    simple = 0;
                    break;
                }
            }

            if (simple) {
                printf("%d і %d\n", i, i + 2);
            }
        }
    }

    return 0;
}