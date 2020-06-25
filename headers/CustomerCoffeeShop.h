#include "CoffeeMachine.h"

#ifndef CUSTOMER_COFFEE_SHOP_H
#define CUSTOMER_COFFEE_SHOP_H

// This is the CoffeeShop class which can be thought as the shop which has multiple coffee machines, and each coffee machine can have multiple outlets to serve to its customers
class CoffeeShop{
	private:
		string name;
		int machineCount;
		vector<CoffeeMachine*> coffeeMachines;
	public:
		CoffeeShop();
		CoffeeShop(string coffeeShopName, CoffeeMachine *machine);

		void addCoffeeMachine(int outlets);

		void addCoffeeMachine(CoffeeMachine *machine);

		CoffeeMachine* getCoffeeMachine();
};

// The Customer class is used as an actor, who comes to a coffee shop and places an order randomly to any of the coffee machines
class Customer{
	private:
		string name;
		CoffeeShop shop;
	public:
		Customer(CoffeeShop shopName);
		Customer(string personName, CoffeeShop shopName);
		string getName();

		// submits Order to a random coffee machine in the shop
		bool submitOrder(Order curOrder);

		// Actually starts all the orders
		bool startOrders();

};
#endif