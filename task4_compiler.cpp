#include <iostream>
#include <string>
using namespace std;

string expr;
int idx = 0;

// Forward declarations
int expression();
int term();
int factor();

// ------------------- PARSER FUNCTIONS -------------------

int number() {
    int val = 0;
    while (idx < expr.size() && isdigit(expr[idx])) {
        val = val * 10 + (expr[idx] - '0');
        idx++;
    }
    return val;
}

int factor() {
    if (expr[idx] == '(') {
        idx++; // skip '('
        int val = expression();
        idx++; // skip ')'
        return val;
    }
    return number();
}

int term() {
    int val = factor();
    while (idx < expr.size() && (expr[idx] == '*' || expr[idx] == '/')) {
        char op = expr[idx++];
        int next = factor();
        if (op == '*') val *= next;
        else val /= next;
    }
    return val;
}

int expression() {
    int val = term();
    while (idx < expr.size() && (expr[idx] == '+' || expr[idx] == '-')) {
        char op = expr[idx++];
        int next = term();
        if (op == '+') val += next;
        else val -= next;
    }
    return val;
}

// ------------------- MAIN COMPILER -------------------

int main() {
    cout << "Enter an arithmetic expression: ";
    getline(cin, expr);

    // remove spaces
    string temp = "";
    for (char c : expr) if (c != ' ') temp += c;
    expr = temp;

    int result = expression();

    cout << "Output = " << result << endl;

    return 0;
}
