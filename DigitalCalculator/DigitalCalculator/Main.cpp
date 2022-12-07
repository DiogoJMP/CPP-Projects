#include <iostream>
#include <cmath>
using namespace std;


void calculate() {
	double input;
	char oprtr;
	double res = 0;

	cout << "Input: ";
	cin >> res;
	cout << "Operator: ";
	cin >> oprtr;

	while (oprtr != '=') {
		while (oprtr != '+' && oprtr != '-' && oprtr != '/' && oprtr != '*' && oprtr != '%' && oprtr != '^') {
			cout << "Invalid operator." << endl;
			cout << "Operator: ";
			cin >> oprtr;
		}
		cout << "Next input: ";
		cin >> input;
		cout << res;
		switch (oprtr) {
		case '+':
			res += input;
			break;
		case '-':
			res -= input;
			break;
		case '*':
			res *= input;
			break;
		case '/':
			res /= input;
			break;
		case '%':
			res = (int)res % (int)input;
			break;
		case '^':
			res = pow(res, input);
			break;
		}
		cout << oprtr << input << '=' << res << endl;
		cout << "Next operator: ";
		cin >> oprtr;
	}
	cout << "Result: " << res << endl;
}

int main() {
	calculate();
	return 0;
}