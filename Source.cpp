
/* Authors: Alison Hart & Luis Sotomayor
// SPRING 2017

 ------- Student-Rent Calculator --------

 This program reads in user inputs to calculate the cost 
of renting a home over a certain period.

*/

#include <iomanip>		// For setw
#include <string>		// For string variables
#include <iostream>		// I/O stream

using namespace std;

// Function and constant declarations 

void homepage(float n[], int lim);
float myRent();
int myLease();
float extraFees();
float insure();
void finalCalc(float n[], int lease);
void finalCalcPt2(float z[], float n[], int lease, int people);
void exitMessage();
const int LIM = 5;


// The main function contains code for entering defaults or entering new values for variables that will be
// passed into functions. It also contains the function calls.

int main()
{
	// Variable declarations

	float amenitiesFee = 20.00;
	float cableBill = 100.00;
	float waterBill = 35.00;
	float electricityBill = 100.00;
	float yardMaintain = 0.00;
	char response;
	int numOfPeople;
	float defaults[5] = { electricityBill, cableBill, waterBill, yardMaintain, amenitiesFee };		// Default values 


	homepage(defaults, LIM);		// Function call homepage - shows home interface and default values



	cout << setw(79) << "Would you like to use ALL these values? (Y/N) : ";		// Ask if the user would like to use defaults




	do		// do-while loop to check validity of reponse character
	{
		cin >> response;


		if ((response == 'Y') || (response == 'y'))		// If user says Y/y, save these values
		{
			cout << endl << setw(84) << "Great! These values will be used in the final calculation.\n" << endl;
		}

		else if ((response == 'N') || (response == 'n'))	// If user says N/n, let them enter values
		{
			char correctVar = 'n';				// Variable to initialize loop

			while ((correctVar != 'Y') && (correctVar != 'y'))	// While loop for checking if values are correct
			{
				cout << "\nPlease enter the cost of your cable/internet bill: $";		// Enter values
				cin >> cableBill;
				while (cin.fail()) {		// Check that the input value is the valid type
					cin.clear();
					cin.ignore();
					cout << "Please enter a valid cost.\n" << endl;
					cin >> cableBill;
				}

				cout << "\nPlease enter the cost of your electricity bill: $";
				cin >> electricityBill;
				while (cin.fail()) {		// Check that the input value is the valid type
					cin.clear();
					cin.ignore();
					cout << "Please enter a valid cost.\n" << endl;
					cin >> electricityBill;
				}

				cout << "\nPlease enter the cost of your water bill: $";
				cin >> waterBill;

				while (cin.fail()) {		// Check that the input value is the valid type
					cin.clear();
					cin.ignore();
					cout << "Please enter a valid cost.\n" << endl;
					cin >> waterBill;
				}

				cout << "\nPlease enter the cost of your yard maintenance: $";
				cin >> yardMaintain;

				while (cin.fail()) {		// Check that the input value is the valid type
					cin.clear();
					cin.ignore();
					cout << "Please enter a valid cost.\n" << endl;
					cin >> yardMaintain;
				}

				cout << "\nPlease enter the cost of your amenities: $";
				cin >> amenitiesFee;

				while (cin.fail()) {		// Check that the input value is the valid type
					cin.clear();
					cin.ignore();
					cout << "Please enter a valid cost.\n" << endl;
					cin >> amenitiesFee;
				}

				do
				{
					cout << endl << "Are these values correct? (Y/N)" << endl;				// Ask if values are correct
					cin >> correctVar;
				} while ((correctVar != 'Y') && (correctVar != 'y') && (correctVar != 'N') && (correctVar != 'n'));
			}

		}

		else				// If response is neither Y/y nor N/n
		{
			cout << "Please enter Y for yes and N for no." << endl;
		}

	} while ((response != 'Y') && (response != 'y') && (response != 'N') && (response != 'n'));		// Condition Expression

	cout << endl << "How many people will be contributing to the rent?" << endl;

	cin >> numOfPeople;

	while (cin.fail()) {		// Check that the input value is the valid type
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid number of people.\n" << endl;
		cin >> numOfPeople;
	}

	while (numOfPeople > 20)
	{
		cout << "The maximum number of people supported is 20. Please enter a valid input.\n";
		cin >> numOfPeople;
	}


	cout << endl << endl << "Now, let's look at rent.\n";

	float rent = myRent();			// Rent function call

	float lease = myLease();		// Lease function call

	float totalFees = extraFees();		// Fees function call

	float totalInsure = insure();		// Insurance function call

										// Update all values to split between numOfPeople

	float cableBillSplit = cableBill / numOfPeople;
	float electricityBillSplit = electricityBill / numOfPeople;
	float waterBillSplit = waterBill / numOfPeople;
	float yardMaintainSplit = yardMaintain / numOfPeople;
	float amenitiesFeeSplit = amenitiesFee / numOfPeople;
	float rentSplit = rent / numOfPeople;
	float totalFeesSplit = totalFees / numOfPeople;
	float totalInsureSplit = totalInsure / numOfPeople;

	float allValues[8] = { cableBill, electricityBill, waterBill, yardMaintain,
		amenitiesFee, rent, totalInsure, totalFees };	// Array with all 
														// entered values


	float allValuesSplit[8] = { cableBillSplit, electricityBillSplit, waterBillSplit, yardMaintainSplit,		// Array with all values divided
		amenitiesFeeSplit, rentSplit, totalInsureSplit, totalFeesSplit };										// by numOfPeople


	finalCalc(allValues, lease);		// Final calc function call
	finalCalcPt2(allValuesSplit, allValues, lease, numOfPeople);


	exitMessage(); // Exit message function call



}









