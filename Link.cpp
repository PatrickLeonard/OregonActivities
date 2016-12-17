/****************************************************************************
*                                                                           *
*           Name: Patrick Leonard                                           *
*           Class: CS202 Professor Fant                                     *
*           Assignment: Program 2                                           *
*           Date: 10-30-12                                                  *
*           Filename: Link.cpp                                              *
*                                                                           *
*        This file implements the Link class. This class has an array of    * 
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


#include "Link.h"

//Defaults constructor initializes all data members to null or zero
Link::Link(): next(NULL), previous(NULL), interest(NULL), activityArray(NULL), numActivities(0)

	{

	}

//Copy constructor, initialize member pointers to null, and makes a deep copy of the link
//including the array of Activity objects
Link::Link(const Link &source): next(NULL), previous(NULL), interest(NULL)

	{

		interest = arrayCopy(source.interest); //Deep copy of the interest character array

		numActivities = source.numActivities;  //Copy the number of activities

		activityArray = new Activity*[numActivities];  //Create a new array of pointers to Activity objects

		for(int j = 0; j < numActivities; j++)    //Set all of the pointers in the array to null

			{

				activityArray[j] = NULL;

			}

		for(int i = 0; numActivities > i; i++)  //Create new Activity objects using the copy constructor 

			{

				activityArray[i] = new Activity(*(source.activityArray[i]));  //Assign the new object to the corresponding pointer in the array

			}

	}

//Destoys every dynamically allocated member data/object in the Link class
Link::~Link()

	{

		delete [] interest;    //Delete the interest char array

		for(int i = 0; numActivities > i; ++i) 

			{

				delete activityArray[i];   //Iterate through the activityArray and delete each Activity object

			}

		delete [] activityArray;  //Delete the array itself

	}

//Overloaded constructor, sets the interest member data, and creates numActs amount of Activity objects
//assigns them to pointers in the activity array, sets the member points to null
Link::Link(const char inputInterest[], int numActs): next(NULL), previous(NULL)

	{

		numActivities = numActs;     //Set the number of activities in the Link class

		interest = arrayCopy(inputInterest);   //Set the interest member data

		if(numActivities == 0)      //If no activities are warrented, set activityArray pointer to null

			{

				activityArray = NULL;
			
				return;  //No activity objects so return

			}

		activityArray = new Activity*[numActivities];   //If activites are needed create the array		

		for(int j = 0; j < numActivities; j++)    //Set te elements to null

			{

				activityArray[j] = NULL;

			}

		for(int i = 0; i < numActivities; i++)   //Assign each pointer to a new object

			{

				activityArray[i] = new Activity();

			}

	}

//Sets the next pointer member data
void Link::setNext(Link* nextLink) 
	
	{

		next = nextLink;

	}

//Sets the previous pointer member data
void Link::setPrevious(Link* prevLink)

	{

		previous = prevLink;

	}

//Returns te next member pointer
Link* Link::getNext()

	{

		return next;

	}

//Returns the previous member pointer
Link* Link::getPrevious()

	{

		return previous;

	}

//Sets the interest member data
void Link::setInterest(char input[])

	{

		delete [] interest;  //Deletes interest if already used

		interest = arrayCopy(input);  //Set interest pointer to new array created in arrayCopy

	}

//Add an activity to the activityArray
void Link::userAddActivity()

	{

		if(numActivities == 0)  //If no activities 

			{

				++numActivities;   //Increase number of activities by one

				activityArray = new Activity*[numActivities];  //Assign new array of pointers to activityArray member pointer

				activityArray[0] = setActivity(); //Set the first pointer to Activity pointer returned by setActivity()

			}

		else     //If there are activities in the array

			{

				Activity** tempArray = new Activity*[numActivities + 1];  //create a new array with one larger element size

				for(int i = 0; i < numActivities; ++i)   //Set all elements of te arra to null

					{

						tempArray[i] = NULL;

						tempArray[i] = activityArray[i];  //Copy the pointers from the old array into the new

						activityArray[i] = NULL;      //Set the old array pointers to null

					}

				tempArray[numActivities] = NULL;   //Set the new element spot to null

				tempArray[numActivities] = setActivity();   //Assign that element spot to the Activity pointer returned from setActivity()

				++numActivities;    //Increment the numActivities variable by one

				delete [] activityArray;   //Delete the old array

				activityArray = tempArray;   //Assign the pointer to the new array to the member pointer activityArray

			}

	}

//Removes activity from the activityArray and resize the array to the correct size, leaves no holes in the array
//accepts removeIndex argument
void Link::removeActivity(int removeIndex) 

	{

		if(numActivities == 0)  //If there are no activities in the array, say so and return

			{

				std::cout << "No activities to remove!" << std::endl;

				return;

			}

		else if((removeIndex < 0) || (removeIndex > numActivities))  //If the index input is out of bounds says so and return

			{

				std::cout << "No such activity exists!" << std::endl;

				return;

			}

		delete activityArray[removeIndex - 1];  //Delete the Activity object and account for 'off-by-one'

		activityArray[removeIndex - 1] = NULL;  //Set the hole to null

		int tempIndex = 0;           //Initialize variable to match index of array to be copied

		--numActivities;   //Decrement the number of activities by one

		Activity** tempArray = new Activity*[numActivities];  //Create a new array one less element large

		for(int i = 0; i < numActivities; ++i)   //Set new array element to null, if array to be copied element is null skip that index ahead

			{

				tempArray[i] = NULL;

				if(activityArray[tempIndex] == NULL)

					{

						++tempIndex;  //Skip ahead

					}

				tempArray[i] = activityArray[tempIndex];  //Copy pointer into new array

				activityArray[tempIndex] = NULL;  //Set old array to null

				++tempIndex;    //increment array to be copied index by one, to keep up with for loop

			}

		delete [] activityArray;   //Delete the array that was copied

		activityArray = tempArray;   //Assign array member pointer to newly copied array

	}				

				
//Creates an activity object with user input and returns a pointer to that object
Activity* Link::setActivity()

	{

		Activity* newActivity = NULL;   //Pointer to the newly created object

		const int BUFFER_SIZE = 255;   //Input character size

		char* nameInput = new char[BUFFER_SIZE];     //Char arrays to hold user input for Activity data members	

		char* locationInput = new char[BUFFER_SIZE];

		char* equipmentInput = new char[BUFFER_SIZE];

		char* descriptionInput = new char[BUFFER_SIZE];

		float priceInput;   //Input variable for float member data

		char choice = 'x';   //Choice for switch statement

		do

			{
				//Promt and acecpt user input for data members

				std::cout << "Please input the name, location, price, equipment, and a description of the activity.\n" << std::endl;

				std::cout << "Name: ";

				std::cin.getline(nameInput, BUFFER_SIZE);

				std::cout << "Location: "; 

				std::cin.getline(locationInput, BUFFER_SIZE);

				std::cout << "Price (ex. 19.99): ";

				std::cin >> priceInput;

				std::cin.get();

				std::cout << "Equipment: ";

				std::cin.getline(equipmentInput, BUFFER_SIZE);

				std::cout << "Description: ";

				std::cin.getline(descriptionInput, BUFFER_SIZE);	

				//Create Activity object using input data
				newActivity = new Activity(nameInput, locationInput, priceInput, equipmentInput, 
								     descriptionInput);
			
				//Display object data for confirmation
				newActivity->displayActivity();

				std::cout << "Continue editing activity? (Y/N): ";

				std::cin >> choice;

				std::cin.get();

				//Input validation for confirmation
				while((choice != 'y') && (choice != 'Y') && (choice != 'n') && (choice != 'N'))
					
					{

						std::cout << "Invalid input, try again: " << std::endl;

						std::cin >> choice;

					}

				if((choice == 'y') || (choice == 'Y'))

					{
						delete newActivity; 	

					}

			}while((choice != 'n') && (choice != 'N'));    //Continues creating an activity object until user is satisfied

		//Delete dynamically created character arrays for user input
		delete [] nameInput;

		delete [] locationInput;

		delete [] equipmentInput;

		delete [] descriptionInput; 

		return newActivity;

	}

//Compare the interest and the input char array, return the int from strcmp()
int Link::interestCompare(char input[])

	{

		return strcmp(input, interest);

	}

//Display the interest member data
void Link::displayInterest()

	{

		std::cout << interest << std::endl;

	}

//Display the Activity objects in the activityArray
void Link::displayActivities()

	{

		if(numActivities == 0) //If no activities in array, say so and return

			{

				std::cout << "No activities under this interest!" << std::endl;

				return;

			}

		for(int i = 0; i < numActivities; i++)   //Iterate through the array and present the data nicely using diaplayActivity()

			{

				std::cout << "\nActivity #" << (i + 1) << std::endl;

				std::cout << "-----------" << std::endl;

				activityArray[i]->displayActivity();

				if((i + 1) % 3 == 0) ///Pause every third object and wait for user to press enter 

					{

						std::cout << "\n--Press Enter to Continue--\n";      

						std::cin.get();

					}

			}

	}		

//Accept input char array as argument and copy it into a newly created array and return a pointer to that array with the proper length
char* Link::arrayCopy(const char input[]) 

	{	

		int length = 0;

		length = strlen(input);

		char* newString = new char[length + 1];

		strcpy(newString, input);

		return newString;	

	}
