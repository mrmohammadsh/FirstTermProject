// Created by mostafa on 12/23/18.
// The functions for Admin tasks.
//needs to be completed
//for function allTransactions format of the out put must be edited
//the password confim in edit trips must be completed
//dorost kardan tarikh barayeh admin(   ghesmati keh ba ***********  mashakh  shodeh dorost shode)
#ifndef PROJECT_ADMIN_H
#define PROJECT_ADMIN_H

#endif //PROJECT_ADMIN_H

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;



//declaration functions
void allUsers();//complete
void allTransactions();//complete
void allTrips();//completed
void editDrivers();//complete
void editTrips();//completed
void editVehicles();//complete
void signUpANewDriver();//complete
void editDriversInfo();//complete
int editDriversInfoInAllUsersFile(int, int, int, int, char[]);//complete
int computeNewDistance(int, int);//complete
int computeNewTime(int, char[]);//complete
int computeNewPrice(int, char[]);//complete
void cancelOrDelay();
void printInAccountFileAndTransactions(int ,int , int , int , int , int , int , int , int , char []);
int findPass(int);
int findAccountNumber(int);


void adminMain() //function to clear what admin wants to do
{
	int n;
	while (1)
	{
		//start function menu
		cout << "Enter the number of task you want to do please...\n";
		cout << "1. See all users info.\n";
		cout << "2. See all transaction.\n";
		cout << "3. See all trips.\n";
		cout << "4. Edit drivers info.\n";
		cout << "5. Edit trips info.\n";
		cout << "6. Edit vehicles info.\n";
		cout << "7. Cancel or delay in a trip\n";
		cout << "0. Exit.\n\n";
		//end function menu
		cin >> n;
		if (n == 1)
		{
			//goes to users function
			allUsers();
		}
		else if (n == 2)
		{
			//goes to transactions function
			allTransactions();
		}
		else if (n == 3)
		{
			//goes to trips function
			allTrips();
		}
		else if (n == 4)
		{
			//goes to function to Edit drivers info
			editDrivers();
		}
		else if (n == 5)
		{
			//goes to function to Edit trips info
			editTrips();
		}
		else if (n == 6)
		{
			//goes to function to Edit vehicles info
			editVehicles();
		}
		else if(n == 7)
        {
		    //goes to function to cancel or edit a trip
            cancelOrDelay();
        }
		else if (n == 0)
		{
			return;
		}
		else
		{
			cout << "The number you inserted is not correct! try again.\n";
			return;
		}
	}
}

