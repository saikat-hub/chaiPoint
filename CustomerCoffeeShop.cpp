#include "headers/CustomerCoffeeShop.h"

// This is the CoffeeShop class which can be thought as the shop which has multiple coffee machines, and each coffee machine can have multiple outlets to serve to its customers
CoffeeShop::CoffeeShop(){
	name = "Saikat's Coffee Shop";
	machineCount = 1;
	coffeeMachines = vector<CoffeeMachine*> {new CoffeeMachine()};
}

CoffeeShop::CoffeeShop(string coffeeShopName, CoffeeMachine *machine){
	//CoffeeShop();
	name = coffeeShopName;
	machineCount = 1;
	coffeeMachines = vector<CoffeeMachine*> {machine};
}

// Adds a coffee machine
void CoffeeShop::addCoffeeMachine(int outlets=5){
	CoffeeMachine* machine = new CoffeeMachine(outlets);
	machineCount++;
	coffeeMachines.push_back(machine);
}

// Add a custom coffee machine to our shop.
void CoffeeShop::addCoffeeMachine(CoffeeMachine *machine){
	machineCount++;
	coffeeMachines.push_back(machine);
}

// Get a random coffee machine from the shop
CoffeeMachine* CoffeeShop::getCoffeeMachine(){
	int idx=0;
	srand(time(NULL));
	idx = rand()%machineCount;
	return coffeeMachines[idx];
}


// The Customer class is used as an actor, who comes to a coffee shop and places an order randomly to any of the coffee machines
Customer::Customer(CoffeeShop shopName){
	name = "Person";
	shop = shopName;
}

Customer::Customer(string personName, CoffeeShop shopName){
	name = personName;
	shop = shopName;
}

string Customer::getName(){
	return name;
}

// submits Order to a random coffee machine in the shop
bool Customer::submitOrder(Order curOrder){
	CoffeeMachine *machine = shop.getCoffeeMachine();
	machine->addOrder(curOrder);
	return true;
}

bool Customer::startOrders(){
	CoffeeMachine *machine = shop.getCoffeeMachine();
	machine->processNextOrders();
	return true;
}
