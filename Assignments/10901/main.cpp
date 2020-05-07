#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> ii;
#define endl "\n"

/*****************************************************
Class Name: SortedList

Purpose:
The SortedList class creates doubly linked lists. It
includes member functions that insert nodes in order,
remove nodes from the list, return the size of the
linked list, and display the contents of the list in
either correct or reverse order.
*****************************************************/
class SortedList {
protected:
	struct Node {
		ii value;
		Node* next;
		Node* prev;
		Node(ii num, Node* a, Node* b = NULL) {
			value.first = num.first;
      value.second = num.second;
			prev = a;
			next = b;
		}
	};
private:
	Node* head;
public:
	SortedList();
	~SortedList();
	void insert(ii num);
	//void remove(double num);
	void display();
	int size();
	//void displayReversed(ofstream &out);
};

/*************************************************
Default Constructor
*************************************************/
SortedList::SortedList()
{
	head = NULL;
}

/*************************************************
Destructor
*************************************************/
SortedList::~SortedList() {
	Node* tmp = head;
	while (tmp != NULL) {
		head = head->next;
		delete tmp;
		tmp = head;
	}
}

/*************************************************
Member Functions
*************************************************/


/*****************************************************
Function Name: insert

Input: A double that is the value of the new node
	being inserted into the list.
Process: Using a series of if-else statements, the
	function determines if the new node needs to be
	inserted at the beginning, in the middle, or at
	the end of the list.
Result: A new node with the new value is inserted in
	order into the list.
*****************************************************/
void SortedList::insert(ii num) {
	//if there's an empty list
	if (head == NULL)
		head = new Node(num, NULL);
	else {
		//insert at beginning
		if (num.first < head->value.first)
			head = head->prev = new Node(num, NULL, head);
		//insert in middle
		else {
			Node* tmp = head;
			while (tmp->next != NULL && num.first > tmp->value.first) {
				tmp = tmp->next;
			}
			if (num.first > tmp->value.first) {
				tmp->next = new Node(num, tmp);
				tmp = NULL;
			}
			else {
				tmp->prev = tmp->prev->next = new Node(num, tmp->prev, tmp);
				tmp = NULL;
			}
		}
	}
}

/*****************************************************
Function Name: remove

Input: A double that is the value to be deleted from
	the list.
Process: Using a series of if-else statements, the
	function checks to see if the list is empty. If
	the list is populated, then the function searches
	for that value and deletes it. If it's not found,
	nothing happens.
Result: Either a value is deleted from the list, or
	nothing happens.
*****************************************************/
// void SortedList::remove(double num) {
// 	Node* tmp = head;
// 	//first check to see if the list is empty
// 	if (head != NULL) {
// 		//now check to see if the value is the first in the list
// 		if (head->value == num) {
// 			head = head->next;
// 			head->prev = NULL;
// 			delete tmp;
// 			tmp = NULL;
// 		}
// 		//advance the tmp pointer to find the value in the list
// 		else {
// 			while (tmp != NULL && tmp->value != num)
// 				tmp = tmp->next;
// 		}
// 		//execute these instructions only if value found
// 		if (tmp != NULL) {
// 			tmp->prev->next = tmp->next;
// 			tmp->next->prev = tmp->prev;
// 			delete tmp;
// 			tmp = NULL;
// 		}
// 	}
// }

/*****************************************************
Function Name: display

Input: The ofstream object that allows the function to
	print to the output file.
Process: Prints the value of the node to the outfile
	and advances the pointer until it reaches NULL.
Result: List printed to output file.
*****************************************************/
void SortedList::display() {
	Node* tmp = head;
	while (tmp != NULL) {
		cout << tmp->value.second << endl;
		tmp = tmp->next;
	}
}

/*****************************************************
Function Name: size

Input: None.
Process: Increments a counter for every node found in
	the list and advances the pointer.
Result: Returns the counter.
*****************************************************/
int SortedList::size() {
	Node* tmp = head;
	int counter = 0;
	while (tmp != NULL) {
		counter++;
		tmp = tmp->next;
	}
	return counter;
}

