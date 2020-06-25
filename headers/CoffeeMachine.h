#include "ItemIngredient.h"
#include "BeverageOrder.h"
#include "Display.h"

#ifndef COFFEE_MACHINE_H
#define COFFEE_MACHINE_H

class CoffeeMachine{
	private:
		int outlets;
		int preparationTime;
		IngredientDeck ingredientDeck;
		vector<Order> upcomingOrders;
		vector<Order> unfulfilledOrders;
		vector<Order> completedOrders;

		volatile int outletsUsed;
		Display displayer;

	public:
		CoffeeMachine();

		// Setting the outlet count
		CoffeeMachine(int n);

		// To get the ingredient deck
		IngredientDeck getIngredientDeck();

		// Updates the ingredient in the ingredient deck (It updates the value with additional amount, if that item was already present)
		bool updateIngredientDeck(Ingredient curIngredient);

		// Adds a order into the list of upcoming order
		void addOrder(Order curOrder);

		// Returns if there is any order left to process
		bool hasUpcomingOrder();

		// Simply Brews the order
		void brewBeverage(Beverage curBeverage);

		// Fix IT SAIKAT - add the final list of beverages int a order into respective places 
		bool checkOrderAndBrew(Order curOrder);

		// Selects a random order from the list of upcoming orders, and tries to process it.
		bool processNextOrders();

};
#endif