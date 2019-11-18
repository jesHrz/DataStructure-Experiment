#include <iostream>
#include <sstream>
#include <stack/linkedStack.h>
#include "test1.h"

using namespace std;

//�ַ���ת����
template<typename T>
T str2num(const string& str) {
	istringstream iss(str);
	T num;
	iss >> num;
	return num;
}

//���ȼ�����
int priority(char symbol) {
	switch (symbol) {
	case '+':
	case '-':
		return 0;
	case '*':
	case '/':
		return 1;
	case '(':
	case ')':
		return 2;
	}
	return -1;
}

//�ж��Ƿ�Ϊ�����
bool isOp(char symbol) {
	switch (symbol) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
		return true;
	}
	return false;
}

//���ַ����ֽ�Ϊ�������ֺ������
void translate(const string& str, arrayList<item>& vecIn) {
	int nCount = str.length();
	int nIndex = 0;
	bool last = false;//false op  true num
	while (nIndex < nCount) {
		if (isOp(str[nIndex])) {
			if (str[nIndex] != '-' || (str[nIndex] == '-' && last)) {
				vecIn.push_back({ false, 0, str[nIndex++] });
				last = false;
				continue;
			}
		}
		if (str[nIndex] == '-') {
			string num;
			int nTemp = nIndex + 1;
			while (nTemp < nCount && (isdigit(str[nTemp]) || str[nTemp] == '.'))    num += str[nTemp++];
			if (num.length() > 0) {
				if (nIndex > 1 && vecIn[vecIn.size() - 1].op == ')') {
					vecIn.push_back({ false, 0, '+' });
				}
				vecIn.push_back({ false, 0, '(' });
				vecIn.push_back({ true, 0, 0 });
				vecIn.push_back({ false, 0, '-' });
				vecIn.push_back({ true, str2num<double>(num), 0 });
				vecIn.push_back({ false, 0, ')' });
				nIndex += num.length();
				last = true;
			} else {
				if (vecIn.size() == 0) {
					vecIn.push_back({ true, -1, 0 });
					vecIn.push_back({ false, 0, '*' });
				} else if (vecIn[vecIn.size() - 1].isDigit) {
					vecIn.push_back({ false, 0, '-' });
					vecIn.push_back({ true, 1, 0 });
					vecIn.push_back({ false, 0, '*' });
				} else {
					vecIn.push_back({ false, 0, '-' });
				}
			}
			nIndex++;
			continue;
		}
		string num;
		int nTemp = nIndex;
		while (nTemp < nCount && (isdigit(str[nTemp]) || str[nTemp] == '.'))	num += str[nTemp++];
		if (nTemp != nIndex) {
			vecIn.push_back({ true, str2num<double>(num), 0 });
			last = true;
			nIndex += num.length();
		} else nIndex++;
	}
}

//��׺ת��׺
void infix2suffix(const arrayList<item>& infixIn, arrayList<item>& suffixOut) {
	linkedStack<char> symbolStack;
	for (auto it = infixIn.begin(); it != infixIn.end(); ++it) {
		if (it->isDigit)	suffixOut.push_back(*it);
		else {
			if (it->op == ')') {
				while (!symbolStack.empty()) {
					char op = symbolStack.top();
					symbolStack.pop();
					if (op == '(')	break;
					suffixOut.push_back({ false, 0, op });
				}
			} else {
				while (!symbolStack.empty() && symbolStack.top() != '(' && priority(it->op) <= priority(symbolStack.top())) {
					suffixOut.push_back({ false, 0, symbolStack.top() });
					symbolStack.pop();
				}
				symbolStack.push(it->op);
			}
		}
	}
	while (!symbolStack.empty()) {
		suffixOut.push_back({ false, 0, symbolStack.top() });
		symbolStack.pop();
	}

}

//�����׺���ʽ��ֵ
double calculate(const arrayList<item>& vecIn) {
	linkedStack<double> numStack;
	for (auto it = vecIn.begin(); it != vecIn.end(); ++it) {
		if (it->isDigit)	numStack.push(it->num);
		else {
			double num1 = numStack.top(); numStack.pop();
			double num2 = numStack.top(); numStack.pop();
			switch (it->op) {
			case '+':
				numStack.push(num2 + num1);
				break;
			case '-':
				numStack.push(num2 - num1);
				break;
			case '*':
				numStack.push(num2 * num1);
				break;
			case '/':
				numStack.push(num2 / num1);
				break;
			default:
				break;
			}
		}
	}
	return numStack.top();
}


void test1() {
	cout << "������Ϸ�����ѧ���ʽ: " << endl;
	string str;
	getline(cin, str);
	arrayList<item> vecIn, vecOut;
	try {
		translate(str, vecIn);
		infix2suffix(vecIn, vecOut);
		cout << "������Ϊ: " << endl;
		cout << calculate(vecOut) << endl;
	} catch (...) {
		cout << "�Ƿ����ʽ" << endl;
	}
}
