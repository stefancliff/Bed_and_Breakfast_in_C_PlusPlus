#include "Customer.h"
#include <iostream>
#include <string>

using namespace std;

Customer::Customer() {};

Customer::Customer(string firstName, string lastName, string personID, int dayBirth, int monthBirth, int yearBirth,
	string customerUsername, string creditCardNumber, int creditCardMonth, int creditCardYear)
	:Person(firstName, lastName, personID, dayBirth, monthBirth, yearBirth) {
	
	this->customerUsername = customerUsername;
	this->creditCardNumber = creditCardNumber;
	this->creditCardMonth = creditCardMonth;
	this->creditCardYear = creditCardYear;
	this->createUsername(firstName, lastName, personID);
}

void Customer::printDataPerson() {
	
	Person::printDataPerson();
		cout << "Their username: " << customerUsername << endl << "Their credit card information(number, expiration month/year): "
		<< creditCardNumber << " " << creditCardMonth << "/" << creditCardYear << endl;
}

void Customer::checkCreditCardNumber()
{
	int counter = 0;

	if (creditCardNumber.length() == 16)
	{
		for (int i = 0; i < creditCardNumber.length(); i++)
		{
			if (isdigit(creditCardNumber.at(i))) {
				counter++;
			}
		}
	}
	
	if (counter == 16)
		cout << "The credit card number is in the correct format. " << endl;
	else
	{ 
		cout << "The credit card number is not in the correct format. Could you please enter it again, starting with the number(16 digits long): " << endl;
		cin >> this->creditCardNumber;
		checkCreditCardNumber();
	}
	
}

void Customer::checkCreditCardDate()
{
	if (creditCardMonth < 1 || creditCardMonth>12)
	{
		cout << "The month for the credit card is not possible!" << endl;
		cin >> this->creditCardMonth;
		checkCreditCardDate();
	}
	else if (creditCardYear < 2021) {
		cout << "The year for the credit card is not possible!" << endl;
		cin >> this->creditCardYear;
		checkCreditCardDate();
	}
	else
		cout << "The credit card experation date seems to be in order!" << endl;
}

string Customer::createUsername(string firstName, string lastName, string personID) {
	customerUsername = firstName + lastName + personID;
	return customerUsername;
}


void Customer::checkPerson()
{
	Person::checkPerson();
	checkCreditCardNumber();
	checkCreditCardDate();
}
string Customer::getUsername() { return customerUsername; }
/*
void Customer::setCreditCardNumber(string creditCardNumber){ this->creditCardNumber = creditCardNumber;}
void Customer::setCreditCardMonth(int creditCardMonth){	this->creditCardMonth = creditCardMonth;}
void Customer::setCreditCardYear(int creditCardYear) { this->creditCardYear = creditCardYear;}
void Customer::setCustomerUsername(string customerUsername) { this->customerUsername = customerUsername; }


string Customer::getCreditCardNumber(){	return creditCardNumber;}
int Customer::getCreditCardMonth(){	return creditCardMonth;}
int Customer::getCreditCardYear(){	return creditCardYear;}
*/
