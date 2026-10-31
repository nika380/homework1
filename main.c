#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void inputArray(int array[], int size);
void printArray(const int array[], int size);
int findMin(const int array[], int size);
int findMax(const int array[], int size);
long long calculateSum(const int array[], int size);
double calculateAverage(long long sum, int size);

void performIndividualTask(const int array[], int size);

int main(void)
{
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif

    int array[MAX_SIZE];
    int size;

    printf("Введите размер массива от 1 до %d: ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE)
    {
        printf("Ошибка: недопустимый размер массива.\n");
        return 1;
    }

    inputArray(array, size);
    
    printf("\nИсходный массив:\n");
    printArray(array, size);

    int minIdx = findMin(array, size);
    int maxIdx = findMax(array, size);
    long long sum = calculateSum(array, size);
    double avg = calculateAverage(sum, size);

    printf("\n--- Основные характеристики ---\n");
    printf("Минимальный элемент: %d (индекс: %d)\n", array[minIdx], minIdx);
    printf("Максимальный элемент: %d (индекс: %d)\n", array[maxIdx], maxIdx);
    printf("Сумма элементов: %lld\n", sum);
    printf("Среднее арифметическое: %.2f\n", avg);

    int pos = 0, neg = 0, zeros = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) pos++;
        else if (array[i] < 0) neg++;
        else zeros++;
    }
    printf("Количество: положительных = %d, отрицательных = %d, нулей = %d\n", pos, neg, zeros);

    int even = 0, odd = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) even++;
        else odd++;
    }
    printf("Количество: чётных = %d, нечётных = %d\n", even, odd);

    int a, b;
    printf("\nВведите границы диапазона [a, b] через пробел: ");
    if (scanf("%d %d", &a, &b) == 2) {
        printf("Элементы в диапазоне [%d, %d]: ", a, b);
        int found = 0;
        for (int i = 0; i < size; i++) {
            if (array[i] >= a && array[i] <= b) {
                printf("%d ", array[i]);
                found = 1;
            }
        }
        if (!found) printf("нет таких элементов");
        printf("\n");
    }

    performIndividualTask(array, size);

    return 0;
}

void inputArray(int array[], int size)
{
    printf("Введите %d элементов массива:\n", size);
    for (int i = 0; i < size; i++)
    {
        while (scanf("%d", &array[i]) != 1)
        {
            printf("Ошибочный ввод. Повторите ввод для элемента [%d]: ", i);
            while (getchar() != '\n');
        }
    }
}

void printArray(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int findMin(const int array[], int size)
{
    int minIdx = 0;
    for (int i = 1; i < size; i++)
    {
        if (array[i] < array[minIdx])
        {
            minIdx = i;
        }
    }
    return minIdx;
}

int findMax(const int array[], int size)
{
    int maxIdx = 0;
    for (int i = 1; i < size; i++)
    {
        if (array[i] > array[maxIdx])
        {
            maxIdx = i;
        }
    }
    return maxIdx;
}

long long calculateSum(const int array[], int size)
{
    long long sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

double calculateAverage(long long sum, int size)
{
    return (double)sum / size;
}

void performIndividualTask(const int array[], int size)
{
    printf("\n--- Индивидуальное задание (Вариант 6) ---\n");
    if (size <= 0) {
        printf("Длина возрастающего фрагмента: 0\n");
        return;
    }

    int maxLength = 1;
    int currentLength = 1;

    for (int i = 1; i < size; i++)
    {
        if (array[i] > array[i - 1])
        {
            currentLength++;
        }
        else
        {
            if (currentLength > maxLength)
            {
                maxLength = currentLength;
            }
            currentLength = 1;
        }
    }
    
    if (currentLength > maxLength)
    {
        maxLength = currentLength;
    }

    printf("Длина самого длинного непрерывного строго возрастающего фрагмента: %d\n", maxLength);
}


    
   

    
    
    
        

   
    
   
    
    
   
