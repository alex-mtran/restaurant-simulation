[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9887001&assignment_repo_type=AssignmentRepo)
# Al Dente Amore
 
 Authors: 
 \<[Scott Gonzalez Barrios](https://github.com/ShadyBarrios)\>
 \<[Annabelle Le](https://github.com/AnnabelleLLe)\>
 \<[Augustine Ayoub](https://github.com/aayou004)\>
 \<[Alexander Tran](https://github.com/atran388)\>

## Project Description
Our project, Al Dente Amore, serves as an administrative management system and customer interface for an Italian restaurant. It also allows the user to add or remove food items to a cart, view its macros, and checkout. We chose to create an online menu because it's an easily accessible way for customer to preview our menu or order from our restaurant if they choose to. On the admin side, they are able to open and close the restaurant, and edit the inventory of the ingredients and its expiration dates. By keeping track of the food inventory and expiration dates, it ensures that customers can only order from what's available in the valid ingredients.
 
Why is it important or interesting to you? It's interesting because a restaurant menu is something that we are very well acquainted with, and use often. We are also all interested in food and so this just seemed like it would align with our interests. It's a fun way for us to express our love for restaurants through a project.

What languages/tools/technologies do you plan to use? (This list may change over the course of the project) We plan to use C++ for our main language. For testing, we will use Valgrind to help test our code and spot-check errors more efficiently. Lastly, we will use git commands to help push and pull our work from the repository and use the methods taught in lab to create pull requests and branching skills so that the main branch is not affected with our individual work.

What will be the input/output of your project? Input: user input from command line file data (csv or other formats). Output: standard command line text output file data (csv or other formats)

What are the features that the project provides? Customer options to: create a cart of food orders, view order history, create accounts, remove food from cart, add food to cart, adjust the count per food item, show order receipt/ order confirmation
Administrative options to add/delete food options, display active stock of food items, items with shared ingredients impact each other's stock when ordered, view sales
Guest customer mode can be used for quick order, wont save history 

## Class Diagram
 
  \<[Link to UML (pre-SOLID)](https://docs.google.com/drawings/d/1tmDw4ST6a0OEPIa669jf099ls6TBYpku3PV4Vl3EYvM/edit)\>
  \<[Link to UML (post-SOLID)](https://docs.google.com/drawings/d/11nxvkwqatBpmCZN0MjFaYFj8OJ0UTuF2HEYt8vElkG4/edit)\>
  
  
Description of UML Diagram:
The user class has the getMenu() function so that in main we are able to repeatedly print out a menu for the user to choose their options. The derived class customerAccount will have the choices listed and the choices will call upon the functions listed under customerAccount (addToCart, removeFromCart, changeItemQuantity, calculateTotal, etc). The Goods of the cart will be stored in a vector of Goods pointers called myCart. Goods is a class that contains the name, price, and ingredients of a set number of goods that we will implement (pizza, pasta, salads). Under such goods, a set of more specific goods will be implemented (cheese pizza, combo pizza, etc). Each ingredient (mozzarella, dough, pepperoni, etc) will be written to the Ingredients.txt file each with their own expiration date. If the expiration date has passed then once the customer has finished (quit) the program, the expired ingredients will be deleted and will never be used. When the customer is adding ingredients and such, the program will call the Ingredient.txt file and look through it; if when doing so the ingredient is expired, the program will skip over it and continue searching for the desired ingredients to add to the Goods item's vector of Ingredient pointers. Upon adding a good to the cart, the ingredients that belong to that Goods item will be inUse and will be reserved, essentially invisible in the Ingredients.txt file, much like how the program treats expired goods. If they remove that specific item from their cart, its ingredients will be unreserved and no longer in use, making them able to be used once more. Under the admin account, the admin will be able to order more ingredients which will be issued its expiration date. The admin will have access to the logistics and the status of the restaurant itself. They will also be issued its own menu (one for logistics and for status respectively) and will be able to call on functions: addToStock(), open(), close(), and closePerm(). They will also be able to view the inventory. The open(), close(), and closePerm() statuses of the restaurant will be denoted by a 1, 2, or 3 in the StatusFile.csv file. If the restaurant status is 1, restaurant is open and both customer and admins alike will be able to access their options and run the program. If the restaurant status is 2, restaurant is closed and only the admin will be able to access their options and run the program. If the status is 3, then neither customer nor admin will be able to access their options, as the restaurant is closed forever.
 
 
 > ## Phase III

 >     * What SOLID principle(s) did you apply?
 Single Responsibility Principle (SRP)- we are separating the admin account logistics so that each class only has a single responsibility. We also separated functions such as addToCart and removeFromCart so that they only do that, add to the cart and remove from the cart respectively, when before they not only prompted the user to input the necessary parameters in order for the function to be called, but printed to the screen the results and changes as well as adding to the cart or removing from the cart.
 
 >     * How did you apply it? i.e. describe the change. Interface Segregation Principle 
 One for the logistics and one for the status of the restaurant. Before our admin logistics and admin status were under one class, but now it is in two different classes. The logistics class allows us to add ingredient stock, and print inventory and print finances. The status class allows us to see the status of our restaurant, in which we can open or close the restaurant. We implemented the prompt and print statements in main, leaving the functions to only access the cart and do its job.
 
 >     * How did this change help you write better code?
 This helped separate the classes to have a singular responsibilty so that only changes to one part of the software's specification should affect the specification of the class. So, if we were to change anything that has to do with logistics, it would affect the logistics class. If we were to change anything that has to do with status, it would affect the status class. It also allowed us to be able to test our code. By making the sole responsibility of the for example, addToCart function be adding a Goods pointer to the cart, it allowed us the ability to test it in our unit tests if the function is working as intended.
 

 
 > ## Final deliverable
 
 ## Screenshots
 > Our screenshots will be on this Google Docs. 
 https://docs.google.com/document/d/1111xYAoUXyNc2sVgJVKEG5tRdhHt1K6tS5UlaBjcWu4/edit?usp=sharing

 ## Installation/Usage
 > Instructions on installing and running your application
 To run the program, they would need to run the commands "cmake ." and "make" while in the src folder. Then, they would run the executable ./bin/AlDenteAmore. For our restaurant, we have a customer and admin side. The user will have to log in as either a customer or admin before starting, with username and passwords respectively being "customer", "customerPassword", "admin", "adminPassword". If the user is a customer, they will input their customer username and password to start ordering. A list of options will be shown, in which they can input "1" if they want to see the menu, "2" to add an item to their cart, "3" to remove an item, "4" to change the item quantity, "5" to print the total of the cart, "6" to view the macros of their food items, "7" to view their cart. To finish, they would input "q" to quit and so that they can see finalize their order, showing the total price of the cart including tax. As the ingredient stock and expiration date of the food could change, customers can only order food if there is enough ingredients to make the food and if the expiration dates for the ingredients are valid. With this, it ensures that the customer's food is not expired and the customers to be unable to place their order in the event that the ingredients stock for that particular menu item is too low to make. If the user is an admin, they can control the status of the restaurant (opened, closed, closed permanently) and to see/add to the inventory of the ingredients in the restaurant. They will also be able to see the expiration dates of the ingredients. 

 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
 We all created unit tests for our functions in separate test files. We checked the state of the files before and after running. We manually went through to test each function with a given edge case in mind. We also used Valgrind, in which we were able to get the Mem check clear.
