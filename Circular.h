/****************************************************************************
*                                                                           *
*           Name: Patrick Leonard                                           *
*           Class: CS202 Professor Fant                                     *
*           Assignment: Program 2                                           *
*           Date: 10-30-12                                                  *
*           Filename: Circular.h                                            *
*                                                                           *
*        This file declares the Circular class. A circular linked list that *
*    uses all the functions declared in the class from which it's derived,  *
*    LinkList. It does not have an special functions that would need to be  *
*    Only with dynamic binding. The standard member fucntions for a linked  *
*    list are represented: insert, delete, search, display, with copy,      *
*    normal constructors and destructor.                                    *
*                                                                           *
*                                                                           *
*                                                                           *
*                                                                           *
****************************************************************************/ 


#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "LinkList.h"

//Circular class is derived from the LinkList class
class Circular : public LinkList

	{

		private:

			//Pointer to the first and current Link in the list
			Link* first;

			Link* current;

		
		public:

			//Class constructor
			Circular();

			//Class destructor
			~Circular();

			//Copy constructor, takes a Circular class object reference as the argument
			Circular(const Circular &source);

			//Inserts a Link class object into the list, takes a pointer to the object as the argument
			void insertLink(Link* newLink);

			//Removes a Link class object from the list, takes a pointer to the obejct as the argument
			//returns a bool to confirm removal
			bool deleteLink(Link* delLink);

			//Searches the List for a Link object that matches the input interest, returns a pointer to that object
			Link* search(char input[]);

			//Display the Interested object data for every link in the list
			void displayList();

	};


#endif
