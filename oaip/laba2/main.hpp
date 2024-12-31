#include <time.h>

int var6() {
    // ������������� ���������� ��������� �����
    srand(time(NULL));

    // ��������� ��������� ������������ ����� � ������ �� � ����
    FILE* fileA = fopen("fA.txt", "w");
    if (!fileA) {
        printf("�� ������� ������� ���� fA\n");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        double randomValue = -50.0 + (rand() / (RAND_MAX / (50.0 - (-50.0) + 1.0))); // ��������� ������������� ����� � ��������� �� -50 �� 50
        fprintf(fileA, "%lf\n", randomValue);
    }

    fclose(fileA);

    // ���������� ������ ����� �� ������������
    int target;
    printf("������� ����� �����: ");
    if (scanf("%d", &target) != 1) {
        printf("������ ����� ������ �����.\n");
        return 1;
    }

    // ������ ����� �� ����� � ����� ���������� � ���������� ������������� �����
    fileA = fopen("fA.txt", "r");
    if (!fileA) {
        printf("�� ������� ������� ���� fA\n");
        return 1;
    }

    double numbers[100];
    int numNumbers = 0;
    double number;

    while (numNumbers < 100 && fscanf(fileA, "%lf", &number) == 1) {
        numbers[numNumbers] = number;
        numNumbers++;
    }

    fclose(fileA);

    if (numNumbers == 0) {
        printf("���� ����.\n");
        return 1;
    }

    double closest = numbers[0];
    int closestIndex = 0;
    double diff = fabs(target - closest);

    for (int i = 1; i < numNumbers; i++) {
        double newDiff = fabs(target - numbers[i]);
        if (newDiff < diff) {
            closest = numbers[i];
            closestIndex = i;
            diff = newDiff;
        }
    }

    printf("����� %f �������� ������ � %d � ����� ���������� ����� %d\n", closest, target, closestIndex);

    return 0;
}
