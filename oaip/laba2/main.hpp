#include <time.h>

int var6() {
    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Генерация случайных вещественных чисел и запись их в файл
    FILE* fileA = fopen("fA.txt", "w");
    if (!fileA) {
        printf("Не удалось открыть файл fA\n");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        double randomValue = -50.0 + (rand() / (RAND_MAX / (50.0 - (-50.0) + 1.0))); // Генерация вещественного числа в диапазоне от -50 до 50
        fprintf(fileA, "%lf\n", randomValue);
    }

    fclose(fileA);

    // Считывание целого числа от пользователя
    int target;
    printf("Введите целое число: ");
    if (scanf("%d", &target) != 1) {
        printf("Ошибка ввода целого числа.\n");
        return 1;
    }

    // Чтение чисел из файла и поиск ближайшего к введенному пользователем числу
    fileA = fopen("fA.txt", "r");
    if (!fileA) {
        printf("Не удалось открыть файл fA\n");
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
        printf("Файл пуст.\n");
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

    printf("Число %f наиболее близко к %d и имеет порядковый номер %d\n", closest, target, closestIndex);

    return 0;
}