// Function for the homepage interface

void homepage(float n[], int lim)
{

	string title = "Rent Calculator";
	string credit = "By Luis Sotomayor and Alison Hart";

	cout << setw(83) << "---------------------------------------------------------------"		// Prints title
		<< endl << setw(61) << title << endl
		<< setw(70) << credit << endl;
	cout << setw(83) << "---------------------------------------------------------------";

	cout << endl << endl << setw(70) << "Hello User! In order to use this rent calculator effectively, "		// Prompt user to prepare values
		<< "please prepare to enter your cost values." << endl << endl;

	cout << setw(75) << "-- Default values are displayed below --" << endl << endl;				// Show default values

	cout << setw(25) << "Electricity Bill" << setw(25) << "Cable/Internet Bill" << setw(15)		// Prints lables for default values
		<< "Water Bill" << setw(23) << "Yard Mainteinance" << setw(20) << "Amenities Fee" << endl;


	for (int i = 0; i < lim; i++)			// For loop prints out the array (default values)
	{
		cout << fixed << showpoint << setprecision(2) << setw(15) << "$" << n[i];
	}


	cout << endl << endl;

}


// Ask for monthly payment (rent)

float myRent()
{
	// Variable declarations

	float rent;
	float totalMonthlyPay;
	float rentTax;
	char choice;
	float tax;
	cout << endl << "Please enter your monthly rent payment : $";	// Prompt user

	cin >> rent;			// User enters value for rent

	while (cin.fail()) {		// Check that the input value is the valid type
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid cost.\n" << endl;
		cin >> rent;
	}

	do
	{
		cout << "\nWould you like to include taxes on the rent (Y/N)?\n";
		cin >> choice;
	} while ((choice != 'Y') && (choice != 'y') && (choice != 'N') && (choice != 'n'));

	if ((choice == 'Y') || (choice == 'y'))
	{
		cout << "\nEnter the tax percentage: ";
		cin >> tax;

		while (cin.fail()) {		// Check that the input value is the valid type
			cin.clear();
			cin.ignore();
			cout << "Please enter a valid percentage.\n" << endl;
			cin >> tax;
		}

		rentTax = rent*(tax / 100);		// Calculate tax - based on rate entered

		rent = rent + rentTax;	// Add the rent's tax value to value of rent
	}
	else
	{
		rent = rent;
	}

	cout << endl;

	return rent;			// Return rent for later use

}



