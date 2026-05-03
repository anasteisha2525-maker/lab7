#include <stdio.h>

// Функція перевірки, чи число просте
int isPrime(int n) {
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
// Функція для виводу пар "близнюків"
void findTwins(int start, int end) {
    printf("Пари простих чисел-близнюків:\n");

    for (int i = start; i <= end - 2; i++) {
        if (isPrime(i) && isPrime(i + 2)) {
            printf("(%d, %d)\n", i, i + 2);
        }
    }
}
int main() {
    int choice;

    do {
        printf("\n=== МЕНЮ ===\n");
        printf("1. Знайти всі пари близнюків на [0, 100]\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                findTwins(0, 100);
                break;

            case 0:
                printf("Вихід з програми...\n");
                break;

            default:
                printf("Невірний вибір! Спробуйте ще раз.\n");
        }

    } while (choice != 0);

    return 0;
}
