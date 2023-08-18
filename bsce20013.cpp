#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <type_traits>
#include <string.h>
using namespace std;

void setupFiles();
int blank();
void printall();
void addRoom();
void rentRoom();
void deleteRoom();
void searchRoom();
void editRoom();
void sales();
int blank2();
void policy();
void eraseAll();
void checkOut();
void available();


int main()
{

	system("Color 0E");


	char option[100];

	int size;
	while (true)
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		cout << "			Grand Reagent Hotel											" << endl;

		cout << "==========================================================================================================================================" << endl;
		cout << "Welcome User!" << endl;
		cout << "==========================================================================================================================================" << endl;
		cout << endl;

		cout << "A\t Add a Room." << endl;

		cout << "E\t Edit a Room." << endl;

		cout << "S\t Search a Room." << endl;

		cout << "D\t Delete a Room." << endl;

		cout << "P\t Print all Rooms." << endl;

		cout << "W\t Show all available Rooms." << endl;

		cout << "C\t Check-in." << endl;

		cout << "L\t Check-out." << endl;

		cout << "O\t Open Sales File." << endl;

		cout << "U\t Erase all Data." << endl;

		cout << "R\t Read Me." << endl;

		cout << "F\t Restore to Default." << endl;

		cout << "X\t Exit the Program." << endl;



		cout << "==========================================================================================================================================" << endl;
		cout << "Enter an option: ";
		cin >> option;


		if (*option == 'C' || *option == 'c')
		{

			rentRoom();
		}
		else if (*option == 'L' || *option == 'l')
		{
			checkOut();
		}
		else if (*option == 'A' || *option == 'a')
		{
			addRoom();
		}
		else if (*option == 'P' || *option == 'p')
		{
			printall();
			system("pause");
			system("cls");
		}
		else if (*option == 'O' || *option == 'o')
		{
			sales();
		}
		else if (*option == 'D' || *option == 'd')
		{
			deleteRoom();
		}
		else if (*option == 'E' || *option == 'e')
		{
			editRoom();
		}
		else if (*option == 'S' || *option == 's')
		{
			searchRoom();
		}
		else if (*option == 'R' || *option == 'r')
		{
			policy();
		}
		else if (*option == 'W' || *option == 'w')
		{
			available();
		}
		else if (*option == 'U' || *option == 'u')
		{
			eraseAll();
		}
		else if (*option == 'F' || *option == 'f')
		{
			setupFiles();
			cout << "The files have been created. " << endl;
			system("pause");
			system("cls");
		}
		else if (*option == 'x' || *option == 'X')
		{
			return 0;
		}

		else
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "Invalid input. Try again. " << endl;
			system("pause");
			system("cls");
		}

		int ignore = strlen(option);
		cin.ignore();
		system("cls");



	}
}

