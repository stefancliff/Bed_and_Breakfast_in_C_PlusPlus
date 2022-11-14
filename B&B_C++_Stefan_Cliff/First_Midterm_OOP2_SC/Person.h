#pragma once
#include <string>

using namespace std;

class Person {
private:
	string firstName, lastName, personID;
	int dayBirth=0, monthBirth=0, yearBirth=0;

public:

	Person();
	Person(string firstName, string lastName, string personID, int dayBirth, int monthBirth, int yearBirth);

	virtual void printDataPerson();
	virtual bool checkPersonID();
	virtual bool checkAge();
	virtual void checkPerson();
	
	/*
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setPersonID(string PersonID);
	void setDayBirth(int dayBirth);
	void setMonthBirth(int monthBirth);
	void setYearBirth(int yearBirth);
	void writePeople();
	string getFirstName();
	string getLastName();
	string getPersonID();
	int getDayBirth();
	int getMonthBirth();
	int getYearBirth();
*/

	friend ostream&operator<<(ostream&out, const Person&p) {
		return out << "This persons basic data is: " << endl << "First name: " << p.firstName << endl << "Last name: " << p.lastName << endl
			<< "Personal ID number(JMBG): " << p.personID << endl << "Their date of birth (dd/mm/yyyy): " << p.dayBirth << "/" << p.monthBirth << "/" << p.yearBirth << endl;
	}
};
