#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
// Заповнення масиву випадковими числами [-100;100]
void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 201 - 100;
}
// Заповнення масиву випадковими числами [-100;100]
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%4d ", arr[i]);
    printf("\n");
}
// Пошук мінімального елемента
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}
// Сума елементів між першим і другим від’ємними
int sumBetweenNegatives(int arr[], int n) {
    int first = -1, second = -1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (first == -1)
                first = i;
            else {
                second = i;
                break;
            }
        }
    }

    if (first != -1 && second != -1)
        for (int i = first + 1; i < second; i++)
            sum += arr[i];
    else
        printf("Немає двох від’ємних!\n");

    return sum;
}
int main() {
    int arr[N];
    int choice;
    srand(time(NULL)); //генератор випадкових чисел

    while (1) {
        printf("\n1-Старт  0-Вихід: ");
        scanf("%d", &choice);

        if (choice == 1) {
            fillArray(arr, N);
            printArray(arr, N);
            printf("Мін: %d\n", findMin(arr, N));
            printf("Сума: %d\n", sumBetweenNegatives(arr, N));
        }
        else if (choice == 0) {
            break;
        }
        else {
            printf("Помилка!\n");
        }
    }

    return 0;
}
