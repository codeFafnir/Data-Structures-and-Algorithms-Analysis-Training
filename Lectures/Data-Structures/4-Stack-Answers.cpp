#include <bits/stdc++.h>
using namespace std;

// This function reverses a string
string reverse_str(string str) {
    int n = str.size();
    stack<char> stk;
    for (int i = 0; i < n; i++)  
        stk.push(str[i]);
    for (int i = 0; i < n; i++) {
        str[i] = stk.top();
		stk.pop();
	}
    return str;
}
// This function checks if a string is palindrome
string is_palindrome(string str) { 
    int n = str.size();
    stack<char> stk;
    int i = 0;
    while (i < n/2) {
        stk.push(str[i]);
        i++;
    }
    if (n % 2 == 1)
        i++;
    while (!stk.empty()) {
        if (stk.top() != str[i]) 
            return "not palindrome";
        stk.pop();
        i++; 
    }
    return "palindrome"; 
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
    int n = str.size();
    stack<char> stk;
    string res = "";
    stk.push('$');
    for (int i = 0; i < n; i++) {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')) 
            res += str[i];
        else if (str[i] == '(')
            stk.push('(');
        else if (str[i] == ')') { 
            while (stk.top() != '$' && stk.top() != '(') {
                res += stk.top();
                stk.pop();
            }
            if (stk.top() == '(')
                stk.pop(); 
        }
        else { 
            while (stk.top() != '$' && prec(str[i]) <= prec(stk.top())) { 
                res += stk.top();
                stk.pop();
            }
            stk.push(str[i]);
        }  
    }
    while (stk.top() != '$') { 
        res += stk.top();
        stk.pop();
    }
    return res;
}
// This function converts the infix to prefix
string infix_to_prefix(string str) { 
    int n = str.size();
    stack<char> stk;
    string res = "";
    stk.push('$');
    for (int i = n-1; i >= 0; i--) {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')) 
            res += str[i];
        else if (str[i] == ')')
            stk.push(')');
        else if (str[i] == '(') { 
            while (stk.top() != '$' && stk.top() != ')') {
                res += stk.top();
                stk.pop();
            }
            if (stk.top() == ')')
                stk.pop(); 
        }
        else { 
            while (stk.top() != '$' && prec(str[i]) <= prec(stk.top())) { 
                res += stk.top();
                stk.pop();
            }
            stk.push(str[i]);
        }  
    }
    while (stk.top() != '$') { 
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
// This function converts the postfix to infix
string postfix_to_infix(string str) { 
    int n = str.size();
    stack<string> stk;
    for (int i = 0; i < n; i++) {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')) {
            string op = "";
            op += str[i];
            stk.push(op);
        }
        else {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            stk.push("(" + op2 + str[i] + op1 + ")");
        }
    }
    return stk.top();
}
// This function converts the prefix to infix
string prefix_to_infix(string str) { 
    int n = str.size();
    stack<string> stk;
    for (int i = n-1; i >= 0; i--) {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')) {
            string op = "";
            op += str[i];
            stk.push(op);
        }
        else {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            stk.push("(" + op1 + str[i] + op2 + ")");
        }
    }
    return stk.top();
}
// This function converts the postfix to prefix
string postfix_to_prefix(string str) {
    int n = str.size();
    stack<string> stk;
    for (int i = 0; i < n; i++) {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')) {
            string op = "";
            op += str[i];
            stk.push(op);
        }
        else {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            stk.push(str[i] + op2 + op1);
        }
    }
    return stk.top();
}
// This function converts the prefix to postfix
string prefix_to_postfix(string str) {
    int n = str.size();
    stack<string> stk;
    for (int i = n-1; i >= 0; i--) {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')) {
            string op = "";
            op += str[i];
            stk.push(op);
        }
        else {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            stk.push(op1 + op2 + str[i]);
        }
    }
    return stk.top();
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
    int n = str.size();
    stack<float> stk;
    for (int i = 0; i < n; i++) {
        if ('0' <= str[i] && str[i] <= '9')  
            stk.push(float(str[i] - '0'));
        else {
            float val2 = stk.top(); stk.pop();
            float val1 = stk.top(); stk.pop();
            stk.push(apply_operator(val1, val2, str[i]));
        }
    }
    return stk.top();  
}
// This function evaluates the prefix expression
float evaluate_prefix(string str) {
    int n = str.size();
    stack<float> stk;
    for (int i = n-1; i >= 0; i--) {
        if ('0' <= str[i] && str[i] <= '9')  
            stk.push(float(str[i] - '0'));
        else {
            float val1 = stk.top(); stk.pop();
            float val2 = stk.top(); stk.pop();
            stk.push(apply_operator(val1, val2, str[i]));
        }
    }
    return stk.top();  
}
// This function evaluates the infix expression
float evaluate_infix(string str) {
    int n = str.size();
    stack<float> vals;
    stack<char> ops;
    for (int i = 0; i < n; i++) {
        if ('0' <= str[i] && str[i] <= '9') 
            vals.push(float(str[i] - '0'));
        else if (str[i] == '(')
            ops.push('(');
        else if (str[i] == ')') { 
            while (!ops.empty() && ops.top() != '(') {
                float val2 = vals.top(); vals.pop();
                float val1 = vals.top(); vals.pop();
                char op = ops.top(); ops.pop();
                vals.push(apply_operator(val1, val2, op));
            }
            if (ops.top() == '(')
                ops.pop(); 
        }
        else { 
            while (!ops.empty() && prec(str[i]) <= prec(ops.top())) { 
                float val2 = vals.top(); vals.pop();
                float val1 = vals.top(); vals.pop();
                char op = ops.top(); ops.pop();
                vals.push(apply_operator(val1, val2, op));
            }
            ops.push(str[i]);
        }  
    }
    while (!ops.empty()) { 
        float val2 = vals.top(); vals.pop();
        float val1 = vals.top(); vals.pop();
        char op = ops.top(); ops.pop();
        vals.push(apply_operator(val1, val2, op));
    }
    return vals.top();
}
// This function checks if paranthesis are balanced 
string is_paranthesis_balanced(string str) { 
    int n = str.size();
    stack<char> stk;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stk.push(str[i]);
            continue;
        }
        if (stk.empty()) 
            return "not balanced";
        if (str[i] == ')') {
            char x = stk.top(); 
            stk.pop(); 
            if (x == '{' || x == '[')
                return "not balanced";
        }
        if (str[i] == '}') {
            char x = stk.top(); 
            stk.pop(); 
            if (x == '(' || x == '[')
                return "not balanced";
        }
        if (str[i] == ']') {
            char x = stk.top(); 
            stk.pop(); 
            if (x == '(' || x == '{') 
                return "not balanced";
        }
    }
    return stk.empty()? "balanced" : "not balanced";
}
// This function calculate the maximum ngth of valid balanced substring
int find_max_n_balanced(string str) { 
    int n = str.size();
    stack<int> stk;
    stk.push(-1); 
    int res = 0;
    for (int i = 0; i < n; i++) { 
        if (str[i] == '(') 
            stk.push(i);
        else {
            stk.pop();
            if (!stk.empty())
                res = max(res, i - stk.top());
            else 
                stk.push(i);
        }
    }
    return res; 
} 
// This function counts the minimum reversals to be a valid balanced string
int count_min_reversals(string str) { 
    int n = str.size();
    stack<int> stk;
    if (n % 2)
        return -1; 
    for (int i = 0; i < n; i++) {
        if (str[i] == ')' && !stk.empty()) {
            if (stk.top() == '(') 
                stk.pop();
            else
                stk.push(str[i]);
        }
        else
            stk.push(str[i]);
    }
    int res = stk.size();
    int m = 0;
    while (!stk.empty() && stk.top() == '(') {
        stk.pop();
        m++;
    }
    return (res / 2 + m % 2);
}
// This function calculates the maximum depth of nested parenthesis
int max_depth_nested_parenthesis(string str) { 
    int n = str.size();
    stack<int> stk;
    int res = 0;
    for (int i = 0; i< n; i++) { 
        if (str[i] == '(') { 
            stk.push('(');
            if (stk.size() > res) 
                res = stk.size();
        }
        else if (str[i] == ')') { 
            if (!stk.empty()) 
                stk.pop(); 
            else
                return -1; 
        }
    }
    return stk.empty()? res : -1; 
}
// This function removes brackets from an algebraic expression
string simplify_expression(string str) {
    int n = str.size();
    stack<int> stk;
    stk.push(0);
    string res = "";
    for (int i = 0; i < n; i++) {
        if (str[i] == '+') {
            if (stk.top() == 1)
                res += '-';
            if (stk.top() == 0)
                res += '+';
        }
        else if (str[i] == '-') {
            if (stk.top() == 1)
                res += '+';
            if (stk.top() == 0)
                res += '-';
        }
        else if (str[i] == '(' && i > 0) {
            if (str[i-1] == '-') {
                int x = (stk.top() == 1) ? 0 : 1;
                stk.push(x);
            }
            else if (str[i-1] == '+')
                stk.push(stk.top());
        }
        else if (str[i] == ')')
            stk.pop();
        else
            res += str[i];
    }
    return res; 
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
