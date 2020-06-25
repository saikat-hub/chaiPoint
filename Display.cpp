#include "headers/Display.h"

void Display::insufficientIngredients(Beverage curBeverage, Item curItem, string customerName){
	cout<<"Sorry "<<customerName<<"! "<<curBeverage.getName()<<" could not be prepared, because of insufficient "<<curItem.getName()<<". Please comeback later once we have refilled!\n";
}

void Display::unavailableIngredients(Beverage curBeverage, Item curItem, string customerName){
	cout<<"Sorry "<<customerName<<"! "<<curBeverage.getName()<<" could not be prepared, because "<<curItem.getName()<<" is not available. Please comeback later once we have refilled!\n";
}

void Display::preparedSuccessfully(Beverage curBeverage, string customerName){
	cout<<"Yayy "<<customerName<<"! Your "<<curBeverage.getName()<<" has been successfully prepared. Please collect the same from the counter!\n";
}
void Display::outletsFull(Beverage curBeverage, string customerName, int outlets){
	cout<<"Sheesh! We are completely swamped right now "<<customerName<<"! Kindly wait for a while, we'll prepare your "<<curBeverage.getName()<<" once any of the "<<outlets<<" outlets are availble. Thanks for understanding.\n";
}