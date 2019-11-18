#include "TeleBook.h"

/**
 * delete a contact's information from telebook
 * @param contact the information of contact you want to delete
 */
void TeleBook::erase(const string& name)
{
	int i;
	for (i = 0; i < contacts.size(); ++i)
		if (contacts[i].name == name)
			break;
	if (i == contacts.size())
		throw domain_error("No such contact named " + name);
	contacts.erase(i);
}

/**
 * edit the information
 * @param name    the contact's name you want to edit
 * @param newInfo new information of contact
 */
void TeleBook::edit(const string& name, const Info& newInfo)
{
	bool find = false;
	for (int i = 0; i < contacts.size(); ++i)
		if (contacts[i].name == name)
		{
			contacts[i] = newInfo;
			find = true;
			break;
		}
	if (!find)	throw domain_error("No such contact " + name);
}

/**
 * find contact by name
 * @param  name contact's name you want to find
 * @return      information of the person you want
 */
Info TeleBook::find(const string& name) const
{
	for (int i = 0; i < contacts.size(); ++i)
		if (contacts[i].name == name)
			return contacts[i];
	throw domain_error("No such contact " + name);
	return Info();
}

/**
 * find all people's information
 */
arrayList<Info> TeleBook::find_by_class(const string& cla) const
{
	arrayList<Info> res;
	for (int i = 0; i < contacts.size(); ++i)
		if (contacts[i].cla == cla)
			res.push_back(contacts[i]);
	return res;
}
