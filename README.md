# inventory_management
 An inventory management system showcasing object-oriented programming in C++

# Requirements
Johnny is planning to expand his small bookstore to sell Compact Disks and DVDs. He needs your help. Create a program to manage Johnny's

The program must do the following:

1. Allow entering new items into the program from the keyboard - this identifies the items Johnny will sell, Book, CD, or DVD and the proper inventory record created for each one. The SKU, number on hand,
description and so-on, are initialized at this time. Some of these items will be updated when receiving an order.
BW stock Keeping Unit) is a unique item number. Do not allow the user to enter this number. They might duplicate it. Create the number inside the program. The best way would be to create a static
oblectCount variable and use that to create a new SKU.
NOTE: some data members will reside in the base class and some in the derived classes. You must provide for appropriate member functions and data.

2. Receiving an order: This means the number of items received is entered into the program along with its cost per item and other pertinent details (see below). If there is a change in the cost, the new selling price is
calculated.

3. Calculate the selling price of each item from its cost based on a markup. The markup for books is 25%, for CDs is 30% and for DVDs is 40%.
Price = Cost + Cost * percentage

4. Sell an item: On hand is checked, and if there is enough merchandise, the sale is recorded by decrementing the number on hand by the number sold, computing the total price, including sales tax at 9.25%. Use a
constant to store the tax percentage. If there is not enough inventory, sell whatever is available and issue a message.

5. Output a report of all items on hand, including their total dollar value (not total cost]. Include a warning whenever there are fewer than 10 of an item currently on hand.

For each item your inventory program must maintain the following:

1. When new items are created by using feature 1, assign an inventory number for the item.
2. For Books, maintain the title, author, and short description.

3. For CDs maintain the title, artist name, number of tracks, playing time, and genre such as: Pop, Jazz, Rock, Country, Rap, etc. Make this open ended so new classifications can be entered. A text field will do.
4. For DVDs maintain the title, director, lead actor, playing time, and genre such as: Drama, Comedy, etc.(a text field)

5. For all items, compute the price based on cost and markup, keep count of the number on hand.

The report called for by requirement 5 should output all information about each inventory item.
‘You will need to take advantage of the capabilities of C++ classes, inheritance, and polymorphism, including virtual functions.

Program Design:

1. All data members in all classes must be private.

2. Create a class called Inventory that handles the inventory. The main function calls only a member functions of this class to display a menu. The rest of the inventory management is done in this class. The other
classes (below) are never directly referred to in the main function.

3. Create a class called Item which will serve as a base class for each of the several derived classes for Johnny's merchandise. The classes Book, DVD and CD will inherit this class. The inventory class must maintain
an array of pointers to Item objects to keep the inventory. Please do not use anything more sophisticated than an array.
