#include "Accommodation.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Accommodation::Accommodation() {};

Accommodation::Accommodation(string hostUsername, string address, string reserved, int lengthOfStay, float priceToRent, float finalPrice):Host(hostUsername)
{
	this->address = address;
	this->reserved = reserved;
	this->lengthOfStay = lengthOfStay;
	this->priceToRent = priceToRent;
	this->finalPrice = finalPrice;
	this->calculateFinalPrice(priceToRent, lengthOfStay);
	this->createReceipt(getUsername(), hostUsername, address, lengthOfStay, finalPrice);
}

void Accommodation::createReceipt(string customerUsername, string hostUsername, string address, int lengthOfStay, float finalPrice)
{
	
	string line, reservedTemp = getReserved();
	
	if (reservedTemp == "true")
	{
		fstream receipt;
		receipt.open("recepits.txt");
		if (receipt.is_open()) {
			receipt << "B&B STEFAN CLIFF\n\nThank you:" << customerUsername << "for renting out: " << this->address << " from: " << hostUsername << endl << "The B&B is yours for: " << this->lengthOfStay <<
				" days, we do hope you enjoy yourself!\n\n\n\n\nFINAL PRICE:" << this->finalPrice << ".00 euros" << endl << endl << endl << endl << endl << endl;
		}
		else cout << "Unable to open the file" << endl;
		cout << "The txt file receipts.txt has been updated" << endl << endl << endl;
		receipt.close();
	}
	
}

float Accommodation::calculateFinalPrice(float priceToRent, int lengthOfStay)
{
	return finalPrice = priceToRent * lengthOfStay;
}
int Accommodation::getLengthOfStay() { return lengthOfStay; }
float Accommodation::getPriceToRent() { return priceToRent; }
string Accommodation::getReserved() { return reserved; }

/*
void Accommodation::setAddress(string address) { this->address = address; }
void Accommodation::setReserved(bool reserved) { this->reserved = reserved; }
void Accommodation::setLengthOfStay(int lengthOfStay) { this->lengthOfStay = lengthOfStay; }
void Accommodation::setPriceToRent(float priceToRent) { this->priceToRent = priceToRent; }
void Accommodation::setFinalPrice(float finalPrice) { this->finalPrice = finalPrice; }

string Accommodation::getAddress() { return address; }
bool Accommodation::getReserved() { return reserved; }

float Accommodation::getFinalPrice() { return finalPrice; }
*/