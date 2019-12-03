//============================================================================
// Name        : Josephus.cpp
// Author      : Daniel Matsunaga
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// ECE304project1_1.cpp : User friendly application to solve a Josephus problem
//

#include <iostream>
#include <iomanip>
#include<cstdio>
#include<cstdlib>
#include <string>

using namespace std;

struct lnode {
	int data;
	lnode *next;
}*last;

class circularList
{
  public:
	  void createNode(int value);
	  void addNode(int value);
	  void update(int value, int pos);
	  int GetNth(int index);
};


int main()
{
	//Declaration of variables
	string name,answer;
	int N, M ;
	circularList c;

	//Prompt user to input data
	cout <<"Hi, welcome to the Josephus Solver \nEnter your name please? ";
	getline(cin, name);
	cout << name + ", please enter the number of people: ";
	cin >> N;
	cout << "Thanks, now, please enter the number to be skipped: ";
	cin >> M;

	//populate the linked list
	int count = N;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			c.createNode(count); //create the first node
		}
		if (i == N - 1)
		{
			c.addNode(1);//add last node
		}
		else
		{
			c.addNode(count); //add more nodes
		}

		count--;
	}

	//declare variables
	int x = M-1;
	int num = 0;
	int counter = 0;

	cout << "Good deal, " << name << "! Here is the order of the execution :" << endl;

	//algorithm to print out sequence
	while (num < N)//loop through N times
	{

		if (x > N-1)//resets x to 0 if it increments above N
		{
			x = 0;
		}

		while (c.GetNth(x) == -1)//check if the node has been visited
		{
			x++;//go to the next node, but don't increase the count if it has been visited

			if (x > N - 1)//resets x to 0 if it increments above N
			{
				x = 0;
			}
		}

		if (counter%M == 0)//used to tell if it is the Mth node
		{
			cout << c.GetNth(x);//print out the value of the Nth node
			if (num != N - 1)
			{
				cout << " -> ";
			}
			c.update(-1, x);//update the node if it has already been visited
			num++;//increment the while loop
		}


		x++;
		counter++;//increment M
	}

	cout << endl << endl;

	cout << "Do you want to continue? " << name <<"? (Enter yes or no): ";
	cin >> answer;
	cout << endl << endl;
	while (answer == "yes")
	{
		//Prompt user to input data
		cout << "Hi, welcome to the Josephus Solver " << name << "." << endl;
		cout << name + ", please enter the number of people: ";
		cin >> N;
		cout << "Thank you, now, please enter the number to be skipped: ";
		cin >> M;

		//populate the linked list
		int count = N;
		for (int i = 0; i < N; i++)
		{
			if (i == 0)
			{
				c.createNode(count); //create the first node
			}
			if (i == N - 1)
			{
				c.addNode(1);//add last node
			}
			else
			{
				c.addNode(count); //add more nodes
			}

			count--;
		}

		//declare variables
		int x = M - 1;
		int num = 0;
		int counter = 0;

		cout << "Good deal, " << name << "! Here is the order of the execution :" << endl;

		//algorithm to print out sequence
		while (num < N)//loop through N times
		{

			if (x > N - 1)//resets x to 0 if it increments above N
			{
				x = 0;
			}

			while (c.GetNth(x) == -1)//check if the node has been visited
			{
				x++;//go to the next node, but don't increase the count if it has been visited

				if (x > N - 1)//resets x to 0 if it increments above N
				{
					x = 0;
				}
			}

			if (counter%M == 0)//used to tell if it is the Mth node
			{
				cout << c.GetNth(x);//print out the value of the Nth node
				if (num != N - 1)
				{
					cout << " -> ";
				}
				c.update(-1, x);//update the node if it has already been visited
				num++;//increment the while loop
			}


			x++;
			counter++;//increment M
		}

		cout << endl << endl;
		cout << "Do you want to have more fun " << name << "? (Enter yes or no): ";
		cin >> answer;

	}
	cout << "Thank you and have a good day " << name << "." << endl << endl;




	system("pause");
    return 0;
}

void circularList::createNode(int value)//this function creates the first node
{
	struct lnode *temp;
	temp = new (struct lnode);
	temp->data = value;

	if (last == NULL)
	{
		last = temp;
		temp->next = last;
	}
	else
	{
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}


void circularList::addNode(int value)//this function adds a node to the linked list with a value
{
	struct lnode *temp;
	temp = new(struct lnode);
	temp->data = value;
	temp->next = last->next;
	last->next = temp;

}


void circularList::update(int value,int pos)//this function updates the value at the index
{

	struct lnode *s;
	s = last->next;
	for (int i = 0; i < pos ; i++)//traverse through linked list to the position
	{
		s = s->next;
	}
	s->data = value;//set the node to a new value
}


int circularList::GetNth(int index)//This function returns the value at the index
{
	struct lnode* s;
	s = last->next;
	int count = 0;
	while (s != last)
	{
		if (count == index)
		{
			return(s->data);//return the node at the index
		}
		count++;
		s = s->next;
	}
	return 0;//If it returns 0, then it means that the element at the index does not exist
}

