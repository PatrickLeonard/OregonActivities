/****************************************************************************
*                                                                           *
*           Name: Patrick Leonard                                           *
*           Class: CS202 Professor Fant                                     *
*           Assignment: Program 2                                           *
*           Date: 10-30-12                                                  *
*           Filename: Activity.h                                            *
*                                                                           *
*        This file declares the Activity class. This class holds data on    * 
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



#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include <iomanip>
#include <cstring>

//Declared the class Activity
class Activity

	{

		private:

                        //Character arrays for the activity data
			char* name;

			char* location;

			float price;

			char* equipment;

			char* description;

		public:

			//Default constructor
			Activity();

			//Overloaded constructor
			Activity(char name[], char location[], float price, char equipment[], char description[]);

			//Class destructor
			~Activity();

			//Class copy constructor, takes a reference to an Activity object to be copied as the argument
			Activity(const Activity &source);

			//Display the member data in a nicely formmated manner
			void displayActivity();

			//Sets the name member data, accpets a char array as the argument
			void setName(char input[]);

			//Sets the location member data, accpets a char array as the argument
			void setLocation(char input[]);

			//Sets the price member data, accpets a float as the argument
			void setPrice(float cost);

			//Sets the equipment member data, accpets a char array as the argument
			void setEquipment(char input[]);

			//Sets the description member data, accpets a char array as the argument
			void setDescription(char input[]);

			//Creates a new character array and copies the input array into the new array, with the correct size 
			//Returns a pointer to the char array, and accepts a constant character array
			char* arrayCopy(const char input[]);

	};	

#endif
