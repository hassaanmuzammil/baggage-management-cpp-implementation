#pragma once
#include<sstream>
#include<string>
#include<iostream>
#include"Baggage.h"
using namespace std;

class Passenger 
{
	
	string FN;
	string LN;
	string PassportNo;
	int number_bags;

public:
	Baggage *baggage;
	Passenger();
	~Passenger();
	void setFN(string);
	string getFN();
	void setLN(string);
	string getLN();
	void setPassportNo(string);
	string getPassportNo();
	void setBags(int);
	int getBags();
	
	string getPassengerInfo();
	void saveDataToFile(Passenger);
};