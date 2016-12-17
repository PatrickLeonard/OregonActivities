/****************************************************************************
*                                                                           *
*           Name: Patrick Leonard                                           *
*           Class: CS202 Professor Fant                                     *
*           Assignment: Program 2                                           *
*           Date: 10-30-12                                                  *
*           Filename: Link.h                                                *
*                                                                           *
*        This file declares the Link class. This class has an array of      * 
*    Activity objects as well as pointers to the next and previous link.    * 
*    Functions in the class have to do with managing itself as a node and   *
*    managing the array of Activity objects. It also compares and manages   *
*    its Interest data member and keeps track of the number of Activity     *
*    objects held by its array. It can add and delete Activity objects from *
*    the array, and keep the size of the array exact to the number of       *
*    Actibity objects. It also displays all the objects in the array.       *
*                                                                           *
*                                                                           *
****************************************************************************/ 



#ifndef LINK_H
#define LINK_H

#include "Activity.h"

//Declare class Link
class Link

	{

		private:

			Link* next;    //Pointer to the next and previous Link object

			Link* previous;

			char* interest;    //Interest member data

			Activity** activityArray;   //Pointer to an array of pointers

			int numActivities;   //Keeps track of the number of Activity objects in the array

		public:

			//Default constructor
			Link();

			//Copy constructor
			Link(const Link &source);

			//Class destructor
			~Link();
			
			//Overloaded constructor, sets the interest data member, and creates a number of defaultly constructoed 
			//Activity objects
			Link(const char inputInterest[], int numActs);

			//Sets the next pointer of the link, accepts a pointer to a Link object
			void setNext(Link* nextLink);

			//Sets the previous pointer of the link, accepts a pointer to a Link object
			void setPrevious(Link* prevLink);

			//Returns the link's next pointer
			Link* getNext();

			//Returns the link's previous pointer
			Link* getPrevious();

			//Sets the interested data member, accepts a char array as argument
			void setInterest(char input[]);

			//Adds an Activity object to the activityArray, uses the setActivity()
			void userAddActivity();

			//Removes an activity from the array that matches the input index argument
			void removeActivity(int removeIndex);

			//Accepts user input to create and Activity object, and returns a pointer to that object
			Activity* setActivity();

			//Compares the input char array argument to the interest data member
			int interestCompare(char input[]);

			//Displays the interest data member
			void displayInterest();

			//Calls the displayActivity() function of every Activity in the activityArray
			void displayActivities();

			//Creates a new character array and copies the contents of the input char array argument
			//to the newly created array, and returns a pointer to the new array
			char* arrayCopy(const char input[]);

	};	  			

#endif
