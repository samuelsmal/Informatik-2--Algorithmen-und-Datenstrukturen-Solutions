#include <iostream>
#include <cstdlib>

#define LENGTH 10
class Sort
{
public:
  void insertionSort (int arr[], int length);
  void quickSort (int arr[], int left, int right);
private:
  int partition (int a[], int left, int right, int pivot); // had to add int pivot. how would i otherwise know which element to compare to? of course i could use the left or right element as a pivot.
  void exchange (int a[], int i, int j);
};

void
Sort::insertionSort (int arr[], int length)
{
    int swap, i = 1, j = 0;
	for (; i < length; i++) {
        swap = arr[i];
        for (j = i - 1; (j >= 0) && (arr[j] > swap); j--) {
            arr[j + 1] = arr[j];
        }
        arr[j+1] = swap;
    }
}

void
Sort::quickSort (int a[], int left, int right)
{
    srand(time(0));
	if (right - left > 1) {
        int pivot_pos = left + (rand()%(right - left)), l = left, r = right;
        
        // partition
        while (left < right) {
            while (a[right] > a[pivot_pos]) --right;
            while (a[left]  < a[pivot_pos]) ++left;
            std::swap(a[left], a[right]);
            if (a[right] == a[left]) --right;
        }
        
        quickSort(a, l, left - 1);
        quickSort(a, left + 1, r);
    }
}

int Sort::partition(int a[], int left, int right, int pivot_pos) {
    int pivot_value = a[pivot_pos];
    for (int i = left; i < right; i++) {
        if (a[i] <= pivot_value) {
            a[i] = pivot_value;
            a[pivot_pos] = a[i];
            pivot_pos = i;
        }
    }
    return pivot_pos;
}

int
main (int argc, char *const argv[])
{

  std::cout << "Enter the " << LENGTH << " elements of the array" << std::
    endl;
  int arr[LENGTH];
  for (int i = 0; i < LENGTH; i++)
    {
      std::cin >> arr[i];
    }
  Sort Object;
  // Each of the following should work
  // Object.insertionSort (arr, LENGTH);
  Object.quickSort (arr, 0, LENGTH-1);

  std::cout << "Sorted list:" << std::endl;
  for (int i = 0; i < LENGTH; i++)
    {
      std::cout << arr[i] << std::endl;
    }

  return 0;
}

