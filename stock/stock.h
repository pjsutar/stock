// stock.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <string>

class Stock {
private:
	std::string company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }

public:
	Stock(); // default constructor
	Stock(const std::string co, int n = 0, double pr = 0.0); // constructor
	~Stock(); // do-nothing destructor
	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	void show();
	const Stock& topval(const Stock& s) const;
};