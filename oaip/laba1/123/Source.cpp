#include <iostream>
#include <cstdarg>

int** createMatrix(int size, ...)
{
    // —оздание двумерного динамического массива
    int** matrix = new int* [size];
    for (int i = 0; i < size; ++i)
    {
        matrix[i] = new int[size];  
    }

    // «аполнение матрицы значени€ми из переменных параметров
    va_list args;
    va_start(args, size);
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            matrix[i][j] = va_arg(args, int);
        }
    }
    va_end(args);

    return matrix;
}


void deleteMatrix(int** matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int sumIntoDiagMatrix(int** matrix, int size)
{
    int sum = 0;
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}


int main()
{
    int** matrix = createMatrix(4, 5, 2, 3, 8, 5, 9, 1, 1, 4, 1, 2, 3, 6, 7, 8, 9);

    // ¬ывод матрицы
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Sum below matrix: " << sumIntoDiagMatrix(matrix, 4);

    
    deleteMatrix(matrix, 4);

    return 0;
}