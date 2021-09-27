#include <bits/stdc++.h>
using namespace std;

bool jump_search_iterative(int arr[], int n, int item) {
    int step = sqrt(n);
    int i = 0;
    while (i + step < n && arr[i + step] <= item)
        i += step;
    int j = i;
    while (j < min(i + step, n)) {
        if (arr[j] == item)
            return true;
        j += 1;
    }
    return false;
}

int main() {

    int n = 8;
    int arr[] = {10, 14, 19, 27, 33, 35, 42, 44};

    cout << "jump_search for 42: " << jump_search_iterative(arr, n, 42) << '\n';
    cout << "jump_search for 43: " << jump_search_iterative(arr, n, 43) << '\n';
    cout << "jump_search for 44: " << jump_search_iterative(arr, n, 44) << '\n';
    cout << "jump_search for 12: " << jump_search_iterative(arr, n, 12) << '\n';
    cout << "jump_search for 8: " << jump_search_iterative(arr, n, 8) << '\n';
    cout << "jump_search for 10: " << jump_search_iterative(arr, n, 10) << '\n';
    cout << "jump_search for 14: " << jump_search_iterative(arr, n, 14) << '\n';
    cout << "--------------------------\n";

}
/*
jump_search for 42: 1
jump_search for 43: 0
jump_search for 44: 1
jump_search for 12: 0
jump_search for 8: 0
jump_search for 10: 1
jump_search for 14: 1
--------------------------
*/