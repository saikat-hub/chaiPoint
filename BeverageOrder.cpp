/*
Use enum status of order
*/
//#include "headers/ItemIngredient.h"
#include "headers/BeverageOrder.h"
//using namespace std;
// class Beverage is used to store the ingredients needed to prepare a beverage

Beverage::Beverage(){
	itemCount = 0;
	name = "";
	requiredItems = vector<Item> ();
}

Beverage::Beverage(string beverageName, Item curItem){
	itemCount = 0;
	name = beverageName;
	requiredItems = vector<Item> ();
	addItem(curItem);
}

string Beverage::getName(){
	return name;
}

void Beverage::setName(string beverageName){
	name=beverageName;
}
int Beverage::getItemCount(){
	return itemCount;
}

void Beverage::addItem(Item curItem){
	itemCount++;
	requiredItems.push_back(curItem);
}

vector<Item> Beverage::getItems(){
	return requiredItems;
}

// The Order class, is used to track the beverages asked in this order

Order::Order(){
	orderStatus = 0;		// FIX IT SAIKAT, later. Using enums
	beverageCount = 0;
	beverages = vector<Beverage> ();
	customerName = "Saikat";
}

// If it has only one beverage, we want to override the constructor to initializing it with the single beverage for convenience
Order::Order(Beverage curBeverage){
	orderStatus = 0;		// FIX IT SAIKAT, later Using enums
	beverageCount = 1;
	beverages = vector<Beverage> {curBeverage};
	customerName = "Saikat";
}

Order::Order(string name, Beverage curBeverage){
	orderStatus = 0;		// FIX IT SAIKAT, later Using enums
	beverageCount = 1;
	beverages = vector<Beverage> {curBeverage};
	customerName = name;
}

string Order::getCustomerName(){
	return customerName;
}

int Order::getBeverageCount(){
	return beverageCount;
}

bool Order::completeOrder(){
	orderStatus = 1;
	return true;
}
void Order::addBeverage(Beverage curBeverage){
	beverageCount++;
	beverages.push_back(curBeverage);
}

vector<Beverage> Order::getBeverages(){
	return beverages;
}

