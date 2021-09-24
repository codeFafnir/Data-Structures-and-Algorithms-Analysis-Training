#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void insertion_sort_recursive(int arr[], int n, int i=0) {
    if (i == n)
        return;
    int j = i;
    int temp = arr[i];
    while (j > 0 && arr[j - 1] > temp) {
        arr[j] = arr[j - 1];
        j = j - 1;
    }
    arr[j] = temp;
    insertion_sort_recursive(arr, n, i+1);
}

void insertion_sort_iterative(int arr[], int n) {
    for (int i = 0 ; i < n ; i++) {
        int j = i;
        int temp = arr[i];
        while (j > 0 && arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = temp;
    }
}

/*
array
35 33 42 10 14 19 27 44 

i = 0
35 33 42 10 14 19 27 44 

i = 1
33 35 42 10 14 19 27 44 

i = 2
33 35 42 10 14 19 27 44 

i = 3
10 33 35 42 14 19 27 44 

i = 4
10 14 33 35 42 19 27 44 

i = 5
10 14 19 33 35 42 27 44 

i = 6
10 14 19 27 33 35 42 44 

i = 7
10 14 19 27 33 35 42 44 
*/

int main() {

    int n = 8;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    
    print_array(arr, n);
    cout << "insertion_sort: \n";
    insertion_sort_iterative(arr, n);
    print_array(arr, n);

}
