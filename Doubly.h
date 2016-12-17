/****************************************************************************
*                                                                           *
*           Name: Patrick Leonard                                           *
*           Class: CS202 Professor Fant                                     *
*           Assignment: Program 2                                           *
*           Date: 10-30-12                                                  *
*           Filename: Doubly.h                                              *
*                                                                           *
*     This file delcares the Doubly class. A doubly linked linear list that *
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


#ifndef DOUBLY_H
#define DOUBLY_H


#include "LinkList.h"

//Derive Doubly class from abstract Linklist class
class Doubly : public LinkList

	{

		private:

			//Pointers to first and current links in the list
			Link* first;

			Link* current;

		
		public:

			//Class constructor
			Doubly();

			//Class destructor
			~Doubly();

			//Copy constructor, takes a Doubly class object by reference as the argument
			Doubly(const Doubly &source);

			//Inserts a link into the list, and takes a pointer to a Link object as the argument
			void insertLink(Link* newLink);

			//Removes a link from the list, takes a pointer to a Link object as the argument
			//and returns a bool to confirm removal
			bool deleteLink(Link* delLink);

			//Searches the list for a link matching the input char array to the Interest member data
			//then returns a pointer to the link
			Link* search(char input[]);

			//Displays the Interest member data from every link in the list
			void displayList();

	};

#endif
