#include <stdio.h>

#define N 15


void selectionSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
      
        int temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }
}


int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}


int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (arr[middle] == target) {
            return middle;
        }
        if (arr[middle] < target) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return -1;
}

int main() {
    int X[N];
    int A;

   
    printf("Введіть %d елементів масиву X:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    
    printf("Введіть цільовий елемент A: ");
    scanf("%d", &A);

 
    int linearIndex = linearSearch(X, N, A);
    if (linearIndex != -1) {
        printf("Лінійний пошук: елемент знайдено на позиції %d\n", linearIndex);
    } else {
        printf("Лінійний пошук: елемент не знайдено\n");
    }

    
    selectionSortDescending(X, N);
    printf("Відсортований масив за спаданням:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");

  
    int binaryIndex = binarySearch(X, N, A);
    if (binaryIndex != -1) {
        printf("Бінарний пошук: елемент знайдено на позиції %d\n", binaryIndex);
    } else {
        printf("Бінарний пошук: елемент не знайдено\n");
    }

    return 0;
}
