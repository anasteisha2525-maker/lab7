#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

// Заповнення масиву випадковими числами [-100;100]
void fillArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100;
    }
}

// Виведення масиву
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");
}

// Пошук мінімального елемента
int findMin(int arr[], int n) {
    int i, min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

// Сума елементів між першим і другим від’ємними
int sumBetweenNegatives(int arr[], int n) {
    int i, first = -1, second = -1, sum = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (first == -1)
                first = i;
            else {
                second = i;
                break;
            }
        }
    }

    if (first != -1 && second != -1) {
        for (i = first + 1; i < second; i++) {
            sum += arr[i];
        }
    }

    return sum;
}

int main() {
    int arr[N];
    int min, sum;

    srand(time(NULL));

    fillArray(arr, N);

    printf("Масив:\n");
    printArray(arr, N);

    min = findMin(arr, N);
    sum = sumBetweenNegatives(arr, N);

    printf("Мінімальний елемент: %d\n", min);
    printf("Сума між першим і другим від’ємними: %d\n", sum);

    return 0;
}