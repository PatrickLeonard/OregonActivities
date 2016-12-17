/****************************************************************************
*                                                                           *
*           Name: Patrick Leonard                                           *
*           Class: CS202 Professor Fant                                     *
*           Assignment: Program 2                                           *
*           Date: 10-30-12                                                  *
*           Filename: Linear.h                                              *
*                                                                           *
*        This file declares the Linear class. A linear linked list that     *
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


#ifndef LINEAR_H
#define LINEAR_H

#include "LinkList.h"

//Derive Linear class from LinkList abstract class
class Linear : public LinkList

	{

		private:

			//Pointers to the first and current links in the list
			Link* first;

			Link* current;			

		public:

			//Class contructor
			Linear();

			//Class destructor
			~Linear();

			//Copy constructor, takes a Linear class reference as an argument
			Linear(const Linear &source);

			//Inserts a link into the list, takes a link pointer as argument
			void insertLink(Link* newLink);

			//Deletes a link from the list, returns a boolean and takes a link pointer as argument
			bool deleteLink(Link* delLink);

			//Searches through the list with a character array as argument, and returns a pointer to a link
			Link* search(char input[]);

			//Displays the Interest data of every link in the list
			void displayList();

	};

#endif				
