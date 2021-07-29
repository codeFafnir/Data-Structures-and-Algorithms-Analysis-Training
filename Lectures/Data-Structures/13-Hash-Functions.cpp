#include <bits/stdc++.h>
using namespace std;

int table_size = 1e5+3;

// This function calculates the hash value of the given key with type int
int hash_function_int(int x) {
    return x % table_size;
}
// This function calculates the hash value of the given key with type int
int hash_function_int_complex(int x) {
    return (37LL * (x % table_size)) % table_size;
}
// This function calculates the hash value of the given key with type long long
int hash_function_long(long long x) {
    return x % table_size;
}
// This function calculates the hash value of the given key with type long long
int hash_function_long_complex(long long x) {
    return (37LL * (x % table_size)) % table_size;
}
// This function calculates the hash value of the given key with type char
int hash_function_char(char x) {
    return int(x) % table_size;
}
// This function calculates the hash value of the given key with type char
int hash_function_char_complex(char x) {
    return (37LL * int(x)) % table_size;
}
// This function calculates the hash value of the given key with type string
int hash_function_str(string x) {
    int res = 0;
    for (int i = 0 ; i < x.size() ; i++)
        res = (res + x[i]) % table_size;
    return res;
}
// This function calculates the hash value of the given key with type string
int hash_function_str_complex(string x) {
    int res = 0;
    for (int i = 0 ; i < x.size() ; i++)
        res = (res + 37LL * x[i]) % table_size;
    return res;
}

int main() {
	
	// Functionality Testing 
	
    cout << "Table size: " << table_size << '\n';

	/* Expected Output:
	Table size: 100003
	*/

    cout << "key " << int(1e9+6);
    cout << " has hash value " << hash_function_int(1e9+6)                << '\n';
    cout << "key " << int(1e9+6);
    cout << " has hash value " << hash_function_int_complex(1e9+6)        << '\n';
    cout << "key " << long(1LL<<61);
    cout << " has hash value " << hash_function_long(1LL<<61)             << '\n';
    cout << "key " << long(1LL<<61);
    cout << " has hash value " << hash_function_long_complex(1LL<<61)     << '\n';

	/* Expected Output:
	key 1000000006 has hash value 70009
	key 1000000006 has hash value 90258
	key 2305843009213693952 has hash value 13994
	key 2305843009213693952 has hash value 17763
	*/

    cout << "key " << 'R';
    cout << " has hash value " << hash_function_char('R')                 << '\n';
    cout << "key " << 'R';
    cout << " has hash value " << hash_function_char_complex('R')         << '\n';
    cout << "key " << "hashtables";
    cout << " has hash value " << hash_function_str("hashtables")         << '\n';
    cout << "key " << "hashtables";
    cout << " has hash value " << hash_function_str_complex("hashtables") << '\n';

	/* Expected Output:
	key R has hash value 114
	key R has hash value 4218
	key hashtables has hash value 1055
	key hashtables has hash value 39035
	*/

}

