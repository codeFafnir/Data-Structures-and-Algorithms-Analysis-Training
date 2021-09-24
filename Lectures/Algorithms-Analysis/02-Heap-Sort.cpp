#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void heapify(int arr[], int n, int i) {
    int j = -1;
    while (i != j) {
        j = i;
        int left_idx  = 2 * i + 1;
        int right_idx = 2 * i + 2;
        if (left_idx < n && arr[left_idx] > arr[i])
            i = left_idx  ;
        if (right_idx < n && arr[right_idx] > arr[i])
            i = right_idx;
        swap(arr[i], arr[j]);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 ; i >= 0 ; i--)
        heapify(arr, n, i);
    for (int i = n - 1 ; i >= 0 ; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

/*
array
35 33 42 10 14 19 27 44 35 33 42 10 14 19 27 44 

heapify
44 44 42 35 42 19 27 33 35 33 14 10 14 19 27 10 

i = 15
44 42 42 35 33 19 27 33 35 10 14 10 14 19 27 44 

i = 14
42 35 42 35 33 19 27 33 27 10 14 10 14 19 44 44 

i = 13
42 35 27 35 33 19 19 33 27 10 14 10 14 42 44 44 

i = 12
35 35 27 33 33 19 19 14 27 10 14 10 42 42 44 44 

i = 11
35 33 27 27 33 19 19 14 10 10 14 35 42 42 44 44 

i = 10
33 33 27 27 14 19 19 14 10 10 35 35 42 42 44 44 

i = 9
33 27 27 14 14 19 19 10 10 33 35 35 42 42 44 44 

i = 8
27 14 27 10 14 19 19 10 33 33 35 35 42 42 44 44 

i = 7
27 14 19 10 14 10 19 27 33 33 35 35 42 42 44 44 

i = 6
19 14 19 10 14 10 27 27 33 33 35 35 42 42 44 44 

i = 5
19 14 10 10 14 19 27 27 33 33 35 35 42 42 44 44 

i = 4
14 14 10 10 19 19 27 27 33 33 35 35 42 42 44 44 

i = 3
14 10 10 14 19 19 27 27 33 33 35 35 42 42 44 44 

i = 2
10 10 14 14 19 19 27 27 33 33 35 35 42 42 44 44 

i = 1
10 10 14 14 19 19 27 27 33 33 35 35 42 42 44 44 

i = 0
10 10 14 14 19 19 27 27 33 33 35 35 42 42 44 44 
*/

int main() {

    int n = 16;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 35, 33, 42, 10, 14, 19, 27, 44};
    
    print_array(arr, n);
    cout << "heap_sort: \n";
    heap_sort(arr, n);
    print_array(arr, n);

}
