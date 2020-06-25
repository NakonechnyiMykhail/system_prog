// hw4.cpp :	BubbleSort.
// author:      Nakonechnyi Mikhail
// date:        25.06.20
// version:     1.0
//
// description of homework:
// Есть массив -> int arr[] = { 6,5,3,1,8,7,2,4 };
// Нужно его отсортировать методом пузырька так, чтобы получился :
// 1 2 3 4 5 6 7 8
// Вот как выглядит метод пузырьковой сортировки :
// https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif?uselang=ru

#include <iostream>

void printArray(int array[], int arraySize);
void bubbleSort(int array[], int arraySize);
void bubbleSort2(int array[], int arraySize);
void swap(int* a, int* b);

int main()
{
	int arr[] = { 6,5,3,1,8,7,2,4 };
	int arr2[] = { 6,5,3,1,8,7,2,4 };
	const int arrSize = sizeof(arr)/sizeof(int);

	bubbleSort(arr, arrSize);
	std::cout << "-------------------" << std::endl;
	bubbleSort2(arr2, arrSize);
}

void bubbleSort(int array[], int arraySize)
{
	printArray(array, arraySize);
	int tmp{ 0 };
	for (size_t j = 0; j < arraySize; j++)
	{
		for (size_t i = 1; i < arraySize; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
			}
			//else
			//{
			//	continue;
			//}
		}
	}
	printArray(array, arraySize);
}

void printArray(int array[], int arraySize)
{
	for (size_t i = 0; i < arraySize; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void bubbleSort2(int array[], int arraySize)
{
	printArray(array, arraySize);
	bool swapped;
	for (int i = 0; i < arraySize - 1; i++) 
	{
		swapped = false;
		for (int j = 0; j < arraySize - i - 1; j++) 
		{
			if (array[j] > array[j + 1]) 
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
	printArray(array, arraySize);
}

void swap(int* a, int* b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}