// User enters int value of lease period (months)

int myLease()
{
	int lease;		// int type 

	cout << endl << "Enter the period, in months, covered by your lease : ";	// Prompt

	cin >> lease;	// User input

	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid number of months.\n" << endl;
		cin >> lease;
	}

	cout << endl;

	return lease;	// Return value of lease for later use
}

// User enters extra fees (security deposit, move-in fee, etc.)

float extraFees()
{
	char response1;	// Variable definitions
	float appFee;
	float securityDeposit;
	float moveInFee;
	float allFees;

	cout << "Do you have to pay extra fees? E.g. "		// Prompt
		<< "Security deposit, move-in fees, application fee etc... (Y/N) : ";


	do					//do-while for reading user responses
	{
		cin >> response1;
		if ((response1 == 'y') || (response1 == 'Y'))		// If user says Y/n, let them enter values
		{
			cout << "\nOkay! Please enter values below. If any fee is not applicable, enter 0.\n" << endl;	// Prompt
			cout << "Application Fee: $";

			cin >> appFee;		// User enters value for appFee

			while (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Please enter a valid cost.\n" << endl;
				cin >> appFee;
			}

			cout << "\nSecurity deposit: $";

			cin >> securityDeposit;		// User enters value for securityDeposit

			while (cin.fail()) {		// Check that the input value is the valid type
				cin.clear();
				cin.ignore();
				cout << "Please enter a valid cost.\n" << endl;
				cin >> securityDeposit;
			}

			cout << "\nMove-In Fee: $";

			cin >> moveInFee;			// User enters value for moveInFee

			while (cin.fail()) {		// Check that the input value is the valid type
				cin.clear();
				cin.ignore();
				cout << "Please enter a valid cost.\n" << endl;
				cin >> moveInFee;
			}

			allFees = appFee + securityDeposit + moveInFee;
		}

		else if ((response1 == 'n') || (response1 == 'N'))	// If user says N/n, set allFees = 0
		{
			cout << "Great!";
			allFees = 0;
		}

		else	// If user enters an invalid character
		{
			cout << "Please enter 'Y' for yes and 'N' for no : " << endl;	// Prompt correct character entry
		}

	} while ((response1 != 'n') && (response1 != 'N') && (response1 != 'y') && (response1 != 'Y')); // Checks validity of character



	return allFees;		// Return value of allFees for later use


}

// Function for user to enter value of renter's insurance

float insure()
{
	float rentersInsure;
	char response2;


	cout << endl << endl << "How about renters insurance? (Y/N) : ";	// Prompt


	do					// do-while for checking character
	{
		cin >> response2;	// User enters character

		if ((response2 == 'y') || (response2 == 'Y'))		// If user says Y/y, let them enter values
		{
			cout << endl << "Okay! Please enter the cost of your renters insurance : $";

			cin >> rentersInsure;

			while (cin.fail()) {		// Check that the input value is the valid type
				cin.clear();
				cin.ignore();
				cout << "Please enter a valid cost.\n" << endl;
				cin >> rentersInsure;
			}
		}

		else if ((response2 == 'n') || (response2 == 'N'))	// If user says N/n, set rentersInsure = 0
		{
			cout << "Great!";
			rentersInsure = 0;
		}

		else		// If value of response1 is not equal to Y/y or N/n
		{
			cout << "Please enter 'Y' for yes and 'N' for no : ";		// Prompt correct character entry
		}

	} while ((response2 != 'n') && (response2 != 'N') && (response2 != 'y') && (response2 != 'Y'));		// Checks validity of character

	return rentersInsure;		// Return rentersInsure for later use


}



// This function will show the initial entered values and complete the final rent calculation - first month,
// following months, and total cost over lease period.

