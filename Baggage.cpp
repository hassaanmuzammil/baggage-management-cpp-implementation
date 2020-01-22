#include "Baggage.h"

Baggage::Baggage()
{
}

Baggage::~Baggage()
{
}

void Baggage::setbarcode(string code)
{
	barcode = _atoi64(code.c_str());
}

long unsigned int Baggage::getbarcode()
{
	return (rand() % 1000000000 + 99999999);
}

long unsigned int  Baggage::getbarcode(bool status)
{
	return barcode;
}

string  Baggage::getStatus()
{
	return status;
}
void  Baggage::setStatus(string s)
{
	status = s;
}

string Baggage::getBaggageInfo()

{
	stringstream a;
	a << getbarcode() << "," << transit;
	return a.str();
}

void Baggage::setweight(float w)
{
	weight = w;
}
float Baggage::getweight()
{ 
	return weight; 
}

void Baggage::checkweight(float w)
{
	if (w > 23)
	{
		cout << "Weight of Bag exceeds allowed limit!" << endl;
		cout << "1) Proceed by paying fine! " << endl;
		cout << "2) Reduce baggage weight and re-check in! " << endl;
		int choice;
		cin >> choice;
		if (choice = 1)
		{
			cout << "Fine= $" << (w - 23) * 20;
			cout << "Press Enter for paid." << endl;
		}
		if (choice = 2)
			cout << "Bag weight within range: " << endl;
	}
}