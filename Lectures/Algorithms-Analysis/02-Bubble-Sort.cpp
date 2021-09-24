#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void bubble_sort_recursive(int arr[], int n, int i=0) {
    if (i == n)
        return;
    for (int j = 0 ; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1])
            swap(arr[j], arr[j + 1]);
    }
    bubble_sort_recursive(arr, n, i+1);
}

void bubble_sort_iterative(int arr[], int n) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

/*
array
35 33 42 10 14 19 27 44 

i = 0
33 35 10 14 19 27 42 44 

i = 1
33 10 14 19 27 35 42 44 

i = 2
10 14 19 27 33 35 42 44 

i = 3
10 14 19 27 33 35 42 44 

i = 4
10 14 19 27 33 35 42 44 

i = 5
10 14 19 27 33 35 42 44 

i = 6
10 14 19 27 33 35 42 44 

i = 7
10 14 19 27 33 35 42 44 
*/

int main() {

    int n = 8;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    
    print_array(arr, n);
    cout << "bubble_sort: \n";
    bubble_sort_iterative(arr, n);
    print_array(arr, n);

}