void finalCalc(float n[], int lease)		// parameter types of a float array and int
{
	char x;

	cout << "\nHere are the total cost values: " << endl;




	// Display labels of first 4 values in the array n

	cout << setw(18) << "Cable Bill" << setw(18) << "Electric Bill" << setw(15) << "Water Bill" << setw(20)
		<< "Yard Maintenance" << endl;


	for (int i = 0; i < 4; i++)		// For loop prints out first 4 values in array																	
	{
		cout << fixed << showpoint << setprecision(2) << setw(11) << "$" << n[i];	// print values in array based on values of i
	}

	// Display labels of last 4 values in the array n

	cout << endl << setw(20) << "Amenities Bill" << setw(15) << "Rent Bill"
		<< setw(18) << "Insurance Cost" << setw(18) << "Additional Fees" << endl;

	for (int i = 4; i < 8; i++)		// For loop prints out last 4 values in array																		
	{
		cout << fixed << showpoint << setprecision(2) << setw(11) << "$" << n[i];	// Print values in array based on values of i
	}

	cout << endl << endl << "The period of the lease is " << lease << " months.";	// Print out value of lease

	cout << endl << endl;

	cout << "Enter any character to continue: ";		// Prompt user
	cin >> x;
	cout << endl;
}

//----------------------------------------------------------
//----------------------------------------------------------


