#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void selection_sort_recursive(int arr[], int n, int i=0) {
    if (i == n)
        return;
    int idx = i;
    for (int j = i ; j < n ; j++) {
        if (arr[idx] > arr[j])
            idx = j;
    }
    swap(arr[i], arr[idx]);
    selection_sort_recursive(arr, n, i+1);
}

void selection_sort_iterative(int arr[], int n) {
    for (int i = 0 ; i < n ; i++) {
        int idx = i;
        for (int j = i ; j < n ; j++) {
            if (arr[idx] > arr[j])
                idx = j;
        }
        swap(arr[i], arr[idx]);
    }
}

/*
array
35 33 42 10 14 19 27 44 

i = 0
10 33 42 35 14 19 27 44 

i = 1
10 14 42 35 33 19 27 44 

i = 2
10 14 19 35 33 42 27 44 

i = 3
10 14 19 27 33 42 35 44 

i = 4
10 14 19 27 33 42 35 44 

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
    cout << "selection_sort: \n";
    selection_sort_iterative(arr, n);
    print_array(arr, n);

}