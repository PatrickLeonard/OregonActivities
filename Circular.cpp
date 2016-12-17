/****************************************************************************
*                                                                           *
*           Name: Patrick Leonard                                           *
*           Class: CS202 Professor Fant                                     *
*           Assignment: Program 2                                           *
*           Date: 10-30-12                                                  *
*           Filename: Circular.cpp                                          *
*                                                                           *
*      This file implements the Circular class. A circular linked list that *
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


#include "Circular.h"

//Class constructor, intialize the first and current pointers to null
Circular::Circular(): first(NULL), current(NULL)

	{

	}


//Class destructor
Circular::~Circular()

	{

		Link* temp = NULL;  //Declare a temp pointer to a Link, and set to null
		
		current = first;   //Start at the beginning of the list

		if(current->getNext() == first)  //Circular list must pay attention to the first link as the marker

			{

				delete current;  //If the first link is pointing to itself as first, there is only one link to delete

				return;

			}

		current = current->getNext(); //If there is more than one link, move to the next one, leave the first as the marker to stop

		while(current != first)   //While the current link isn't at the link pointed to by first

			{

				temp = current;     //Point temp at the current link

				current = current->getNext();    //Move current to the next link

				delete temp;      //Delete the link pointed to by temp

			}

		delete current;    //Once only the link pointed to by first is left...delete it

		return;	

	}	
			 
//Copy constructor, performs deap copies, and initializes first to null
Circular::Circular(const Circular &source): first(NULL) 

	{

		Link* copyCurrent = NULL;    //Declare and initialize a pointer to  Link object

		copyCurrent = source.first;   //point to the first link in the list being copied

		if(copyCurrent->getNext() == source.first)   //If there is only one link in the list

			{

				Link* copyFirst = NULL;     //Create a new Link using the Link copy constructor

				copyFirst = new Link(*copyCurrent);

				this->insertLink(copyFirst);    //Insert it into the new list

				return;

			}

		copyCurrent = copyCurrent->getNext();    //If there is more than one, move to the next and leave first as the marker

		while(copyCurrent != source.first)   //While not at the first link in the list

			{

				Link* copyLink = NULL;    //Create a new link using the Link copy constructor

				copyLink = new Link(*copyCurrent);

				this->insertLink(copyLink);   //Insert the link into the list

				copyCurrent = copyCurrent->getNext();   //and move to the next link in the list being copied

			}

		Link* copyFirst = NULL;   //Create a link for the first link in the list being copied, using copy constructor of Link

		copyFirst = new Link(*copyCurrent);

		this->insertLink(copyFirst);   //Insert it into the list to finish copying the whole list

		return;

	}

//Insert a link into the list, taking a pointer to a Link object as the argument
//Inserts links just after the first link, to the second position
void Circular::insertLink(Link* newLink)

	{

		current = first;   //Start at the beginning 

		if(current == NULL)  //If the list is empty, point first to the link 

			{

				first = newLink;

				newLink->setNext(first);   //Set the next of the link to itself to being the circle

			}

		else            //If list isn't empty

			{

				newLink->setNext(first->getNext()); //Set the next of the newLink to the link after first 

				first->setNext(newLink);     //Set the next of first to the newLink

			}

	}

//Removes a link from the list, and returns a boolean to confirm removal, takes a pointer to a Link object as argument
bool Circular::deleteLink(Link* delLink)

	{

		current = first;    //Start at the beginning

		Link* temp = NULL;   //Declare and initialize a pointer to a temp pointer to a Link

		if(current == NULL)  //If list is empty, says so and return false

			{

				std::cout << "List is empty!" << std::endl;

				return false;

			}

		if(current == delLink) //If the link to be deleted is the first link in the list

			{

				temp = current;   //Point temp to the current

				while(current->getNext() != first)   //While current next isn't pointed at first

					{

						current = current->getNext();   //Move to the link that has it's next pointing to first

					}

				current->setNext(temp->getNext());   //Set the current link's next to the second link in the list

				first = current->getNext();     //Point first to the second link in the list, updates first

				delete temp;   //Delete the first link in the list

				temp = NULL;   //Set temp pointer to null

				return true;  //Confirm removal

			}			

		else    //If delLink is not the first in the list

			{

				while(current->getNext() != delLink)  //While the next link isn't to be deleted

					{

						current = current->getNext();  //Move to the next link

						if(current == first)   //If the current link is the first, then have gone around full circle

							{

								//Link not found, says so and return false
								std::cout << "\n\n---/---/---Link not found!---/---/---\n\n" << std::endl;

								return false;

							}

					}

				temp = current->getNext();  //Set temp to the link to be deleted

				current->setNext(temp->getNext());  //Set the current next to the next of the deleted link

				delete temp;   //Delete the link 

				temp = NULL;  //Set temp to null

				return true;  //Confirm removal	

			}

	}	


//Search through the list and compare the input character array to the Interest data, and return pointer to the proper link
Link* Circular::search(char input[])

	{

		current = first;   //Start at the beginning of the list
		
		if(current == NULL)    //If list is empty, say so and return a null pointer

			{

				std::cout << "List is empty!" << std::endl;

				return NULL;

			}

		if(current->interestCompare(input) == 0)   //If first in the list matches, return the pointer

			{

				std::cout << "Interest Found!" << std::endl;

				return current;

			}

		else    //If not first link

			{

				current = current->getNext();  //Move to the next link

				while(current != first)      //While link hasn't gone around back to the first

					{

						if(current->interestCompare(input) == 0)   //Compare input to Interest data

							{

								std::cout << "Interest Found!" << std::endl;  //Say match found, and return pointer

								return current;

							}

						current = current->getNext();  //If no match, move to the next link

					}

				//After going full circle, the link isn't found, say so and return null pointer
				std::cout << "\n\n---/---/---Interest not Found!---/---/---\n\n" << std::endl;

				return NULL;
						

			}

	}

//Display the entire list Interest member data of each link
void Circular::displayList() 
	
	{

		current = first;  //Start at the beginning

		if(current == NULL)    //If list is empty, say so and return

			{

				std::cout << "List is empty!" << std::endl;

				return;

			}

		else    //Else display the first link's Interest data

			{

				current->displayInterest();

			}

		current = current->getNext();   //Move to the next

		while(current != first)   //While having not gone around full circle

			{

				current->displayInterest();    //Display Interest data and move to the next link

				current = current->getNext();

			}

		return;   //After going full circle displaying Interest data, return

	}  
