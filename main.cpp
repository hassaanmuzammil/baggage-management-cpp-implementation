#include"Passenger.h"
#include"Baggage.h"
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>

void getBaggageStatus(string status, string file)
{
	ifstream inFile;
	string line;
	Passenger myPassenger;

	inFile.open(file);

	cout << "Barcode   - Status" << endl;

	while (inFile.good())
	{
		//read firstname
		getline(inFile, line, ',');
		myPassenger.setFN(line);

		//read last name
		getline(inFile, line, ',');
		myPassenger.setLN(line);

		//read passport number
		getline(inFile, line, ',');
		myPassenger.setPassportNo(line);

		//read number of bags
		getline(inFile, line, '\n');
		//converting the string to int
		int noBags = atoi(line.c_str());
		myPassenger.setBags(noBags);

		//initialize the baggage object
		if (noBags > 0)
		{
			myPassenger.baggage = new Baggage[noBags];

			for (int k = 0; k < noBags; k++)
			{
				//read baggage barcode 
				getline(inFile, line, ',');
				myPassenger.baggage[k].setbarcode(line);

				getline(inFile, line, ';');
				myPassenger.baggage[k].setStatus(line);

			}

		}
		//ignore the '*' in the file
		getline(inFile, line);

		for (int j = 0; j < noBags; j++)
		{
			if (myPassenger.baggage[j].getStatus() == status)
			{
				cout << myPassenger.baggage[j].getbarcode(false) << " - ";
				cout << myPassenger.baggage[j].getStatus() << endl;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	int choice = 0; 
	while (choice != 5){
		
		system("cls");
		cout << "\t\t*******Login to Islamabad International Airport Baggage Handling System*******\n\n" << endl;
		//this will repeat until user press 5
		Passenger P1;
		string userInput;
		int numberofBags;
		float bagWeight;
		ifstream inFile;
		string line, search;

		cout << " 1)  *Passenger check-in*  " << endl;
		cout << " 2)  *View baggage in transit*  " << endl;
		cout << " 3)  *Report Missing bag* " << endl;
		cout << " 4)  *View Delivered Baggage* " << endl;
		cout << " 5)  *EXIT* " << endl;
		cin >> choice;

		switch (choice){
			case 1:
				cout << endl << " *****PASSENGER DATA ENTRY***** " << endl;
				cout << " First Name:  ";
				cin >> userInput;
				P1.setFN(userInput);

				cout << " Last Name:  ";
				cin >> userInput;
				P1.setLN(userInput);

				cout << " Passport No: ";
				cin >> userInput;
				P1.setPassportNo(userInput);

				cout << " Number of bags to be checked-in:  ";
				cin >> numberofBags;
				P1.setBags(numberofBags);

				if (numberofBags > 0)
				{
					Baggage *bag = new Baggage[numberofBags];
					for (int i = 0; i < numberofBags; i++)
					{
						cout << "Enter Baggage Weight: ";
						cin >> bagWeight;
						bag->setweight(bagWeight);
					}

					P1.baggage = bag;

				}
				cout << P1.getPassengerInfo();
				P1.saveDataToFile(P1);

				cout << endl;
				system("pause");
				break;
			case 2:
				cout << "\n\n *****View Baggage In Transit*****" << endl;

				//moved this to a function
				getBaggageStatus("Transit", "Flight.txt");
				
				cout << endl;
				system("pause");
				break;
			case 3:
				//this feature is applicable when a baggage agent or a customer 
				//tells that he lost a bag
				cout << "\n\n *****REPORT MISSING BAGGAGE*****" << endl;
				inFile.open("Lost and Found.txt");

				if (!inFile){
					cout << "Unable to open file" << endl;
					exit(1);
				}
				cout << "Enter Bag Barcode: ";
				cin >> search;

				size_t pos;
				while (inFile.good())
				{
					getline(inFile, line); // get line from file
					pos = line.find(search); // search
					if (pos != string::npos) // string::npos is returned if string is not found
					{
						cout << "Bag Found!" << endl;
						break;
					}
					else
					{
						ofstream inFile;
						inFile.open("Lost and Found.txt",ios::app);
						inFile << "\n" << search;
						cout << "Bag added to missing list! " << endl;
						break;
					}
				}
				cout << endl;
				system("pause");
				break;
			case 4:
				cout << "\n\n *****View Delivered Baggage*****" << endl;

				//moved this to a function
				getBaggageStatus("Delivered", "Flight.txt");

				cout << endl;
				system("pause");
				break;
		}//end switch
	}//end while 

	system("pause");
	return 0;
 }

