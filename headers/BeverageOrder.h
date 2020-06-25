/*
Use enum status of order
*/
#include <bits/stdc++.h>
#include "ItemIngredient.h"
//#include "ItemIngredient.h"
//using namespace std;
// class Beverage is used to store the ingredients needed to prepare a beverage

#ifndef BEVERAGE_ORDER_H
#define BEVERAGE_ORDER_H

class Beverage{
	private:
		int itemCount;
		string name;
		vector<Item> requiredItems;

	public:
		Beverage();

		Beverage(string beverageName, Item curItem);

		string getName();
		void setName(string beverageName);
		int getItemCount();

		void addItem(Item curItem);

		vector<Item> getItems();
};

// The Order class, is used to track the beverages asked in this order
class Order{
	private:
		int orderStatus;
		int beverageCount;
		vector<Beverage> beverages;
		string customerName;

		// To complete the order, we also set its status to completed
		bool completeOrder();

	public:
		Order();

		// If it has only one beverage, we want to override the constructor to initializing it with the single beverage for convenience
		Order(Beverage curBeverage);
		Order(string name, Beverage curBeverage);
		string getCustomerName();
		int getBeverageCount();
		void addBeverage(Beverage curBeverage);
		vector<Beverage> getBeverages();
};


//Class goes here, full declaration AND implementation

#endif