#pragma once
#include <string>
#include <list> 
#include <iterator> 
#include "Person.h"

using namespace std;

class Host : public Person 
{
private:
	string hostUsername;
	list <string> locationsList;
public:
	void showListOfLocations();
	virtual void printDataPerson() override;
	void checkPerson();
	/*
	void setHostUsername(string hostUsername);
	void setLocationList(list <string> locationsList);
	string getHostUsername();
	list <string> getLocationList();
	*/
	string createHostUsername(string firstName, string lastName, string personID);

	Host();
	Host(string hostUsername);
	Host(string firstName, string lastName, string personID, int dayBirth, int monthBirth, int yearBirth, string hostUsername, list <string> locationsList);

};