//definition functions
void allUsers()
{
	//completed
	FILE * allUsersFile = fopen("allUsers.txt", "r"); // open allUsers file to see all of them
	if (allUsersFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	cout << "The users will be displayed in the format below\n";
	cout << "username\tpassword\taccount number\tfirst name\tlast name\tphone\tvehicle(for drivers) or reagent\n";
	int fileCharacters = getc(allUsersFile);
	while (fileCharacters != EOF)
	{
		// display contents of file on screen
		putchar(fileCharacters);
		fileCharacters = getc(allUsersFile);
	}
	cout << endl;
	//close open file
	fclose(allUsersFile);
}

void allTransactions()
{
	//needs to be completed
	FILE * allTransactionsFile = fopen("Transactions.txt", "r");
	if (allTransactionsFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	cout << "The users will be displayed in the format below\n";
	cout << "username\taccount number\tfirst name\tlast name\tphone\tvehicle\tpriceOfTheTicket\ttrackingCode\n";
	int fileCharacters = getc(allTransactionsFile);
	while (fileCharacters != EOF)
	{
		// display contents of file on screen
		putchar(fileCharacters);
		fileCharacters = getc(allTransactionsFile);
	}
	cout << endl;
	//close open file
	fclose(allTransactionsFile);
}

void allTrips()
{
	//needs to be completed
	FILE * allTripsFile = fopen("Trips.txt", "r");
	if (allTripsFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	cout << "The trips will be displayed in the format below\n";
	cout << "driver'sUsername\torigin\tdestination\tdistance\ttimeStartTrip\tduration of the trip\tvehicle\tpriceOfTheTicket\n";
	int fileCharacters = getc(allTripsFile);
	while (fileCharacters != EOF)
	{
		// display contents of file on screen
		putchar(fileCharacters);
		fileCharacters = getc(allTripsFile);
	}
	cout << endl;
	//close open file
	fclose(allTripsFile);
}

void editDrivers()
{
	//completed
	FILE * driversFile = fopen("Drivers.txt", "a");
	if (driversFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	//main code here
	int a;
	cout << "Enter the number of task you want to do\n";
	cout << "1. sign up a new driver\n";
	cout << "2. Edit drivers Info\n";
	cin >> a;
	if (a == 1)
	{
		signUpANewDriver();
	}
	else if (a == 2)
	{
		editDriversInfo();
	}
	fclose(driversFile);
}

void editTrips()
{
	//needs to be completed
	FILE * tripsFile = fopen("Trips.txt", "r+");
	if (tripsFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	//main code here
	//get the username and pass of the driver
	int username, password, origin, destination, hour, minute;
	cout << "Enter the username of the driver you want to change his/her trip\n";
	cin >> username;
	cout << "Enter driver's password\n";
	cin >> password;
	cout << "Enter trip's origin\n";
	cin >> origin;
	cout << "Enter trip's destination\n";
	cin >> destination;
	cout << "Enter trip's start hour\n";
	cin >> hour;
	cout << "enter trip's start minute\n";
	cin >> minute;
	//search the username in the trip file and change it
	int driverUsername_trip, origin_trip, destination_trip, distance_trip, startTripHour_trip, startTripMinute_trip, tripDurationHour_trip, tripDurationMinute_trip,day_trip,year_trip,month_trip;
	char vehicle_trip[15];
	int price_trip;
	int i;
	int finishLoop = fgetc(tripsFile);

	//in ghesmat dorost shodeh ******************
	fscanf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%d/%d/%d\t%s\t%d", &driverUsername_trip, &origin_trip, &destination_trip, &distance_trip, &startTripHour_trip, &startTripMinute_trip, &tripDurationHour_trip, &tripDurationMinute_trip, &year_trip, &month_trip, &day_trip, vehicle_trip, &price_trip);

	for (i = 0; finishLoop != EOF; i++)
	{
		if (driverUsername_trip == username && origin_trip == origin && destination_trip == destination && startTripHour_trip == hour && startTripMinute_trip == minute)
		{
			cout << "Enter the number of field you want to edit.\n";
			cout << "1. origin\n";
			cout << "2. destination\n";
			cout << "3. origin and destination\n";
			cout << "4. start hour of the trip\n";
			cout << "5. start minute of the trip\n";
			cout << "6. start hour and minute of the trip\n";
			cout << "0. Exit\n";
			int menuNumber;
			cin >> menuNumber;
			if (menuNumber == 1)//origin
			{
				int NewOrigin;
				cout << "Enter new origin\n";
				cin >> NewOrigin;
				int NewDistance = computeNewDistance(NewOrigin, destination_trip);
				if (NewDistance < 0)
				{
					cout << "Sorry something went wrong!!!\n";
					return;
				}
				int NewTime = computeNewTime(NewDistance, vehicle_trip);
				if (NewTime < 0)
				{
					cout << "Sorry something went wrong!!!\n";
					return;
				}
				int tempHourTime = NewTime / 60;
				float tempMinuteTime = NewTime % 60;
				tempMinuteTime /= 10;
				tempMinuteTime = nearbyint(tempMinuteTime);
				tempMinuteTime *= 10;
				//check that minute and hour finish trip be fewer than 60
				if (tempMinuteTime >= 60)
				{
					tempHourTime++;
					tempMinuteTime -= 60;
				}
				//round with 30 minute accuracy (Drop accurately 30 minutes)
				if (tempMinuteTime < 10)
				{
					tempMinuteTime = 0;
				}
				else if (tempMinuteTime <= 30)
				{
					tempMinuteTime = 30;
				}
				else if (tempMinuteTime < 40)
				{
					tempMinuteTime = 30;
				}
				else if (tempMinuteTime < 60)
				{
					tempMinuteTime = 0;
					tempHourTime++;
				}
				int NewPrice = computeNewPrice(NewDistance, vehicle_trip);
				if (NewPrice < 0)
				{
					cout << "Sorry something went wrong!!!\n";
					return;
				}
				//erase the line
				int j;
				char temp;      //for declare the end of a  line
				fseek(tripsFile, -1, SEEK_CUR);
				for (j = 0;; j++)
				{
					fseek(tripsFile, -1, SEEK_CUR);
					fscanf(tripsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(tripsFile, -1, SEEK_CUR);
					}
				}
				for (int k = 0; k <= j; k++)
				{
					fprintf(tripsFile, " ");
				}
				fseek(tripsFile, -1, SEEK_CUR);
				while (1)
				{
					fseek(tripsFile, -1, SEEK_CUR);
					fscanf(tripsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(tripsFile, -1, SEEK_CUR);
					}
				}
				fprintf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%s\t%d", username, NewOrigin, destination_trip, NewDistance, startTripHour_trip, startTripMinute_trip, tempHourTime, (int)tempMinuteTime, vehicle_trip, NewPrice);
				cout << "Edit trip successfully done.\n\n";
				break;
			}
			else if (menuNumber == 2)//destination
			{
				int NewDestination;
				cout << "Enter new destination\n";
				cin >> NewDestination;
				int NewDistance = computeNewDistance(origin_trip, NewDestination);
				if (NewDistance < 0)
				{
					cout << "Sorry something went wrong!!!\n";
					return;
				}
				int NewTime = computeNewTime(NewDistance, vehicle_trip);
				if (NewTime < 0)
				{
					cout << "Sorry something went wrong!!!\n";
					return;
				}
				int tempHourTime = NewTime / 60;
				float tempMinuteTime = NewTime % 60;
				tempMinuteTime /= 10;
				tempMinuteTime = nearbyint(tempMinuteTime);
				tempMinuteTime *= 10;
				//check that minute and hour finish trip be fewer than 60
				if (tempMinuteTime >= 60)
				{
					tempHourTime++;
					tempMinuteTime -= 60;
				}
				//round with 30 minute accuracy (Drop accurately 30 minutes)
				if (tempMinuteTime < 10)
				{
					tempMinuteTime = 0;
				}
				else if (tempMinuteTime <= 30)
				{
					tempMinuteTime = 30;
				}
				else if (tempMinuteTime < 40)
				{
					tempMinuteTime = 30;
				}
				else if (tempMinuteTime < 60)
				{
					tempMinuteTime = 0;
					tempHourTime++;
				}
				int NewPrice = computeNewPrice(NewDistance, vehicle_trip);
				if (NewPrice < 0)
				{
					cout << "Sorry something went wrong!!!\n";
					return;
				}
				//erase the line
				int j;
				char temp;      //for declare the end of a  line
				fseek(tripsFile, -1, SEEK_CUR);
				for (j = 0;; j++)
				{
					fseek(tripsFile, -1, SEEK_CUR);
					fscanf(tripsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(tripsFile, -1, SEEK_CUR);
					}
				}
				for (int k = 0; k <= j; k++)
				{
					fprintf(tripsFile, " ");
				}
				fseek(tripsFile, -1, SEEK_CUR);
				while (1)
				{
					fseek(tripsFile, -1, SEEK_CUR);
					fscanf(tripsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(tripsFile, -1, SEEK_CUR);
					}
				}
				fprintf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%s\t%d", username, origin_trip, NewDestination, NewDistance, startTripHour_trip, startTripMinute_trip, tempHourTime, (int)tempMinuteTime, vehicle_trip, NewPrice);
				cout << "Edit trip successfully done.\n\n";
				break;
			}
			else if (menuNumber == 3)//destination and origin
			{
				int NewDestination, NewOrigin;
				cout << "Enter new origin\n";
				cin >> NewOrigin;
				cout << "Enter new destination\n";
				cin >> NewDestination;
				int NewDistance = computeNewDistance(NewOrigin, NewDestination);
				if (NewDistance < 0)
				{
					cout << "Sorry something went wrong!!!\n";
					return;
				}
				int NewTime = computeNewTime(NewDistance, vehicle_trip);
				if (NewTime < 0)
				{
					cout << "Sorry something went wrong!!!\n";
					return;
				}
				int tempHourTime = NewTime / 60;
				float tempMinuteTime = NewTime % 60;
				tempMinuteTime /= 10;
				tempMinuteTime = nearbyint(tempMinuteTime);
				tempMinuteTime *= 10;
				//check that minute and hour finish trip be fewer than 60
				if (tempMinuteTime >= 60)
				{
					tempHourTime++;
					tempMinuteTime -= 60;
				}
				//round with 30 minute accuracy (Drop accurately 30 minutes)
				if (tempMinuteTime < 10)
				{
					tempMinuteTime = 0;
				}
				else if (tempMinuteTime <= 30)
				{
					tempMinuteTime = 30;
				}
				else if (tempMinuteTime < 40)
				{
					tempMinuteTime = 30;
				}
				else if (tempMinuteTime < 60)
				{
					tempMinuteTime = 0;
					tempHourTime++;
				}
				int NewPrice = computeNewPrice(NewDistance, vehicle_trip);
				if (NewPrice < 0)
				{
					cout << "Sorry something went wrong!!!\n";
					return;
				}
				//erase the line
				int j;
				char temp;      //for declare the end of a  line
				fseek(tripsFile, -1, SEEK_CUR);
				for (j = 0;; j++)
				{
					fseek(tripsFile, -1, SEEK_CUR);
					fscanf(tripsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(tripsFile, -1, SEEK_CUR);
					}
				}
				for (int k = 0; k <= j; k++)
				{
					fprintf(tripsFile, " ");
				}
				fseek(tripsFile, -1, SEEK_CUR);
				while (1)
				{
					fseek(tripsFile, -1, SEEK_CUR);
					fscanf(tripsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(tripsFile, -1, SEEK_CUR);
					}
				}
				fprintf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%s\t%d", username, NewOrigin, NewDestination, NewDistance, startTripHour_trip, startTripMinute_trip, tempHourTime, (int)tempMinuteTime, vehicle_trip, NewPrice);
				cout << "Edit trip successfully done.\n\n";
				break;
			}
			else if (menuNumber == 4)//start Hour
			{
				int NewStartHour;
				cout << "Enter new Hour\n";
				cin >> NewStartHour;
				int j;
				char temp;      //for declare the end of a  line
				fseek(tripsFile, -1, SEEK_CUR);
				for (j = 0;; j++)
				{
					fseek(tripsFile, -1, SEEK_CUR);
					fscanf(tripsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(tripsFile, -1, SEEK_CUR);
					}
				}
				for (int k = 0; k <= j; k++)
				{
					fprintf(tripsFile, " ");
				}
				fseek(tripsFile, -1, SEEK_CUR);
				while (1)
				{
					fseek(tripsFile, -1, SEEK_CUR);
					fscanf(tripsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(tripsFile, -1, SEEK_CUR);
					}
				}
				fprintf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%s\t%d", username, origin_trip, destination_trip, distance_trip, NewStartHour, startTripMinute_trip, tripDurationHour_trip, tripDurationMinute_trip, vehicle_trip, price_trip);
				cout << "Edit trip successfully done.\n\n";
				break;
			}
			else if (menuNumber == 5)//start minute
			{
				int NewStartMinute;
				cout << "Enter new Minute\n";
				cin >> NewStartMinute;
				//erase line
				int j;
				char temp;      //for declare the end of a  line
				fseek(tripsFile, -1, SEEK_CUR);
				for (j = 0;; j++)
				{
					fseek(tripsFile, -1, SEEK_CUR);
					fscanf(tripsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(tripsFile, -1, SEEK_CUR);
					}
				}
				for (int k = 0; k <= j; k++)
				{
					fprintf(tripsFile, " ");
				}
				fseek(tripsFile, -1, SEEK_CUR);
				while (1)
				{
					fseek(tripsFile, -1, SEEK_CUR);
					fscanf(tripsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(tripsFile, -1, SEEK_CUR);
					}
				}
				fprintf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%s\t%d", username, origin_trip, destination_trip, distance_trip, startTripHour_trip, NewStartMinute, tripDurationHour_trip, tripDurationMinute_trip, vehicle_trip, price_trip);
				cout << "Edit trip successfully done.\n\n";
				break;
			}
			else if (menuNumber == 6)
			{
				int NewStartHour, NewStartMinute;
				cout << "Enter new Hour\n";
				cin >> NewStartHour;
				cout << "Enter new Minute\n";
				cin >> NewStartMinute;

				int j;
				char temp;      //for declare the end of a  line
				fseek(tripsFile, -1, SEEK_CUR);
				for (j = 0;; j++)
				{
					fseek(tripsFile, -1, SEEK_CUR);
					fscanf(tripsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(tripsFile, -1, SEEK_CUR);
					}
				}
				for (int k = 0; k <= j; k++)
				{
					fprintf(tripsFile, " ");
				}
				fseek(tripsFile, -1, SEEK_CUR);
				while (1)
				{
					fseek(tripsFile, -1, SEEK_CUR);
					fscanf(tripsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(tripsFile, -1, SEEK_CUR);
					}
				}
				fprintf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%s\t%d", username, origin_trip, destination_trip, distance_trip, NewStartHour, NewStartMinute, tripDurationHour_trip, tripDurationMinute_trip, vehicle_trip, price_trip);
				cout << "Edit trip successfully done.\n\n";
				break;
			}
			else if (menuNumber == 0)//go back
			{
				break;
			}
			else
			{
				cout << "Sorry the number you have entered is not correct!! Try again please.\n";
				break;
			}
		}
		else
		{
			finishLoop = fgetc(tripsFile);
			fscanf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%s\t%d", &driverUsername_trip, &origin_trip, &destination_trip, &distance_trip, &startTripHour_trip, &startTripMinute_trip, &tripDurationHour_trip, &tripDurationMinute_trip, vehicle_trip, &price_trip);
		}
	}
	if (i >= 100000)
	{
		cout << "Sorry the username you have entered is not correct!! try again please..\n";
		return;
	}
	//close open files
	fclose(tripsFile);
}

void editVehicles()
{
	//needs to be completed
	FILE * vehiclesFile = fopen("Vehicles.txt", "r+");
	if (vehiclesFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	//ask for the vehicle
	char vehicleName[21];
	cout << "Enter the name of vehicle you want to change. (bus/train/airplane)\n";
	scanf("%s", vehicleName);
	char vehicleName_temp[21];
	int capacity, speed, price;
	for (int i = 0; i<4; i++)
	{
		fscanf(vehiclesFile, "\n%s\t%d\t%d\t%d", vehicleName_temp, &capacity, &speed, &price);
		if (strcmp(vehicleName, vehicleName_temp) == 0)
		{
			cout << "what do you want to edit?\n";
			cout << "1. Capacity\n";
			cout << "2. Speed\n";
			cout << "3. Pricing policy number\n";
			cout << "0. Exit\n";
			int menuNumber;
			cin >> menuNumber;
			int j;
			char temp;      //for declare the end of a  line
			if (menuNumber == 1)
			{
				int NewCapacity;
				cout << "Enter new capacity\n";
				cin >> NewCapacity;
				fseek(vehiclesFile, -1, SEEK_CUR);
				for (j = 0;; j++)
				{
					fseek(vehiclesFile, -1, SEEK_CUR);
					fscanf(vehiclesFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(vehiclesFile, -1, SEEK_CUR);
					}
				}
				for (int k = 0; k <= j; k++)
				{
					fprintf(vehiclesFile, "\b");
				}
				fseek(vehiclesFile, -1, SEEK_CUR);
				while (1)
				{
					fseek(vehiclesFile, -1, SEEK_CUR);
					fscanf(vehiclesFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(vehiclesFile, -1, SEEK_CUR);
					}
				}
				int Exit;
				Exit = fprintf(vehiclesFile, "%s\t%d\t%d\t%d\n", vehicleName, NewCapacity, speed, price);
				if (Exit >= 0)
				{
					cout << "Capacity edited successfully\n";
					break;
				}
				else
				{
					cout << "Sorry something went wrong!!!\n";
					break;
				}
			}
			else if (menuNumber == 2)
			{
				int NewSpeed;
				cout << "Enter new speed\n";
				cin >> NewSpeed;
				fseek(vehiclesFile, -1, SEEK_CUR);
				for (j = 0;; j++)
				{
					fseek(vehiclesFile, -1, SEEK_CUR);
					fscanf(vehiclesFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(vehiclesFile, -1, SEEK_CUR);
					}
				}
				for (int k = 0; k <= j; k++)
				{
					fprintf(vehiclesFile, "\b");
				}
				fseek(vehiclesFile, -1, SEEK_CUR);
				while (1)
				{
					fseek(vehiclesFile, -1, SEEK_CUR);
					fscanf(vehiclesFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(vehiclesFile, -1, SEEK_CUR);
					}
				}
				int Exit;
				Exit = fprintf(vehiclesFile, "%s\t%d\t%d\t%d\n", vehicleName, capacity, NewSpeed, price);
				if (Exit >= 0)
				{
					cout << "Speed edited successfully\n";
					break;
				}
				else
				{
					cout << "Sorry something went wrong!!!\n";
					break;
				}
			}
			else if (menuNumber == 3)
			{
				int NewPrice;
				cout << "Enter new pricing policy number\n";
				cin >> NewPrice;
				fseek(vehiclesFile, -1, SEEK_CUR);
				for (j = 0;; j++)
				{
					fseek(vehiclesFile, -1, SEEK_CUR);
					fscanf(vehiclesFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(vehiclesFile, -1, SEEK_CUR);
					}
				}
				for (int k = 0; k <= j; k++)
				{
					fprintf(vehiclesFile, "\b");
				}
				fseek(vehiclesFile, -1, SEEK_CUR);
				while (1)
				{
					fseek(vehiclesFile, -1, SEEK_CUR);
					fscanf(vehiclesFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(vehiclesFile, -1, SEEK_CUR);
					}
				}
				int Exit;
				Exit = fprintf(vehiclesFile, "%s\t%d\t%d\t%d\n", vehicleName, capacity, speed, NewPrice);
				if (Exit >= 0)
				{
					cout << "Capacity edited successfully\n";
					break;
				}
				else
				{
					cout << "Sorry something went wrong!!!\n";
					break;
				}
			}
			else if (menuNumber == 0)
			{
				break;
			}
			else
			{
				cout << "Sorry the number you entered is not correct! try again please..\n";
				break;
			}
		}
	}
	//close open files
	fclose(vehiclesFile);
}

void signUpANewDriver()
{
	const int n = 499999;
	int driversUsername = n;
	int i;
	FILE * accountsFile = fopen("accounts.txt", "r");
	FILE * driversFile = fopen("Drivers.txt", "a");
	FILE * allUsersFile = fopen("allUsers.txt", "a");
	//make sure that files will open
	if (accountsFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	if (driversFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	if (allUsersFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	// start sign up
	int account, pass;
	int account_temp, pass_temp, cash;
	char firstName[30];
	char lastName[30];
	char phone[30];
	char vehicle[15];
	cout << "Enter driver's first name please...\n";
	scanf("%s", firstName);
	cout << "Enter driver's last name:\n";
	scanf("%s", lastName);
	cout << "Enter driver's phone number:\n";
	scanf("%s", phone);
	cout << "Enter driver's account number: (you can not change it later)\n";
	cin >> account;
	cout << "Enter the password: (you can not change it later)\n";
	cin >> pass;
	cout << "Confirm the password:\n";
	cin >> pass_temp;
	cout << "Enter driver's vehicle\n";
	scanf("%s", vehicle);
	if (pass == pass_temp)
	{
		for (i = 0; i<100000; i++)
		{
			driversUsername++;
			fscanf(accountsFile, "%d\t%d\t%d\n", &account_temp, &pass_temp, &cash);
			if (account_temp == account)
			{
				if (pass_temp == pass)
				{
					fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s\n", driversUsername, pass, account, firstName, lastName, phone, vehicle);
					fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s\n", driversUsername, pass, account, firstName, lastName, phone, vehicle);
					cout << "Sign up successfully\n";
					break;
				}
				else
				{
					cout << "Sorry the password is incorrect...\n";
				}
			}
		}
		if (i == 100000)
		{
			cout << "The account number you have entered is incorrect! Try again please...\n";
		}
	}
	else
	{
		cout << "two passwords are not the same !!!\n";
		return;
	}
	//finish sign up
	//close open files
	fclose(accountsFile);
	fclose(driversFile);
	fclose(allUsersFile);
}



void editDriversInfo()
{
	//getting driver's account info
	int username, password;
	cout << "Enter the username of the driver you want to change his/her Info\n";
	cin >> username;
	cout << "Enter the password of the driver you want to change his/her Info\n";
	cin >> password;
	//open files
	FILE * driversFile = fopen("Drivers.txt", "r+");
	if (driversFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	//search and edit info
	int i, menuNumber;
	int username_driversFile_temp, pass_driversFile_temp, accountNumber_driversFile_temp;
	char firstName_driversFile_temp[21], lastName_driversFile_temp[21], phone_driversFile_temp[21], vehicle_driversFile_temp[21];

	fscanf(driversFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &username_driversFile_temp, &pass_driversFile_temp, &accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, phone_driversFile_temp, vehicle_driversFile_temp);

	for (i = 0; i < 99999; i++)
	{
		//scan info from the file
		if (username == username_driversFile_temp)
		{
			if (password == pass_driversFile_temp)
			{
				//found the drivers line
				//recognize want info has to be edit
				cout << "Enter the number of field you want to edit (You can not change account number and password!).\n";
				cout << "1. Username\n";
				cout << "2. First name\n";
				cout << "3. last name\n";
				cout << "4. phone\n";
				cout << "5. vehicle\n";
				cout << "0. Return to menu\n";
				cin >> menuNumber;

				if (menuNumber == 1)
				{
					int NewUsername;
					cout << "Enter new username\n";
					cin >> NewUsername;
					//erase the line
					int j;
					char temp;      //for declare the end of a  line
					fseek(driversFile, -1, SEEK_CUR);
					for (j = 0;; j++)
					{
						fseek(driversFile, -1, SEEK_CUR);
						fscanf(driversFile, "%c", &temp);
						if (temp == 10)
						{
							break;
						}
						else
						{
							fseek(driversFile, -1, SEEK_CUR);
						}
					}
					for (int k = 0; k <= j; k++)
					{
						fprintf(driversFile, "\b");
					}
					fseek(driversFile, -1, SEEK_CUR);
					while (1)
					{
						fseek(driversFile, -1, SEEK_CUR);
						fscanf(driversFile, "%c", &temp);
						if (temp == 10)
						{
							break;
						}
						else
						{
							fseek(driversFile, -1, SEEK_CUR);
						}
					}
					int ExitNumber;
					char sringForPassToFunction[] = "nothing";
					ExitNumber = editDriversInfoInAllUsersFile(username, password, menuNumber, NewUsername, sringForPassToFunction);
					fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", NewUsername, pass_driversFile_temp, accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, phone_driversFile_temp, vehicle_driversFile_temp);
					if (ExitNumber >= 0)
					{
						cout << "Username edited successfully." << endl;
					}
					else
					{
						cout << "sorry something went wrong!!\n";
					}
				}
				else if (menuNumber == 2)
				{
					char NewFirstName[21];
					cout << "Enter new firstName\n";
					scanf("%s", NewFirstName);
					//erase the line
					int j;
					char temp;      //for declare the end of a  line
					fseek(driversFile, -1, SEEK_CUR);
					for (j = 0;; j++)
					{
						fseek(driversFile, -1, SEEK_CUR);
						fscanf(driversFile, "%c", &temp);
						if (temp == 10)
						{
							break;
						}
						else
						{
							fseek(driversFile, -1, SEEK_CUR);
						}
					}
					for (int k = 0; k <= j; k++)
					{
						fprintf(driversFile, "\b");
					}
					fseek(driversFile, -1, SEEK_CUR);
					while (1)
					{
						fseek(driversFile, -1, SEEK_CUR);
						fscanf(driversFile, "%c", &temp);
						if (temp == 10)
						{
							break;
						}
						else
						{
							fseek(driversFile, -1, SEEK_CUR);
						}
					}
					int ExitNumber;
					ExitNumber = editDriversInfoInAllUsersFile(username, password, menuNumber, 0, NewFirstName);
					fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_driversFile_temp, pass_driversFile_temp, accountNumber_driversFile_temp, NewFirstName, lastName_driversFile_temp, phone_driversFile_temp, vehicle_driversFile_temp);
					if (ExitNumber >= 0)
					{
						cout << "First name edited successfully." << endl;
					}
					else
					{
						cout << "sorry something went wrong!!\n";
					}
				}
				else if (menuNumber == 3)
				{
					char NewLastName[21];
					cout << "Enter new lastName\n";
					scanf("%s", NewLastName);
					//erase the line
					int j;
					char temp;      //for declare the end of a  line
					fseek(driversFile, -1, SEEK_CUR);
					for (j = 0;; j++)
					{
						fseek(driversFile, -1, SEEK_CUR);
						fscanf(driversFile, "%c", &temp);
						if (temp == 10)
						{
							break;
						}
						else
						{
							fseek(driversFile, -1, SEEK_CUR);
						}
					}
					for (int k = 0; k <= j; k++)
					{
						fprintf(driversFile, "\b");
					}
					fseek(driversFile, -1, SEEK_CUR);
					while (1)
					{
						fseek(driversFile, -1, SEEK_CUR);
						fscanf(driversFile, "%c", &temp);
						if (temp == 10)
						{
							break;
						}
						else
						{
							fseek(driversFile, -1, SEEK_CUR);
						}
					}
					fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_driversFile_temp, pass_driversFile_temp, accountNumber_driversFile_temp, firstName_driversFile_temp, NewLastName, phone_driversFile_temp, vehicle_driversFile_temp);
					int ExitNumber;
					ExitNumber = editDriversInfoInAllUsersFile(username, password, menuNumber, 0, NewLastName);
					if (ExitNumber >= 0)
					{
						cout << "Last name edited successfully." << endl;
					}
					else
					{
						cout << "sorry something went wrong!!\n";
					}
				}
				else if (menuNumber == 4)
				{
					char NewPhone[20];
					cout << "Enter new phone number\n";
					scanf("%s", NewPhone);
					//erase the line
					int j;
					char temp;      //for declare the end of a  line
					fseek(driversFile, -1, SEEK_CUR);
					for (j = 0;; j++)
					{
						fseek(driversFile, -1, SEEK_CUR);
						fscanf(driversFile, "%c", &temp);
						if (temp == 10)
						{
							break;
						}
						else
						{
							fseek(driversFile, -1, SEEK_CUR);
						}
					}
					for (int k = 0; k <= j; k++)
					{
						fprintf(driversFile, "\b");
					}
					fseek(driversFile, -1, SEEK_CUR);
					while (1)
					{
						fseek(driversFile, -1, SEEK_CUR);
						fscanf(driversFile, "%c", &temp);
						if (temp == 10)
						{
							break;
						}
						else
						{
							fseek(driversFile, -1, SEEK_CUR);
						}
					}
					fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_driversFile_temp, pass_driversFile_temp, accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, NewPhone, vehicle_driversFile_temp);
					int ExitNumber;
					ExitNumber = editDriversInfoInAllUsersFile(username, password, menuNumber, 0, NewPhone);
					if (ExitNumber >= 0)
					{
						cout << "Phone number edited successfully." << endl;
					}
					else
					{
						cout << "sorry something went wrong!!\n";
					}
				}
				else if (menuNumber == 5)
				{
					char NewVehicle[21];
					cout << "Enter new vehicle\n";
					scanf("%s", NewVehicle);
					//erase the line
					int j;
					char temp;      //for declare the end of a  line
					fseek(driversFile, -1, SEEK_CUR);
					for (j = 0;; j++)
					{
						fseek(driversFile, -1, SEEK_CUR);
						fscanf(driversFile, "%c", &temp);
						if (temp == 10)
						{
							break;
						}
						else
						{
							fseek(driversFile, -1, SEEK_CUR);
						}
					}
					for (int k = 0; k <= j; k++)
					{
						fprintf(driversFile, "\b");
					}
					fseek(driversFile, -1, SEEK_CUR);
					while (1)
					{
						fseek(driversFile, -1, SEEK_CUR);
						fscanf(driversFile, "%c", &temp);
						if (temp == 10)
						{
							break;
						}
						else
						{
							fseek(driversFile, -1, SEEK_CUR);
						}
					}
					fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_driversFile_temp, pass_driversFile_temp, accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, phone_driversFile_temp, NewVehicle);
					int ExitNumber;
					ExitNumber = editDriversInfoInAllUsersFile(username, password, menuNumber, 0, NewVehicle);
					if (ExitNumber >= 0)
					{
						cout << "Vehicle edited successfully." << endl;
					}
					else
					{
						cout << "sorry something went wrong!!\n";
					}
				}
				else if (menuNumber == 0)
				{
					break;
				}
				else
				{
					cout << "Sorry the number you have entered is not correct! Try again please...\n";
					break;
				}
			}
			else
			{
				cout << "Sorry the password is incorrect...\n";
				break;
			}
		}
		else
		{
			//read next line
			fscanf(driversFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &username_driversFile_temp, &pass_driversFile_temp, &accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, phone_driversFile_temp, vehicle_driversFile_temp);
		}
	}
	if (i >= 100000)
	{
		cout << "Sorry the username you have entered is not correct!!!\n";
	}
	//close open file
	fclose(driversFile);
}

//define a function for edit drivers info in all users file
int editDriversInfoInAllUsersFile(int username, int password, int menuNumber, int NewIntegers, char NewStrings[21])
{
	//open file
	FILE * allUsersFile = fopen("allUsers.txt", "r+");
	if (allUsersFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return -1;

	}
	int username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp;
	char firstName_allUsersFile_temp[21], lastName_allUsersFile_temp[21], phone_allUsersFile_temp[21], vehicle_allUsersFile_temp[21];
	//read first line
	fscanf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", &username_allUsersFile_temp, &pass_allUsersFile_temp, &accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
	//search in the file and edit the info
	int i;
	for (i = 0; i<100000; i++)
	{
		if (username_allUsersFile_temp == username)
		{
			if (password == pass_allUsersFile_temp)
			{
				// the line of the driver found
				//erase the line
				int j;
				char temp;
				fseek(allUsersFile, -1, SEEK_CUR);
				for (j = 0;; j++)
				{
					fseek(allUsersFile, -1, SEEK_CUR);
					fscanf(allUsersFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(allUsersFile, -1, SEEK_CUR);
					}
				}
				for (int k = 0; k <= j; k++)
				{
					fprintf(allUsersFile, "\b");
				}
				fseek(allUsersFile, -1, SEEK_CUR);
				while (1)
				{
					fseek(allUsersFile, -1, SEEK_CUR);
					fscanf(allUsersFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(allUsersFile, -1, SEEK_CUR);
					}
				}
				//rewrite the line
				if (menuNumber == 1)//username
				{
					fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", NewIntegers, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
					break;
				}
				else if (menuNumber == 2)//firstName
				{
					fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, NewStrings, lastName_allUsersFile_temp, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
					break;
				}
				else if (menuNumber == 3)//lastName
				{
					fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, NewStrings, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
					break;
				}
				else if (menuNumber == 4)//phone
				{
					fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, NewStrings, vehicle_allUsersFile_temp);
					break;
				}
				else if (menuNumber == 5)//vehicle
				{
					fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, phone_allUsersFile_temp, NewStrings);
					break;
				}
				else
				{
					return -1;
				}
			}
			else
			{
				cout << "Sorry the password is incorrect...\n";
				return -1;
			}
		}
		else
		{
			//read the next line
			fscanf(allUsersFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &username_allUsersFile_temp, &pass_allUsersFile_temp, &accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
		}
	}
	//close open files
	fclose(allUsersFile);
	return 1;
}

int computeNewDistance(int origin, int destination)
{
	FILE * citiesFile = fopen("cities.txt", "r");
	if (citiesFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return -1;
	}
	int originX = 0, originY = 0, tempOrigin, a = 0, b = 0;
	fscanf(citiesFile, "%d\t%d\t%d", &tempOrigin, &a, &b);
	int i = getc(citiesFile);
	fseek(citiesFile, -1, SEEK_CUR);
	int j = 1;
	while (i != EOF)
	{
		if (tempOrigin == origin)
		{
			originX = a;
			originY = b;
			j = 0;
			break;
		}
		else
		{
			fscanf(citiesFile, "%d\t%d\t%d", &tempOrigin, &a, &b);
			i = getc(citiesFile);
		}
	}
	if (j)
	{
		cout << "Sorry the number you have entered is not correct!! Try again\n";
		return -1;
	}
	fseek(citiesFile, 0, SEEK_SET);
	//destination
	int destinationX = 0, destinationY = 0, tempDestination;
	fscanf(citiesFile, "%d\t%d\t%d", &tempDestination, &a, &b);
	i = getc(citiesFile);
	fseek(citiesFile, -1, SEEK_CUR);
	j = 1;
	while (i != EOF)
	{
		if (tempDestination == destination)
		{
			destinationX = a;
			destinationY = b;
			j = 0;
			break;
		}
		else
		{
			fscanf(citiesFile, "%d\t%d\t%d", &tempDestination, &a, &b);
			i = getc(citiesFile);
		}
	}
	if (j)
	{
		cout << "Sorry the number you have entered is not correct!! Try again\n";
		return -1;
	}
	//computing the distance
	float distance = sqrt(((originX - destinationX)*(originX - destinationX)) + ((originY - destinationY)*(originY - destinationY)));
	return (int)distance;
}

int computeNewTime(int distance, char vehicle[15])
{
	int capacity_temp, speed_temp, price_temp;
	int speed = 0;
	//open vehicles file for speed
	FILE * vehiclesFile = fopen("Vehicles.txt", "r");
	if (vehiclesFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return -1;
	}
	for (int i = 0; i<6; i++)
	{
		fscanf(vehiclesFile, "\n%s\t%d\t%d\t%d\n", vehicle, &capacity_temp, &speed_temp, &price_temp);
		if (strcmp(vehicle, vehicle) == 0)
		{
			speed = speed_temp;
			break;
		}
	}
	int time = (distance / speed) * 60;
	return time;
}

int computeNewPrice(int distance, char vehicle[15])
{
	char vehicle_temp[15];
	int capacity_temp, speed_temp, price_temp;
	int price = 0;
	//open vehicles file for speed
	FILE * vehiclesFile = fopen("Vehicles.txt", "r");
	if (vehiclesFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return -1;
	}
	for (int i = 0; i<6; i++)
	{
		fscanf(vehiclesFile, "\n%s\t%d\t%d\t%d\n", vehicle_temp, &capacity_temp, &speed_temp, &price_temp);
		if (strcmp(vehicle, vehicle_temp) == 0)
		{
			price = price_temp;
			break;
		}
	}
	float tripPrice;
	tripPrice = price * distance;
	tripPrice /= 1000;
	tripPrice = nearbyint(tripPrice);
	tripPrice *= 1000;
	return (int)tripPrice;
}

void cancelOrDelay()
{
    cout << "What do you want to do?\n";
    cout << "1. cancel a trip\n";
    cout << "2. delay a trip\n";
    int number;
    cin >> number;
    if(number == 1)
    {



		FILE *fileptr1, *fileptr2;
		char filename[40];
		char ch;

		int delete_line, temp = 1;
		strcpy(filename, "Trips.txt");

		//open file in read mode
		fileptr1 = fopen(filename, "r");
		ch = getc(fileptr1);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = getc(fileptr1);
		}
		//rewind
		rewind(fileptr1);
		printf(" \n Enter line number of the trip to be deleted:");
		scanf("%d", &delete_line);
		//open new file in write mode
		fileptr2 = fopen("replica.c", "w");
		ch = getc(fileptr1);
		while (ch != EOF)
		{
			ch = getc(fileptr1);
			if (ch == '\n')
				temp++;
			//except the line to be deleted
			if (temp != delete_line)
			{
				//copy all lines in file replica.c
				putc(ch, fileptr2);
			}
		}
		fclose(fileptr1);
		fclose(fileptr2);
		remove(filename);
		//rename the file replica.c to original name
		rename("replica.c", filename);
		printf("\n The contents of file after being modified are as follows:\n");
		fileptr1 = fopen(filename, "r");
		ch = getc(fileptr1);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = getc(fileptr1);
		}
		fclose(fileptr1);
		return 0;






    }
    else if(number == 2)
    {
        FILE * ticketFile = fopen("ticket.txt", "r+");
        if(ticketFile == NULL)
        {
            cout << "The File opening was Unsuccessful!\n";
            return;
        }
        char trackingCode[15];
        cout << "Enter ticket's tracking Code\n";
        scanf("%s", trackingCode);
        char firstName[30], lastName[30];
        int username_temp, driverUsername, origin, destination, startTripHour, startTripMinute, year, month, day, cast_temp;
        char trackingCode_temp[15];
        bool r = false;
        int temp = getc(ticketFile);
        fseek(ticketFile, -1, SEEK_CUR);
        for (int i = 0; i<100000 && temp != EOF; i++)
        {
            fscanf(ticketFile, "%s\t%s\t%d\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s\t%d", firstName, lastName, &username_temp, &driverUsername, &origin, &destination, &startTripHour, &startTripMinute, &year, &month, &day, trackingCode_temp, &cast_temp);
            temp = getc(ticketFile);
            fseek(ticketFile, -1, SEEK_CUR);
            fscanf(ticketFile, "\n");
            if(strcmp(trackingCode, trackingCode_temp) == 0)
            {
                // current date/time based on current system
                time_t now = time(0);
                tm *ltm = localtime(&now);
                int yearSys, monthSys, daySys, hourSys, minuteSys;
                yearSys = 1900 + ltm->tm_year;
                monthSys = 1 + ltm->tm_mon;
                daySys = ltm->tm_mday;
                hourSys = ltm->tm_hour;
                minuteSys = ltm->tm_min;
                int time = (abs(startTripHour - hourSys)*60) + (startTripMinute - minuteSys);
                if(time >= 60)
                {
                    //90%
					float cast = cast_temp * (0.9);
					float userCash, adminCash, driverCash;
					userCash = cast;
					adminCash = cast * (0.1);
					driverCash = cast * (0.9);
					int user_account = findAccountNumber(username_temp);
					const int admin_account = 200000;
					const int admin_pass = 1318;
					int driver_account = findAccountNumber(driverUsername);
					int userPass = findPass(user_account);
					int driver_Pass = findPass(driver_account);
					printInAccountFileAndTransactions((int)userCash,(int) adminCash,(int) driverCash, user_account, admin_account, driver_account, userPass, admin_pass, driver_Pass, trackingCode);
					break;
                }
                else
                {
                    //50%
					float cast = cast_temp * (0.5);
					float userCash, adminCash, driverCash;
					userCash = cast;
					adminCash = cast * (0.1);
					driverCash = cast * (0.9);
					int user_account = findAccountNumber(username_temp);
					const int admin_account = 200000;
					const int admin_pass = 1318;
					int driver_account = findAccountNumber(driverUsername);
					int userPass = findPass(user_account);
					int driver_Pass = findPass(driver_account);
					printInAccountFileAndTransactions((int)userCash,(int) adminCash,(int) driverCash, user_account, admin_account, driver_account, userPass, admin_pass, driver_Pass, trackingCode);
					break;
				}
            }
        }
        fclose(ticketFile);
    }
    else
    {
        cout << "Sorry the number you have entered is not correct!!\n";
    }
}


void printInAccountFileAndTransactions(int userCash, int adminCash, int driverCash, int accountNumber_user, int accountNumber_admin, int accountNumber_driver, int password_user, int password_admin, int password_driver, char trackingCode[])
{
	FILE*transactionFile = fopen("transaction.txt", "a");
	if (transactionFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}

	FILE * accountsFile = fopen("accounts.txt", "r+");
	if (accountsFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	int accountNumber_temp, pass_temp, cash;
	fscanf(accountsFile, "%d\t%d\t%d", &accountNumber_temp, &pass_temp, &cash);
	int i;
	for (i = 0; i<100000; i++)
	{
		if (accountNumber_temp == accountNumber_user)
		{
			if (pass_temp == password_user)
			{
				//erase the line
				int j;
				char temp;      //for declare the end of a  line
				fseek(accountsFile, -1, SEEK_CUR);
				for (j = 0;; j++)
				{
					fseek(accountsFile, -1, SEEK_CUR);
					fscanf(accountsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(accountsFile, -1, SEEK_CUR);
					}

				}
				for (int k = 0; k <= j; k++)
				{
					fprintf(accountsFile, " ");
				}
				fseek(accountsFile, -1, SEEK_CUR);
				while (1)
				{
					fseek(accountsFile, -1, SEEK_CUR);
					fscanf(accountsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(accountsFile, -1, SEEK_CUR);
					}
				}
				cash = cash + userCash;
				fprintf(transactionFile, "%d\t+%d\t", accountNumber_user, userCash);
				fprintf(accountsFile, "%d\t%d\t%d", accountNumber_user, password_user, cash);
				break;
			}
			else
			{
				cout << "Sorry the password you entered is incorrect.\n";
				break;
			}
		}
		else
		{
			fscanf(accountsFile, "\n%d\t%d\t%d", &accountNumber_temp, &pass_temp, &cash);
		}
	}
	if (i >= 100000)
	{
		cout << "Sorry the account number you have entered is not correct!\n";
		return;
	}
	cash = 0;
	fseek(accountsFile, 0, SEEK_SET);
	fscanf(accountsFile, "%d\t%d\t%d", &accountNumber_temp, &pass_temp, &cash);
	for (i = 0; i<100000; i++)
	{
		if (accountNumber_temp == accountNumber_admin)
		{
			if (pass_temp == password_admin)
			{
				//erase the line
				int j;
				char temp;      //for declare the end of a  line
				fseek(accountsFile, 0, SEEK_SET);
				/*for(j = 0;;j++)
				{
				fseek(accountsFile, -1, SEEK_CUR);
				fscanf(accountsFile,"%c", &temp);
				if(temp == 10)
				{
				break;
				}
				else
				{
				fseek(accountsFile, -1, SEEK_CUR);
				}
				}*/
				temp = getc(accountsFile);
				for (int k = 0; temp != 10; k++)
				{
					fseek(accountsFile, -1, SEEK_CUR);
					fprintf(accountsFile, " ");
					temp = getc(accountsFile);
				}
				fseek(accountsFile, -1, SEEK_CUR);
				fseek(accountsFile, 0, SEEK_SET);
				/*while(1)
				{
				fseek(accountsFile, -1, SEEK_CUR);
				fscanf(accountsFile,"%c", &temp);
				if(temp == 10)
				{
				break;
				}
				else
				{
				fseek(accountsFile, -1, SEEK_CUR);
				}
				}*/
				cash = cash - adminCash;
				fprintf(transactionFile, "%d\t-%d\t", accountNumber_admin, adminCash);
				fprintf(accountsFile, "%d\t%d\t%d", accountNumber_admin, password_admin, cash);
				break;

			}
			else
			{
				cout << "Sorry the password you entered is incorrect.\n";
				break;
			}
		}
		else
		{
			fscanf(accountsFile, "\n%d\t%d\t%d", &accountNumber_temp, &pass_temp, &cash);
		}
	}
	if (i >= 100000)
	{
		cout << "Sorry the account number you have entered is not correct!\n";
		return;
	}
	fseek(accountsFile, 0, SEEK_SET);
	fscanf(accountsFile, "%d\t%d\t%d", &accountNumber_temp, &pass_temp, &cash);
	for (i = 0; i<100000; i++)
	{
		if (accountNumber_temp == accountNumber_driver)
		{
			if (pass_temp == password_driver)
			{
				//erase the line
				int j;
				char temp;      //for declare the end of a  line
				fseek(accountsFile, -1, SEEK_CUR);
				for (j = 0;; j++)
				{
					fseek(accountsFile, -1, SEEK_CUR);
					fscanf(accountsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(accountsFile, -1, SEEK_CUR);
					}
				}
				for (int k = 0; k <= j; k++)
				{
					fprintf(accountsFile, " ");
				}
				fseek(accountsFile, -1, SEEK_CUR);
				while (1)
				{
					fseek(accountsFile, -1, SEEK_CUR);
					fscanf(accountsFile, "%c", &temp);
					if (temp == 10)
					{
						break;
					}
					else
					{
						fseek(accountsFile, -1, SEEK_CUR);
					}
				}


				fprintf(accountsFile, "%d\t%d\t%d", accountNumber_driver, password_driver, driverCash);
				cash = cash - driverCash;
				fprintf(transactionFile, "%d\t-%d\t%s\n", accountNumber_driver, driverCash, trackingCode);
				fprintf(accountsFile, "%d\t%d\t%d", accountNumber_driver, password_driver, cash);
				break;
			}
			else
			{
				cout << "Sorry the password you entered is incorrect.\n";
				break;
			}
		}
		else
		{
			fscanf(accountsFile, "\n%d\t%d\t%d", &accountNumber_temp, &pass_temp, &cash);
		}
	}
	if (i >= 100000)
	{
		cout << "Sorry the account number you have entered is not correct!\n";
		return;
	}
	fclose(accountsFile);
	fclose(transactionFile);
}

int findPass(int accountNumber)
{
	FILE * accountFile = fopen("accounts.txt", "r");
	if(accountFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return -1;
	}
	int account_temp, pass_temp, cash;
	int password;
	for (int i = 0; i<100000; i++)
	{
		fscanf(accountFile, "%d\t%d\t%d\n", &account_temp, &pass_temp, &cash);
		if(account_temp == accountNumber)
		{
			password = pass_temp;
			break;
		}
	}
	fclose(accountFile);
	return password;
}

int findAccountNumber(int username)
{
	FILE * allUsersFile = fopen("allUsers.txt", "r");
	if (allUsersFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return -1;
	}
	int userName_temp, pass_temp, accountNumber;
	char firstName[30], lastName[30], phone[15], reagent[15];
	int account;
	int temp = getc(allUsersFile);
	fseek(allUsersFile, -1, SEEK_CUR);
	for (int k = 0; temp != EOF; k++)
	{
		fscanf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", &userName_temp, &pass_temp, &accountNumber, firstName, lastName, phone, reagent);
		temp = getc(allUsersFile);
		fseek(allUsersFile, -1, SEEK_CUR);
		fscanf(allUsersFile, "\n");
		if(userName_temp == username)
		{
			account = accountNumber;
			break;
		}
	}
	fclose(allUsersFile);
	return account;
}