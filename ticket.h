//
// Created by mostafa on 1/18/19.
//

#ifndef PROJECT_TICKET_H
#define PROJECT_TICKET_H

#endif //PROJECT_TICKET_H


#include <stdio.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>
#include<ctime>
#include <vector>

using namespace std;
//functions declaration
void printInAccountFile(int, int, int, int, int, int, int, int, int, char[]);
int findTrip(int, int, char[]);
int chooseSeatNumber(int);



void ticketGuest()//completed
{
	int number;
	cout << "Enter 0 to go back and 1 to continue.\n";
	cin >> number;
	if (number == 0)
	{
		return;
	}
	int i;
	FILE * ticketFile = fopen("ticket.txt", "a");
	FILE * tripFile = fopen("Trips.txt", "r");
	FILE * accountsFile = fopen("accounts.txt", "r");
	FILE * driverFile = fopen("Drivers.txt", "r");
	if (ticketFile == NULL || tripFile == NULL || accountsFile == NULL || driverFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
    fseek(ticketFile, 1, SEEK_SET);
    fseek(tripFile, 1, SEEK_SET);


    const int accountNumber_admin = 200000;
	const int password_admin = 1318;
	int driver_pass;
	int origin;
	int destination;
	float driver_mony, admin_mony, passenger_mony;
	int taid;
	int Nvehicle;//the vahicle number
	int origin_temp, destination_temp, driverUsername, startTimeHour, startTimeMinute, timeDurationHour, timeDurationMinute, way_temp, cast_temp, year_ttrip, month_ttrip, day_ttrip;
	int account, pass;
	int account_temp, pass_temp, cash;
	int accountNumber_driver;
	char firstName[30], lastName[30];
	char phone[30];
	char vehicle[20], vehicle_temp[20];
	bool breakbool = false;
	int c;//for realize end of a file
	int userName = 0;
	cout << "Enter your first name please...\n\n";
	scanf("%s", firstName);
	cout << "Enter your last name:\n\n";
	scanf("%s", lastName);
	cout << "enter origin\n";
	cin >> origin;
	cout << "enter destination\n";
	cin >> destination;
	cout << "Select the desired vehicle number...\n";
	cout << "1. bus\n2. train\n3. airplane\n";
	cin >> Nvehicle;
	if (Nvehicle == 1)
	{
		strcpy(vehicle, "bus");
	}
	else if (Nvehicle == 2)
	{
		strcpy(vehicle, "train");
	}
	else if (Nvehicle == 3)
	{
		strcpy(vehicle, "airplane");
	}
	else
	{
		cout << "The number you inserted is not correct!";
	}
	int s = findTrip(origin, destination, vehicle);
	if (s>0)
	{
		cout << "Enter your phone number:\n\n";
		scanf("%s", phone);
		cout << "Enter your account number:\n\n";
		cin >> account;
		cout << "Enter the password:\n\n";
		cin >> pass;
	}
	else
	{
		cout << "Sorry there is no trip at your nest. Try again later...\n";
		return;
	}
	for (i = 0; i < 100000; i++)
	{
		fscanf(accountsFile, "%d\t%d\t%d\n", &account_temp, &pass_temp, &cash);
		if (account_temp == account)
		{
			if (pass_temp == pass)
			{
				c = getc(tripFile);
				fseek(tripFile, -1, SEEK_CUR);
				for (int k = 0; c != EOF; k++)
				{
					fscanf(tripFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%d/%d/%d\t%s\t%d", &driverUsername, &origin_temp, &destination_temp, &way_temp, &startTimeHour, &startTimeMinute, &timeDurationHour, &timeDurationMinute, &year_ttrip, &month_ttrip, &day_ttrip, vehicle_temp, &cast_temp);
					c = getc(tripFile);
					fseek(tripFile, -1, SEEK_CUR);
					fscanf(tripFile, "\n");
					if (origin == origin_temp && destination == destination_temp && strcmp(vehicle, vehicle_temp) == 0)
					{
                        cout << "Choose your seat\n";
                        int a = chooseSeatNumber(Nvehicle);
                        cout<<"*************your ticket**************\n\n";
                        cout << "           Your route:\t" << origin_temp << "->" << destination_temp << "\n\n";
                        cout << "   The distance between two cities:\n " ;
                        cout<<"              " <<way_temp << "\n\n";
                        printf("departure time:\t%d:%d\t", startTimeHour, startTimeMinute);
                        printf("Time of travel:\t%d:%d\n\n", timeDurationHour, timeDurationMinute);
                        cout << "The rate of each seat:\n" << cast_temp << "\n\n";
                        cout << "Passenger name:\t" << firstName << " " << lastName << "\n\n";
                        cout << "Phone:\n" << phone << "\n\n";
                        cout << "Seat number:\t" << a << "\n\n";
                        cout<<"**************************************\n";
                        cout << "press 1 to reseve\n";
                        cout << "or press 0 to exit\n";
						cin >> taid;
						if (taid == 1)
						{
							passenger_mony = cast_temp;
							driver_mony = cast_temp * (0.9);
							admin_mony = cast_temp * (0.1);

							//give a randomNumber
							srand(time(NULL));
							char arr[] = "123456789";
							char trackingCode[10];
							for (int i = 0; i<9; i++)
							{
								trackingCode[i] = arr[rand() % 9];
							}
							trackingCode[9] = '\0';
							{
								//search in drivers file and give account number and password
								int usernameTemp, passwordTemp, accountNumberTemp;
								char firstNameTemp[30], lastNameTemp[30], phoneTemp[15], vehicleTemp[15];
								int t = getc(driverFile);
								fseek(driverFile, -1, SEEK_CUR);
								while (t != EOF)
								{
									fscanf(driverFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", &usernameTemp, &passwordTemp, &accountNumberTemp, firstNameTemp, lastNameTemp, phoneTemp, vehicleTemp);
									if (usernameTemp == driverUsername)
									{
										accountNumber_driver = accountNumberTemp;
										driver_pass = passwordTemp;
										break;
									}
									t = fgetc(driverFile);
								}
							}
							printInAccountFile((int)passenger_mony, (int)admin_mony, (int)driver_mony, account, accountNumber_admin, accountNumber_driver, pass, password_admin, driver_pass, trackingCode);
							fprintf(ticketFile, "%s\t%s\t%d\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s\t%d\n", firstName, lastName, userName, driverUsername, origin_temp, destination_temp, startTimeHour, startTimeMinute, year_ttrip, month_ttrip, day_ttrip, trackingCode, cast_temp);
							cout << "Your ticket has been issued\nyour tracking code is:\t" << trackingCode << endl;
							breakbool = true;
							break;
						}
						else
						{
							break;
						}
					}
				}
				if (breakbool == true)
				{
					break;
				}
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
	fclose(ticketFile);
	fclose(tripFile);
	fclose(accountsFile);
	fclose(driverFile);
}

void userTicket(int username, int account_Number, int password)
{
	FILE * ticketFile = fopen("ticket.txt", "a");
	FILE * tripFile = fopen("Trips.txt", "r");
	FILE * accountsFile = fopen("accounts.txt", "r");
	FILE * driverFile = fopen("Drivers.txt", "r");
	if (ticketFile == NULL || tripFile == NULL || accountsFile == NULL || driverFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
    fseek(ticketFile, 1, SEEK_SET);
    fseek(tripFile, 1, SEEK_SET);
    int c;//for realize end of a file
	const int accountNumber_admin = 200000;
	const int password_admin = 1318;
	int driver_pass;
	int origin;
	int destination;
	float driver_mony, admin_mony, passenger_mony;
	int taid;
	int Nvehicle;//the vahicle number
	int origin_temp, destination_temp, driverUsername, startTimeHour, startTimeMinute, timeDurationHour, timeDurationMinute, way_temp, cast_temp, year_ttrip, month_ttrip, day_ttrip;
	int account, pass;
	int account_temp, pass_temp, cash;
	int accountNumber_driver;
	char firstName[30], lastName[30];
	char phone[30];
	char vehicle[20], vehicle_temp[20];
	bool breakbool = false;
	int i, r;
	FILE * allUsersFile = fopen("allUsers.txt", "r");
	if (allUsersFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	int userName_temp, accountNumber;
	char reagent[21];

    cout << "enter origin\n";
    cin >> origin;
    cout << "enter destination\n";
    cin >> destination;
    cout << "Select the desired vehicle number...\n";
    cout << "1. bus\n2. train\n3. airplane\n";
    cin >> Nvehicle;
    if (Nvehicle == 1)
    {
        strcpy(vehicle, "bus");
    }
    else if (Nvehicle == 2)
    {
        strcpy(vehicle, "train");
    }
    else if (Nvehicle == 3)
    {
        strcpy(vehicle, "airplane");
    }
    else
    {
        cout << "The number you inserted is not correct!";
    }
    bool k = false;
    c = getc(tripFile);
    fseek(tripFile, -1, SEEK_CUR);
	for (i = 0; i < 100000 && c!=EOF; i++)
	{
		c = getc(tripFile);
		fseek(tripFile, -1, SEEK_CUR);
        fscanf(tripFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%d/%d/%d\t%s\t%d", &driverUsername, &origin_temp, &destination_temp, &way_temp, &startTimeHour, &startTimeMinute, &timeDurationHour, &timeDurationMinute, &year_ttrip, &month_ttrip, &day_ttrip, vehicle_temp, &cast_temp);
        if(origin == origin_temp && destination == destination_temp && strcmp(vehicle, vehicle_temp) == 0)
        {
        	int temp = getc(allUsersFile);
        	fseek(allUsersFile, -1, SEEK_CUR);
			for (int k = 0; temp != EOF; k++)
			{
				fscanf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", &userName_temp, &pass_temp, &accountNumber, firstName, lastName, phone, reagent);
				temp = getc(allUsersFile);
				fseek(allUsersFile, -1, SEEK_CUR);
				fscanf(allUsersFile, "\n");
				if (username == userName_temp)
				{
					if (password == pass_temp)
					{
					    cout << "Choose your seat\n";
                        int a = chooseSeatNumber(Nvehicle);
					    cout<<"*************your ticket**************\n\n";
						cout << "           Your route:\t" << origin_temp << "->" << destination_temp << "\n\n";
						cout << "   The distance between two cities:\n " ;
						cout<<"              " <<way_temp << "\n\n";
						printf("departure time:\t%d:%d\t", startTimeHour, startTimeMinute);
						printf("Time of travel:\t%d:%d\n\n", timeDurationHour, timeDurationMinute);
						cout << "The rate of each seat:\n" << cast_temp << "\n\n";
						cout << "Passenger name:\t" << firstName << " " << lastName << "\n\n";
						cout << "Phone:\n" << phone << "\n\n";
						cout << "Seat number:\t" << a << "\n\n";
						cout<<"**************************************\n";
						cout << "press 1 to reseve\n";
						cout << "or press 0 to exit\n";
						cin >> taid;
						if (taid == 1)
						{
							passenger_mony = cast_temp;
							driver_mony = cast_temp * (0.9);
							admin_mony = cast_temp * (0.1);
							//give a randomNumber
							srand(time(NULL));
							char arr[] = "123456789";
							char trackingCode[10];
							for (int i = 0; i<9; i++)
							{
								trackingCode[i] = arr[rand() % 9];
							}
							trackingCode[9] = '\0';
							{
								//search in drivers file and give account number and password
								int usernameTemp, passwordTemp, accountNumberTemp;
								char firstNameTemp[30], lastNameTemp[30], phoneTemp[15], vehicleTemp[15];
								int t = getc(driverFile);
								fseek(driverFile, -1, SEEK_CUR);
								while (t != EOF)
								{
									fscanf(driverFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", &usernameTemp, &passwordTemp, &accountNumberTemp, firstNameTemp, lastNameTemp, phoneTemp, vehicleTemp);
									if (usernameTemp == driverUsername)
									{
										accountNumber_driver = accountNumberTemp;
										driver_pass = passwordTemp;
										break;
									}
									t = fgetc(driverFile);
								}
							}
							printInAccountFile((int)passenger_mony, (int)admin_mony, (int)driver_mony, account_Number, accountNumber_admin, accountNumber_driver, password, password_admin, driver_pass, trackingCode);
							fprintf(ticketFile, "%s\t%s\t%d\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s\t%d\n", firstName, lastName,username, driverUsername, origin_temp, destination_temp, startTimeHour, startTimeMinute, year_ttrip, month_ttrip, day_ttrip, trackingCode, cast_temp);
                            cout << "Your ticket has been issued\nyour tracking code is:\t" << trackingCode << endl;
							breakbool = true;
							break;
						}
						else
						{
							break;
						}
					}
					if (breakbool == true)
					{
						break;
					}
				}
			}
			k = true;
        }
	}
	if (k == false)
	{
		cout << "Sorry there is no trip at your nest. Try again later...\n";
		return;
	}
	fclose(ticketFile);
	fclose(tripFile);
	fclose(accountsFile);
	fclose(driverFile);
	fclose(allUsersFile);
}

void printInAccountFile(int userCash, int adminCash, int driverCash, int accountNumber_user, int accountNumber_admin, int accountNumber_driver, int password_user, int password_admin, int password_driver, char trackingCode[])
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
				cash = cash - userCash;
				fprintf(transactionFile, "%d\t-%d\t", accountNumber_user, userCash);
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
				cash = cash + adminCash;
				fprintf(transactionFile, "%d\t+%d\t", accountNumber_admin, adminCash);
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
				cash = cash + driverCash;
				fprintf(transactionFile, "%d\t+%d\t%s\n", accountNumber_driver, driverCash, trackingCode);
				fprintf(accountsFile, "%d\t%d\t%d\n", accountNumber_driver, password_driver, cash);
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

int findTrip(int origin, int destination, char vehicle[])
{
	FILE * tripFile = fopen("Trips.txt", "r");
	if (tripFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return -1;
	}
    fseek(tripFile, 1, SEEK_SET);
	int origin_temp, destination_temp, driverUsername, startTimeHour, startTimeMinute, timeDurationHour, timeDurationMinute, way_temp, cast_temp, year_ttrip, month_ttrip, day_ttrip;
	char vehicle_temp[15];
	int a = 0;
	int temp = getc(tripFile);
	fseek(tripFile, -1, SEEK_CUR);
	for (int i = 0; temp != EOF; i++)
	{
		fscanf(tripFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%d/%d/%d\t%s\t%d", &driverUsername, &origin_temp, &destination_temp, &way_temp, &startTimeHour, &startTimeMinute, &timeDurationHour, &timeDurationMinute, &year_ttrip, &month_ttrip, &day_ttrip, vehicle_temp, &cast_temp);
		temp = getc(tripFile);
		fseek(tripFile, -1, SEEK_CUR);
		fscanf(tripFile, "\n");
		if (origin == origin_temp && destination == destination_temp && strcmp(vehicle, vehicle_temp) == 0)
		{
			a = 1;
			break;
		}
		else
		{
			a = 0;
		}
	}
	//close open file
	fclose(tripFile);
	return a;
}

int computeCapacity(int number)
{
    FILE * vehicleFile = fopen("Vehicles.txt", "r");
    if (vehicleFile == NULL)
    {
        cout << "Opening file was not successful!!\n";
        return -1;
    }
    char vehicle[15];
    int cap_temp, cap, speed, pricePolicy;
    if (number == 1)
    {
        fscanf(vehicleFile, "\n%s\t%d\t%d\t%d\n", vehicle, &cap_temp, &speed, &pricePolicy);
        cap = cap_temp;
    }
    else if (number == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            fscanf(vehicleFile, "\n%s\t%d\t%d\t%d\n", vehicle, &cap_temp, &speed, &pricePolicy);
        }
        cap = cap_temp;
    }
    else if (number == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            fscanf(vehicleFile, "\n%s\t%d\t%d\t%d\n", vehicle, &cap_temp, &speed, &pricePolicy);
        }
        cap = cap_temp;
    }
    return cap;
}


int chooseSeatNumber(int num)
{
    FILE * busFile = fopen("busF.txt", "r+");
    FILE * trainFile = fopen("trainF.txt", "r+");
    FILE * airplaneFile = fopen("airplaneF.txt", "r+");
    if (busFile == NULL || trainFile == NULL || airplaneFile == NULL)
    {
        cout << "Opening file was not successful!!\n";
        return -1;
    }
    vector <int> busvec;
    vector <int> trainvec;
    vector <int> airplanevec;

    int buscap = computeCapacity(1);
    int traincap = computeCapacity(2);
    int airplanecap = computeCapacity(3);

    int number;

    if (num == 1)
    {
        int c = getc(busFile);
        fseek(busFile, -1, SEEK_CUR);
        int temp;
        while (c != EOF)
        {
            fscanf(busFile, "%d\t", &temp);
            busvec.push_back(temp);
            c = getc(busFile);
            fseek(busFile, -1, SEEK_CUR);
        }
        fseek(busFile, 0, SEEK_END);
        bool b;
        for (int i = 0; i < buscap; i++)
        {
            b = false;
            for (int j = 0; j < busvec.size(); j++)
            {
                if (busvec.at(j) == i + 1)
                {
                    b = true;
                    break;
                }
            }
            if (b == false)
            {
                cout << "[" << i + 1 << "]";
                if ((i + 1) % 3 == 1)
                {
                    cout << "\t";
                }
                else if ((i + 1) % 3 == 0)
                {
                    cout << endl;
                }
                else if ((i + 1) % 3 == 2)
                {
                    cout << "  ";
                }
            }
            else
            {
                if (i + 1 >= 10)
                {
                    cout << "   ";
                }
                else
                {
                    cout << "   ";
                }
                if ((i + 1) % 3 == 1)
                {
                    cout << "\t";
                }
                else if ((i + 1) % 3 == 0)
                {
                    cout << endl;
                }
                else if ((i + 1) % 3 == 2)
                {
                    cout << "   ";
                }
            }
        }
        cout << "\nplease inter number ..\n";
        cin >> number;
        fprintf(busFile, "%d\t", number);
    }
        //
    else if (num == 2)
    {
        int c = getc(trainFile);
        fseek(trainFile, -1, SEEK_CUR);
        int temp;
        while (c != EOF)
        {
            fscanf(trainFile, "%d\t", &temp);
            trainvec.push_back(temp);
            c = getc(trainFile);
            fseek(trainFile, -1, SEEK_CUR);
        }
        fseek(trainFile, 0, SEEK_END);
        bool b;
        for (int i = 0; i < traincap-1 ; i++)
        {
            b = false;
            for (int j = 0; j < trainvec.size(); j++)
            {
                if (trainvec.at(j) == i+2)
                {
                    b = true;
                    break;
                }
            }

            if (b == false)
            {

                if (i == 0)
                {
                    cout << "[" << i + 1 << "]\t";
                }
                cout << "[" << i + 2 << "]";
                if ((i + 1) % 2 == 0)
                {
                    cout << "\t";
                }
                else if ((i + 1) % 2 == 1)
                {
                    cout << endl;
                }
            }
            else
            {
                if (i == 0)
                {
                    cout << "\t\t";
                }
                if (i == 1)
                {
                    cout << "   ";
                }
                if ((i + 1) % 2 == 0)
                {
                    cout << "\t";
                }
                else if ((i + 1) % 2 == 1)
                {
                    cout << endl;
                }
            }
        }
        cout << "\nplease inter number ..\n";
        cin >> number;
        fprintf(trainFile, "%d\t", number);

    }
        //
    else if (num == 3)
    {
        int c = getc(airplaneFile);
        fseek(airplaneFile, -1, SEEK_CUR);
        int temp;
        while (c != EOF)
        {
            fscanf(airplaneFile, "%d\t", &temp);
            airplanevec.push_back(temp);
            c = getc(airplaneFile);
            fseek(airplaneFile, -1, SEEK_CUR);
        }
        fseek(airplaneFile, 0, SEEK_END);
        bool b;
        for (int i = 0; i < airplanecap-1 ; i++)
        {
            b = false;
            for (int j = 0; j < airplanevec.size(); j++)
            {
                if (airplanevec.at(j) == i+2)
                {
                    b = true;
                    break;
                }
            }

            if (b == false)
            {

                if (i == 0)
                {
                    cout << "[" << i + 1 << "]\t";
                }
                cout << "[" << i + 2 << "]";
                if ((i + 1) % 2 == 0)
                {
                    cout << "\t";
                }
                else if ((i + 1) % 2 == 1)
                {
                    cout << endl;
                }
            }
            else
            {
                if (i == 0)
                {
                    cout << "\t\t";
                }
                if (i == 1)
                {
                    cout << "   ";
                }
                if ((i + 1) % 2 == 0)
                {
                    cout << "\t";
                }
                else if ((i + 1) % 2 == 1)
                {
                    cout << endl;
                }
            }
        }
        cout << "\nplease inter number ..\n";
        cin >> number;
        fprintf(airplaneFile, "%d\t", number);
    }
    fclose(busFile);
    fclose(trainFile);
    fclose(airplaneFile);
    return number;
}