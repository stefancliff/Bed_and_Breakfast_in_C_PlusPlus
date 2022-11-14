#pragma once
#include <string>
#include "Person.h"

class Customer : public Person 
{
private:
	
	string customerUsername, creditCardNumber;
	int creditCardMonth, creditCardYear;

public:

	virtual void printDataPerson() override;
	void checkCreditCardNumber();
	void checkCreditCardDate();
	void checkPerson();
	/*
	void setCreditCardNumber(string creditCardNumber);
	void setCreditCardMonth(int creditCardMonth);
	void setCreditCardYear(int creditCardYear);
	void setCustomerUsername(string custromerUsername);

	
	string getCreditCardNumber();
	int getCreditCardMonth();
	int getCreditCardYear();
	*/
	string getUsername();
	string createUsername(string firstName, string lastName, string personID);

	Customer();
	Customer(string firstName, string lastName, string personID, int dayBirth, int monthBirth, int yearBirth, 
		string customerUsername, string creditCardNumber, int creditCardMonth, int creditCardYear);
};

