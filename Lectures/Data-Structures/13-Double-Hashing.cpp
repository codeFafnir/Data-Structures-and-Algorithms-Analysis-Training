#include <bits/stdc++.h>
using namespace std;

// Initialize a hash table with static length
const int hash_table_size = 1e3+13;
const int hash_table_prime = 1e3+9;
string arr[hash_table_size];

// This function calculates the hash value of the given key with type string
int hash_function_str_complex(string key) {
    int res = 0;
    for (int i = 0 ; i < key.size() ; i++)
        res = (res + 37LL * key[i]) % hash_table_size;
    return res;
}

// This function calculates the hash value of the given hash value
int hash_function_secondary(int hash_idx) {
    return hash_table_prime - hash_idx % hash_table_prime;
}

// This function searches for an element in the hash table
bool search_item(string key) {
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // calculate the second hash value of the given hash value
    int step = hash_function_secondary(idx);
    // loop till find the given key
    int i = 0;
    while (arr[(idx + i*step) % hash_table_size] != key && 
		   arr[(idx + i*step) % hash_table_size] != "")
        i++;
    // return whether the current position in the hash table contain the given key
    return arr[(idx + i*step) % hash_table_size] == key;
}

// This function inserts an element in the hash table
void insert_item(string key) {
	// check if the given key exists or not 
    if (search_item(key) == true)
        return;
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // calculate the second hash value of the given hash value
    int step = hash_function_secondary(idx);
    // loop till find an empty position
    int i = 0;
    while (arr[(idx + i*step) % hash_table_size] != "" && 
		   arr[(idx + i*step) % hash_table_size] != "#")
        i++;
    // insert the new element
    arr[(idx + i*step) % hash_table_size] = key;
}

// This function deletes an element at the given index in the hash table
void delete_item(string key) {
	// check if the given key exists or not 
    if (search_item(key) == false)
        return;
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // calculate the second hash value of the given hash value
    int step = hash_function_secondary(idx);
    // loop till find the given key
    int i = 0;
    while (arr[(idx + i*step) % hash_table_size] != key)
        i++;
    // set the position of the deleted element as a hash sign
    arr[(idx + i*step) % hash_table_size] = "#";
}

// This function prints the contents of the hash table
void print_hash_table() {
    // loop to print the elements in the hash table
    for (int i = 0 ; i < hash_table_size ; i++) {
        if (arr[i] == "" || arr[i] == "#")
            continue;
        cout << "index " << i << ": " << arr[i] << '\n';
    }
}

int main() {

	// Functionality Testing 

    for (char c = 'a' ; c <= 'z' ; c++) {
        string item = "";
        for (int i = 0 ; i < 10 ; i++) {
            item += c;
            insert_item(item);
        }
    }

    for (char c = 'a' ; c <= 'z' ; c++) {
        string item = "";
        for (int i = 0 ; i < 10 ; i++) {
            if (search_item(item) == false)
                cout << item << " not found\n";
            item += c;
        }
    }

    print_hash_table();
    cout << "----------------------------------------------------\n";

    for (char c = 'a' ; c <= 'z' ; c++) {
        string item = "";
        for (int j = 0 ; j < 10 ; j++) {
            item += c;
            if (j < 3)
                continue;
            delete_item(item);
        }
    }

    for (char c = 'a' ; c <= 'z' ; c++) {
        string item = "";
        for (int j = 0 ; j < 3 ; j++) {
            item += c;
            if (search_item(item) == false)
                cout << item << " not found\n";
        }
    }

    print_hash_table();
    cout << "----------------------------------------------------\n";

}
