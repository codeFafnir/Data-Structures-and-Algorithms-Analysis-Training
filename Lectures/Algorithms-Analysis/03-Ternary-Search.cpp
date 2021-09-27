#include <bits/stdc++.h>
using namespace std;

bool ternary_search_iterative(int arr[], int n, int item) { 
    int b = 0, e = n - 1;
    while (b <= e) {
        int m1 = b + (e - b) / 3;
        int m2 = e - (e - b) / 3;
        if (arr[m1] == item || arr[m2] == item)
            return true;
        else if (item < arr[m1])
            e = m1 - 1;
        else if (item > arr[m2])
            b = m2 + 1;
        else {
            b = m1 + 1;
            e = m2 - 1;
        }
    }
    return false;
}

bool ternary_search_recursive(int arr[], int b, int e, int item) {
    if (e < b)
        return false;
    int mid1 = b + (e - b) / 3;
    int mid2 = e - (e - b) / 3;
    if (arr[mid1] == item || arr[mid2] == item)
        return true;
    if (item < arr[mid1])
        return ternary_search_recursive(arr, b, mid1 - 1, item);
    else if (item > arr[mid2])
        return ternary_search_recursive(arr, mid2 + 1, e, item);
    else
        return ternary_search_recursive(arr, mid1 + 1, mid2 - 1, item);
}

int main() {

    int n = 8;
    int arr[] = {10, 14, 19, 27, 33, 35, 42, 44};

    cout << "ternary_search for 42: " << ternary_search_iterative(arr, n, 42) << '\n';
    cout << "ternary_search for 43: " << ternary_search_iterative(arr, n, 43) << '\n';
    cout << "ternary_search for 44: " << ternary_search_iterative(arr, n, 44) << '\n';
    cout << "ternary_search for 12: " << ternary_search_iterative(arr, n, 12) << '\n';
    cout << "ternary_search for 10: " << ternary_search_iterative(arr, n, 10) << '\n';
    cout << "--------------------------\n";
    cout << "ternary_search for 42: " << ternary_search_recursive(arr, 0, n-1, 42) << '\n';
    cout << "ternary_search for 43: " << ternary_search_recursive(arr, 0, n-1, 43) << '\n';
    cout << "ternary_search for 44: " << ternary_search_recursive(arr, 0, n-1, 44) << '\n';
    cout << "ternary_search for 12: " << ternary_search_recursive(arr, 0, n-1, 12) << '\n';
    cout << "ternary_search for 10: " << ternary_search_recursive(arr, 0, n-1, 10) << '\n';
    cout << "--------------------------\n";

}
/*
ternary_search for 42: 1
ternary_search for 43: 0
ternary_search for 44: 1
ternary_search for 12: 0
ternary_search for 10: 1
--------------------------
ternary_search for 42: 1
ternary_search for 43: 0
ternary_search for 44: 1
ternary_search for 12: 0
ternary_search for 10: 1
--------------------------
*/
