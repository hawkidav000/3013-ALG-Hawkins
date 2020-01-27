///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           David Hawkins and Terry Griffin
// Email:            david.james@hawkinsonline.us
// Label:            A02
// Title:            Commenting C++ Code
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       This program implements a class that allows a linked list to be used just like 
//       an array. It overloads the "[]" (square brackets) to simulate accessing seperate 
//       array elements, but really it traverses the list to find the specified node using
//       an index value. It also overloads the "+" and "-" signs allowing a user to "add"
//       or "push" items onto the end of the list, as well as "pop" items off the end of our 
//       array. This class is not meant to replace the STL vector library, its simply a project
//       to introduce the beginnings of creating complex / abstract data types. 
//      
// Files:            
//      main.cpp    : driver program
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int A[100];         //Not entirely sure what this is used for...

struct Node {
    int x;
    Node *next;
    Node() {
        x = -1;
        next = NULL;
    }
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      This class implements a linked list that acts very similarly to a
 *      vector. It implements several overloaded operators, such as +, <<,
 *      and [] in order to perform different operations between lists, print
 *      out the list, and provide ease of access to nodes by allowing the list
 *      to be treated like an array.
 * 
 * Public Methods:
 *      void        Push(int val)
 *      void        Insert(int val)
 *      void        PrintTail()
 *      int         Pop()
 *      List        operator+(const List &Rhs)
 *      int         operator[](int index)
 *      ostream     &operator<<(ostream &os, List L)
 * 
 * Usage: 
 * 
 *      List L;             //Create instance of list.
 *      L.Push(val);        //Pushes the value stored in the variable val
 *                          //to the end of the list.
 *      L.Insert(val);      //Inserts the value stored in the variable val
 *                          //to the front of the list.
 *      L.PrintTail();      //Prints what's at the end of L.
 *      L.Pop();            //Pops a value from the end of the list.
 *      L + R;              //Adds two lists together using the overloaded
 *                          //operator.
 *      L[1];               //Accesses a specific position in the linked
 *                          //list as if it were an array, and in this case
 *                          //it is the second position.
 *      cout << L;          //Prints out the list using the overloaded <<
 *                          //operator.
 *      
 */
class List {
private:
    Node *Head;     //Pointer to front of linked list
    Node *Tail;     //Pointer to back of linked list
    int Size;       //Size of the linked list

public:
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

    void PrintTail() {
        cout << Tail->x << endl;
    }

    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {
    List L1;        //Instantiates a linked list called L1
    List L2;        //Instantiates a linked list called L2

    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}
