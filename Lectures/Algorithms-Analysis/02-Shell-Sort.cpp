#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void shell_sort_recursive(int arr[], int n, int gap) {
    if (gap == 0)
        return;
    for (int i = gap ; i < n ; i++) {
        int j = i, temp = arr[i];
        while (j - gap >= 0 && temp < arr[j - gap]) {
            arr[j] = arr[j - gap];
            j -= gap;
        }
        arr[j] = temp;
    }
    shell_sort_recursive(arr, n, gap/2);
}

void shell_sort_iterative(int arr[], int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap ; i < n ; i++) {
            int j = i, temp = arr[i];
            while (j - gap >= 0 && temp < arr[j - gap]) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

/*
array
35 33 42 10 14 19 27 44 35 33 42 10 14 19 27 44 

gap = 8
35 33 42 10 14 19 27 44 35 33 42 10 14 19 27 44 

gap = 4
14 19 27 10 14 19 27 10 35 33 42 44 35 33 42 44 

gap = 2
14 10 14 10 27 19 27 19 35 33 35 33 42 44 42 44 

gap = 1
10 10 14 14 19 19 27 27 33 33 35 35 42 42 44 44 
*/

int main() {

    int n = 16;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 35, 33, 42, 10, 14, 19, 27, 44};
    
    print_array(arr, n);
    cout << "shell_sort: \n";
    shell_sort_iterative(arr, n, n/2);
    print_array(arr, n);

}