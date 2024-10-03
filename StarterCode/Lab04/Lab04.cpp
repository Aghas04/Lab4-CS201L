#include <iostream>
#include <string>
#include "Functions.h"
using namespace std;

int main() {
	float accountValue = 0.0f,number, intrestRate,loanAmount, borrow;
	char choice;
	int credit, months;
	string askUserDeposit = "Enter amount you want to depost: ", askUserWithdraw = "Enter amount you want to Withdraw: ";
	
	while (true) {
		choice = mainMenu();
		if (choice == 'D') {
			number = getValue(askUserDeposit);
			deposit(accountValue, number);
			outputAccount(accountValue);
		}
		else if (choice == 'W') {
			number = getValue(askUserWithdraw, accountValue);
			withdraw(accountValue, number);
			outputAccount(accountValue);
		}
		else if (choice == 'L') {
			credit = getCreditRating();
			months = GetLoanMonths();
			intrestRate = getIntrestRate(credit);
			cout << "How much do you want to borrow? ";
			cin >> borrow;
			loanAmount = calculateLoanAmount(borrow, intrestRate, months);
			cout << endl << endl << "Intrest Rate : " << intrestRate << endl << "Principal : " << borrow << endl << "Months : " << months << endl;
			cout << "Your total loan amount is " << loanAmount << endl;

		}
		else if (choice == 'Q') {
			break;
		}
	}
}