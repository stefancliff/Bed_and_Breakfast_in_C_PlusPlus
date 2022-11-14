#include "Host.h"
#include <iostream>
#include <string>
#include <list> 
#include <iterator> 


using namespace std;

Host::Host() {}
Host::Host(string hostUsername)
{
	this->hostUsername = hostUsername;

}


Host::Host(string firstName, string lastName, string personID, int dayBirth, int monthBirth, int yearBirth, string hostUsername, list <string> locationsList)
	:Person(firstName, lastName, personID, dayBirth, monthBirth, yearBirth)
{
	this->hostUsername = hostUsername;
	this->locationsList = locationsList;
	this->createHostUsername(firstName,lastName,personID);
}

void Host::checkPerson() 
{
	Person::checkPerson();

}

void Host::showListOfLocations()
{
	list <string> ::iterator it;
	for (it = locationsList.begin(); it != locationsList.end(); ++it)
		cout << '\t' << *it;
	cout << '\n';
}

void Host::printDataPerson()
{
	Person::printDataPerson();
	cout << "Their host username is: "<< hostUsername << endl;
}

string Host::createHostUsername(string firstName, string lastName, string personID)
{
	return hostUsername=firstName+lastName+personID+"HOST";
}
/*
void Host::setHostUsername(string hostUsername){ this->hostUsername = hostUsername;}
void Host::setLocationList(list<string> locationsList){	this->locationsList = locationsList;}
string Host::getHostUsername(){	return hostUsername;}
list<string> Host::getLocationList(){ return list<string>(locationsList);}
*/