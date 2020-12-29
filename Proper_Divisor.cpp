//Author: Mark McCarthy
//Date: 12/28/2020

/*This program takes a number n as input and returns
 the sum of the base 10 log of all proper divisors of 
 the input.*/
#include <math.h>
#include<vector>
#include<iostream>

using namespace std;

/*This function takes an int i, checks if it is a 
divisor of the second input n and returns a bool if 
i is a divisor of n*/
bool divisor(int i, int n);

int main() {

	//declare needed containers
	int n;
	long double total = 0.0;
	vector<long double> div_list;

	//prompt user for input
	cout << "Please enter a number." << endl;
	cin >> n;

	//This loop checks if each of the integers up to 
	// n/2 are proper divisors of n
	for (int i = 1; i <= (n / 2); i++) {

		//if the divisor function returns true
		// then i is a divisor and we add it to 
		// the divisor list
		if (divisor(i, n))
			div_list.push_back(i);
	}

	//this loop outputs the divisors
	cout << "The divisors of your number are: ";
	for (int i = 0; i < div_list.size(); i++) {
		cout << div_list[i] << ", ";
	}
	cout << endl;

	//This loop takes each of the elts of the 
	// divisor list and replaces it with its log
	for (int i = 0; i < div_list.size(); i++) {
		div_list[i] = log10(div_list[i]);
	}

	// this loop outputs the log of the divisors
	cout << "The log of the divisors are: ";
	for (int i = 0; i < div_list.size(); i++) {
		cout << div_list[i] << ", ";
	}
	cout << endl;

	//This loop sums all of the elts in the divisor list
	for (int i = 0; i < div_list.size(); i++) {
		total = total + div_list[i];
	}

	//output statement 
	cout << "The sum of the log of all proper divisors \n"
		"of your number is. \n";
	cout << total << endl;
	
	return 0;
}

//The divisor function takes an int i and an int n
//then returns a bool if i is a proper divisor of n
//function utilizes the ternary operator
bool divisor(int i, int n) { return n % i != 0 ? false : true; }


