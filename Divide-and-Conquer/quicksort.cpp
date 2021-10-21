#include <iostream>

void swap(int *arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(int *arr, int ini, int fin)
{
  int pivot = arr[fin];
  int i = ini;
  for (int j = ini; j < fin; j++)
  {
    if (arr[j] <= pivot)
    {
      swap(arr, i, j);
      i++;
    }
  }
  swap(arr, i, fin);
  return i;
}

void quicksort(int *arr, int ini, int fin)
{
  if (ini < fin)
  {
    int piv = partition(arr, ini, fin);
    quicksort(arr, ini, piv - 1);
    quicksort(arr, piv + 1, fin);
  }
}

void printArray(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main()
{
  int arr[] = {0, 2, 5, 4, 6, 2, 3, 1, 85, 64, 4, 8, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, n);
  quicksort(arr, 0, n);
  printArray(arr, n);
}