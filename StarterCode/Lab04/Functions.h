#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;


char mainMenu() {
	
	cout << "Main Menu (Enter one of the following)" << endl;
	cout << setfill(' ') << setw(45) << right << "(D)eposit,(W)ithdrawal,(L)oan or (Q)uit" << endl;
	char choice;
	cout << "pick a choice: ";
	cin >> choice;
	while ((choice != 'd' && choice != 'D') && (choice != 'w' && choice != 'W') && (choice != 'l' && choice != 'L') && (choice != 'q' && choice != 'Q')) {
		cout << setfill(' ') << setw(45) << right << "(D)eposit,(W)ithdrawal,(L)oan or (Q)uit" << endl;
		cout << "pick a choice: ";
		cin >> choice;
	}

	return toupper(choice);
}

float getValue(string askUser) {
	float number;
	cout << askUser << endl;
	cin >> number;
	while (number < 0) {
		cout << "number has to be bigger than 0" << endl;
		cout << "Enter a number: ";
		cin >> number;
	}
	return number;
}

float getValue(string askUser, float upperLimit) {
	cout << askUser << endl;
	float amount;
	cout << "enter a amount: ";
	cin >> amount;
	while ((amount < 0) || (amount > upperLimit)) {
		cout << "value has to be less than balance and more than 0" << endl;
		cout << "enter a amount: ";
		cin >> amount;
	}
	return amount;
}

float getIntrestRate(int creditScore) {
	float intrest;
	if (creditScore <= 500) {
		intrest = .05;
	}
	else if ((creditScore > 500) && (creditScore <= 700)) {
		intrest = .03;
	}
	else if (creditScore > 700) {
		intrest = .01;
	}
	return intrest;
}

void withdraw(float& account, float amount) {
	account = account - amount;

}

int GetLoanMonths() {
	int loanMonths;
	cout << "Enter months for loans(12, 24, 36 or 60 months)" << endl;
	cin >> loanMonths;
	cout << endl;
	while ((loanMonths != 12) && (loanMonths != 24) && (loanMonths != 36) && (loanMonths != 60)) {
		cout << "invalid input" << endl;
		cout << "Enter months for loans(12, 24, 36 or 60 months): ";
		cin >> loanMonths;
		cout << endl;
	}
	return loanMonths;
}

int getCreditRating() {
	int rating;
	cout << "enter a credit rating: " << endl;
	cin >> rating;
	while ((rating < 300) || (rating > 850)) {
		cout << "value has to be between 300-850" << endl;
		cout << "enter a credit rating: " << endl;
		cin >> rating;
	}
	return rating;
}

float calculateLoanAmount(float mainAmount,float intrestRate, int months) {
		float amount;
		amount = mainAmount * pow((1 + (intrestRate / 12)), (months / 12));
		return amount;
}

void outputAccount(float amount) {
	cout << endl << "Summary of Account" << endl;
	cout << "    Amount $ " << amount << endl << endl;

}

void deposit(float& account, float amount) {
	account = account + amount;

}