// stock.cpp : Implementing the Stock class member functions

#include <iostream>
#include <string>
#include "stock.h"

// constructors
// default constructor

Stock::Stock() {
	std::cout << "Default constructor called\n";
	company = "Unnamed";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string co, int n, double pr) {
	std::cout << "Constructing stock for \'" << co << "\'...\n";
	company = co;
	
	if (n < 0) {
		std::cerr << "Number of shares can not be negative;" 
			<< company << "shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;

	share_val = pr;
	set_tot();
}

// class destructor

Stock::~Stock() {
	std::cout << "Destructing stock: \'" << company << "\'...\n";
}

void Stock::buy(int num, double price) {
	if (num < 0) {
		std::cout << "Number of shares purchased can not be negative; "
			<< "Transaction is aborted.\n";
	}
	else {
		shares += num;
		share_val = price;
		set_tot();
		std::cout << "Purchased " << num << " shares of " << company << ".\n";
	}
}

void Stock::sell(int num, double price) {
	if (num < 0) {
		std::cerr << "Number of shares sold can not be negative; "
			<< "Transaction is aborted.\n";
	}
	else if (num > shares) {
		std::cerr << "You can not sell more than you have! "
			<< "Transaction is aborted.\n";
	}
	else {
		shares -= num;
		share_val = price;
		set_tot();
		std::cout << "Sold " << num << " stocks of " << company << ".\n";
	}
}

void Stock::update(double price) {
	double* ppr = new double;
	*ppr = share_val;
	share_val = price;
	set_tot();
	std::cout << "Updated price of " << company << " stock from $"
		<< *ppr << " to $" << price << "\n";
	delete ppr;
}

void Stock::show() {
	std::cout << "Company: " << company << "\n"
		<< "Shares: " << shares << "\n"
		<< "Share Price: $" << share_val << "\n"
		<< "Total Worth: $" << total_val << "\n";
}

const Stock& Stock::topval(const Stock& s) const {
	if (s.total_val > total_val) {
		return s;
	}
	else
		return *this;
}
