#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printFileContent(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Ќе удалось открыть файл %s\n", filename);
        return;
    }

    int number;
    printf("—одержимое файла %s: ", filename);
    while (fscanf(file, "%d", &number) == 1) {
        printf("%d ", number);
    }
    printf("\n");

    fclose(file);
}

int isPositive(int num) {
    return num > 0;
}

int isUniquePositive(int* arr, int size, int num) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == num) {
            return 0;  // число уже встречалось
        }
    }
    return 1;  // число уникальное
}

int var4() {
    FILE* fileA = fopen("fileA.txt", "w");
    FILE* fileB = fopen("fileB.txt", "w");

    if (!fileA) {
        printf("Ќе удалось открыть файл fileA\n");
        return 1;
    }

    if (!fileB) {
        printf("Ќе удалось открыть файл fileB\n");
        fclose(fileA);
        return 1;
    }

    srand(time(NULL));  // »нициализаци€ генератора случайных чисел

    int currentNumber;
    int seenPositiveNumbers[1000];  // массив дл€ отслеживани€ уникальных положительных чисел
    int positiveCount = 0;          // количество уникальных положительных чисел

    // √енераци€ и запись случайных чисел в fileA
    for (int i = 0; i < 10; ++i) {  // пример: генераци€ 10 чисел
        currentNumber = rand() % 200 - 100;  // генераци€ числа от -100 до 99

        fprintf(fileA, "%d ", currentNumber);

        if (isPositive(currentNumber) && isUniquePositive(seenPositiveNumbers, positiveCount, currentNumber)) {
            seenPositiveNumbers[positiveCount++] = currentNumber;  // сохранение уникального положительного числа
        }
    }

    fclose(fileA);
    fileA = fopen("fileA.txt", "r");  // ѕереоткрываем fileA дл€ чтени€

    // „тение и запись уникальных положительных чисел из fileA в fileB
    for (int i = 0; i < positiveCount; ++i) {
        fprintf(fileB, "%d ", seenPositiveNumbers[i]);
    }

    fclose(fileA);
    fclose(fileB);

    // ¬ывод содержимого файлов в консоль
    printFileContent("fileA.txt");
    printFileContent("fileB.txt");

    return 0;
}