void finalCalcPt2(float z[], float n[], int lease, int people)
{
	float B = 0;
	int squareft;
	double allTheStuff1 = 0;
	double allTheStuff = 0;
	char x;
	char r;
	float A[20];
	float newRent[20];
	float finalArray1[20];
	float finalArray[20];

	//------ This do-while loop asks the user if they want to split the rent cost based 
	//------ on room size

	do
	{
		cout << "Would your like to distribute the shares of rent based on individual room size? (Y/N)\n";		// Prompt
		cin >> r;
		if ((r == 'Y') || (r == 'y'))	// If-statement for checking user response
		{

			for (int y = 0; y < people; y++)		// Assuming number of people = room number
			{
				cout << "\nWhat is the square footage of room " << (y + 1) << "?\n";
				cin >> squareft;

				while (cin.fail()) {		// Check that the input value is the valid type
					cin.clear();
					cin.ignore();
					cout << "Please enter a valid number.\n" << endl;
					cin >> squareft;
				}

				A[y] = squareft;	// Create array with square footage values
			}
			for (int i = 0; i <= (people - 1); i++)	// Adds square footage
			{
				B = B + A[i];
			}

			cout << endl << "The total square footage is " << B << " sq ft." << endl << endl;

			for (int i = 0; i <= (people - 1); i++)		// Calculates the price of rent based on room size
			{
				newRent[i] = static_cast <float> (A[i]) * n[5] / B;
				cout << "The price of room " << i + 1 << " is $" << fixed << setprecision(2) << newRent[i] << endl << endl;
			}


			cout << "\nHere are the cost values each person will pay: " << endl;

			for (int i = 0; i <= (people - 1); i++)		// For loop that prints out values for each person based on room number
			{
				cout << "Room " << i + 1 << ":" << endl;	// prints out room number i+1 (i starts at 0)

				z[5] = newRent[i];		// Sets index 5 in z to the newRent value

				cout << setw(18) << "Cable Bill" << setw(18) << "Electric Bill" << setw(15) << "Water Bill" << setw(20)
					<< "Yard Maintenance" << endl;


				for (int i = 0; i < 4; i++)		// For loop prints out first 4 values in array																	
				{
					cout << fixed << showpoint << setprecision(2) << setw(11) << "$" << z[i];	// print values in array based on values of i
				}



				// Display labels of last 4 values in the array n

				cout << endl << setw(20) << "Amenities Bill" << setw(14) << "Rent Bill"
					<< setw(18) << "Insurance Cost" << setw(19) << "Additional Fees" << endl;

				for (int i = 4; i < 8; i++)		// For loop prints out last 4 values in array																		
				{
					cout << fixed << showpoint << setprecision(2) << setw(11) << "$" << z[i];	// Print values in array based on values of i
				}

				cout << endl << endl;

				for (int x = 0; x < 8; x++)		// This for loop adds each value in array n together sets this value equal to variable allTheStuff1
				{
					allTheStuff1 += z[x];
					finalArray1[i] = allTheStuff1;
				}

				for (int x = 0; x < 7; x++)		// This for loop adds indexes 0-5 in array n together and sets this value equal to variable allTheStuff
				{
					allTheStuff += z[x];		// This value does not include fees and insurance
					finalArray[i] = allTheStuff;
				}
				allTheStuff1 = 0;
				allTheStuff = 0;
			}


			cout << "Enter any character to continue: ";		// Prompt user

			cin >> x;

			// Display final calculations

			cout << "\nDuring the first month, the total payments will be:" << endl;

			for (int i = 0; i <= (people - 1); i++)		// For loop that prints out initial monthly calculations for each room/person
			{
				cout << "Person staying in Room " << i + 1 << ":  $" << finalArray1[i] << endl;
			}

			// Uses variable allTheStuff1

			cout << endl << "After this, the monthly payments will be:" << endl;	// Lable

			for (int i = 0; i <= (people - 1); i++)		// For loop that prints out monthly calculations for each room/person
			{
				cout << "Person staying in Room " << i + 1 << ":  $" << finalArray[i] << endl;
			}

			cout << endl << endl;

			cout << "The total cost for each person over the period of the lease will be: " << endl;

			for (int i = 0; i <= (people - 1); i++)		// For loop that prints out TOTAL AMOUNT per room/person over the lease period
			{
				cout << "Person staying in Room " << i + 1 << ":  $" << finalArray[i] * lease << endl;
			}
		}
		else if ((r == 'N') || (r == 'n'))				// If user response is N/n to splitting cost based on room size
		{
			cout << "\nHere are the cost values for each person: " << endl;

			// Display labels of first 4 values in the array n

			cout << setw(15) << "Cable Bill" << setw(25) << "Electric Bill" << setw(15) << "Water Bill" << setw(25)
				<< "Yard Maintenance" << endl;


			for (int i = 0; i < 4; i++)		// For loop prints out first 4 values in array																	
			{
				cout << fixed << showpoint << setprecision(2) << setw(11) << "$" << z[i];	// print values in array based on values of i
			}

			// Display labels of last 4 values in the array n

			cout << endl << setw(20) << "Amenities Bill" << setw(15) << "Rent Bill"
				<< setw(20) << "Insurance Cost" << setw(25) << "Additional Fees" << endl;

			for (int i = 4; i < 8; i++)		// For loop prints out last 4 values in array																		
			{
				cout << fixed << showpoint << setprecision(2) << setw(11) << "$" << z[i];	// Print values in array based on values of i
			}

			cout << endl;

			for (int i = 0; i < 8; i++)		// This for loop adds each value in array n together sets this value equal to variable allTheStuff1
			{
				allTheStuff1 += z[i];
			}

			for (int i = 0; i < 7; i++)		// This for loop adds indexes 0-5 in array n together and sets this value equal to variable allTheStuff
			{
				allTheStuff += z[i];		// This value does not include fees and insurance
			}

			cout << "Enter any character to continue: ";		// Prompt user

			cin >> x;

			// Display final calculations

			cout << "\nDuring the first month, each person will pay a total of $" << allTheStuff1 << endl; // Uses variable allTheStuff1

			cout << "After this, each person will pay $" << allTheStuff << " to contribute equally to the total monthly costs."	// Uses variable allTheStuff 
				<< endl;

			cout << "The total cost for each person over the period of the lease will come to: $" << allTheStuff1 + (allTheStuff*lease) << ".";	// Adds allTheStuff1 and 
																																				// allTheStuff*lease period 
																																				// to get total cost over lease

			cout << endl << endl;

		}
		else
		{
			cout << "Please enter a valid (y/n) response." << endl;
		}
	} while ((r != 'Y') && (r != 'y') && (r != 'N') && (r != 'n'));


}





// Function for exit message to user

void exitMessage()
{
	cout << setw(83) << "---------------------------------------------------------------" << endl;
	cout << setw(90) << "Thanks so much for using this rent calculator! We hope you enjoy your new home.\n" << endl;
}

// END OF PROGRAM
