#include <bits/stdc++.h>
using namespace std;

// This function reverses a string
string reverse_str(string str) {
	
}
// This function checks if a string is palindrome
string is_palindrome(string str) { 

}
// This function gives the priority of the operator
int prec(char c) { 
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
// This function converts the infix to postfix
string infix_to_postfix(string str) { 

}
// This function converts the infix to prefix
string infix_to_prefix(string str) { 

}
// This function converts the postfix to infix
string postfix_to_infix(string str) { 

}
// This function converts the prefix to infix
string prefix_to_infix(string str) { 

}
// This function converts the postfix to prefix
string postfix_to_prefix(string str) {

}
// This function converts the prefix to postfix
string prefix_to_postfix(string str) {

}
// This function performs arithmetic operations
float apply_operator(float a, float b, char op) { 
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^') return pow(a, b);
    return 0;
}
// This function evaluates the postfix expression
float evaluate_postfix(string str) {

}
// This function evaluates the prefix expression
float evaluate_prefix(string str) {

}
// This function evaluates the infix expression
float evaluate_infix(string str) {

}
// This function checks if paranthesis are balanced 
string is_paranthesis_balanced(string str) { 

}
// This function calculate the maximum ngth of valid balanced substring
int find_max_n_balanced(string str) { 

} 
// This function counts the minimum reversals to be a valid balanced string
int count_min_reversals(string str) { 

}
// This function calculates the maximum depth of nested parenthesis
int max_depth_nested_parenthesis(string str) { 

}
// This function removes brackets from an algebraic expression
string simplify_expression(string str) {

}

int main() {
	
	cout << "reverse of " << "abcdef" << " : " << reverse_str("abcdef") << "\n";
	cout << "reverse of " << "aabbcc" << " : " << reverse_str("aabbcc") << "\n";
	cout << "reverse of " << "abbaab" << " : " << reverse_str("abbaab") << "\n";
    cout << "\n";

	cout << "abcdef" << " is " << is_palindrome("abcdef") << "\n";
	cout << "abbabba" << " is " << is_palindrome("abbabba") << "\n";
	cout << "abccba" << " is " << is_palindrome("abccba") << "\n";
    cout << "\n";

	cout << "infix   : " << "((a+b)-c)" << "\n";
    cout << "postfix : " << infix_to_postfix("((a+b)-c)") << "\n";
    cout << "\n";
	cout << "infix   : " << "a+b*(c^d-e)^(f+g*h)-i" << "\n";
    cout << "postfix : " << infix_to_postfix("a+b*(c^d-e)^(f+g*h)-i") << "\n";
    cout << "\n";

	cout << "infix   : " << "((a+b)-c)" << "\n";
    cout << "prefix  : " << infix_to_prefix("((a+b)-c)") << "\n";
    cout << "\n";
	cout << "infix   : " << "a+b*(c^d-e)^(f+g*h)-i" << "\n";
    cout << "prefix  : " << infix_to_prefix("a+b*(c^d-e)^(f+g*h)-i") << "\n";
    cout << "\n";

	cout << "postfix : " << "ab+c-" << "\n";
    cout << "infix   : " << postfix_to_infix("ab+c-") << "\n";
    cout << "\n";
	cout << "postfix : " << "abcd^e-fgh*+^*+i-" << "\n";
    cout << "infix   : " << postfix_to_infix("abcd^e-fgh*+^*+i-") << "\n";
    cout << "\n";

	cout << "prefix  : " << "-+abc" << "\n";
    cout << "infix   : " << prefix_to_infix("-+abc") << "\n";
    cout << "\n";
	cout << "prefix  : " << "+a-*b^-^cde+f*ghi" << "\n";
    cout << "infix   : " << prefix_to_infix("+a-*b^-^cde+f*ghi") << "\n";
    cout << "\n";

	cout << "postfix : " << "ab+c-" << "\n";
    cout << "prefix  : " << postfix_to_prefix("ab+c-") << "\n";
    cout << "\n";
	cout << "postfix : " << "abcd^e-fgh*+^*+i-" << "\n";
    cout << "prefix  : " << postfix_to_prefix("abcd^e-fgh*+^*+i-") << "\n";
    cout << "\n";

	cout << "prefix  : " << "-+abc" << "\n";
    cout << "postfix : " << prefix_to_postfix("-+abc") << "\n";
    cout << "\n";
	cout << "prefix  : " << "-+a*b^-^cde+f*ghi" << "\n";
    cout << "postfix : " << prefix_to_postfix("-+a*b^-^cde+f*ghi") << "\n";
    cout << "\n";

    cout << "evaluation of postfix expression " << "35+2-";
    cout << " = " << evaluate_postfix("35+2-") << "\n";
    cout << "evaluation of postfix expression " << "7123^2-210*+^*+2-";
    cout << " = " << evaluate_postfix("7123^2-210*+^*+2-") << "\n";
    cout << "evaluation of prefix  expression " << "-+352";
    cout << " = " << evaluate_prefix("-+352") << "\n";
    cout << "evaluation of prefix  expression " << "-+7*1^-^232+2*102";
    cout << " = " << evaluate_prefix("-+7*1^-^232+2*102") << "\n";
    cout << "evaluation of infix   expression " << "((3+5)-2)";
    cout << " = " << evaluate_infix("((3+5)-2)") << "\n";
    cout << "evaluation of infix   expression " << "7+1*(2^3-2)^(2+1*0)-2";
    cout << " = " << evaluate_infix("7+1*(2^3-2)^(2+1*0)-2") << "\n";
    cout << "\n";

	cout << "[(({}){[]})] is " << is_paranthesis_balanced("[(({}){[]})]") << "\n";
	cout << "[](()){} is " << is_paranthesis_balanced("[](()){}") << "\n";
	cout << "][]()(){ is " << is_paranthesis_balanced("][]()(){") << "\n";
	cout << ")(())(()))()( is " << is_paranthesis_balanced(")(())(()))()(") << "\n";
    cout << "\n";

	cout << "max valid ngth of " << "(((())(())))" << " is ";
    cout << find_max_n_balanced("(((())(())))") << "\n";
	cout << "max valid ngth of " << "()(())()" << " is ";
    cout << find_max_n_balanced("()(())()") << "\n";
	cout << "max valid ngth of " << ")()()()(" << " is ";
    cout << find_max_n_balanced(")()()()(") << "\n";
	cout << "max valid ngth of " << ")(())(()))()(" << " is ";
    cout << find_max_n_balanced(")(())(()))()(") << "\n";
    cout << "\n";

	cout << "min reversal of " << "(((())(())))" << " is ";
    cout << count_min_reversals("(((())(())))") << "\n";
	cout << "min reversal of " << "()(())()" << " is ";
    cout << count_min_reversals("()(())()") << "\n";
	cout << "min reversal of " << ")()()()(" << " is ";
    cout << count_min_reversals(")()()()(") << "\n";
	cout << "min reversal of " << ")(())(()))()(" << " is ";
    cout << count_min_reversals(")(())(()))()(") << "\n";
    cout << "\n";

	cout << "max depth of nested parenthesis " << "(((())(())))" << " is ";
    cout << max_depth_nested_parenthesis("(((())(())))") << "\n";
	cout << "max depth of nested parenthesis " << "()(())()" << " is ";
    cout << max_depth_nested_parenthesis("()(())()") << "\n";
	cout << "max depth of nested parenthesis " << "(()()())" << " is ";
    cout << max_depth_nested_parenthesis("(()()())") << "\n";
	cout << "max depth of nested parenthesis " << "((())(()))()" << " is ";
    cout << max_depth_nested_parenthesis("((())(()))()") << "\n";
    cout << "\n";

    cout << "the simplest form of this expression " << "a-(b+c)" << " is ";
    cout << simplify_expression("a-(b+c)") << "\n";
    cout << "the simplest form of this expression " << "a-(b-c-(d+e))-f" << " is ";
    cout << simplify_expression("a-(b-c-(d+e))-f") << "\n";
    cout << "\n";

}
