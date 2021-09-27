#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int f, int m, int e) {
    int temp[e - f + 1];
    int inv_count = 0;	
    int i = 0, st1 = f, st2 = m + 1;
    while (st1 <= m && st2 <= e) {
        if (arr[st1] <= arr[st2]) {
            temp[i] = arr[st1];
            i = i + 1;
            st1 = st1 + 1;
        }
        else {
            inv_count += ((m+1) - st1);
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
    return inv_count;
}

int count_inversions_recursive(int arr[], int f, int e) {
    if (f >= e)
        return 0;
    int m = (f + e) / 2;
    int inv_count = 0;
    inv_count += count_inversions_recursive(arr, f, m);
    inv_count += count_inversions_recursive(arr, m + 1, e);
    inv_count += merge(arr, f, m, e);
    return inv_count;
}

int main() {

    int n = 8;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    
    cout << "count_inversions: \n";
    cout << count_inversions_recursive(arr, 0, n-1);

}