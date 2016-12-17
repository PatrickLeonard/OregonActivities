/****************************************************************************
*                                                                           *
*           Name: Patrick Leonard                                           *
*           Class: CS202 Professor Fant                                     *
*           Assignment: Program 2                                           *
*           Date: 10-30-12                                                  *
*           Filename: Doubly.h                                              *
*                                                                           *
*   This file implements the Doubly class. A doubly linked linear list that *
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


#include "Doubly.h"

//Class constructor that initializes the first and current pointers to null
Doubly::Doubly(): first(NULL), current(NULL)

	{

	}

//Class destructor, destroys all the links in the list
Doubly::~Doubly()

	{

		Link* temp = NULL;   //Delcare and initilize a pointer to a link

		current = first;    //Start at the beginning

		while(current != NULL)  //While not off the end of the list

			{

				temp = current;   //Point temp to the current link

				current = current->getNext();   //Move current to the next link

				delete temp;   //Delete the link pointed at by temp

			}

	}

//Copy constructor, deep copies another Doubly class, initializes first and current pointers to null
Doubly::Doubly(const Doubly &source): first(NULL), current(NULL)

	{

		Link* copyLink = NULL;    //Delcare and intialize a Link pointer to null

		copyLink = source.first;   //Point copyLink to the first link in the list to be copied

		while(copyLink != NULL)   //While the copyLink isn't pointing off the list

			{

				Link* newListLink = NULL;    //Create a new link using the Link copy constructor 

				newListLink = new Link(*copyLink);

				this->insertLink(newListLink);  //Insert the link into the list 

				copyLink = copyLink->getNext();   //Move to the next link in the list to be copied

			}

	}

//Insert a link into the list, takes a pointer to a Link object as the argument
//Inserts at thte front of the list
void Doubly::insertLink(Link* newLink)

	{

		current = first;     //Start at the beginning

		if(current == NULL)   //If list is empty, point first to the new link and return

			{

				first = newLink;

				return;

			}

		else      //If the list isn't empty

			{

				first->setPrevious(newLink);   //Set the previous pointer of first to the new link

				newLink->setNext(first);   //Set the next pointer of new link to the first link

				first = newLink;       //Set first to point at the new link

				return;

			}

	}

//Removes a link from the list, takes a pointer to a Link objects as argument, and returns a boolean to confirm removal
bool Doubly::deleteLink(Link* delLink) 

	{

		current = first;    //Start at the beginning

		Link* temp = NULL;   //Declare a temp pointer to a Link and set to null

		if(current == NULL)   //If the list is empty, says so, and return false

			{

				std::cout << "List is empty!" << std::endl;

				return false;

			}

		else    //If not empty

			{

				while(current != NULL)   //And while current isn't pointing off the list

					{

						if(current == delLink)  //Check for if the delLink matches the current

							{

								temp = current;   //Set temp to the link to be deleted

								current = temp->getPrevious();  //Step current to the link before temp

								if(current != NULL)  //Check if current points off the list

									{

										current->setNext(temp->getNext());  //Set current next to the deleted link's next

									}

								current = temp->getNext();  //Set current to the link after the one being deleted

								if(current != NULL)  //Check if current points off the list

									{

										current->setPrevious(temp->getPrevious());  //Set current previous to the delete link's previous

									}

								if(temp == first)  //If the deleted link is first on the list

									{

										first = temp->getNext();  //Set first to the next link in the list

									}

								delete temp;   //Delete the link

								return true;   //Return true confirmation of removal

							}

						current = current->getNext();  //If not the link to be deleted then move to the next

					}

				//If made it to the end of the list without finding the link, says so, and return false
				std::cout << "\n\n---/---/---Link not found!---/---/---\n\n" << std::endl;

				return false;

			}

	}

//Search through the list to match the input char array to the Interest member 
//data of the links in the list, then return a pointer to the link if found
Link* Doubly::search(char input[])

	{

		current = first;    //Start at the beginning

		if(current == NULL)  //If the list is empty, say so and return null

			{

				std::cout << "List is empty!" << std::endl;

				return NULL;

			}

		else      //If the list isn't empty

			{

				while(current != NULL)  //While not off the end of the list

					{

						if(current->interestCompare(input)  == 0)  //Compare the link Interest to the input char array

							{ 				

								return current;  //If match return pointer to current link

							}

						else
	
							{

								current = current->getNext();   //if not move to the next list

							}

					}

				//If checked through the whole list without match, says not found, and return null
				std::cout << "\n\n---/---/---Interest not found!---/---/---\n\n" << std::endl;

				return NULL;

			}

	}

//Display the Interest member data of all the links in the list
void Doubly::displayList()

	{

		current = first;  //Start at the beginning

		if(current == NULL)  //If list is empty, say so and return

			{

				std::cout << "List is empty!" << std::endl;
		
				return;

			}

		else   //If not empty

			{

				while(current != NULL)  //While not off the end of the list

					{

						current->displayInterest();   //Displays the Interest member data and move to the next link

						current = current->getNext();

					}

			}

		return;   //After displaying the entire list, return

	}
