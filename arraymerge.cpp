#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};
    int n = 10;

    cout << "Before Sorting: ";
    display(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting: ";
    display(arr, n);

    cout << "Reflection question:\n";
    cout << "1. What is the time complexity of Merge Sort?\n";
    cout << " O(nlogn)\n";
    cout << "2. Why does Merge Sort work well with linked lists?\n";
    cout << " Linkedlist is not a continuous data type so you can merge two sorted lists by simply updating pointers, which means you don't need to allocate a massive block of extra temporary memory for the merge step\n ";
    cout << " Is Merge Sort stable?\n";
    cout << " Yes\n";
    cout << "What extra memory does Merge Sort require?\n";
    cout << "For array: it require O(n) because it need a temp placeholder for the array\n";
    cout << " For LinkedList: it will require O(logn) because you mostly rearranging existing nodes\n";
        

    return 0;
}
