#include "headers/CoffeeMachine.h"

/*
1) Think about Preparation time
2) How to return enum type from processOrder
3) Should I include bits/stdc++.h from every file?
4) http://www.cplusplus.com/reference/mutex/mutex/lock/
5) Fix completeOrders
6) https://stackoverflow.com/questions/19549793/c-classes-in-separate-file
*/

CoffeeMachine::CoffeeMachine(){
	outlets = 5;
	outletsUsed = 0;
	preparationTime = 5;
	displayer = Display();
	ingredientDeck = IngredientDeck();
}

// Setting the outlet count
CoffeeMachine::CoffeeMachine(int n){
	outlets = n;
	outletsUsed = 0;
	preparationTime = 5;
	displayer = Display();
	ingredientDeck = IngredientDeck();
}

// Updates the ingredient in the ingredient deck (It updates the value with additional amount, if that item was already present)
IngredientDeck CoffeeMachine::getIngredientDeck(){
	return ingredientDeck;
}
// Updates the ingredient in the ingredient deck (It updates the value with additional amount, if that item was already present)
bool CoffeeMachine::updateIngredientDeck(Ingredient curIngredient){
	return ingredientDeck.addIngredient(curIngredient);
}

// Adds a order into the list of upcoming order
void CoffeeMachine::addOrder(Order curOrder){
	upcomingOrders.push_back(curOrder);
	//processNextOrders();
}

// Returns if there is any order left to process
bool CoffeeMachine::hasUpcomingOrder(){
	if (upcomingOrders.size()>0)
		return true;
	else
		return false;
}

// FIX IT SAIKAT
void CoffeeMachine::brewBeverage(Beverage curBeverage){
	// Now make the beverage
	vector<Item> requiredItems = curBeverage.getItems();
	for (int j=0; j<curBeverage.getItemCount(); j++){
		Item curItem = requiredItems[j];
		ingredientDeck.useFromIngredients(curItem);
	}
	// Display that this beverage was brewed successfully
}

// Fix IT SAIKAT - add the final list of beverages int a order into respective places 
bool CoffeeMachine::checkOrderAndBrew(Order curOrder){
	int i=0, j=0, len=0;
	string customerName = curOrder.getCustomerName();
	vector<Beverage> pendingBeverages = curOrder.getBeverages();
	
	
	vector<Beverage> completedBeverages;
	vector<Beverage> unfullfilledBeverages;
	for (i=0; i<curOrder.getBeverageCount(); i++){
		
		Beverage curBeverage = pendingBeverages[i];
		vector<Item> requiredItems = curBeverage.getItems();
		for (j=0; j<curBeverage.getItemCount(); j++){
			
			Item curItem = requiredItems[j];
			if (ingredientDeck.hasItem(curItem)==false){
				// Display Inavailibility
				displayer.unavailableIngredients(curBeverage, curItem, customerName);
				break;
			}
			else if (ingredientDeck.hasIngredientAmount(curItem)==false){
				// Display insufficiency
				displayer.insufficientIngredients(curBeverage, curItem, customerName);
				break;
			}
		}
		if (j<curBeverage.getItemCount()){
			unfullfilledBeverages.push_back(curBeverage);
			// No need to display any further
		}
		else{ 
			// Now make the beverage, since everything seems fine
			outletsUsed++;
			if (outletsUsed==outlets){
				// Display a message and wait for 5 seconds
				displayer.outletsFull(curBeverage, customerName, outlets);
				outletsUsed = 0;
			}
			brewBeverage(curBeverage);
			// Display that this beverage was brewed successfully
			completedBeverages.push_back(curBeverage);
			displayer.preparedSuccessfully(curBeverage, customerName);
		}
	}

	return true;
	/*
	Handle the orders of beverages that are completed successfully and unsuccessfully into the respective ORDERS list
	*/
}

// Selects a random order from the list of upcoming orders, and tries to process it until no orders are pending.
bool CoffeeMachine::processNextOrders(){
	if (hasUpcomingOrder()==false)
		return false;

	srand(time(NULL));

	int size=0, idx=0;
	Order curOrder;
	bool processStatus;
	while (hasUpcomingOrder()){
		
		size = upcomingOrders.size();
		
		idx = rand()%size;
		curOrder = upcomingOrders[idx];
		if (idx!=size-1)
			swap(upcomingOrders[idx], upcomingOrders[size-1]);
		processStatus = checkOrderAndBrew(curOrder);
		upcomingOrders.pop_back();
		
		//if (processStatus==1)  // We can handle accordingly
		//	return true;
	}
	return true;
}
