#include <bits/stdc++.h>
using namespace std;

int make_equal_length(string &str1, string &str2) {
    while (str1.size() < str2.size())
        str1 = '0' + str1;
    while (str2.size() < str1.size())
        str2 = '0' + str2;
    return str1.size();
}

string add_bit_strings(string x, string y) {
    string result = "";
    int n = make_equal_length(x, y);
    int carry = 0;
    for (int i = n-1 ; i >= 0 ; i--) {
        int a = x[i] - '0';
        int b = y[i] - '0';
        int sum = (a ^ b ^ carry)+'0';
        result = (char)sum + result;
        carry = (a&b) | (b&carry) | (a&carry);
    }
    if (carry) {
        result = '1' + result;
    }
    return result;
}

int multiply_single_bit(string a, string b) {
    return (a[0] - '0') * (b[0] - '0');
}

long int karatsuba_multiply(string X, string Y) {
    int n = make_equal_length(X, Y);
    if (n == 0)
        return 0;
    if (n == 1)
        return multiply_single_bit(X, Y);

    int fh = n/2;
    int sh = (n-fh);
    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);
 
    long int P1 = karatsuba_multiply(Xl, Yl);
    long int P2 = karatsuba_multiply(Xr, Yr);
    long int P3 = karatsuba_multiply(add_bit_strings(Xl, Xr), 
                                     add_bit_strings(Yl, Yr));

    return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2;
}
 
int main() {
    cout << karatsuba_multiply("1100", "1010") << '\n';
    cout << karatsuba_multiply("110", "1010") << '\n';
    cout << karatsuba_multiply("11", "1010") << '\n';
    cout << karatsuba_multiply("1", "1010") << '\n';
    cout << karatsuba_multiply("0", "1010") << '\n';
    cout << karatsuba_multiply("111", "111") << '\n';
    cout << karatsuba_multiply("11", "11") << '\n';
}
