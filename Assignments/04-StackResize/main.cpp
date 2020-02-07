
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
//		This program uses a class to implement an array-based stack. The stack
//		class is written in a way that allows the size of the stack to change
//		when it reaches capacity or when it becomes half-full. However, just
//		like a normal stack, it still pushes, pops, and checks if empty/full.
//		The program reads in from a file of large positive numbers, and if a
//		value read-in is even, it is pushed onto the stack; if the value is
//		odd, the program pops one of the even numbers off of the stack.
//
// Usage:
//		When you run the program, you will be prompted with message telling you
//		to write in the name of the file. Write the name of the file and press
//		enter, and the program will begin reading from the file you selected.
//		After the program has finished reading in values and altering the
//		stack, a prompt will appear that reads "Press any key to continue..."
//		Simply press a key and the program will stop running.
//
// Files:
//		main.cpp		: Driver program
//		nums.dat		: Input file	
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      An array-based stack that pushes and pops values onto itself. It is
 * 		implemented in such a way that allows it to resize itself if it
 * 		reaches capacity or becomes half-full.
 *
 * Public Methods:
 *      				ArrayStack()
 * 						ArrayStack(int s)
 * 		bool			Empty()
 * 		bool			Full()
 * 		int				Peek()
 * 		int				Pop()
 * 		void			Print()
 * 		void			Push(int x)
 * 		void			ContainerGrow()
 * 		void			ContainerShrink()
 * 		void			CheckResize()
 *
 * Usage:
 *      Used to hold values read-in from a file of 100000 numbers. When a value
 * 		is found to be even, it would get pushed onto the stack. When a value
 * 		is found odd, an item is popped off of the stack. Each time a value is
 * 		popped or pushed, the CheckResize method checks to see if the size of
 * 		the stack needs to be modified by checking to see if it's full or if
 * 		the ratio between (top + 1) and size is less than one-half.
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
	 *      Default Constructor. Sets size to 10, dynamically allocates the
	 * 		array, and sets top equal to -1.
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
	 *      Parameterized Constructor. Sets size to the value passed to it,
	 * 		dynamically allocates the array, and sets top equal to -1.
	 *
	 * Params:
	 *     - None
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
	 *      Checks to see if the stack is empty or not.
	 *
	 * Params:
	 *		- NULL
	 *
	 * Returns:
	 *      - [bool] true = empty
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
	 *      Returns top value without altering the stack.
	 *
	 * Params:
	 *      - NULL
	 *
	 * Returns:
	 *      - [int] top value if any
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
	 *      Checks to see if the stack's size needs to be altered, then returns
	 * 		top value and removes it from stack.
	 *
	 * Params:
	 *      - NULL
	 *
	 * Returns:
	 *      - [int] top value if any
	 */
	int Pop() {

		CheckResize();	//Checks to see is size needs to be altered

		if (!Empty()) {
			return A[top--];
		}

		return -99; 	// some sentinel value
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

	/**
	 * Public int: getSize
	 *
	 * Description:
	 *      Returns size of the stack
	 *
	 * Params:
	 *      - NULL
	 *
	 * Returns:
	 *      - [int] : size of the stack
	 */
	int getSize() {
		return size;
	}

	/**
	 * Public bool: Push
	 *
	 * Description:
	 *      Checks to see if the stack's size needs to be altered, then adds an
	 * 		item to top of stack.
	 *
	 * Params:
	 *      - [int] : item to be added
	 *
	 * Returns:
	 *      - [bool] : success = true
	 */
	bool Push(int x) {

		CheckResize();	//Checks to see is size needs to be altered

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
	 *      Resizes the container for the stack by increasing its capacity
	 * 		by 1.75.
	 *
	 * Params:
	 *      - NULL
	 *
	 * Returns:
	 *      - NULL
	 */
	void ContainerGrow() {
		int newSize = size * 1.75;    		// size of orig increases by 1.75
		int *B = new int[newSize];  		// allocate new memory

		for (int i = 0; i < size; i++) {	// copy values to new array
			B[i] = A[i];
		}

		delete[] A;                			// delete old array

		size = newSize;             		// save new size

		A = B;                      		// reset array pointer

	}

	/**
	  * Public void: ContainerShrink
	  *
	  * Description:
	  *      Resizes the container for the stack by halfing its capacity.
	  *
	  * Params:
	  *      - NULL
	  *
	  * Returns:
	  *      - NULL
	  */
	void ContainerShrink() {
		int newSize = size / 2;					//size of original cut in half
		int *B = new int[newSize];


		for (int i = 0; i < (top + 1); i++) {	// copy values to new array
			B[i] = A[i];
		}

		delete[] A;                				// delete old array

		size = newSize;             			// save new size

		A = B;                      			// reset array pointer
	}

	/**
	  * Public void: CheckResize
	  *
	  * Description:
	  *      Checks if the container needs to be resized
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
		else if (((top + 1) < size / 2) && size >= 10) {	//checks ratio AND if
			ContainerShrink();							//stack is empty
		}
	}

};

/*****************************************************
 * 
 * Function Prototypes
 * 
 ****************************************************/

void openFiles(ifstream & infile);

void readValue(ifstream & infile, int &v);

bool evenOrOdd(int val);

void printResults(ArrayStack sta, int resized, int max);

void closeFiles(ifstream& infile);

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {

	ifstream infile;						//input file object
	openFiles(infile);

	ArrayStack stack;                   	//stack object
	int v = 0;								//holds read-in values
	int resize = 0;							//how many times stack resized
	int changeSize = 0;						//holds size before resizing

	readValue(infile, v);					//read in first value

	int maxSize = stack.getSize();			//get first size sets to maxsize

	while(!infile.eof())					//loops until end of file
	{

		changeSize = stack.getSize();		//records size before push/pop

		if (evenOrOdd(v)) {
			stack.Push(v);
		}

		else {
			stack.Pop();
		}

		if(changeSize != stack.getSize()){	//checks if size was changed
			resize++;						//increments # of resizes
		}
		if(stack.getSize() > maxSize){		//if size > maxSize, then size
			maxSize = stack.getSize();		//is the new maxSize
		}

		readValue(infile, v);				//read next value
	}

	printResults(stack, resize, maxSize);

	closeFiles(infile);

	system("pause");
	return 0;

}

/**
* void: openFiles
*
* Description:
*		Opens the file to be read from
*
* Params:
*      - [ifstream] : stream object that reads from the file
*
* Returns:
*      - NULL
*/
void openFiles(ifstream & infile){
	char inFileName[40];
	cout << "Enter the input file name: ";
	cin >> inFileName; infile.open(inFileName);
}

/**
* void: readValue
*
* Description:
*      Reads in the next value from the file using the infile object
*
* Params:
*		- [ifstream] : used to read-in values
*		- [int&] : reference variable that holds read-in values
*
* Returns:
*		- NULL
*/
void readValue(ifstream & infile, int &v){
	infile >> v;
}

/**
* bool: evenOrOdd
*
* Description:
*		Checks to see if the value read in from the file is an even or odd #
*
* Params:
*      - [int] : value read in from the file
*
* Returns:
*      - [bool] : true = value was even
*/
bool evenOrOdd(int val) {
	if (val % 2 == 0) {
		return true;      //if the value is even, function returns true
	}
	else {
		return false;     //if the value if odd, function returns false
	}
}

/**
* void: printResults
*
* Description:
*		Prints the results of maxSize, Ending Stack Size, and how many times
*		the stack was resized to the standard out.
*
* Params:
*      - [ArrayStack] : stack object. Get final size from this object.
*	   - [int] : how many times the stack was resized
*	   - [int] : the maximum size that the stack reached
*
* Returns:
*      - NULL
*/
void printResults(ArrayStack sta, int resized, int max) {
	cout << "########################################################" << endl;
	cout << "\tAssignment 4 - Resizing the Stack" << endl;
	cout << "\tCMPS 3013" << endl;
	cout << "\tDavid Hawkins" << endl << endl;
	cout << "\tMax Size:\t\t" << max << endl;
	cout << "\tEnd Stack Size:\t\t" << sta.getSize() << endl;
	cout << "\tStack Resized:\t\t" << resized << " times" << endl;
	cout << "########################################################" << endl;
}

/**
* void: closeFiles
*
* Description:
*		Closes the files that were opened for reading.
*
* Params:
*      - [ifstream] : stream object used to read
*
* Returns:
*      - NULL
*/
void closeFiles(ifstream& infile)
{
	infile.close();
}