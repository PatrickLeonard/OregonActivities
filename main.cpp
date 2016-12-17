/****************************************************************************
*                                                                           *
*           Name: Patrick Leonard                                           *
*           Class: CS202 Professor Fant                                     *
*           Assignment: Program 2                                           *
*           Date: 10-30-12                                                  *
*           Filename: main.cpp                                              *
*                                                                           *
*     This file implements the main function. This file takes care of the   * 
*    choices of the user in using the Oregon Activites program. It enables  * 
*    the user to add interests and activities, as well as delete them. It   *
*    creates several interests and many activities using the overloaded     *
*    constructor of the Link class. The add a new interest class was        *
*    seperated from the rest of main to simplify the main code a bit.       *
*    The program exit is located in the case 4 of the first switch          *
*    which is a bit different than usual.                                   *
*                                                                           *
*                                                                           *
****************************************************************************/ 



#include "Linear.h"
#include "Circular.h"
#include "Doubly.h"
#include <cstdlib>

//Function prototype for adding an interest to a link list
Link* addInterest();


int main()

	{

  		std::cout << "Welcome to Oregon Activities v.5! This is a proof of concept for an activitiy listing. It begins\n";

		std::cout << "by asking about three basic categories, and after selecting one will display a number of default\n";

		std::cout << "interests from that category. Users will then have a chance to add or delete interests as well as\n";

		std::cout << "add or delete activities from those interests. Unfortunately no progress can be saved, and switching\n";

		std::cout << "between the main categories will also lose progress from the current category. Thank you for looking\n";
			
		std::cout << "at this proof of concept program. Enjoy!~" << std::endl;



		LinkList* list = NULL;       //Create a pointer to a LinkList object and set it to null (mainly for scope)

		const int BUFFER_SIZE = 255;  //Buffer size for input char arrays

		while(1)   //While loop that will continue until program exit. 
		
			{

				char choice = 'x';   //Prompt user for choice using switch statment

				std::cout << "Please choose an activity category: " << std::endl;

				std::cout << "1. Arts" << std::endl;

				std::cout << "2. Entertainment" << std::endl;

				std::cout << "3. Sports" << std::endl;
			
				std::cout << "4. Exit Program" << std::endl;

				std::cin >> choice;

				std::cin.get();

				//Input validation for choice input
				while((choice != '1') && (choice != '2') && (choice != '3') && (choice != '4'))

					{

						std::cout << "Invalid input. Please enter a choice(1-3): ";

						std::cin >> choice;

						std::cin.get();

					}

				switch(choice)

					{

								//These cases create a different type of linked list depending on the category
								//and the program treate them all the same through dynamic binding
								//They also provide some default data for the lists for the user
							
						case '1': 

							{

								list = new Linear();

								Link* link1 = new Link("Theatre", 15);

								Link* link2 = new Link("Ballet", 2);

								Link* link3 = new Link("Opera", 3);

								Link* link4 = new Link("Art Museums", 10);

								Link* link5 = new Link("Craft Fairs", 4);
						
								Link* link6 = new Link("Galleries" , 8);

								list->insertLink(link1);

								list->insertLink(link2);

								list->insertLink(link3);

								list->insertLink(link4);

								list->insertLink(link5);

								list->insertLink(link6);

								break;

							}

						case '2': 

							{

								list = new Circular();

								Link* link1 = new Link("Movie Theaters", 6);

								Link* link2 = new Link("Concerts", 4);

								Link* link3 = new Link("Arcades", 3);

								Link* link4 = new Link("Bars/Wineries", 25);

								Link* link5 = new Link("Parks", 10);
						
								Link* link6 = new Link("Carnivals/Fairs" , 8);

								list->insertLink(link1);

								list->insertLink(link2);

								list->insertLink(link3);

								list->insertLink(link4);

								list->insertLink(link5);

								list->insertLink(link6);

								break;

							}


						case '3': 

							{

								list = new Doubly();

								Link* link1 = new Link("Basketball", 6);

								Link* link2 = new Link("Soccer", 4);

								Link* link3 = new Link("Hockey", 3);

								Link* link4 = new Link("Bicycling", 25);

								Link* link5 = new Link("Skateboarding", 10);
						
								Link* link6 = new Link("Running", 8);

								list->insertLink(link1);

								list->insertLink(link2);

								list->insertLink(link3);

								list->insertLink(link4);

								list->insertLink(link5);

								list->insertLink(link6);

								break;

							}

						case '4': 

							{

								exit(0);   //Program exit on choice of user

								break;

							}


					}

				bool interestMenu = true;  //Bool to test if stay in the menue

				do   //Begin do-while

					{

						//Prompt user for choices and test certain cases from the input
						char choice = 'x';

						std::cout << "\nInterests in this category: \n";

						list->displayList();

						std::cout << "\nTo display and edit activities enter the name of the interest, enter ADD to input a new interest,\n";
						std::cout << "enter DELETE to remove and interest, or enter EXIT to return to the previous menu(input is case sensitive): ";

						char* inputInterest = new char[BUFFER_SIZE];	

						std::cin.getline(inputInterest, BUFFER_SIZE);

						if(strcmp(inputInterest, "ADD") == 0)   //Call add interest function on user input

							{

								list->insertLink(addInterest());

							}

						else if(strcmp(inputInterest, "DELETE") == 0)  //Delete interest upon user input

							{

								std::cout << "Enter the interest that you would like to delete: ";

								char* deleteInput = new char[BUFFER_SIZE];

								std::cin.getline(deleteInput, BUFFER_SIZE); 

								Link* delLink = list->search(deleteInput);

								delete [] deleteInput;

								if(delLink != NULL)

									{

										list->deleteLink(delLink);

									}


							}

						else if(strcmp(inputInterest, "EXIT") == 0) //Changes interest menu bool with warning and returns to previous menu

							{

								std::cout << "WARNING! All input data will be deleted in this beta";

								std::cout << " as it doesn't have the capability to save.  Continue?(Y/N): ";

								char cont = 'x';

								std::cin >> cont;	

								std::cin.get();

								while((cont != 'y') && (cont != 'Y') && (cont != 'n') && (cont != 'N'))

									{

										std::cout << "Invalid input. Please enter Y or N: ";

										std::cin >> cont;

										std::cin.get();

									}

								if((cont == 'Y') || (cont == 'y'))

									{

										interestMenu = false;

									}	

							}
					

						else  //Anything other than the specified choices will search through the list for a matching interest input

							{

								Link* searchLink = list->search(inputInterest);

								//If a link insterest match is made, then prompt choice to view and edit activities
								if(searchLink != NULL)

									{

									bool activityMenu = true;

									do
	
										{

										searchLink->displayInterest();

										searchLink->displayActivities();

										std::cout << "Please make a selection: " << std::endl;

										std::cout << "1. Add an activity" << std::endl;

										std::cout << "2. Delete an activity" << std::endl;

										std::cout << "3. Return to interest menu" << std::endl;	

										std::cin >> choice;

										std::cin.get();

										//Input validation for choice
										while((choice != '1') && (choice != '2') && (choice != '3') && (choice != '4'))

											{

												std::cout << "Invalid input. Please enter a choice(1-3): ";

												std::cin >> choice;

												std::cin.get();

											}

										switch(choice)

										{

											case '1':  //Add activity from user input

												{

													searchLink->userAddActivity();

													break;

												}

											case '2':  //Delete activity with given index

												{

													int index = 0;

													std::cout << "Select the activity to be deleted by choosing the";
 													std::cout << "activity number.(i.e. for Activity #4 enter the";
													std::cout << " number 4):";

													std::cin >> index;	

													searchLink->removeActivity(index);

													break;

												}	

											case '3':  //Exit this menu

												{

													activityMenu = false;

													break;


												}

										}

										}while(activityMenu);  //End activity do-while

									}

							}

					delete [] inputInterest;   //delete the dynamically allocated array for interest input

					}while(interestMenu); //End interest do-while

				delete list;

			}

	}


