# chaiPoint
This is a low level system design for a Coffee/Chai Shop

1) To compile type:
	g++ *.cpp

2) To run this, type:
	a.exe


3) Every tests are invoked from the MainWrapper.cpp
4) Input tests in Json are included in input_data_files folder
5) This system has a CoffeeShop, which has multiple Coffee Machines
6) Each Coffee Machine has multiple outlets, from which coffee can be taken out simultaneously

7) A customer can visit a Coffee Shop and place an order. It gets randomly placed in either of the coffee machine and gets processed further accordingly. 

8) A CoffeeMachine has an IngredientDeck to keep track of ingredients, and use from it to brew coffee
9) An ingredient is basically derived from an Item. 
10) Multiple Items together composes a Beverage.
11) Multiple Beverages can be placed in an single order.
12) The coffee machine tries to brew beverages in a single order intelligently and randomly along its n outlets in parallel

13) When outlets are filled, it displays the message that all are full and then starts again later.
14) When an ingredient is lacking it displays the appropriate message about insufficiency or unavaibility.
15) We can increase/refill the Ingredient Deck accordingly.

16) Inputs are in Json files as mentioned in the problem
17) There is further scope for this, but that's all for now. 

