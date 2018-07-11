#include <iostream>
#include <cstdlib>
#include "food.cpp"
#include <fstream>
using namespace std;
void readFromFile(LinkedList * list)
{
	string buffer = "";
	char command;
	double serving;
	double protein;
	double fat;
	double carb;
	ifstream infile;
	infile.open("output.txt", ios::in);

	while(infile)
	{
		command = 'c';
		infile >> command;
		//cout << command << endl;
		switch(command)
		{
			case 'a': {
					  infile.ignore();
					  getline(infile, buffer);
					  infile >> serving;
					  infile >> protein;
					  infile >> carb;
					  infile >> fat;
					  list -> add(buffer, serving, protein, carb, fat);
					  break;
				  }
			case 'r': { 
					  infile.ignore();
					  getline(infile, buffer);
					  list -> remove(buffer);
					  break;
				  }
		}
	}
	infile.close();



}
int main()
{
	string buffer = "";
	char command;
	double serving;
	double protein;
	double fat;
	double carb;
	LinkedList * list = new LinkedList();
	ofstream myfile;
	myfile.open("output.txt", ios_base::app);


	readFromFile(list);
	while (cin)
	{
		command = 'c';      //resets the character
		cout << "Please enter a command ((a)dd, (r)emove, (p)rint, (d)elete the list)";
		cin >> command;
		cout << endl;

		switch (command) 
		{
			case 'a': {
					  myfile << 'a' << endl;
					  cout << "Food name: ";
					  cin.ignore();
					  getline(cin, buffer); 
					  myfile << buffer << endl;

					  cout << "number of Servings :";
					  cin >> serving;
					  myfile << serving << endl;

					  cout << "grams of Protein :";
					  cin >> protein;
					  myfile << protein << endl;

					  cout << "grams of Carbs :";
					  cin >> carb;
					  myfile << carb << endl;

					  cout << "grams of Fat :";
					  cin >> fat;
					  myfile << fat << endl;

					  list -> add(buffer, serving, protein, carb, fat);
					  break;
				  }

			case 'r': {
					  myfile << 'r' << endl;
					  cout << "Enter the food to remove: ";
					  cin.ignore();
					  getline(cin, buffer);
					  myfile << buffer << endl;
					  if(list -> remove(buffer))
					  {
						  cout<< buffer << " REMOVED" << endl;
					  }
					  else
					  {
						  cout << "REMOVE FAILED"<< endl;
					  }
					  break;
				  }


			case 'p': {
					  list -> print();
					  break;
				  }
				  

			case 'd': {
					  cout << "Are you sure you want to delete the list? (y)es / (n)o";
					  cin >> command;
					  if(command == 'y')
					  {
					  remove("output.txt");
					  list -> removeAllNodes(); 
					  }
					  break;
				  }
				  
		}
	

	}
 	delete list;

	


}

