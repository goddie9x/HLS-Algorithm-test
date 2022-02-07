#include <iostream>

int findIndexOfMinElementOfArray(int **array, int size);
int findIndexOfMaxElementOfArray(int **array, int size);
int sumTotalElementsExceptIndexOfArray(int **array, int index);
void printSumMaxAndSumMinOfFourElementsInAnArrayOfFiveElements(int **array, int size);
void printAllEvenElementsOfArray(int **array, int size);
void printAllOddElementsOfArray(int **array, int size);
void inputArray(int **array, int size);
void printArray(int **array, int size);

int main()
{
    const int arrayLength = 5;
    int *array = new int[arrayLength];

    inputArray(&array, arrayLength);
    printArray(&array, arrayLength);
    printSumMaxAndSumMinOfFourElementsInAnArrayOfFiveElements(&array, arrayLength);
    printAllEvenElementsOfArray(&array, arrayLength);
    printAllOddElementsOfArray(&array, arrayLength);
    delete[] array;
}

int findIndexOfMinElementOfArray(int **array, int size)
{
    int minElement = **array;
    int indexOfMinElement = 0;
    for (int i = 0; i < size; i++)
    {
        if (minElement > *(*array + sizeof(int) * i))
        {
            minElement = *(*array + sizeof(int) * i);
            indexOfMinElement = i;
        }
    }

    return indexOfMinElement;
}

int findIndexOfMaxElementOfArray(int **array, int size)
{
    int maxElement = **array;
    int indexOfMaxElement = 0;
    for (int i = 0; i < size; i++)
    {
        if (maxElement < *(*array + sizeof(int) * i))
        {
            maxElement = *(*array + sizeof(int) * i);
            indexOfMaxElement = i;
        }
    }

    return indexOfMaxElement;
}

int sumTotalElementsExceptIndexOfArray(int **array,int size, int index)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += (i != index) ? *(*array + sizeof(int) * i) : 0;
    }

    return sum;
}

void printAllEvenElementsOfArray(int **array, int size)
{
    std::cout << "All even elements of array: ";
    for (int i = 0; i < size; i++)
    {
        if (*(*array + sizeof(int) * i) % 2 == 0)
        {
            std::cout << *(*array + sizeof(int) * i) << " ";
        }
    }
    std::cout << std::endl;
}

void printAllOddElementsOfArray(int **array, int size)
{
    std::cout << "All odd elements of array: ";
    for (int i = 0; i < size; i++)
    {
        if (*(*array + sizeof(int) * i) % 2 != 0)
        {
            std::cout << *(*array + sizeof(int) * i) << " ";
        }
    }
    std::cout << std::endl;
}

void inputArray(int **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> *(*array + sizeof(int) * i);
    }
}

void printArray(int **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << *(*array + sizeof(int) * i) << " ";
    }
    std::cout << std::endl;
}

void printSumMaxAndSumMinOfFourElementsInAnArrayOfFiveElements(int **array, int size)
{
    int indexOfMinElement = findIndexOfMinElementOfArray(array, size);
    int indexOfMaxElement = findIndexOfMaxElementOfArray(array, size);
    int sumMin = sumTotalElementsExceptIndexOfArray(array, size, indexOfMaxElement);
    int sumMax = sumTotalElementsExceptIndexOfArray(array, size, indexOfMinElement);

    std::cout << "The minimum and maximum values that can be calculated by summing exactly four of the five integers are:" << std::endl;
    std::cout << sumMin << " " << sumMax << std::endl;
}