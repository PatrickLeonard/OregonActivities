/****************************************************************************
*                                                                           *
*           Name: Patrick Leonard                                           *
*           Class: CS202 Professor Fant                                     *
*           Assignment: Program 2                                           *
*           Date: 10-30-12                                                  *
*           Filename: Linear.cpp                                            *
*                                                                           *
*        This file implements the Linear class. A linear linked list that   *
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

#include "Linear.h"

//Constructor initializes the first and current pointers to null
Linear::Linear(): first(NULL), current(NULL)

	{

	}

//Destructor, destroys all the links in the list
Linear::~Linear()

	{

		current = first;        //start at the beginning

		Link* temp = NULL;      //Declraed and initialize temp pointer to a Link object

		while(current != NULL)     //While not off the end of the list

			{

				temp = current;      //Point the temp to the current link

				current = current->getNext();   //Move curent to the next link

				delete temp;         //Delete the link pointed to by temp

			}

	}

//Copy constructor, initializes first and current to null, and takes a Linear class reference as arguement
Linear::Linear(const Linear &source): first(NULL), current(NULL)

	{

		Link* copyCurrent = NULL;   //Declare and initialize a pointer to null
		
		copyCurrent = source.first;   //Point to the first link on the list being copied

		while(copyCurrent != NULL)   //While not off the end of the list
		
			{

				Link* copyLink = NULL;     //Delare a pointer to a link, set to null

				copyLink = new Link(*copyCurrent);  //Create a new link using the Link copy constructor

				this->insertLink(copyLink);     //Insert the newly created copyLink into the list

				copyCurrent = copyCurrent->getNext();   //Point to the next link in the list being copied

			}

	}

//Inserts a link into the list, takes a pointer to a Link object as argument
//This adds links to the front of the list
void Linear::insertLink(Link* newLink)

	{

		current = first;   //Start at the beginning

		if(current == NULL)   //If list is empty 

			{

				first = newLink;      //Point first to the newLink

			}

		else           //If not empty

			{

				newLink->setNext(first);  //Point the new link to the link pointed to by first

				first = newLink;         //Point first to the new link. 

			}
						
	}

//Removes a link from the list, and returns a boolean to confirm removal
bool Linear::deleteLink(Link* delLink)

	{

		current = first;    //Start at the beginning

		Link* temp = NULL;   //Create a temp Link pointer and set to null 

		if(current == NULL)   //If list is empty, says so and return, nothing to remove

			{

				std::cout << "List is empty!" << std::endl;

				return false;

			}	

		if(current == delLink)  //If the link to be removed is the first handle the special case

			{

				first = current->getNext();   //Set first to the next link in the list

				current->setNext(NULL);     //Set the next pointer in the deleted Link to null

				delete current;     //Delete the Link

				return true;      //Return true for confirmation of removal
			
			}

		else                     //If the link to be removed is not the first

			{

				while(current->getNext() != NULL)    //While not off the end of the list

					{

						if(current->getNext() == delLink)   //Test for if next link is to be deleted

							{
						
								temp = current->getNext();   //Set temp to the link to be deleted

								current->setNext(temp->getNext());   //Set the current link's next to the link after deleted link

								temp->setNext(NULL);          //Set deleted link next pointer to null

								delete temp;           //Delete the link
		
								return true;             //Return true for confirmation of removal

							}

						current = current->getNext();       //If the next link isn't to be deleted move on to the next link

					}

				std::cout << "\n\n---/---/---Interest not found!---/---/---\n\n" << std::endl;   //if off the list and no removal, so no Link found


				return false;     //Return false to confirm non-removal

			}

	}

//Search the list for a particular interest, takes a character array as argument
Link* Linear::search(char input[])							

	{

		current = first;   //Start at the beginning of the list

		while(current != NULL)   //While not off the end of the list

			{

				if(current->interestCompare(input) == 0)    //Compare the input interest to the interest of the list

					{

						return current;   //If input matches return a pointer to the link

					}

				else

					{

						current = current->getNext();  //If no match, move to the next link

					}

			}

		std::cout << "\n\n---/---/---Interest not found!---/---/---/\n\n" << std::endl;    //If not found, say so and return null pointer

		return NULL;

	}			

//Display all the Link's inerest data member of the Links
void Linear::displayList()

	{

		current = first;   //Start at the beginning

		if(current == NULL)   //If list is empty, says so and return

			{

				std::cout << "List is empty!" << std::endl;

				return;

			}

		else

			{

				while(current != NULL)  //If not full and while not off the list

					{

						current->displayInterest();   //Display the interest and move to the next link

						current = current->getNext();

					}

			}

		return;   //After list is displayed, return

	}
  

