
///////////////////////////////////////////////////////////////////////////////
//
// Authors:          David Hawkins, Terry Griffin
// Email:            david.james@hawkinsonline.us
// Label:            P01
// Title:            Assignment 7 - Heapify Debacle
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//		This program implements a min heap class and demonstrates its
//		functionality in main() by inserting values, then taking a list of
//		unsorted values and "heapifying" it.
//
// Files:
//		heap_working.cpp		: Driver program	
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

/**
 * Class Heap
 *
 * @methods:
 *      constructors:
 *          Heap        : default constructor
 *          Heap(int)   : overload constructor with heap size
 *      private:
 *          BubbleUp    : you comment this
 *          Left        : you comment this
 *          OnHeap      : you comment this
 *          Parent      : you comment this
 *          Right       : you comment this
 *          Swap        : you comment this
 *          /// Fix These:
 *          SinkDown    : you comment this
 *          PickChild   : you comment this
 *      public:
 *          Insert      : you comment this
 *          Print       : you comment this
 *          Remove      : you comment this
 */
class Heap {
private:
	int size; // size of the array
	int *H;   // array pointer
	int end;  // 1 past last item in array

	/**
   * BubbleUp
   *
   * @description:
   *    This puts one value into its proper
   *    place in the heap.
   *
   * @param  {int} index : index to start bubbling at
   * @return             : void
   */
	void BubbleUp(int index) {
		// check parent is not of beginning of array
		if (Parent(index) >= 1) {
			// index is on array and value is less than parent
			while (index > 1 && H[index] < H[Parent(index)]) {
				// do a swap
				Swap(index, Parent(index));

				// update index to values new position
				index = Parent(index);
			}
		}
	}

	/**
	 * Left
	 * @description:
	 *      Calculates index of left child.
	 *
	 * @param  {int} index : index of parent
	 * @return {int}       : index of left child
	 */
	int Left(int index) {
		return 2 * index;
	}

	/**
	 * OnHeap
	 * @description:
	 *      Checks if an index is on the array (past the end).
	 *
	 * @param  {int} index : index to check
	 * @return {bool}      : 0 = off heap / 1 = on heap
	 */
	bool OnHeap(int index) {
		return index < end;
	}

	/**
	 * Parent
	 * @description:
	 *      Calculates parent of a given index.
	 *
	 * @param  {int} index : index to check
	 * @return {int}       : parent index
	 */
	int Parent(int index) {
		return index / 2;
	}

	/**
	 * Right
	 * @description:
	 *      Calculates index of right child.
	 *
	 * @param  {int} index : index of parent
	 * @return {int}       : index of right child
	 */
	int Right(int index) {
		return 2 * index + 1;
	}

	/**
	 * Swap
	 *
	 * @description:
	 *      Swaps to values in the heap
	 *
	 * @param  {int} i  : index in array
	 * @param  {int} j  : index in array
	 * @return          : void
	 */
	void Swap(int i, int j) {
		int temp = H[i];
		H[i] = H[j];
		H[j] = temp;
	}

	////////////////////////////
	//Fix These Methods
	////////////////////////////

	/**
	 * SinkDown
	 * @description:
	 *      Places one heap item into its proper place in the heap
	 *      by bubbling it down to it proper location.
	 *
	 * @param  {int} index  : index to start from in the array
	 * @return              : void
	 */
	void SinkDown(int index) {
		int newIndex = 0;
		while ((index <= end) && 
		(H[index] > H[Left(index)] || H[index] > H[Right(index)])) {
			newIndex = PickChild(index);
			if (OnHeap(newIndex)) {
				Swap(index, newIndex);
			}
			index = newIndex;
		}
	}

	/**
	 * PickChild
	 * @description:
	 *      If one child exists, return it.
	 *      Otherwise, return the smaller of the two.
	 *
	 * @param  {int} index  : index of parent in the array
	 * @return              : index to child
	 */
	int PickChild(int index) {
		if (OnHeap(Left(index))) {
			if (!OnHeap(Right(index))) {
				return Left(index);
			}
			else {
				if (H[Left(index)] <= H[Right(index)]) {
					return Left(index);
				}
				else if (H[Left(index)] >= H[Right(index)]) {
					return Right(index);
				}
			}
		}
		else {
			return end + 1;
		}
	}

public:
	/**
   * Heap constructor
   */
	Heap() {
		size = 100;
		H = new int[size];
		end = 1;
	}

	/**
   * Heap constructor
   *
   * @param  {int} s : heap size
   */
	Heap(int s) {
		size = s;
		H = new int[s];
		end = 1;
	}

	/**
   * Insert
   *
   * @description:
   *        Add a value to the heap.
   *
   * @param  {int} x : value to Insert
   * @return         : void
   */
	void Insert(int x) {
		H[end] = x;
		BubbleUp(end);
		end++;
	}

	/**
	 * Print
	 * 
	 * @description:
	 * 		Prints the contents of the heap
	 * 
	 * @param  		: none
	 * @return		: none
	 */
	void Print() {
		for (int i = 1; i <= end - 1; i++) {
			cout << H[i];
			if (i < end - 1) {
				cout << "->";
			}
		}
	}

	/**
	 * Remove
	 * @description:
	 *      Removes item from top of heap
	 *
	 * @return {int}  : top of heap
	 */
	int Remove() {
		int temp = H[1];
		H[1] = H[end-1];
		--end;
		SinkDown(1);

		return temp;
	}

	/**
	 * Heapify
	 * @description:
	 * 		Sorts an unsorted list of values into min-heap order
	 *
	 * @param  {int*} A   :  array pointer with unsorted values to make into a heap
	 * @param  {int} size :  size of new heap
	 */
	void Heapify(int *A, int size) {
		for (int i = 0; i < size; i++){
			Insert(A[i]);
		}
		end = size + 1;
	}
};

int main() {
	Heap H;							//Heap object that uses sorted values
	Heap J;							//Heap object that stores unsorted values
	int size = 15;					//Size of dynamically allocated array
	int* A = new int[size];			//Array that stores unsorted values

	for (int i = 1; i <= 15; i++) {	//These statements will fill the heap of
		H.Insert(rand() % 50);		//sorted values
	}
    H.Print();
    cout << endl;

    for (int i = 1; i < 4; i++){	//This demonstrates the functionality of
	    H.Remove();					//the remove method
	}
	H.Print();

	for (int i = 0; i < 15; i++){	//Fills the array of unsorted values with
		A[i] = rand() % 50;			//random numbers
	}

	cout << "\nUnsorted values: ";
	for (int i = 0; i < size; i++){	//Prints the array of unsorted values
		cout << A[i];
		if (i < size - 1) {
			cout << "->";
		}
	}

	J.Heapify(A, size);				//Sorts the values into min-heap order

	cout << "\nSorted values: ";
	J.Print();						//Prints the sorted values
}