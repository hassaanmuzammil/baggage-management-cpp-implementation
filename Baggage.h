#pragma once
#include<sstream>
#include<string>
#include<iostream>

using namespace std;
class Baggage
{
	int weight;
	long unsigned int barcode;
	string status;
	string transit = "Transit";

public:
	Baggage();
	~Baggage();
	void setweight(float);
	float getweight();
	
	void setStatus(string);
	string getStatus();
	long unsigned int getbarcode();
	long unsigned int getbarcode(bool);
	void setbarcode(string);

	void checkweight(float);
	string getBaggageInfo();
};

