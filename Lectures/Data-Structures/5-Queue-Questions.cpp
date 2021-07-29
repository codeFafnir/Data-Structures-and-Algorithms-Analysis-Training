#include <bits/stdc++.h>
using namespace std;

// This function finds the max value in each window with length k
void print_k_max(int arr[], int n, int k) {

}
// This function checks if a string is palindrome
string is_palindrome(string str) { 

}
// This function generates binary numbers from 1 to n
void generate_binary(int n) {

}
// This function reverses the queue
void reverse_queue_first_k_elements(int k, queue<int> &q) { 

}
// This function print the queue elements
void print_queue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
// This function calculates the sum of min and max elements of subarrays of size k
int sum_min_max_k_subarrays(int arr[], int n, int k) { 

}
// This function prints first negative number on each subarrays of size k
void print_first_negative_k_subarrays(int arr[], int n, int k) {

}

int main() {
	
    int arr[] = {4, 5, 3, 1, 2, 8, 10, 6, 9, 7};
    cout << "array {4, 5, 3, 1, 2, 8, 10, 6, 9, 7} has maximum values with\n";
    cout << "window 3 : ";
	print_k_max(arr, 10, 3);
	cout << "\n";
    cout << "window 4 : ";
	print_k_max(arr, 10, 4);
	cout << "\n";
    cout << "window 5 : ";
	print_k_max(arr, 10, 5);
	cout << "\n";
    cout << "window 6 : ";
	print_k_max(arr, 10, 6);
	cout << "\n";
	cout << "\n";

	cout << "abcdef" << " is " << is_palindrome("abcdef") << "\n";
	cout << "abbabba" << " is " << is_palindrome("abbabba") << "\n";
	cout << "abccba" << " is " << is_palindrome("abccba") << "\n";
    cout << "\n";

    generate_binary(3);
    cout << "--------------\n";
    generate_binary(8);
    cout << "--------------\n";
    generate_binary(15);
    cout << "--------------\n";

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    print_queue(q);
    cout << '\n';
    reverse_queue_first_k_elements(3, q);
    print_queue(q);
    cout << '\n';
    cout << '\n';

    int arr2[] = {2, 5, -1, 7, -3, -1, -2};
    cout << "sum of min and max 3 subsrrays of \n";
    cout << "{2, 5, -1, 7, -3, -1, -2} is ";
    cout << sum_min_max_k_subarrays(arr2, 7, 3);
    cout << '\n';

    int arr3[] = {12, -1, -7, 8, -15, 30, 16, 28}; 
    cout << "first negative number 3 subsrrays of \n";
    cout << "{12, -1, -7, 8, -15, 30, 16, 28} is \n";
    print_first_negative_k_subarrays(arr3, 8, 3); 
    cout << '\n';

}
