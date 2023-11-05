#include <iostream>
using namespace std;


int sequentialSearch(int* arr, int size, int value) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int* arr, int size, int value) {
    int f_index = 0;
    int l_index = size - 1;
    while(f_index <= l_index) {
        int position = (f_index + l_index) / 2;
        if(arr[position] == value) {
            return position;
        } else if (arr[position] < value) {
            f_index = position + 1;
        } else {
            l_index = position - 1;
        }
    }
    return -1;
}

int binarySearchRecursion(int* arr, int f_index, int l_index, int value) {
    int position = (f_index + l_index) / 2;
    if(arr[position] == value) {
        return position;
    } else if (arr[position] < value) {
        binarySearchRecursion(arr, position + 1, l_index, value);
    } else {
        binarySearchRecursion(arr, f_index, position - 1, value);
    }
}

void bubbleSort(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    ////////////Bubble Sort///////////////////
    int arr1[5] = {9999, 0, -10, 1000, 10};
    bubbleSort(arr1, 5);
    //////////Searching////////
    int size = 10000;
    int* arr = new int[size];
    for(int j = 0; j < size; j++) {
        arr[j] = j;
    }
    cout << sequentialSearch(arr, size, 500) << endl;
    cout << binarySearch(arr, size, 150) <<endl;
    cout << binarySearchRecursion(arr, 0 , size, 888) << endl;

    return 0;
}