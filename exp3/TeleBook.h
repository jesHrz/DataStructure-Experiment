#ifndef __TELEBOOK_H_
#define __TELEBOOK_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <linearList/arrayList.h>
using namespace std;

struct Info
{
	string name;
	string phone;
	string cla;
	string dorm;

	bool operator==(const Info& c) const
	{
		if (name == c.name && phone == c.phone && cla == c.cla && dorm == c.dorm)
			return true;
		else return false;
	}
	bool operator!=(const Info& c) const
	{
		return !(*this == c);
	}
	friend istream& operator>>(istream& in, Info& c)
	{
		in >> c.name >> c.phone >> c.cla >> c.dorm;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Info& c)
	{
		out << c.name << ' ' << c.phone << ' ' << c.cla << ' ' << c.dorm;
		return out;
	}
};

/**
 * name: student's name
 * phone: student's phone
 * cla: student's class
 * dorm: student's dormitory
 */
class TeleBook
{
protected:
	arrayList<Info> contacts;

public:
	TeleBook(int initialCapacity = 10): contacts(initialCapacity) {};
	TeleBook(const TeleBook& con): contacts(con.contacts) {};

	// insert information of contact to the telebook
	int size() const {return contacts.size();}
	void insert(const Info& contact) {contacts.push_back(contact);};
	void erase(const string&);
	void edit(const string&, const Info&);
	Info find(const string&) const;
	arrayList<Info> find_by_class(const string&) const;

	Info& operator[](int index) {return contacts[index];}
	const Info& operator[](int index) const {return contacts[index];}
};

#endif //__TELEBOOK_H_