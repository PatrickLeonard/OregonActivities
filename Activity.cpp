/****************************************************************************
*                                                                           *
*           Name: Patrick Leonard                                           *
*           Class: CS202 Professor Fant                                     *
*           Assignment: Program 2                                           *
*           Date: 10-30-12                                                  *
*           Filename: Activity.cpp                                          *
*                                                                           *
*        This file implements the Activity class. This class holds data on  * 
*    activites that match the interests that the user selects in the main   * 
*    application. This class is entirely about holding and displaying the   *
*    data. It has no getter fucnctions, but does have set and display       *
*    functions. It is in a 'has-a' relationship with the Link class and     *
*    is held by an array in the Link object.                                *
*                                                                           *
*                                                                           *
*                                                                           *
*                                                                           *
****************************************************************************/ 



#include "Activity.h"

//Default constructor, initialize char* pointers to null, and set them to default values since 
//data needs to be provided for testing
Activity::Activity(): name(0), location(0), 
			price(0), equipment(0), 
			description(0)

	{

		name = arrayCopy("Random Activity");

		location = arrayCopy("Somewhere in Oregon");

		price = 99.95;

		equipment = arrayCopy("Either none or expensive");

		description = arrayCopy("Probably a pretty good time to be had if it suits your interests");

	}

//Overlaoded constructor sets the member data to the input char* and float arguments
Activity::Activity(char inputName[], char inputLoc[], float cost, char inputEquip[], char inputDescr[])

	{

		name = arrayCopy(inputName);

		location = arrayCopy(inputLoc);

		price = cost;

		equipment = arrayCopy(inputEquip);

		description = arrayCopy(inputDescr);

	}

//Frees all the dynamically allocated character arrays
Activity::~Activity()

	{

		delete [] name;

		delete [] location;

		delete [] equipment;

		delete [] description;

	}

//Copy constructor, makes deep copies of the member data using the arrayCopy member function
Activity::Activity(const Activity &source)

	{

		price = source.price;

		name = arrayCopy(source.name);

		location = arrayCopy(source.location);

		equipment = arrayCopy(source.equipment);	

		description = arrayCopy(source.description);

	}

//Displays the member data of the Activity object in a nicely formatted manner
void Activity::displayActivity() 
	
	{

		std::cout << "\nActivity Name: "  << name  << "  Location: "  << location << std::endl;

		std::cout << "Required Equipment: " << equipment << "   Price: $";
			  
		std::cout << std::fixed << std::setprecision(2) << price << std::endl;

		std::cout << "Description: " << description << "\n" <<  std::endl;

	}

//Sets the name member data, accepts a char array as argument
void Activity::setName(char input[])

	{

		name = arrayCopy(input);

	}

//Sets the location member data, accepts a char array as argument
void Activity::setLocation(char input[])

	{

		location = arrayCopy(input);

	}

//Sets the price member data, accepts a float as argument
void Activity::setPrice(float cost)

	{

		price = cost;

	}

//Sets the equipment member data, accepts a char array as argument
void Activity::setEquipment(char input[])

	{

		equipment = arrayCopy(input);

	}

//Sets the description member data, accepts a char array as argument
void Activity::setDescription(char input[])

	{

		description = arrayCopy(input);

	}

//Creates a new char array and copies the input array into the char array 
//returns a pointer to the char array of the proper size
char* Activity::arrayCopy(const char input[]) 

	{	

		int length = 0;   //Declare int variable to hold the length of the input array

		length = strlen(input);  //Get length and set to int variable

		char* newString = new char[length + 1];  //Create new char array of size length

		strcpy(newString, input);   //Copy input string into new char array

		return newString;       //Return poiner to newly made array	

	}
