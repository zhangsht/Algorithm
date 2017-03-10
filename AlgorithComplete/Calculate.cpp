/*
默认保留一位小数，且所给表达式正确无误
*/
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <map>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

double calculate(string s) {
	// infix expression to post expression
	stack<char> ops;
	string postfix;

	// set priority
	map<char, int> prior;
	prior['+'] = 0, prior['-'] = 0;
	prior['*'] = 1, prior['/'] = 1;
	prior['('] = 2;

	bool preop = true;
	for (int i = 0; i < s.size(); ++i) {
		char x = s[i];
		if (x == ' ') continue;
		if ((x >= '0' && x <= '9') || x == '.') {
			preop = false;
			postfix += x;
			continue;
		}
		else if (x == ')') {

			while (ops.top() != '(') {  // handle a pair of ()
				postfix += ops.top();
				ops.pop();
			}
			ops.pop();
		}
		else if (x == '(') {
			ops.push(x);
		}
		else if (x == '-' && preop == true) {
			postfix += x;
			continue;
		}
		else {  // stack of operators is not empty

			while (!ops.empty() && ops.top() != '('
				&& prior[x] <= prior[ops.top()]) {
				postfix += ops.top();
				ops.pop();
			}
			ops.push(x);
			preop = true;
		}
		postfix += ' ';
	}

	// the input is empty. pop the entire operators.
	while (!ops.empty()) {
		postfix += ops.top();
		ops.pop();
	}
	// compute postfix expression
	stack<double> nums;

	int sign = 1;
	for (int i = 0; i < postfix.size(); ++i) {
		char x = postfix[i];
		if (x == ' ') continue;
		if (i != postfix.size() - 1 && x == '-' && ((postfix[i + 1] <= '9'
			&& postfix[i + 1] >= '0') || postfix[i + 1] == '.')) {
			sign = -1;
			continue;
		}
		if ((x >= '0' && x <= '9') || x == '.') {
			int pre = i;
			while ((x >= '0' && x <= '9') || x == '.') {
				++i;
				x = postfix[i];
			}
			--i;
			stringstream ss;
			ss << postfix.substr(pre, i - pre + 1);
			double oprand;
			ss >> oprand;

			nums.push(sign*oprand);
			sign = 1;
		}
		else if (x == '+' || x == '-' || x == '*' || x == '/') {
			double operand1, operand2;
			if (!nums.empty())
				operand1 = nums.top();
			nums.pop();
			if (!nums.empty())
				operand2 = nums.top();
			nums.pop();

			// compute
			if (x == '+')
				nums.push(operand2 + operand1);
			else if (x == '-')
				nums.push(operand2 - operand1);
			else if (x == '*')
				nums.push(operand2 * operand1);
			else
				nums.push(operand2 / operand1);
		}
	}

	if (!nums.empty())
		return nums.top();
	else
		return 0.0;
}

//
//int main() {
//	// 行数
//	int n;
//	cin >> n;
//	string str;
//	getline(cin, str);
//
//	//计算每一行的结果
//	while (n--) {
//		string str;
//		getline(cin, str);
//		//固定小数点位数
//		double ans = calculate(str);
//		long about = ans;
//		const double EPSINON = 0.0001;
//		if (abs(ans - about) < EPSINON) {
//			printf("%.ld\n", about);
//		}
//		else {
//			printf("%.1lf\n", ans);
//		}
//		
//	}
//}