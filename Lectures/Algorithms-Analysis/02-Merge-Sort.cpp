#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void merge(int arr[], int f, int m, int e) {
    int temp[e - f + 1], i=0;
    int st1 = f, st2 = m + 1;
    while (st1 <= m && st2 <= e) {
        if (arr[st1] < arr[st2]) {
            temp[i] = arr[st1];
            i = i + 1;
            st1 = st1 + 1;
        }
        else {
            temp[i] = arr[st2];
            i = i + 1;
            st2 = st2 + 1;
        }
    }
    while (st1 <= m) {
        temp[i] = arr[st1];
        i = i + 1;
        st1 = st1 + 1;
    }
    while (st2 <= e) {
        temp[i] = arr[st2];
        i = i + 1;
        st2 = st2 + 1;
    }
    for (int j = f; j <= e; j++)
        arr[j] = temp[j - f];
}

void merge_sort_recursive(int arr[], int f, int e) {
    if (f >= e)
        return;
    int m = (f + e) / 2;
    merge_sort_recursive(arr, f, m);
    merge_sort_recursive(arr, m + 1, e);
    merge(arr, f, m, e);
}

void merge_sort_iterative(int arr[], int n) {
    int sub_size = 1;
    while (sub_size < n) {
        int start_idx = 0;
        while (start_idx < n-1) {
            int mid = min(start_idx + sub_size, n) - 1;
            int end_idx = min(start_idx + 2*sub_size, n) - 1;
            merge(arr, start_idx, mid, end_idx);
            start_idx += 2*sub_size;
        }
        sub_size *= 2;
    }
}

/*
array
35 33 42 10 14 19 27 44 35 33 42 10 14 19 27 44 

f = 0, e = 1, m = 0
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
33 35 42 10 14 19 27 44 35 33 42 10 14 19 27 44 

f = 2, e = 3, m = 2
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
33 35 10 42 14 19 27 44 35 33 42 10 14 19 27 44 

f = 0, e = 3, m = 1
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 33 35 42 14 19 27 44 35 33 42 10 14 19 27 44 

f = 4, e = 5, m = 4
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 33 35 42 14 19 27 44 35 33 42 10 14 19 27 44 

f = 6, e = 7, m = 6
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 33 35 42 14 19 27 44 35 33 42 10 14 19 27 44 

f = 4, e = 7, m = 5
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 33 35 42 14 19 27 44 35 33 42 10 14 19 27 44 

f = 0, e = 7, m = 3
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 14 19 27 33 35 42 44 35 33 42 10 14 19 27 44 

f = 8, e = 9, m = 8
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 14 19 27 33 35 42 44 33 35 42 10 14 19 27 44 

f = 10, e = 11, m = 10
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 14 19 27 33 35 42 44 33 35 10 42 14 19 27 44 

f = 8, e = 11, m = 9
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 14 19 27 33 35 42 44 10 33 35 42 14 19 27 44 

f = 12, e = 13, m = 12
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 14 19 27 33 35 42 44 10 33 35 42 14 19 27 44 

f = 14, e = 15, m = 14
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 14 19 27 33 35 42 44 10 33 35 42 14 19 27 44 

f = 12, e = 15, m = 13
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 14 19 27 33 35 42 44 10 33 35 42 14 19 27 44 

f = 8, e = 15, m = 11
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 14 19 27 33 35 42 44 10 14 19 27 33 35 42 44 

f = 0, e = 15, m = 7
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
10 10 14 14 19 19 27 27 33 33 35 35 42 42 44 44 
*/

int main() {

    int n = 16;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 35, 33, 42, 10, 14, 19, 27, 44};
    
    print_array(arr, n);
    cout << "merge_sort: \n";
    merge_sort_recursive(arr, 0, n-1);
    print_array(arr, n);

}