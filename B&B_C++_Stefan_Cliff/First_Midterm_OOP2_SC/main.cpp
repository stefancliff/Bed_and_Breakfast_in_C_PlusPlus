#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Person.h"
#include "Customer.h"

#include "Host.h"
#include "Accommodation.h"

using namespace std;

int main()
{
	ifstream inPerson("inputPerson.txt");
	ifstream inAccommodation("inputAccommodation.txt");
	

	if (!inPerson.is_open()) return EXIT_FAILURE;
	if (!inAccommodation.is_open()) return EXIT_FAILURE;
	

	vector <Accommodation*> accommodations;
	vector <Host*> hosts;
	vector <Person*> people;
	vector <Customer*> customers;

	while (!inPerson.eof())
	{
		char label;
		string firstName, lastName, personID, customerUsername;
		int dayOfBirth, monthOfBirth, yearOfBirth;
		inPerson >> label;
		
		//Person* person;
		Customer* customer;
		Host* host;
		Accommodation* accomodation;

		if (label == 'C')
		{ 
			
			string creditCardNumber;
			int creditCardMonth, creditCardYear;
			inPerson >> firstName >> lastName >> personID >> dayOfBirth >> monthOfBirth >> yearOfBirth >> creditCardNumber >> creditCardMonth >> creditCardYear;
			customer = new Customer(firstName, lastName, personID, dayOfBirth, monthOfBirth, yearOfBirth, customerUsername, creditCardNumber, creditCardMonth, creditCardYear);
			customer->checkPerson();
			
			cout << "Bellow is the basic information of this customer is:" << endl;
			customer->printDataPerson();
			cout << endl << endl << *customer << endl << endl << endl << endl;
			customers.push_back(customer);
			people.push_back(customer);
		}

		else if (label == 'H')
		{
			
			string hostUsername;
			string stringLocations;
			list<string> listLocations;
			inPerson >> firstName >> lastName >> personID >> dayOfBirth >> monthOfBirth >> yearOfBirth >> stringLocations;
			listLocations.push_back(stringLocations);
			host = new Host(firstName, lastName, personID, dayOfBirth, monthOfBirth, yearOfBirth, hostUsername, listLocations);
			hostUsername = host->createHostUsername(firstName, lastName, personID);
			host->checkPerson();

			cout << "Bellow is the basic information of this host is:" << endl;
			host->printDataPerson();
			cout << "The list of locations is as follows:" << endl;
			host->showListOfLocations();
			cout << endl << endl << *host << endl << endl << endl << endl;
			hosts.push_back(host);
			people.push_back(host);
			
			
			string address;
			string reserved = "false";
			int lengthOfStay=0;
			float priceToRent=0, finalPrice=0;
			inAccommodation >> address >> reserved >> lengthOfStay >> priceToRent;
			accomodation = new Accommodation();
			finalPrice = accomodation->calculateFinalPrice(accomodation->getPriceToRent(), accomodation->getLengthOfStay());
			accomodation = new Accommodation(hostUsername, address, reserved, lengthOfStay, priceToRent, finalPrice);
			
			
			accommodations.push_back(accomodation);
		}
		else 
			cout << "There was an error in getting the information from the inputPerson file, check the labels in the inputPerson.txt file if there is a C or an H at the start!" << endl;
	}


	auto newEnd = remove_if(people.begin(), people.end(), [](Person* p1) {return !p1->checkPersonID() && !p1->checkAge(); });
	/*
	for_each(people.begin(), newEnd, [](Person* p1) {return p1->writePeople(); });
	
	cout << endl << endl << endl << "A new txt file called outputPerson.txt has been made that hopefully exluded the people with some form of invalid data." << endl;
	*/
	for (auto itr = people.begin(); itr != people.end(); itr++)
	{
		Person* pe = *itr;
		cout << pe;
	}

	people.clear();
	customers.clear();
	hosts.clear();
	accommodations.clear();
	inAccommodation.close();
	inPerson.close();
	
	system("pause");
	return 0;
	
}