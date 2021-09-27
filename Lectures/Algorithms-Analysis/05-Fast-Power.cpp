#include <bits/stdc++.h>
using namespace std;

float fast_power_recursive(float b, int e) {
    if (e == 0)
        return 1.0;
    if (e % 2 == 1)
        return b * fast_power_recursive(b * b, e / 2);
    else
        return fast_power_recursive(b * b, e / 2);
}
/*
fast_power 2 ^ 5: 32
fast_power 2 ^ 8: 256
fast_power 3 ^ 5: 243
fast_power 3 ^ 8: 6561
fast_power 4 ^ 5: 1024
fast_power 4 ^ 8: 65536
-------------------------
*/

float fast_power_iterative(float b, int e) {
    float res = 1.0;
    while (e > 0) {
        if (e % 2 == 1)
            res = res * b;
        b = b * b;
        e = e / 2;
    }
    return res;
}
/*
fast_power 2 ^ 5: 32
fast_power 2 ^ 8: 256
fast_power 3 ^ 5: 243
fast_power 3 ^ 8: 6561
fast_power 4 ^ 5: 1024
fast_power 4 ^ 8: 65536
-------------------------
*/

int main() {

    cout << "fast_power 2 ^ 5: " << fast_power_recursive(2, 5) << '\n';
    cout << "fast_power 2 ^ 8: " << fast_power_recursive(2, 8) << '\n';
    cout << "fast_power 3 ^ 5: " << fast_power_recursive(3, 5) << '\n';
    cout << "fast_power 3 ^ 8: " << fast_power_recursive(3, 8) << '\n';
    cout << "fast_power 4 ^ 5: " << fast_power_recursive(4, 5) << '\n';
    cout << "fast_power 4 ^ 8: " << fast_power_recursive(4, 8) << '\n';
    cout << "-------------------------\n";
    cout << "fast_power 2 ^ 5: " << fast_power_iterative(2, 5) << '\n';
    cout << "fast_power 2 ^ 8: " << fast_power_iterative(2, 8) << '\n';
    cout << "fast_power 3 ^ 5: " << fast_power_iterative(3, 5) << '\n';
    cout << "fast_power 3 ^ 8: " << fast_power_iterative(3, 8) << '\n';
    cout << "fast_power 4 ^ 5: " << fast_power_iterative(4, 5) << '\n';
    cout << "fast_power 4 ^ 8: " << fast_power_iterative(4, 8) << '\n';
    cout << "-------------------------\n";
    
}