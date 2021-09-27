#include <bits/stdc++.h>
using namespace std;

bool binary_search_recursive(int arr[], int b, int e, int item) {
    if (b > e)
        return false;
    int m  = b + (e - b) / 2;
    if (arr[m] < item)
        return binary_search_recursive(arr, m + 1, e, item);
    else if (arr[m] > item)
        return binary_search_recursive(arr, b, m - 1, item);
    else
        return true;
}
bool binary_search_iterative(int arr[], int n, int item) {
    int b = 0, e = n - 1;
    while (b <= e) {
        int m  = b + (e - b) / 2;
        if (arr[m] < item)
            b = m + 1;
        else if (arr[m] > item)
            e = m - 1;
        else
            return true;
    }
    return false;
}
/*
binary_search for 42: 1
binary_search for 43: 0
binary_search for 44: 1
binary_search for 12: 0
binary_search for 10: 1
--------------------------
binary_search for 42: 1
binary_search for 43: 0
binary_search for 44: 1
binary_search for 12: 0
binary_search for 10: 1
--------------------------
*/

int lower_bound_recursive(int arr[], int b, int e, int item) {
    if (b >= e)
        return b;
    int m  = b + (e - b) / 2;
    if (arr[m] < item)
        return lower_bound_recursive(arr, m + 1, e, item);
    else
        return lower_bound_recursive(arr, b, m, item);
}
int lower_bound_iterative(int arr[], int n, int item) {
    int b = 0, e = n;
    while (b < e) {
        int m  = b + (e - b) / 2;
        if (arr[m] < item)
            b = m + 1;
        else
            e = m;
    }
    return b;
}
/*
lower_bound for  9: 0
lower_bound for 10: 0
lower_bound for 11: 1
lower_bound for 14: 1
lower_bound for 43: 7
lower_bound for 44: 7
lower_bound for 45: 8
--------------------------
lower_bound for  9: 0
lower_bound for 10: 0
lower_bound for 11: 1
lower_bound for 14: 1
lower_bound for 43: 7
lower_bound for 44: 7
lower_bound for 45: 8
--------------------------
*/

int upper_bound_recursive(int arr[], int b, int e, int item) {
    if (b >= e)
        return b;
    int m  = b + (e - b) / 2;
    if (arr[m] <= item)
        return upper_bound_recursive(arr, m + 1, e, item);
    else
        return upper_bound_recursive(arr, b, m, item);
}
int upper_bound_iterative(int arr[], int n, int item) {
    int b = 0, e = n;
    while (b < e) {
        int m  = b + (e - b) / 2;
        if (arr[m] <= item)
            b = m + 1;
        else
            e = m;
    }
    return b;
}
/*
upper_bound for  9: 0
upper_bound for 10: 1
upper_bound for 11: 1
upper_bound for 14: 2
upper_bound for 43: 7
upper_bound for 44: 8
upper_bound for 45: 8
--------------------------
upper_bound for  9: 0
upper_bound for 10: 1
upper_bound for 11: 1
upper_bound for 14: 2
upper_bound for 43: 7
upper_bound for 44: 8
upper_bound for 45: 8
--------------------------
*/

int main() {

    int n = 8;
    int arr[] = {10, 14, 19, 27, 33, 35, 42, 44};

    cout << "binary_search for 42: " << binary_search_iterative(arr, n, 42) << '\n';
    cout << "binary_search for 43: " << binary_search_iterative(arr, n, 43) << '\n';
    cout << "binary_search for 44: " << binary_search_iterative(arr, n, 44) << '\n';
    cout << "binary_search for 12: " << binary_search_iterative(arr, n, 12) << '\n';
    cout << "binary_search for 10: " << binary_search_iterative(arr, n, 10) << '\n';
    cout << "--------------------------\n";
    cout << "binary_search for 42: " << binary_search_recursive(arr, 0, n-1, 42) << '\n';
    cout << "binary_search for 43: " << binary_search_recursive(arr, 0, n-1, 43) << '\n';
    cout << "binary_search for 44: " << binary_search_recursive(arr, 0, n-1, 44) << '\n';
    cout << "binary_search for 12: " << binary_search_recursive(arr, 0, n-1, 12) << '\n';
    cout << "binary_search for 10: " << binary_search_recursive(arr, 0, n-1, 10) << '\n';
    cout << "--------------------------\n";

    cout << "lower_bound for  9: " << lower_bound_iterative(arr, n, 9) << '\n';
    cout << "lower_bound for 10: " << lower_bound_iterative(arr, n, 10) << '\n';
    cout << "lower_bound for 11: " << lower_bound_iterative(arr, n, 11) << '\n';
    cout << "lower_bound for 14: " << lower_bound_iterative(arr, n, 14) << '\n';
    cout << "lower_bound for 43: " << lower_bound_iterative(arr, n, 43) << '\n';
    cout << "lower_bound for 44: " << lower_bound_iterative(arr, n, 44) << '\n';
    cout << "lower_bound for 45: " << lower_bound_iterative(arr, n, 45) << '\n';
    cout << "--------------------------\n";
    cout << "lower_bound for  9: " << lower_bound_recursive(arr, 0, n, 9) << '\n';
    cout << "lower_bound for 10: " << lower_bound_recursive(arr, 0, n, 10) << '\n';
    cout << "lower_bound for 11: " << lower_bound_recursive(arr, 0, n, 11) << '\n';
    cout << "lower_bound for 14: " << lower_bound_recursive(arr, 0, n, 14) << '\n';
    cout << "lower_bound for 43: " << lower_bound_recursive(arr, 0, n, 43) << '\n';
    cout << "lower_bound for 44: " << lower_bound_recursive(arr, 0, n, 44) << '\n';
    cout << "lower_bound for 45: " << lower_bound_recursive(arr, 0, n, 45) << '\n';
    cout << "--------------------------\n";

    cout << "upper_bound for  9: " << upper_bound_iterative(arr, n, 9) << '\n';
    cout << "upper_bound for 10: " << upper_bound_iterative(arr, n, 10) << '\n';
    cout << "upper_bound for 11: " << upper_bound_iterative(arr, n, 11) << '\n';
    cout << "upper_bound for 14: " << upper_bound_iterative(arr, n, 14) << '\n';
    cout << "upper_bound for 43: " << upper_bound_iterative(arr, n, 43) << '\n';
    cout << "upper_bound for 44: " << upper_bound_iterative(arr, n, 44) << '\n';
    cout << "upper_bound for 45: " << upper_bound_iterative(arr, n, 45) << '\n';
    cout << "--------------------------\n";
    cout << "upper_bound for  9: " << upper_bound_recursive(arr, 0, n, 9) << '\n';
    cout << "upper_bound for 10: " << upper_bound_recursive(arr, 0, n, 10) << '\n';
    cout << "upper_bound for 11: " << upper_bound_recursive(arr, 0, n, 11) << '\n';
    cout << "upper_bound for 14: " << upper_bound_recursive(arr, 0, n, 14) << '\n';
    cout << "upper_bound for 43: " << upper_bound_recursive(arr, 0, n, 43) << '\n';
    cout << "upper_bound for 44: " << upper_bound_recursive(arr, 0, n, 44) << '\n';
    cout << "upper_bound for 45: " << upper_bound_recursive(arr, 0, n, 45) << '\n';
    cout << "--------------------------\n";

}