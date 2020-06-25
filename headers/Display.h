#include "ItemIngredient.h"
#include "BeverageOrder.h"

#ifndef DISPLAY_H
#define DISPLAY_H

class Display{
	public:
		Display(){}
		void insufficientIngredients(Beverage curBeverage, Item curItem, string customerName);
		void unavailableIngredients(Beverage curBeverage, Item curItem, string customerName);
		void preparedSuccessfully(Beverage curBeverage, string customerName);
		void outletsFull(Beverage curBeverage, string customerName, int outlets);
};

#endif