//Allows a user to add an interest to a list, returns a pointer to a Link objects
Link* addInterest()

	{

		const int BUFFER_SIZE = 255;   //Buffer size for input char arrays

		char* inputAdd = new char[BUFFER_SIZE];  //Create a new array for input

		int activityInput = 0;  //Variable to hold how many activities the user wants to add for the new ineterest

		bool addMenu = true;  //use for do-while loop for this menu

		do

			{

				//Prompt user for interest and number of activites and ask for confirmation before creating the new Link object
				char confirm = 'x';

				std::cout << "\nPlease input the name of the interest you would like to add: ";

				std::cin.getline(inputAdd, BUFFER_SIZE);

				std::cout << "\nPlease input the number of activities related to this interest you would like to add(minimum of 1): ";

				std::cin >> activityInput;

				//Input validation for activityInput
				while(activityInput < 1)

					{

						std::cout << "\nInvalid input. At least 1 activity must be entered: ";

						std::cin >> activityInput;

					}

				std::cout << "Interest: " << inputAdd << "  Number of activities: " << activityInput << "  OK? (Y/N): ";

				std::cin >> confirm;

				std::cin.get();

				//Input validation for confirmation
 				while((confirm != 'y') && (confirm != 'Y') && (confirm != 'n') && (confirm != 'N'))

					{

						std::cout << "Invalid input. Please enter Y or N: ";

						std::cin >> confirm;

						std::cin.get();

					}

				if((confirm == 'Y') || (confirm == 'y'))

					{

						addMenu = false;

					}

			}while(addMenu);  //End do-while for addMenu loop


		Link* newLink = new Link(inputAdd, 0);  //create new link and use a for loop to add the amount of activities the user asked for

		for(int i = 0; i < activityInput; ++i)

			{
			
				std::cout << "\n\nInput Activity#" << (i+1) << std::endl;

				newLink->userAddActivity();

			}

		delete [] inputAdd;  //delete dynamically allocated input array

		return newLink;   //return the new link to be inserted into the list 

	}





		

				
