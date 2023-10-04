#include <iostream>
#include <math.h>

using namespace std;

string sciNotation(long double num){
	if(num == 0){ return "0"; }
	if(isnan(num)){ return "Not a number"; }
	int exp = floor(log10(num));
	if(exp < 7 && exp > -3){ return to_string(num); }
	long double adjustedNum = num * pow(10, -exp);
	return to_string(adjustedNum) + "e" + to_string(exp);
}

int main(){
	cout << "Simple C++ Calculator by Shapto Adjie Wahyu Nugroho (X RPL 2)\n-------------------------------------------------------------\n\n";
    cout << "Insert operand 1: ";
    string inputStr;
    cin >> inputStr;
    
    long double num1 = stold(inputStr, nullptr);
    
    char op;
    cout << "Insert operator: ";
    cin >> op;

	cout << "Insert operand 2: ";
	cin >> inputStr;
	long double num2 = stold(inputStr, nullptr);
	
	string output;
	switch(op){
		case '+':
			output = sciNotation(num1 + num2); break;
		case '-':
			output = sciNotation(num1 - num2); break;
		case '*': case 'x':
			output = sciNotation(num1 * num2); break;
		case '/':
			if(num2 == 0){ output = "Undefined"; break; }
			output = sciNotation(num1 / num2); break;
		case '%':
			if(num2 == 0){ output = "0"; break; }
			output = sciNotation(fmod(num1, num2)); break;
		case '^':
			output = sciNotation(pow(num1, num2)); break;
		default:
			output = "Invalid or unknown operator"; break;
	}
	
    cout << "\nResult: " << output << endl;
    return 0;
}