#include "Person.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void Person::printDataPerson() {

	cout << "This persons basic data is: " << endl << "First name: " << this->firstName << endl << "Last name: " << this->lastName << endl
		<< "Personal ID number(JMBG): " << this->personID << endl << "Their date of birth (dd/mm/yyyy): " << this->dayBirth << "/" << this->monthBirth << "/" << this->yearBirth << endl;
}

Person::Person() {};

Person::Person(string firstName="FirstName", string lastName="LastName", string personID="1111111111111", int dayBirth=0, int monthBirth=0, int yearBirth=0) {

	this->firstName = firstName;
	this->lastName = lastName;
	this->personID = personID;
	this->dayBirth = dayBirth;
	this->monthBirth = monthBirth;
	this->yearBirth = yearBirth;
}

bool Person::checkPersonID() {
	int counter = 0;
	
	if (personID.length() == 13)
	{
		for (int i = 0; i < personID.length(); i++)
		{
			
			if (isdigit(personID.at(i))) {
				counter++;
			}
		}
	}
	
	if (counter == 13) 
	{
		cout << "The Person ID is in the correct format. " << endl;
	}
	else
	{
		cout << "The Person ID is not in the correct format. " << endl;
		//cin >> this->personID;
		//checkPersonID();
		
	}
	
	return true;
}

bool Person::checkAge()
{

		if (dayBirth < 1 || dayBirth>31)
		{
			//cout << "The day in the date of birth is not possible!" << endl;
			return false;
		}

		else if (monthBirth < 1 || monthBirth>12)
		{
			//cout << "The month in the date of birth is not possible!" << endl;
			return false;
		}

		else if (yearBirth <= 1900 || yearBirth >= 2021)
		{
			//cout << "The year in the date of birth is not possible!" << endl;
			return false;
		}
	

	return true;
}

void Person::checkPerson()
{
	checkAge();
	checkPersonID();
}
/*
void Person::writePeople() {

	ofstream outputPerson("outputPerson.txt");
	if (outputPerson.is_open()) {
		outputPerson << "This persons basic data is: " << endl << "First name: " << this->firstName << endl << "Last name: " << this->lastName << endl
		<< "Personal ID number(JMBG): " << this->personID << endl << "Their date of birth (dd/mm/yyyy): " << this->dayBirth << "/" << this->monthBirth << "/" << this->yearBirth << endl;
		}
	else cout << "Unable to open the file" << endl;
	outputPerson.close();
}
void Person::setFirstName(string firstName){ this->firstName = firstName; }
void Person::setLastName(string lastName){ this->lastName = lastName; }
void Person::setPersonID(string personID){ this->personID = personID; }
void Person::setDayBirth(int dayBirth){ this->dayBirth = dayBirth; }
void Person::setMonthBirth(int monthBirth){ this->monthBirth = monthBirth; }
void Person::setYearBirth(int yearBirth){ this->yearBirth = yearBirth; }

string Person::getFirstName() { return this->firstName; }
string Person::getLastName() { return this->lastName; }
string Person::getPersonID() { return this->personID; }
int Person::getDayBirth() { return this->dayBirth; }
int Person::getMonthBirth() { return this->monthBirth; }
int Person::getYearBirth() { return this->yearBirth; }
*/