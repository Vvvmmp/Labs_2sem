#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printFileContent(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("�� ������� ������� ���� %s\n", filename);
        return;
    }

    int number;
    printf("���������� ����� %s: ", filename);
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
            return 0;  // ����� ��� �����������
        }
    }
    return 1;  // ����� ����������
}

int var4() {
    FILE* fileA = fopen("fileA.txt", "w");
    FILE* fileB = fopen("fileB.txt", "w");

    if (!fileA) {
        printf("�� ������� ������� ���� fileA\n");
        return 1;
    }

    if (!fileB) {
        printf("�� ������� ������� ���� fileB\n");
        fclose(fileA);
        return 1;
    }

    srand(time(NULL));  // ������������� ���������� ��������� �����

    int currentNumber;
    int seenPositiveNumbers[1000];  // ������ ��� ������������ ���������� ������������� �����
    int positiveCount = 0;          // ���������� ���������� ������������� �����

    // ��������� � ������ ��������� ����� � fileA
    for (int i = 0; i < 10; ++i) {  // ������: ��������� 10 �����
        currentNumber = rand() % 200 - 100;  // ��������� ����� �� -100 �� 99

        fprintf(fileA, "%d ", currentNumber);

        if (isPositive(currentNumber) && isUniquePositive(seenPositiveNumbers, positiveCount, currentNumber)) {
            seenPositiveNumbers[positiveCount++] = currentNumber;  // ���������� ����������� �������������� �����
        }
    }

    fclose(fileA);
    fileA = fopen("fileA.txt", "r");  // ������������� fileA ��� ������

    // ������ � ������ ���������� ������������� ����� �� fileA � fileB
    for (int i = 0; i < positiveCount; ++i) {
        fprintf(fileB, "%d ", seenPositiveNumbers[i]);
    }

    fclose(fileA);
    fclose(fileB);

    // ����� ����������� ������ � �������
    printFileContent("fileA.txt");
    printFileContent("fileB.txt");

    return 0;
}


