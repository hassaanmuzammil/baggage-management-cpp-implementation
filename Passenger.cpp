#include "Passenger.h"
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;

Passenger::Passenger()
{
	baggage = new Baggage[number_bags];
}


Passenger::~Passenger()
{
}


void Passenger::setFN(string n)
{
	FN = n;
}
string Passenger::getFN()
{
	return FN;
}

void Passenger::setLN(string n)
{
	LN = n;
}
string Passenger::getLN()
{
	return LN;
}
void Passenger::setPassportNo(string p)
{
	PassportNo = p;
}
string Passenger::getPassportNo()
{
	return PassportNo;
}

string Passenger::getPassengerInfo()
{
	stringstream a;
	a << getFN() << "," << getLN() << "," << getPassportNo() << ","  << getBags() << "\n";
	for (int i = 0; i < number_bags; i++)
	{
		a << baggage[i].getBaggageInfo() << ";";
	}
	return a.str();
}

void Passenger::setBags(int b)
{
	number_bags = b;
}
int Passenger::getBags()
{
	return number_bags;
}


void Passenger::saveDataToFile(Passenger P)
{
	ofstream MyFile("Flight.txt", ios::app);

	if (MyFile.is_open())
	{
		MyFile << "\n" << P.getPassengerInfo() << "\n" << "*";
	}
}
