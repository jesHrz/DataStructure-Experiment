#include <iostream>
#include <fstream>
#include <string>
#include "TeleBook.h"

using namespace std;


int main() {
	TeleBook t;

	ifstream fin;
	fin.open("contacts.txt");

	if (!fin.is_open())	exit(-1);

	while (fin.good()) {
		struct Info c;
		fin >> c;
		t.insert(c);
	}
	fin.close();
	cout << "读取到" << t.size() << "个联系人" << endl;

	int tp;
	string name, cla;
	struct Info c;
	arrayList<Info> all;
	do {
		cout << "1.插入\n2.删除\n3.编辑\n4.按姓名查找\n5.按班级查找\n6.显示所有联系人\n0.退出\n";
		cin >> tp;
		switch (tp) {
		case 1://insert
			cout << "请依次输入联系人的姓名 号码 班级 宿舍: " << endl;
			cin >> c;
			try {
				t.insert(c);
				cout << c.name << " 插入成功!" << endl;
			} catch (...) {
				cout << "插入失败" << endl;
			}
			break;
		case 2://erase
			cout << "请输入被删联系人的姓名: " << endl;
			cin >> name;
			try {
				t.erase(name);
				cout << name << " 删除成功!" << endl;
			} catch (domain_error & e) {
				cout << e.what() << endl;
			}
			break;
		case 3:
			//edit
			cout << "请输入被编辑联系人的姓名: " << endl;
			cin >> name;
			cout << "请依次输入联系人的姓名 号码 班级 宿舍: " << endl;
			cin >> c;
			try {
				t.edit(name, c);
				cout << name << " 修改成功!" << endl;
			} catch (domain_error & e) {
				cout << e.what() << endl;
			}
			break;
		case 4:
			//find by name
			cout << "请输入姓名: " << endl;
			cin >> name;
			cout << t.find(name) << endl;
			break;
		case 5:
			// find by class
			cout << "请输入班级: " << endl;
			cin >> cla;
			all = t.find_by_class(cla);
			for (int i = 0; i < all.size(); ++i)
				cout << all[i] << endl;
			break;
		case 6:
			for (int i = 0; i < t.size(); ++i)
				cout << t[i] << endl;
			break;
		default:
			break;
		}
	} while (tp > 0);

	ofstream fout("contacts.txt", ios::trunc);
	if (fout.is_open()) {
		//save while exiting
		for (int i = 0; i < t.size(); ++i) {
			if (i > 0)	fout << endl;
			fout << t[i];
		}
	}
	fout.close();

	return 0;
}