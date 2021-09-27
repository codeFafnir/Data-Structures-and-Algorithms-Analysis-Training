#include <bits/stdc++.h>
using namespace std;

bool linear_search_iterative(int arr[], int n, int item) {
    int i = 0;
    while (i < n) {
        if (arr[i] == item)
            return true;
        i += 1;
    }
    return false;
}

bool linear_search_recursive(int arr[], int n, int item, int i) {
    if (i == n)
        return false;
    if (arr[i] == item)
        return true;
    return linear_search_recursive(arr, n, item, i+1);
}

int main() {

    int n = 8;
    int arr[] = {10, 14, 19, 27, 33, 35, 42, 44};

    cout << "linear_search for 10: " << linear_search_iterative(arr, n, 10) << '\n';
    cout << "linear_search for 42: " << linear_search_iterative(arr, n, 42) << '\n';
    cout << "linear_search for 40: " << linear_search_iterative(arr, n, 40) << '\n';
    cout << "linear_search for 44: " << linear_search_iterative(arr, n, 44) << '\n';
    cout << "--------------------------\n";
    cout << "linear_search for 10: " << linear_search_recursive(arr, n, 10, 0) << '\n';
    cout << "linear_search for 42: " << linear_search_recursive(arr, n, 42, 0) << '\n';
    cout << "linear_search for 40: " << linear_search_recursive(arr, n, 40, 0) << '\n';
    cout << "linear_search for 44: " << linear_search_recursive(arr, n, 44, 0) << '\n';
    cout << "--------------------------\n";

}
/*
linear_search for 10: 1
linear_search for 42: 1
linear_search for 40: 0
linear_search for 44: 1
--------------------------
linear_search for 10: 1
linear_search for 42: 1
linear_search for 40: 0
linear_search for 44: 1
--------------------------
*/