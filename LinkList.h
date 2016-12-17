/****************************************************************************
*                                                                           *
*           Name: Patrick Leonard                                           *
*           Class: CS202 Professor Fant                                     *
*           Assignment: Program 2                                           *
*           Date: 10-30-12                                                  *
*           Filename: LinkList.h                                            *
*                                                                           *
*        This file creates the abstract base class LinkList. It covers      *
*    the basica capabilities of a linked list. Inserting, removing,         *
*    searching, and displaying the list. All of the member fucntions        *
*    are pure abstract functions (besides the constructor and destructor).  *
*    This is the base class of the three types of linked list required      *
*    for this assignment. Their functions are all self-similar and fit      *
*    well for use with dynamic binding.                                     *
*                                                                           *
*                                                                           *
*                                                                           *
****************************************************************************/ 

#ifndef LINKLIST_H
#define LINKLIST_H

#include "Link.h"

class LinkList

	{

		private:

		
		public:

			//Constructor defined and implemented due to having no associated .cpp file
			LinkList() {};

			//Destructor also defined and implemented due to have no associated .cpp file
			virtual ~LinkList() {};

			//Pure abstract function for inserting links into the lists
			virtual void insertLink(Link* newLink) = 0;

			//Pure abstract function for deleteing links from the lists, returns a boolean
			virtual bool deleteLink(Link* delLink) = 0;

			//Pure abstract function for searching through the links in the lists, returns a link
			virtual Link* search(char* interest) = 0;

			//Pure abstract function for displaying the Interest of links in the list
			virtual void displayList() = 0;

	};		

#endif
