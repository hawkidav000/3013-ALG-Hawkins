
///////////////////////////////////////////////////////////////////////////////
//
// Author:           David Hawkins
// Email:            david.james@hawkinsonline.us
// Label:            P01
// Title:            Assignment 4 - Resizing the Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 *      - See class below
 *
 * Usage:
 *      - See main program
 *
 */
class ArrayStack {
private:
	int *A;           // pointer to array of int's
	int size;         // current max stack size
	int top;          // top of stack 

public:
	/**
	 * ArrayStack
	 *
	 * Description:
	 *      Constructor no params
	 *
	 * Params:
	 *     - None
	 *
	 * Returns:
	 *     - NULL
	 */
	ArrayStack() {
		size = 10;
		A = new int[size];
		top = -1;
	}

	/**
	 * ArrayStack
	 *
	 * Description:
	 *      Constructor size param
	 *
	 * Params:
	 *     - int size
	 *
	 * Returns:
	 *     - NULL
	 */
	ArrayStack(int s) {
		size = s;
		A = new int[s];
		top = -1;
	}

	/**
	 * Public bool: Empty
	 *
	 * Description:
	 *      Stack empty?
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [bool] true = empty
	 */
	bool Empty() {
		return (top <= -1);
	}

	/**
	 * Public bool: Full
	 *
	 * Description:
	 *      Stack full?
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [bool] true = full
	 */
	bool Full() {
		return (top >= size - 1);
	}

	/**
	 * Public int: Peek
	 *
	 * Description:
	 *      Returns top value without altering the stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [int] top value if any
	 */
	int Peek() {
		if (!Empty()) {
			return A[top];
		}

		return -99; // some sentinel value
					// not a good solution
	}

	/**
	 * Public int: Pop
	 *
	 * Description:
	 *      Returns top value and removes it from stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [int] top value if any
	 */
	int Pop() {

		CheckResize();
		/*
		if ((top + 1) <= size / 2) {
				ContainerShrink();
			}
	*/
		if (!Empty()) {
			return A[top--];
		}

		return -99; // some sentinel value
					// not a good solution
	}

	/**
	 * Public void: Print
	 *
	 * Description:
	 *      Prints stack to standard out
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	void Print() {
		for (int i = 0; i <= top; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}

	int getSize() {
		return size;
	}

	/**
	 * Public bool: Push
	 *
	 * Description:
	 *      Adds an item to top of stack
	 *
	 * Params:
	 *      [int] : item to be added
	 *
	 * Returns:
	 *      [bool] ; success = true
	 */
	bool Push(int x) {

		CheckResize();
		/*
				if (Full()) {
					ContainerGrow();
				}
		*/
		if (!Full()) {
			A[++top] = x;
			return true;
		}

		return false;

	}

	/**
	 * Public void: ContainerGrow
	 *
	 * Description:
	 *      Resizes the container for the stack by doubling
	 *      its capacity
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	void ContainerGrow() {
		int newSize = size * 1.75;    // size of original increases by 1.75
		int *B = new int[newSize];  // allocate new memory

		for (int i = 0; i < size; i++) {    // copy values to new array
			B[i] = A[i];
		}

		delete[] A;                // delete old array

		size = newSize;             // save new size

		A = B;                      // reset array pointer

	}

	/**
	  * Public void: ContainerShrink
	  *
	  * Description:
	  *      Resizes the container for the stack by doubling
	  *      its capacity
	  *
	  * Params:
	  *      NULL
	  *
	  * Returns:
	  *      NULL
	  */
	void ContainerShrink() {
		int newSize = size / 2;
		int *B = new int[newSize];


		for (int i = 0; i < (top + 1); i++) {    // copy values to new array
			B[i] = A[i];
		}

		delete[] A;                // delete old array

		size = newSize;             // save new size

		A = B;                      // reset array pointer
	}

	/**
	  * Public void: CheckResize
	  *
	  * Description:
	  *      Resizes the container for the stack by doubling
	  *      its capacity
	  *
	  * Params:
	  *      NULL
	  *
	  * Returns:
	  *      NULL
	  */
	void CheckResize() {
		if (Full()) {
			ContainerGrow();
		}
		else if (((top + 1) < size / 2) && !Empty()) {
			ContainerShrink();
		}
	}

};

void openFiles(ifstream & infile);

void readValue(ifstream & infile, int &v);

bool evenOrOdd(int val);

void printResults(ArrayStack sta, int resized, int max);

void closeFiles(ifstream& infile);

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {

	ifstream infile;
	openFiles(infile);

	ArrayStack stack;                   //stack object
	int v = 0;							//holds read-in values
	int resize = 0;						//how many times stack resized
	int changeSize = 0;					//holds size before resizing

	readValue(infile, v);				//read in first value

	int maxSize = stack.getSize();		//get first size and make that maxsize

	while(!infile.eof())				//loops until end of file
	{

		changeSize = stack.getSize();

		if (evenOrOdd(v)) {
			stack.Push(v);
		}

		else {
			stack.Pop();
		}

		if(changeSize != stack.getSize()){
			resize++;
		}
		if(stack.getSize() > maxSize){
			maxSize = stack.getSize();
		}
		//read next value
		readValue(infile, v);
	}

	printResults(stack, resize, maxSize);

	closeFiles(infile);

	system("pause");
	return 0;

}

void openFiles(ifstream & infile){
	char inFileName[40];
	cout << "Enter the input file name: ";
	cin >> inFileName; infile.open(inFileName);
}

void readValue(ifstream & infile, int &v){
	infile >> v;
}

bool evenOrOdd(int val) {
	if (val % 2 == 0) {
		return true;      //if the value is even, function returns true
	}
	else {
		return false;     //if the value if odd, function returns false
	}
}

void printResults(ArrayStack sta, int resized, int max) {
	cout << "##########################################################" << endl;
	cout << "\tAssignment 4 - Resizing the Stack" << endl;
	cout << "\tCMPS 3013" << endl;
	cout << "\tDavid Hawkins" << endl << endl;
	cout << "\tMax Size:\t\t" << max << endl;
	cout << "\tEnd Stack Size:\t\t" << sta.getSize() << endl;
	cout << "\tStack Resized:\t\t" << resized << " times" << endl;
	cout << "##########################################################" << endl;
}

void closeFiles(ifstream& infile)
{
	infile.close();
}