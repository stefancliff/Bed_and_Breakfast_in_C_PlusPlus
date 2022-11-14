#pragma once
#include "Host.h"
#include "Customer.h"
#include <string>

using namespace std;

class Accommodation: public Host, public Customer
{
private:

	string address;
	string reserved="false";
	int lengthOfStay = 0;
	float priceToRent = 0;
	float finalPrice = 0;
	
public:
	
	float calculateFinalPrice(float priceToRent, int lengthOfStay);
	void createReceipt(string customerUsername, string hostUsername, string address, int lengthOfStay, float finalPrice);
	/*
	void setAddress(string address);
	void setReserved(bool reserved);
	void setLengthOfStay(int lengthOfStay);
	void setPriceToRent(float priceToRent);
	void setFinalPrice(float finalPrice);
	string getAddress();
	
	float getFinalPrice();
	*/
	string getReserved();
	int getLengthOfStay();
	float getPriceToRent();

	Accommodation();
	Accommodation(string hostUsername, string address, string reserved, int lengthOfStay, float priceToRent, float finalPrice);
};

