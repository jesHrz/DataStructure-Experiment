#ifndef TEST1_H_
#define TEST1_H_
#include <string>
#include <linearList/arrayList.h>

struct item {
	bool isDigit;
	double num;
	char op;
	bool operator!=(const item& it) const { return isDigit != it.isDigit || num != it.num || op != it.op; }
};

bool isOp(char);
void translate(const std::string&, arrayList<item>&);
void infix2suffix(const arrayList<item>&, arrayList<item>&);
double calculate(const arrayList<item>&);
void test1();

#endif //TEST1_H_
