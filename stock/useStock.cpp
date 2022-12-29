// stock.cpp : Defines the entry point for the application.
// Compile with stock.cpp

#include <iostream>
#include "stock.h"

using std::cout;
using std::ios_base;

const int stks = 4;

int main() {
	// Create an array of initialized objects
	Stock stocks[stks] = {
		Stock("Tesla", 12, 700.0),
		Stock("Amazon", 200, 130.14),
		Stock("Google", 130, 102.25),
		Stock("Microsoft", 60, 113.5)
	};

	// Update Price
	{
		Stock meta("Meta", 10, 99.0);
		meta.update(100.0);
	}

	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);

	// List all holdings
	cout << "Stock Holdings:\n";
	int st;
	for (st = 0; st < stks; st++) {
		stocks[st].show();
	}

	// Find most valuable holding
	Stock top = stocks[0];
	for (st = 1; st < stks; st++) {
		top = top.topval(stocks[st]);
	}
	cout << "\n** Most valuable holding **\n";
	top.show();

	return 0;
}