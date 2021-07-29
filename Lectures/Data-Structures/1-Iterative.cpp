#include <bits/stdc++.h>
using namespace std;

int calc_sum(int n) {
    int res = 0;
    while (n > 0) {
        res += n;
        n -= 1;
    }
    return res;
}
float power(float b, int e) {
    int res = 1;
    while (e > 0) {
        res *= b;
        e -= 1;
    }
    return res;
}
int factorial(int n) {
    int res = 1;
    while (n > 0) {
        res *= n;
        n -= 1;
    }
    return res;
}
void fib(int x, int y, int n) {
    while (n > 0) {
        cout << x + y << ' ';
        int z = x;
        x = y;
        y = y + z;
        n -= 1;
    }
}
bool is_prime(int i, int n) {
    while (i < n) {
        if (n % i == 0)
            return false;
        i += 1;
    }
    return true;
}

const int n = 10;
int arr[n] = {7, 4, -5, 2, -10, 3, -12, -17, 6, 13};

void print_evens(int i, int n) {
    while (i < n) {
        if (arr[i] % 2 == 0)
            cout << arr[i] << ' ';
        i += 1;
    }
}
void print_odds(int i, int n) {
    while (i < n) {
        if (arr[i] % 2 != 0)
            cout << arr[i] << ' ';
        i += 1;
    }
}
void print_array_reverse(int i) {
    while (i >= 0) {
        cout << arr[i] << ' ';
        i -= 1;
    }
}
void print_array(int i) {
    while (i < n) {
        cout << arr[i] << ' ';
        i += 1;
    }
}
void reverse_array(int i, int j) {
    while (i < j) {
        swap(arr[i], arr[j]);
        i += 1;
        j -= 1;
    }
}
void print_positive(int i, int n) {
    while (i < n) {
        if (arr[i] > 0)
            cout << arr[i] << ' ';
        i += 1;
    }
}
void print_negative(int i, int n) {
    while (i < n) {
        if (arr[i] < 0)
            cout << arr[i] << ' ';
        i += 1;
    }
}
int count_positive(int i, int n) {
    int res = 0;
    while (i < n) {
        res += (arr[i] > 0);
        i += 1;
    }
    return res;
}
int count_negative(int i, int n) {
    int res = 0;
    while (i < n) {
        res += (arr[i] < 0);
        i += 1;
    }
    return res;
}
int count_even(int i, int n) {
    int res = 0;
    while (i < n) {
        res += (arr[i] % 2 == 0);
        i += 1;
    }
    return res;
}
int count_odd(int i, int n) {
    int res = 0;
    while (i < n) {
        res += (arr[i] % 2 != 0);
        i += 1;
    }
    return res;
}
int find_max_array(int i, int n) {
    int res = -2e9;
    while (i < n) {
        res = max(res, arr[i]);
        i += 1;
    }
    return res;
}
int find_min_array(int i, int n) {
    int res = 2e9;
    while (i < n) {
        res = min(res, arr[i]);
        i += 1;
    }
    return res;
}
bool find_item_array(int i, int n, int k) {
    while (i < n) {
        if (arr[i] == k)
            return true;
        i += 1;
    }
    return false;
}

string str = "abCdeFghIjkL";

void print_str(int i) {
    while (i < str.size()) {
        cout << str[i] << ' ';
        i += 1;
    }
}
void print_str_reverse(int i) {
    while (i >= 0) {
        cout << str[i] << ' ';
        i -= 1;
    }
}
void reverse_str(int i, int j) {
    while (i < j) {
        swap(str[i], str[j]);
        i += 1;
        j -= 1;
    }
}
void print_smalls(int i) {
    while (i < str.size()) {
        if ('a' <= str[i] && str[i] <= 'z')
            cout << str[i] << ' ';
        i += 1;
    }
}
void print_capitals(int i) {
    while (i < str.size()) {
        if ('A' <= str[i] && str[i] <= 'Z')
            cout << str[i] << ' ';
        i += 1;
    }
}
int count_smalls(int i) {
    int res = 0;
    while (i < str.size()) {
        if ('a' <= str[i] && str[i] <= 'z')
            res += 1;
        i += 1;
    }
    return res;
}
int count_capitals(int i) {
    int res = 0;
    while (i < str.size()) {
        if ('A' <= str[i] && str[i] <= 'Z')
            res += 1;
        i += 1;
    }
    return res;
}
char find_max_str(int i) {
    char res = str[n-1];
    while (i < n-1) {
        res = max(res, str[i]);
        i += 1;
    }
    return res;
}
char find_min_str(int i) {
    char res = str[n-1];
    while (i < n-1) {
        res = min(res, str[i]);
        i += 1;
    }
    return res;
}
bool find_item_string(int i, char k) {
    while (i < n) {
        if (str[i] == k)
            return true;
        i += 1;
    }
    return false;
}