void editRoom()
{


	system("cls");
	char name[50];
	int number, size, area, beds;
	float price;
	int id;

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;



	cout << "==========================================================================================================================================" << endl;

	cout << "Enter the ID of the Room you would like to edit: ";
	cin >> id;
	cout << endl;
	float cost;
	if (cin.fail())
	{
		cout << "Error 404! Incorrect input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	else if (id > 100 | id < 0 | id == 0)
	{
		cout << "Invalid Input. Please try again." << endl;
		system("pause");
		system("cls");
		return;

	}
	fstream f("products.txt", ios::in | ios::out);
	f.seekp(id * 127);
	char data2[130];
	f.getline(data2, 127);


	if (strncmp(&data2[95], "Booked", 6) == 0)
	{
		cout << "This room is already booked. You can't edit a booked room. Wait for the occupants to clear out." << endl;
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	f.close();
	fstream f2("products.txt");

	f2.seekp(id * 127);
	char data[130];
	f2.getline(data, 127);

	if (strncmp(&data[15], "                                                  ", 50) == 0)
	{
		cout << "Record doesn't exist!" << endl;

		system("pause");
		system("cls");
		return;
	}
	f2.close();


	cout << "Enter the new Room Number: ";
	cin >> number;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	else if (number > 999 | number <= 0)
	{
		cout << "Invalid Input. Please try again." << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << endl;
	cout << "Enter the new name of the Room: ";
	cin.ignore();
	cin.getline(name, 50);
	if (cin.fail())
	{
		cout << "Error 404! Characters exceed limit. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	else if (strlen(name) == 0)
	{
		cout << endl;
		cout << "You didn't enter the room name. Please try again." << endl;
		return;
	}
	cout << endl;

	cout << "Enter the new maximum guest accomodation: ";
	cin >> size;
	if (cin.fail())
	{
		cout << "Error 404! Incorrect input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	cout << endl;

	if (size > 99 | size <= 0)
	{
		cout << "Invalid Input. Please try again." << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "Enter the new area of the Room in meter square: ";
	cin >> area;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	cout << endl;
	if (area > 9999 | area <= 0)
	{
		cout << "Invalid Input. Please try again." << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "Enter the new number of beds in the room: ";
	cin >> beds;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	cout << endl;
	if (beds > 99 | beds <= 0)
	{
		cout << "Invalid Input. Please try again." << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "Enter the new price of one day stay: ";
	cin >> price;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	else if (price == 0)
	{
		cost = price;
	}
	else if (price > 0)
	{
		cost = price - 0.01;
	}
	else if (price < 0)
	{
		cout << "Please enter a positive price value." << endl;
		return;
	}
	else if (price > 999999 | price <= 0)
	{
		cout << "Invalid Input. Please try again." << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "==========================================================================================================================================" << endl;

	fstream f1("products.txt");
	f1.seekp((127 * id) + 5);

	f1 << left << setw(10) << number;
	f1 << left << setw(50) << name;
	f1 << left << setw(10) << size;
	f1 << left << setw(10) << area;
	f1 << left << setw(10) << beds;
	f1 << left << setw(20) << "Available";
	f1 << left << setw(10) << cost << endl;


	f1.close();

	cout << "The room has been edited successfully." << endl;
	system("pause");
	system("cls");

}

void searchRoom()
{

	system("cls");
	char search[100];
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "==========================================================================================================================================" << endl;
	cout << "How would you like to Search?" << endl;
	cout << "==========================================================================================================================================" << endl;
	cout << "I\t Search by ID." << endl;
	cout << "N\t Search by Room Name." << endl;
	cout << "R\t Search by Room Number." << endl;
	cout << "B\t Back." << endl;
	cout << "==========================================================================================================================================" << endl;
	cin >> search;

	if (*search == 'i' || *search == 'I') //id
	{
		system("cls");

		fstream f1("products.txt", ios::in);

		int id;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "==========================================================================================================================================" << endl;
		cout << "Enter the ID of the Room: ";
		cin >> id;
		if (cin.fail())
		{
			cout << "Error 404! Invalid input. " << endl;
			system("pause");
			system("cls");
			exit(0);
		}
		else if (id > 100 | id < 0 | id == 0)
		{
			cout << "Invalid Input. Please try again." << endl;
			system("pause");
			system("cls");
			return;
		}

		char title[130];
		f1.getline(title, 127);


		f1.seekp(id * 127);
		char data[130];
		f1.getline(data, 127);



		if (strncmp(&data[15], "                                                  ", 50) == 0)
		{
			cout << "No record found." << endl;
		}
		else
		{
			cout << title << endl;
			cout << data << endl;
		}
		cout << "==========================================================================================================================================" << endl;

		f1.close();

		system("pause");


	}
	else if (*search == 'n' || *search == 'N')//name
	{

		system("cls");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "==========================================================================================================================================" << endl;
		char name[50];
		cout << "Please enter the name of the Room. ";
		cin.ignore();
		cin.getline(name, 50);
		if (cin.fail())
		{
			cout << "Error 404! Characters exceed limit. " << endl;
			system("pause");
			system("cls");
			exit(0);
		}
		else if (strlen(name) == 0)
		{
			cout << endl;
			cout << "You didn't enter the room name. Please try again." << endl;
			return;
		}


		ifstream fin("products.txt");
		char data[130];
		int counter = 0;
		cout << left << setw(5) << "ID";
		cout << left << setw(10) << "No#";
		cout << left << setw(50) << "Name";
		cout << left << setw(10) << "Size";
		cout << left << setw(10) << "Area(m^2)";
		cout << left << setw(10) << "Bed(s)";
		cout << left << setw(20) << "Status";
		cout << left << setw(10) << "Price($)" << endl;

		while (!fin.eof())
		{
			fin.getline(data, 127);
			if (strncmp(&data[15], name, strlen(name)) == 0)
			{
				cout << data << endl;
				counter++;
			}
		}
		cout << endl;


		if (counter == 0)
		{
			cout << "No record found." << endl;
		}

		if (counter > 0)
		{
			cout << counter << " results found." << endl;
		}

		cout << "==========================================================================================================================================" << endl;

	}
	else if (*search == 'r' || *search == 'R')//number
	{
		system("cls");

		char number[10];
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "==========================================================================================================================================" << endl;
		cout << "Enter the Room Number: ";
		cin.ignore();
		cin.getline(number, 10);
		if (cin.fail())
		{
			cout << "Error 404! Character exceeds value. " << endl;
			system("pause");
			system("cls");
			exit(0);
		}
		else if (strlen(number) == 0)
		{
			cout << endl;
			cout << "You didn't enter the room number. Please try again." << endl;
			return;
		}

		cout << left << setw(5) << "ID";
		cout << left << setw(10) << "No#";
		cout << left << setw(50) << "Name";
		cout << left << setw(10) << "Size";
		cout << left << setw(10) << "Area(m^2)";
		cout << left << setw(10) << "Bed(s)";
		cout << left << setw(20) << "Status";
		cout << left << setw(10) << "Price($)" << endl;

		ifstream fin("products.txt");
		char data[130];
		int counter = 0;
		while (!fin.eof())
		{
			fin.getline(data, 127);
			if (strncmp(&data[5], number, strlen(number)) == 0)
			{
				cout << data << endl;
				counter++;
			}
		}

		if (counter == 0)
		{
			cout << "No record found." << endl;
		}

		if (counter > 0)
		{
			cout << "Room found." << endl;
		}
		cout << "==========================================================================================================================================" << endl;


	}
	else if (*search == 'b' || *search == 'B')
	{
		system("cls");
		return;
	}
	else
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Invalid input. Try again. " << endl;
		system("pause");
		system("cls");
		return;
	}

	int ignore = strlen(search);
	cin.ignore();
	system("cls");
}

void rentRoom()
{
	system("cls");
	int num, stay;
	char name[25];
	char phone[15];
	char room[50];
	char room_number[10];
	float total;
	float price;
	float tax = 17;
	float cost;
	float final;

	system("cls");
	fstream f1("products.txt", ios::in);

	char data[130];

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "==========================================================================================================================================" << endl;
	int counter=0;
	cout << left << setw(5) << "ID";
	cout << left << setw(10) << "Room No#";
	cout << left << setw(50) << "Name";
	cout << left << setw(10) << "Size";
	cout << left << setw(10) << "Area(m^2)";
	cout << left << setw(10) << "Bed(s)";
	cout << left << setw(20) << "Status";
	cout << left << setw(10) << "Price($)" << endl;
	while (!f1.eof())
	{

		f1.getline(data, 127);
		if (strncmp(&data[15], "                                                  ", 50) != 0 & strncmp(&data[95], "Available", 9) == 0)
		{
			cout << data << endl;
			cout << endl;
			counter++;
		}
	}
	if (counter == 0)
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "We are terribly sorry. All the rooms are currently booked. We apologize for the inconvenience." << endl;


		system("pause");
		system("cls");
		return;
	}
	cout << "==========================================================================================================================================" << endl;

	f1.close();

	fstream f("products.txt", ios::in | ios::out);

	
	cout << endl;
	cout << "==========================================================================================================================================" << endl;
	cout << "Enter the ID of the Room you would like to rent: ";
	cin >> num;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	else if (num > 100 | num <= 0)
	{
		{
			cout << "Error 404! Invalid input. " << endl;
			system("pause");
			system("cls");
			return;
		}
	}


	f.seekp(num * 127);
	char data99[130];
	f.getline(data99, 127);


	if (strncmp(&data99[95], "Booked", 6) == 0)
	{
		cout << "This room is already booked." << endl;
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	f.seekp(num * 127);
	char data2[130];
	f.getline(data2, 127);

	if (strncmp(&data2[15], "                                                  ", 50) == 0)
	{
		cout << "Room doesn't exist!" << endl;

		system("pause");
		system("cls");
		return;
	}


	cout << "How many days would you like to stay? ";
	cin >> stay;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	else if (stay > 99 | stay <= 0)
	{
		cout << "Invalid input. Please try again.";
		return;
	}
	int limit;
	f.seekp(127 * num + 65);
	f >> limit;

	int person;
	cout << "How many persons in your party? "; 
	cin >> person;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	else if (person > limit)
	{
		cout << "The room size does not support the number of people." << endl;
	
		system("pause");
		return;
	}
	else if (person <= 0)
	{
		cout << "Invalid input. Please try again.";
		return;
	}


	f.seekp(127 * num + 95);
	f << left << setw(20) << "Booked";



	cout << "Enter the customer's name: ";
	cin.ignore();
	cin.getline(name, 25);
	if (cin.fail())
	{
		cout << "Error 404! Input exceeds limit. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	else if (strlen(name) == 0)
	{
		cout << endl;
		cout << "You didn't enter the customer's name. Please try again." << endl;
		return;
	}

	cout << "Enter the customer's Phone Number: ";

	cin.getline(phone, 15);
	if (cin.fail())
	{
		cout << "Error 404! Input exceeds limit. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}


	f.seekp(127 * num + 15); //room name
	f.get(room, 50);

	f.seekp(127 * num + 5);  //room number
	f.get(room_number, 10);

	f.seekp(127 * num + 115); //price
	f >> price;



	total = (stay * price);
	cost = (tax / 100) * total;
	final = cost + total;



	f.close();

	int id = blank2();
	if (id > 10000)
	{
		cout << "Data overflow. Please manage space in sales file." << endl;
		system("pause");
		system("cls");
		return;
	}

	fstream f2("sales.txt", ios::in | ios::out);

	f2.seekp(147 * id + 5);

	f2 << left << setw(25) << name;
	f2 << left << setw(15) << phone;
	f2 << left << setw(50) << room;
	f2 << left << setw(10) << room_number;
	f2 << left << setw(10) << price;
	f2 << left << setw(5) << stay;
	f2 << left << setw(5) << tax;
	f2 << left << setw(20) << final << endl;


	f2.close();

	cout << "The room has been booked for " << stay << " days." << endl;

	cout << "==========================================================================================================================================" << endl;


	system("pause");
	system("cls");

}

void deleteRoom()
{
	system("cls");
	int id;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "==========================================================================================================================================" << endl;
	cout << "Enter the ID of the room you want to delete: ";
	cin >> id;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}

	else if (id > 99 | id <= 0)
	{
		cout << "Invalid value. Please try again." << endl;
		system("cls");
		system("pause");

		return;
	}

	fstream f1("products.txt", ios::out | ios::in);

	f1.seekp(id * 127);
	char data[130];
	f1.getline(data, 127);

	if (strncmp(&data[15], "                                                  ", 50) == 0)
	{
		cout << "Record doesn't exist." << endl;
	}

	else
	{
		f1.seekp(127 * id + 5);
		f1 << left << setw(10) << 0;
		f1 << left << setw(50) << "  ";
		f1 << left << setw(10) << 0;
		f1 << left << setw(10) << 0;
		f1 << left << setw(10) << 0;
		f1 << left << setw(20) << "Available ";
		f1 << left << setw(10) << 0 << endl;

		cout << "The data has been successfully removed." << endl;

	}
	cout << "==========================================================================================================================================" << endl;

	f1.close();

	system("pause");
	system("cls");
}


void addRoom()
{
	system("cls");
	char name[50];
	int number, size, area, beds;
	int price;
	int id = blank();
	float cost;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	fstream f1("products.txt");

	cout << "==========================================================================================================================================" << endl;

	cout << "Enter the Room Number: ";
	cin >> number;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}

	else if (number > 999)
	{
		cout << "Error. Enter a number less than 999." << endl;
	}


	cout << endl;
	cout << "Enter the name of the Room: ";
	cin.ignore();
	cin.getline(name, 50);
	if (cin.fail())
	{
		cout << "Error 404! Input exceeds limit. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	else if (strlen(name) == 0)
	{
		cout << endl;
		cout << "You didn't enter the room name. Please try again." << endl;
		return;
	}
	cout << endl;

	cout << "Enter the maximum guest accomodation: ";
	cin >> size;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	cout << endl;

	cout << "Enter the area of the Room in meter square: ";
	cin >> area;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	cout << endl;

	cout << "Enter the number of beds in the room: ";
	cin >> beds;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	cout << endl;

	cout << "Enter the price of 1 night stay: ";
	cin >> price;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	else if (price == 0)
	{
		cost = price;
	}
	else if (price > 0)
	{
		cost = price - 0.01;
	}
	else if (price < 0)
	{
		cout << "Please enter a positive price value." << endl;
		return;
	}
	else if (price > 999999)
	{
		cout << "Price value too large." << endl;
		return;
	}




	f1.seekp((127 * id) + 5);

	f1 << left << setw(10) << number;
	f1 << left << setw(50) << name;
	f1 << left << setw(10) << size;
	f1 << left << setw(10) << area;
	f1 << left << setw(10) << beds;
	f1 << left << setw(20) << "Available";
	f1 << left << setw(10) << cost << endl;

	f1.seekp(id * 127);
	char data3[130];
	f1.getline(data3, 127);

	if (strncmp(&data3[15], "                                                  ", 50) == 0)
	{
		cout << "You didn't enter the room name. Please try again." << endl;

		system("pause");
		system("cls");
		return;
	}


	f1.close();


	cout << "The room has been added successfully on " << id << endl;
	cout << "==========================================================================================================================================" << endl;
	system("pause");
	system("cls");
}

void printall()
{
	system("cls");
	fstream f1("products.txt", ios::in);

	char data[130];
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "==========================================================================================================================================" << endl;

	while (!f1.eof())
	{

		f1.getline(data, 127);
		if (strncmp(&data[15], "                                                  ", 50) != 0)
		{
			cout << data << endl;
			cout << endl;
		}
	}
	cout << "==========================================================================================================================================" << endl;

	f1.close();

	

}

int blank()
{
	fstream f1("products.txt", ios::in);

	char data[130];
	int counter = 0;

	while (!f1.eof())
	{
		f1.getline(data, 127);
		if (strncmp(&data[15], "                                                  ", 50) == 0)
		{
			return counter;
		}
		counter++;
	}

	f1.close();
}

int blank2()
{
	fstream f1("sales.txt", ios::in);

	char data[150];
	int counter = 0;

	while (!f1.eof())
	{
		f1.getline(data, 147);
		if (strncmp(&data[5], "                         ", 25) == 0)
		{
			return counter;
		}
		counter++;
	}

	f1.close();
}


void setupFiles()
{
	fstream f1;
	f1.open("products.txt", ios::out);

	fstream f2;
	f2.open("sales.txt", ios::out);


	f1 << left << setw(5) << "ID";
	f1 << left << setw(10) << "Room No#";
	f1 << left << setw(50) << "Name";
	f1 << left << setw(10) << "Size";
	f1 << left << setw(10) << "Area(m^2)";
	f1 << left << setw(10) << "Bed(s)";
	f1 << left << setw(20) << "Status";
	f1 << left << setw(10) << "Price($)" << endl;


	f1 << left << setw(5) << 1;
	f1 << left << setw(10) << 001;
	f1 << left << setw(50) << "Superior Queen Room ";
	f1 << left << setw(10) << 2;
	f1 << left << setw(10) << 40;
	f1 << left << setw(10) << 1;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 669.99 << endl;


	f1 << left << setw(5) << 2;
	f1 << left << setw(10) << 002;
	f1 << left << setw(50) << "Deluxe King Room";
	f1 << left << setw(10) << 2;
	f1 << left << setw(10) << 42;
	f1 << left << setw(10) << 1;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 689.99 << endl;


	f1 << left << setw(5) << 3;
	f1 << left << setw(10) << 003;
	f1 << left << setw(50) << "Junior Suite";
	f1 << left << setw(10) << 3;
	f1 << left << setw(10) << 42;
	f1 << left << setw(10) << 2;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 709.99 << endl;


	f1 << left << setw(5) << 4;
	f1 << left << setw(10) << 004;
	f1 << left << setw(50) << "Executive One-Bedroom Suite ";
	f1 << left << setw(10) << 4;
	f1 << left << setw(10) << 65;
	f1 << left << setw(10) << 1;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 844.99 << endl;


	f1 << left << setw(5) << 5;
	f1 << left << setw(10) << 005;
	f1 << left << setw(50) << "Two-Bedroom Suite";
	f1 << left << setw(10) << 6;
	f1 << left << setw(10) << 125;
	f1 << left << setw(10) << 2;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 1999.99 << endl;


	f1 << left << setw(5) << 6;
	f1 << left << setw(10) << 100;
	f1 << left << setw(50) << "Common Suite";
	f1 << left << setw(10) << 4;
	f1 << left << setw(10) << 41;
	f1 << left << setw(10) << 2;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 89.99 << endl;


	f1 << left << setw(5) << 7;
	f1 << left << setw(10) << 101;
	f1 << left << setw(50) << "Standard Room";
	f1 << left << setw(10) << 2;
	f1 << left << setw(10) << 25;
	f1 << left << setw(10) << 1;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 189.99 << endl;

	f1 << left << setw(5) << 8;
	f1 << left << setw(10) << 102;
	f1 << left << setw(50) << "Deluxe King Suite";
	f1 << left << setw(10) << 4;
	f1 << left << setw(10) << 62;
	f1 << left << setw(10) << 4;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 439.99 << endl;

	f1 << left << setw(5) << 9;
	f1 << left << setw(10) << 103;
	f1 << left << setw(50) << "Lake View Room";
	f1 << left << setw(10) << 2;
	f1 << left << setw(10) << 28;
	f1 << left << setw(10) << 2;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 1934.99 << endl;

	f1 << left << setw(5) << 10;
	f1 << left << setw(10) << 104;
	f1 << left << setw(50) << "Deluxe Queen Room";
	f1 << left << setw(10) << 4;
	f1 << left << setw(10) << 33;
	f1 << left << setw(10) << 4;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 1699.99 << endl;

	f1 << left << setw(5) << 11;
	f1 << left << setw(10) << 105;
	f1 << left << setw(50) << "Country Suite";
	f1 << left << setw(10) << 1;
	f1 << left << setw(10) << 15;
	f1 << left << setw(10) << 1;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 499.99 << endl;

	f1 << left << setw(5) << 12;
	f1 << left << setw(10) << 106;
	f1 << left << setw(50) << "Owl's Resort";
	f1 << left << setw(10) << 4;
	f1 << left << setw(10) << 49;
	f1 << left << setw(10) << 3;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 999.99 << endl;

	f1 << left << setw(5) << 13;
	f1 << left << setw(10) << 107;
	f1 << left << setw(50) << "Family's Retreat";
	f1 << left << setw(10) << 10;
	f1 << left << setw(10) << 120;
	f1 << left << setw(10) << 8;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 2499.99 << endl;

	f1 << left << setw(5) << 14;
	f1 << left << setw(10) << 108;
	f1 << left << setw(50) << "Room of Solitude";
	f1 << left << setw(10) << 1;
	f1 << left << setw(10) << 16;
	f1 << left << setw(10) << 1;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 399.99 << endl;

	f1 << left << setw(5) << 15;
	f1 << left << setw(10) << 109;
	f1 << left << setw(50) << "Chinese Zone";
	f1 << left << setw(10) << 3;
	f1 << left << setw(10) << 59;
	f1 << left << setw(10) << 2;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 799.99 << endl;

	f1 << left << setw(5) << 16;
	f1 << left << setw(10) << 200;
	f1 << left << setw(50) << "Lion's Den";
	f1 << left << setw(10) << 2;
	f1 << left << setw(10) << 29;
	f1 << left << setw(10) << 1;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 839.99 << endl;

	f1 << left << setw(5) << 17;
	f1 << left << setw(10) << 201;
	f1 << left << setw(50) << "Scholar's Study";
	f1 << left << setw(10) << 1;
	f1 << left << setw(10) << 45;
	f1 << left << setw(10) << 1;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 299.99 << endl;

	f1 << left << setw(5) << 18;
	f1 << left << setw(10) << 202;
	f1 << left << setw(50) << "Fun Extravaganza";
	f1 << left << setw(10) << 6;
	f1 << left << setw(10) << 70;
	f1 << left << setw(10) << 6;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 649.99 << endl;

	f1 << left << setw(5) << 19;
	f1 << left << setw(10) << 203;
	f1 << left << setw(50) << "Hall of Fame";
	f1 << left << setw(10) << 12;
	f1 << left << setw(10) << 120;
	f1 << left << setw(10) << 12;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 2999.99 << endl;

	f1 << left << setw(5) << 20;
	f1 << left << setw(10) << 204;
	f1 << left << setw(50) << "Black and White";
	f1 << left << setw(10) << 4;
	f1 << left << setw(10) << 34;
	f1 << left << setw(10) << 3;
	f1 << left << setw(20) << "Available ";
	f1 << left << setw(10) << 1244.99 << endl;

	f2 << left << setw(5) << "ID";
	f2 << left << setw(25) << "Customer Name";
	f2 << left << setw(15) << "Phone No#";
	f2 << left << setw(50) << "Room Name";
	f2 << left << setw(10) << "Room No#";
	f2 << left << setw(10) << "Price($)";
	f2 << left << setw(5) << "Days";
	f2 << left << setw(5) << "Tax%";
	f2 << left << setw(20) << "Total Cost" << endl;


	for (int i = 21; i <= 100; i++)
	{
		f1 << left << setw(5) << i;
		f1 << left << setw(10) << 0;
		f1 << left << setw(50) << "  ";
		f1 << left << setw(10) << 0;
		f1 << left << setw(10) << 0;
		f1 << left << setw(10) << 0;
		f1 << left << setw(20) << "Available ";
		f1 << left << setw(10) << 0 << endl;
	}

	for (int i = 1; i <= 10000; i++)
	{
		f2 << left << setw(5) << i;
		f2 << left << setw(25) << " ";
		f2 << left << setw(15) << " ";
		f2 << left << setw(50) << " ";
		f2 << left << setw(10) << 0;
		f2 << left << setw(10) << 0;
		f2 << left << setw(5) << 0;
		f2 << left << setw(5) << 0;
		f2 << left << setw(20) << 0 << endl;
	}

	f1.close();
	f2.close();

}

void sales()
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	char a[100];
	cout << "==========================================================================================================================================" << endl;
	cout << "P\t Print the Sales Files." << endl;
	cout << "D\t Delete a Record." << endl;
	cout << "B\t Back." << endl;
	cout << "==========================================================================================================================================" << endl;
	cin >> a;

	if (*a == 'P' | *a == 'p')
	{
		system("cls");
		fstream f1("sales.txt", ios::in);
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		char data[150];
		cout << "==========================================================================================================================================" << endl;

		while (!f1.eof())
		{
			f1.getline(data, 147);
			if (strncmp(&data[5], "                                                  ", 25) != 0)
			{
				cout << data << endl;
				cout << endl;
			}
		}
		cout << "==========================================================================================================================================" << endl;

		f1.close();

		system("pause");
		system("cls");
	}
	else if (*a == 'D' | *a == 'd')
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		system("cls");
		int id;
		cout << "==========================================================================================================================================" << endl;
		cout << "Enter the ID of the room you want to delete: ";
		cin >> id;
		if (cin.fail())
		{
			cout << "Error 404! Invalid input. " << endl;
			system("pause");
			system("cls");
			exit(0);
		}


		else if (id > 999 | id <= 0)
		{
			cout << "Invalid value. Please try again." << endl;
			system("cls");
			system("pause");

			return;
		}

		fstream f1("sales.txt", ios::out | ios::in);

		f1.seekp(id * 147);
		char data[150];
		f1.getline(data, 147);

		if (strncmp(&data[5], "                                                  ", 25) == 0)
		{
			cout << "Record doesn't exist." << endl;
		}

		else
		{
			f1.seekp(147 * id + 5);

			f1 << left << setw(25) << " ";
			f1 << left << setw(15) << " ";
			f1 << left << setw(50) << " ";
			f1 << left << setw(10) << 0;
			f1 << left << setw(10) << 0;
			f1 << left << setw(5) << 0;
			f1 << left << setw(5) << "5%";
			f1 << left << setw(20) << 0 << endl;

			cout << "The data has been successfully removed." << endl;

		}
		cout << "==========================================================================================================================================" << endl;

		f1.close();

		system("pause");
		system("cls");
	}
	else if (*a == 'B' | *a == 'b')
	{

		system("cls");
		return;
	}
	else
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Invalid input. Try again. " << endl;
		system("pause");
		system("cls");
		return;
	}
	int ignore = strlen(a);
	cin.ignore();
	system("cls");

}

void policy()
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "==========================================================================================================================================" << endl;
	cout << "1\t No pets allowed." << endl;
	cout << "2\t No smoking allowed in rooms." << endl;
	cout << "3\t Editing of sales file is not allowed." << endl;
	cout << "4\t A person can stay a maximum of 99 days during a single transaction." << endl;
	cout << "5\t Room number cannot exceed 999." << endl;
	cout << "6\t Maximum amount of 100 rooms can be supported." << endl;
	cout << "7\t Maximum price of a room can be 999,999$" << endl;
	cout << "8\t Maximum area of 9999 meter square can be supported." << endl;
	cout << "9\t Maximum of 10,000 sales can be supported. Then data will need to be managed." << endl;
	cout << "10\t If the number of party members exceeds room size limit, the room cannot be booked." << endl;
	cout << "11\t Booked rooms cannot be checked- in, similarily, free rooms cannot be checked-out. " << endl;
	cout << "12\t A person may choose not to enter his phone number and simply enter blank, however, the input of name is essential." << endl;
	cout << "13\t All prices inclusive of tax." << endl;

	cout << "==========================================================================================================================================" << endl;

	system("pause");
	return;

}

void eraseAll()
{
	fstream f1;
	f1.open("products.txt", ios::out);

	fstream f2;
	f2.open("sales.txt", ios::out);


	f1 << left << setw(5) << "ID";
	f1 << left << setw(10) << "Room No#";
	f1 << left << setw(50) << "Name";
	f1 << left << setw(10) << "Size";
	f1 << left << setw(10) << "Area(m^2)";
	f1 << left << setw(10) << "Bed(s)";
	f1 << left << setw(20) << "Status";
	f1 << left << setw(10) << "Price($)" << endl;

	for (int i = 1; i <= 100; i++)
	{
		f1 << left << setw(5) << i;
		f1 << left << setw(10) << 0;
		f1 << left << setw(50) << "  ";
		f1 << left << setw(10) << 0;
		f1 << left << setw(10) << 0;
		f1 << left << setw(10) << 0;
		f1 << left << setw(20) << "Available ";
		f1 << left << setw(10) << 0 << endl;
	}


	f2 << left << setw(5) << "ID";
	f2 << left << setw(25) << "Customer Name";
	f2 << left << setw(15) << "Phone No#";
	f2 << left << setw(50) << "Room Name";
	f2 << left << setw(10) << "Room No#";
	f2 << left << setw(10) << "Price($)";
	f2 << left << setw(5) << "Days";
	f2 << left << setw(5) << "Tax%";
	f2 << left << setw(20) << "Total Cost" << endl;

	for (int i = 1; i <= 10000; i++)
	{
		f2 << left << setw(5) << i;
		f2 << left << setw(25) << " ";
		f2 << left << setw(15) << " ";
		f2 << left << setw(50) << " ";
		f2 << left << setw(10) << 0;
		f2 << left << setw(10) << 0;
		f2 << left << setw(5) << 0;
		f2 << left << setw(5) << 0;
		f2 << left << setw(20) << 0 << endl;
	}

	f1.close();
	f2.close();




	cout << "All data has been erased." << endl;


	system("pause");
	system("cls");


}

void checkOut()
{
	system("cls");
	int num;
	fstream f("products.txt", ios::in | ios::out);

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "==========================================================================================================================================" << endl;
	cout << "Enter the ID of the Room you would like to check-out: ";
	cin >> num;
	if (cin.fail())
	{
		cout << "Error 404! Invalid input. " << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	else if (num > 100 | num <= 0)
	{
		{
			cout << "Error 404! Invalid input. " << endl;
			system("pause");
			system("cls");
			return;
		}
	}

	f.seekp(num * 127);
	char data[130];
	f.getline(data, 127);


	if (strncmp(&data[95], "Available", 9) == 0)
	{
		cout << "This room is already available." << endl;
		cout << endl;
		system("pause");
		system("cls");
		return;
	}

	f.seekp(num * 127);
	char data2[130];
	f.getline(data2, 127);

	if (strncmp(&data2[15], "                                                  ", 50) == 0)
	{
		cout << "Room doesn't exist!" << endl;

		system("pause");
		system("cls");
		return;
	}

	f.seekp(127 * num + 95);
	f << left << setw(20) << "Available";

	f.close();

	cout << "The room has been checked out." << endl;

	
	system("pause");
	system("cls");
}

void available()
{
	system("cls");
	int num;
	fstream f1("products.txt", ios::in | ios::out);

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "==========================================================================================================================================" << endl;
	char data[130];
	int counter = 0;
	cout << left << setw(5) << "ID";
    cout << left << setw(10) << "Room No#";
	cout << left << setw(50) << "Name";
	cout << left << setw(10) << "Size";
	cout << left << setw(10) << "Area(m^2)";
	cout << left << setw(10) << "Bed(s)";
	cout << left << setw(20) << "Status";
	cout << left << setw(10) << "Price($)" << endl;
	while (!f1.eof())
	{

		f1.getline(data, 127);
		if (strncmp(&data[15], "                                                  ", 50) != 0 & strncmp(&data[95], "Available", 9) == 0)
		{
			cout << data << endl;
			cout << endl;
			counter++;
		}
	}
	if (counter == 0)
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "We are terribly sorry. All the rooms are currently booked. We apologize for the inconvenience." << endl;
		

		system("pause");
		system("cls");
		return;
	}
	cout << "==========================================================================================================================================" << endl;

	f1.close();

	system("pause");
	system("cls");


}
