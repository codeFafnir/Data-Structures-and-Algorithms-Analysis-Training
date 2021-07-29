#include <bits/stdc++.h>
using namespace std;

// Initialize a hash table with dynamic length
int n;
int capacity;
int prime_capacity;
string* arr;

// Initialize the load_factor
const float load_factor = 0.5;

// This function find the next prime of the given number
int get_next_prime(int x) {
    // loop for maximum 150 numbers after x to find a prime one
    for (int i = x + 1 ; i < x + 150 ; i++) {
        bool is_prime = true;
        // loop to check if the current number is prime
        for (int j = 2 ; j * j <= i ; j++) {
            if (i % j == 0)
                is_prime = false;
        }
        // if the current number is prime return it
        if (is_prime)
            return i;
    }
    // return the given number
    return x;
}

// This function calculates the hash value of the given key with type string
int hash_function_str_complex(string key) {
    int res = 0;
    for (int i = 0 ; i < key.size() ; i++)
        res = (res + 37LL * key[i]) % capacity;
    return res;
}

// This function calculates the hash value of the given hash value
int hash_function_secondary(int hash_idx) {
    return prime_capacity - hash_idx % prime_capacity;
}

// This function reinserts the elements in the hash table
void reinsert_items(string* temp, int old_capacity) {
    // loop on all items in the hash table to reinsert them again
    for (int i = 0 ; i < old_capacity ; i++) {
        // check if the current item empty
        if (arr[i] == "" || arr[i] == "#") 
            continue;
        // calculate the hash value of the given key
        int idx = hash_function_str_complex(arr[i]);
        // calculate the second hash value of the given hash value
        int step = hash_function_secondary(idx);
        // loop till find an empty position
        int j = 0;
        while (temp[(idx + j*step) % capacity] != "")
            j++;
        // insert the new element
        temp[(idx + j*step) % capacity] = arr[i];
    }
}

// This function updates the capacity of the hash table
void reserve(int new_capacity) {
    // Initialize a new hash table with the new capacity
    string* temp = new string[new_capacity];
    // store the old capacity to use it in reinserting the items
    int old_capacity = capacity;
    // set the current capacity of the hash table to be the new capacity
	capacity = new_capacity;
    // copy the elements in the current hash table to the new hash table
    reinsert_items(temp, old_capacity);
    // delete the old hash table
	delete[] arr;
    // set the temp hash table with new capacity to be the hash table
	arr = temp;
}

// This function searches for an element in the hash table
bool search_item(string key) {
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // calculate the second hash value of the given hash value
    int step = hash_function_secondary(idx);
    // loop till find the given key
    int i = 0;
    while (arr[(idx + i*step) % capacity] != key && 
           arr[(idx + i*step) % capacity] != "")
        i++;
    // return whether the current position in the hash table contain the given key
    return arr[(idx + i*step) % capacity] == key;
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
    while (arr[(idx + i*step) % capacity] != "" && 
           arr[(idx + i*step) % capacity] != "#")
        i++;
    // insert the new element
    arr[(idx + i*step) % capacity] = key;
	// update the size of the hash table
	n = n + 1;
    // check if we need to update the capacity of the hash table
    if (1.0 * n / capacity >= load_factor) {
        prime_capacity = get_next_prime(2 * capacity);
        reserve(get_next_prime(prime_capacity));
    }
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
    while (arr[(idx + i*step) % capacity] != key)
        i++;
    // set the position of the deleted element as a hash sign
    arr[(idx + i*step) % capacity] = "#";
	// update the size of the hash table
	n = n - 1;
    // check if we need to update the capacity of the min-heap
    if (n < capacity / 2) {
        prime_capacity = get_next_prime(capacity / 2);
        reserve(get_next_prime(prime_capacity));
	}
}

// This function prints the contents of the hash table
void print_hash_table() {
    // loop to print the elements in the hash table
    for (int i = 0 ; i < capacity ; i++) {
        if (arr[i] == "" || arr[i] == "#")
            continue;
        cout << "index " << i << ": " << arr[i] << '\n';
    }
}

int main() {

	// Functionality Testing 

    capacity = 3;
    prime_capacity = 2;
    arr = new string[capacity];

    cout << "Hash Table capacity: " << capacity << '\n';
    cout << "Hash Table prime_capacity: " << prime_capacity << '\n';
    cout << "Hash Table size: " << n << '\n';
    cout << "----------------------------------------------------\n";

    for (char i = 'a' ; i <= 'm' ; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0 ; j < 75 ; j++) {
            insert_item(item);
            item += i;
        }

        cout << "Hash Table capacity: " << capacity << '\n';
        cout << "Hash Table prime_capacity: " << prime_capacity << '\n';
        cout << "Hash Table size: " << n << '\n';
        cout << "----------------------------------------------------\n";
    }

    for (char i = 'a' ; i <= 'm' ; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0 ; j < 75 ; j++) {
            if (search_item(item) == false)
                cout << item << " not found\n";
            item += i;
        }
    }

	// print_hash_table();
    cout << "----------------------------------------------------\n";

    for (char i = 'a' ; i <= 'm' ; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0 ; j < 75 ; j++) {
            if (j < 10) {
                item += i;
                continue;
            }
            delete_item(item);
            item += i;
        }

        cout << "Hash Table capacity: " << capacity << '\n';
        cout << "Hash Table prime_capacity: " << prime_capacity << '\n';
        cout << "Hash Table size: " << n << '\n';
        cout << "----------------------------------------------------\n";
    }
	
    for (char i = 'a' ; i <= 'm' ; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0 ; j < 10 ; j++) {
            if (search_item(item) == false)
                cout << item << " not found\n";
            item += i;
        }
    }

	// print_hash_table();
    cout << "----------------------------------------------------\n";

}