int main() {

	// Functionality Testing 
	
    cout << "sum 1 to 4  : " << calc_sum(4) << '\n';
    cout << "power 2^10  : " << power(2, 10) << '\n';
    cout << "factorial 6 : " << factorial(6) << '\n';
    cout << "fibonacci 6 : ";
    fib(0, 1, 6);
    cout << '\n';
    cout << "15 is prime : " << is_prime(2, 15) << '\n';
    cout << "17 is prime : " << is_prime(2, 17) << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	sum 1 to 4  : 10
	power 2^10  : 1024
	factorial 6 : 720
	fibonacci 6 : 1 2 3 5 8 13 
	15 is prime : 0
	17 is prime : 1
	----------------------------------------------------
	*/

    cout << "array items : \n";
    print_array(0);
    cout << '\n';
    print_array_reverse(n-1);
    cout << '\n';
    cout << "array reversing ... \n";
    reverse_array(0, n-1);
    cout << "array items : \n";
    print_array(0);
    cout << '\n';
    print_array_reverse(n-1);
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	array items : 
	7 4 -5 2 -10 3 -12 -17 6 13 
	13 6 -17 -12 3 -10 2 -5 4 7 
	array reversing ... 
	array items : 
	13 6 -17 -12 3 -10 2 -5 4 7 
	7 4 -5 2 -10 3 -12 -17 6 13 
	----------------------------------------------------
	*/
	
    cout << "count evens : " << count_even(0, n) << '\n';
    cout << "count odds  : " << count_odd(0, n) << '\n';
    cout << "array even items : ";
    print_evens(0, n);
    cout << '\n';
    cout << "array odd items  : ";
    print_odds(0, n);
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	count evens : 5
	count odds  : 5
	array even items : 6 -12 -10 2 4 
	array odd items  : 13 -17 3 -5 7 
	----------------------------------------------------
	*/

    cout << "count positive : " << count_positive(0, n) << '\n';
    cout << "count negative : " << count_negative(0, n) << '\n';
    cout << "array positive items : ";
    print_positive(0, n);
    cout << '\n';
    cout << "array negative items : ";
    print_negative(0, n);
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	count positive : 6
	count negative : 4
	array positive items : 13 6 3 2 4 7 
	array negative items : -17 -12 -10 -5 
	----------------------------------------------------
	*/
	
    cout << "find max array : " << find_max_array(0, n) << '\n';
    cout << "find min array : " << find_min_array(0, n) << '\n';
    cout << "find 4 in array  : " << find_item_array(0, n, 4) << '\n';
    cout << "find 5 in array  : " << find_item_array(0, n, 5) << '\n';
    cout << "find -4 in array : " << find_item_array(0, n, -4) << '\n';
    cout << "find -5 in array : " << find_item_array(0, n, -5) << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	find max array : 13
	find min array : -17
	find 4 in array  : 1
	find 5 in array  : 0
	find -4 in array : 0
	find -5 in array : 1
	----------------------------------------------------
	*/

    cout << "string items : \n";
    print_str(0);
    cout << '\n';
    print_str_reverse(n-1);
    cout << '\n';
    cout << "string reversing ... \n";
    reverse_str(0, n-1);
    cout << "string items : \n";
    print_str(0);
    cout << '\n';
    print_str_reverse(n-1);
    cout << '\n';
    cout << "----------------------------------------------------\n";
	
	/* Expected Output:
	string items : 
	a b C d e F g h I j k L 
	j I h g F e d C b a 
	string reversing ... 
	string items : 
	j I h g F e d C b a k L 
	a b C d e F g h I j 
	----------------------------------------------------
	*/
	
    cout << "count smalls   : " << count_smalls(0) << '\n';
    cout << "count capitals : " << count_capitals(0) << '\n';
    cout << "string small items   : ";
    print_smalls(0);
    cout << '\n';
    cout << "string capital items : ";
    print_capitals(0);
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	count smalls   : 8
	count capitals : 4
	string small items   : j h g e d b a k 
	string capital items : I F C L 
	----------------------------------------------------
	*/
	
    cout << "find max string : "  << find_max_str(0) << '\n';
    cout << "find max string : "  << find_min_str(0) << '\n';
    cout << "find a in string : " << find_item_string(0, 'a') << '\n';
    cout << "find f in string : " << find_item_string(0, 'f') << '\n';
    cout << "find A in string : " << find_item_string(0, 'A') << '\n';
    cout << "find F in string : " << find_item_string(0, 'F') << '\n';
    cout << "----------------------------------------------------\n";
	
	/* Expected Output:
	find max string : j
	find max string : C
	find a in string : 1
	find f in string : 0
	find A in string : 0
	find F in string : 1
	----------------------------------------------------
	*/

}