/*****************************************************
Function Name: displayReversed

Input: The ofstream object that allows the function to
	print to the output file.
Process: Advances a pointer to the end of the list and
	prints the values in reverse until it reaches NULL
	at the beginning of the list.
Result: List printed to output file in reverse order.
*****************************************************/
// void SortedList::displayReversed(ofstream &out) {
// 	Node* tmp = head;
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	while (tmp != NULL) {
// 		out << tmp->value << "     ";
// 		tmp = tmp->prev;
// 	}
// 	out << endl;
// }

queue<ii> carsLeft;
queue<ii> carsRight;

int main() {
  int numCases;         //number of cases in input file
  int maxCars;          //number of cars the ferry can carry
  int travTime;         //how long it takes the ferry to travel
  int numCars;          //number of cars that will be carried across
  string bank = "";     //string that stores bank side
  int arrTime;          //time that the car arrives at the bank
  int ferryPos;         //side of the river that the ferry is on
  int currentTime;      //keeps track of the current time
  bool loaded = false;  //checks to see if the boat loaded any cars
  int priority;         //Keeps the order in which the cars arrive include
  bool firstCar;        //Keeps track of whether or not the first car has been loaded
  int numLoaded;        //Keeps track of number loaded on boat

  SortedList* LIST = new SortedList;

  cin >> numCases;

  for(int i = 0; i < numCases; i++)
  {
    ferryPos = 0;
    currentTime = 0;
    priority = 0;
    firstCar = false;
    numLoaded = 0;
  
    cin >> maxCars >> travTime >> numCars;

    for(int n = 0; n < numCars; n++)
    {
      cin >> arrTime >> bank;
      if (bank == "left")
        carsLeft.push(make_pair(priority, arrTime));
      else if (bank == "right")
        carsRight.push(make_pair(priority, arrTime));
      bank = "";
      priority++;
    }

    //cout << "Hello!" << endl;

    int leftSize = carsLeft.size();
    int rightSize = carsRight.size();

    //Checking to make sure the cars are read in correctly
    // for (int m = 0; m < leftSize; m++)
    // {
    //   cout << carsLeft.front().second << endl;
    //   carsLeft.pop();
    // }

    // for (int m = 0; m < rightSize; m++)
    // {
    //   cout << carsRight.front().second << endl;
    //   carsRight.pop();
    // }

    while(!carsLeft.empty() || !carsRight.empty())
    {
      if (ferryPos == 0)
      {
        for (int n = 0; n < maxCars && numLoaded < maxCars; n++)
        {
          if (!carsLeft.empty() && (carsLeft.front().second <= currentTime))
          {
            if (firstCar == false && (carsLeft.front().second <= currentTime))
            {
              LIST->insert(make_pair(carsLeft.front().first, carsLeft.front().second + travTime));
              currentTime = carsLeft.front().second;
              carsLeft.pop();
              loaded = true;
              firstCar = true;
              numLoaded++;
            }
            else if (firstCar == true && (carsLeft.front().second <= currentTime) && numLoaded < maxCars)
            {
              //cout << currentTime + travTime << endl;
              LIST->insert(make_pair(carsLeft.front().first, currentTime + travTime));
              carsLeft.pop();
              // if (!carsLeft.empty() && !carsRight.empty())
              // {
              //   cout << endl;
              // }
              loaded = true;
              numLoaded++;
            }
          }
        }
        if ((!carsRight.empty() && carsRight.front().second <= currentTime) || loaded)
        {
          ferryPos++;
          currentTime = currentTime + travTime;
        }
        else
          currentTime = currentTime + 1;
        loaded = false;
        numLoaded = 0;
      }
      if (ferryPos == 1)
      {
        for (int n = 0; n < maxCars && numLoaded < maxCars; n++)
        {
          if (!carsRight.empty() && (carsRight.front().second <= currentTime) && numLoaded < maxCars)
          {
            // if (firstCar == false && (carsRight.front().second <= currentTime))
            // {
            //   LIST->insert(make_pair(carsRight.front().first, carsRight.front().second + travTime));
            //   currentTime = carsRight.front().second;
            //   carsRight.pop();
            //   loaded = true;
            //   firstCar = true;
            // }
            //else if (firstCar == true && (carsRight.front().second <= currentTime))
            //{
              //cout << currentTime + travTime << endl;
              LIST->insert(make_pair(carsRight.front().first, currentTime + travTime));
              carsRight.pop();
              if (firstCar == false)
              {
                firstCar = true;
              }
              // if (!carsLeft.empty() && !carsRight.empty())
              // {
              //   cout << endl;
              // }
              loaded = true;
            //}
          }
        }
        if ((!carsLeft.empty() && carsLeft.front().second <= currentTime) || loaded)
        {
          ferryPos--;
          currentTime = currentTime + travTime;
        }
        else
          currentTime = currentTime + 1;
        loaded = false;
      }
    }
    LIST->display();
    LIST->~SortedList();
    if (i != numCases - 1)
    {
      cout << endl;
    }
  }
}
