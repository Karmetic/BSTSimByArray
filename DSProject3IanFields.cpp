//Ian Fields
//7/23/2021
//DS Project 3
//A program that simulates a binary search tree using a one dimensional array

#include <iomanip>
#include <iostream>
using namespace std;

class BST 
{

public:
	int bst_arr[100]; 
	int value;
	int max;
	int min;

	BST() //Initializes all variables, including the BST array that will be simulated.
	{
		value = NULL; //Value passed from main
		max = NULL; //Maximum value in tree
		min = NULL; //Minimum value in tree
		index = 0; //Counter for insert
		parent = 0; //Parent tracker for insert
		root = NULL;

		//Initializing elements in the binary search tree array to NULL.
		for (int L = 0; L < 100; L++)
			bst_arr[L] = NULL;
	}

	void Search(int value) //A function that searches the binary search tree array to return an index storing a particular element. Prints all elements in that search path.
	{
		cout << "\nSearch: ";
		index = 0;
		parent = bst_arr[(index - 1) / 2];

		if (bst_arr[0] == NULL) //Checks to see if the inserted value is the root, if so, then simply assign the passed value as the root.
		{
			bst_arr[0] = value;
			parent = bst_arr[0];
			cout << parent << endl;
		}
		else
		{
			while ((parent != NULL) && (bst_arr[parent] != value))
			{
				//Find the position for the new value by comparing it to the current parent
				if (value < parent)
				{
					index = (2 * index) + 1;
					parent = bst_arr[index];
					cout << index << " "; //Print index

					if (parent == value)
						break;
				}
				else if (value > parent)
				{
					index = (2 * (index)) + 2;
					parent = bst_arr[index];
					cout << index << " "; //Print index
					
					if (parent == value)
						break;
				}
			}
			if (parent == NULL) //Once the position is established, this if else set determines whether a child is a left or right child, and then resets the index to figure out the next inserts path
			{
				if (value < bst_arr[(index - 1) / 2])
				{
					bst_arr[(2 * ((index - 1) / 2)) + 1] = value; //Left child is assigned the new value
					index = 0;
				}
				else if (value > bst_arr[(index - 1) / 2])
				{
					bst_arr[(2 * ((index - 1) / 2)) + 2] = value; //Right child is assigned the new value
					index = 0;
				}
			}

		}
	}

	void Find_max() //Finds and displays the maximum value in the BST.
	{
		index = 0; 

		while (bst_arr[(2 * index) + 2] != NULL)
		{
			index = (2 * index) + 2;
		}
		cout << "\nMax: " << bst_arr[index] << endl;
		
	}

	void Find_min() //Finds and displays the minimum value in the BST.
	{
		index = 0;

		while (bst_arr[(2 * index) + 1] != NULL)
		{
			index = (2 * index) + 1;
		}

		cout << "\nMin: " << bst_arr[index] << endl;
	}

	void Print_BST() //Prints the Binary Search Tree in array form, including indexes.
	{
		index = 0;
		cout << "Index: " << "      " << "Value: " << endl;

		for (int k = 0; k < 100; k++) //A for loop that goes through the entire array. If the index is null (aka an empty leaf) then it skips the index to make the tree look cleaner visually.
		{
			if (bst_arr[index] != NULL)
			{
				cout << index << "         " << bst_arr[k];
				cout << endl;
			}
			
			index++;
		}
	}

	void Insert(int value) //Inserts a passed value into the BST
	{
		parent = bst_arr[(index - 1) / 2]; //Initialize parent

		if (bst_arr[0] == NULL) //Checks to see if the inserted value is the root, if so, then simply assign the passed value as the root.
		{
			bst_arr[0] = value;
			parent = bst_arr[0];
		}
		else
		{
			while ((parent != NULL) && (bst_arr[parent] != value))
			{
				//Find the position for the new value by comparing it to the current parent
				if (value < parent)
				{
					index = (2 * index) + 1;
					parent = bst_arr[index];
				}
				else if (value > parent)
				{
					index = (2 * (index)) + 2;
					parent = bst_arr[index];
				}
			} 
			if (parent == NULL) //Once the position is established, this if else set determines whether a child is a left or right child, and then resets the index to figure out the next inserts path
			{
				if (value < bst_arr[(index - 1) / 2])
				{
					bst_arr[(2 * ((index - 1) / 2)) + 1] = value; //Left child is assigned the new value
					index = 0;
				}
				else if (value > bst_arr[(index - 1) / 2])
				{
					bst_arr[(2 * ((index - 1) / 2)) + 2] = value; //Right child is assigned the new value
					index = 0;
				}
			}
			else
				cout << "node duplicate!" << endl;
			
		}
	}

	private: 
		int index;
		int parent;
		int root;
};

int main()
{
	BST Tree;

	Tree.Insert(5);
	Tree.Insert(8);
	Tree.Insert(3);
	Tree.Insert(1);
	Tree.Insert(4);
	Tree.Insert(9);
	Tree.Insert(18);
	Tree.Insert(20);
	Tree.Insert(19);
	Tree.Insert(2);
	Tree.Print_BST();
	Tree.Find_max();
	Tree.Find_min();
	Tree.Search(3);
	Tree.Search(18);
	Tree.Search(19);
	
	cout << endl;

}