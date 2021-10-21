#include <iostream>

void swap(int *array, int i, int j)
{
  int aux = array[i];
  array[i] = array[j];
  array[j] = aux;
}

void wigglesort(int *array, int length)
{
  bool shouldBeBigger = false;

  for (int i = 0; i < length - 1; i++)
  {
    if (shouldBeBigger)
    {
      if (array[i] < array[i + 1])
      {
        swap(array, i, i + 1);
      }
    }
    else
    {
      if (array[i] > array[i + 1])
      {
        swap(array, i, i + 1);
      }
    }

    shouldBeBigger = !shouldBeBigger;
  }
}

void print(int *arr, int length)
{
  for (int i = 0; i < length; i++)
  {
    if (i != length - 1)
      std::cout << arr[i] << " - ";
    else
      std::cout << arr[i];
  }
  std::cout << std::endl;
}

int main()
{
  int arr[] = {15, 1, 41, 20, 100, 50, 120};
  int len = sizeof(arr) / sizeof(arr[0]);

  print(arr, len);

  wigglesort(arr, len);

  print(arr, len);

  int arr2[] = {15, 1, 41, 20, 100, 50, 120, 100, 4, 5534, 432, 432, 543, 423, 14, 454};
  int len2 = sizeof(arr2) / sizeof(arr2[0]);

  print(arr2, len2);

  wigglesort(arr2, len2);

  print(arr2, len2);
}
