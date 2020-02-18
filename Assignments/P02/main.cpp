#include <iostream>
#include "JsonFacade.hpp"
#include <time.h>
#include <chrono> 
#include "Timer.hpp"
#include "mygetch.hpp"

using namespace std;

struct wordNode{
    string word;
    string definition;
    wordNode* next;

    wordNode(string w, string def){
        word = w;
        definition = def;
        next = NULL;
    }
};

class LinkedList {
private:
    wordNode* head;
    wordNode* tail;
    int size;

public:
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }

    int GetSize(){
        //return size of the list
        return 0;
    }

    void Insert(string w, string def){
        if (head == NULL){      //if list is empty, insert at beginning
            head = tail = new wordNode(w, def);
            size++;
        }
        else{                   //if list is not empty
            tail->next = new wordNode(w, def);
            tail = tail->next;
            size++;
        }
    }

    string Remove(){
        //Im thinking Ill just remove from the front of the list
        //Just to keep it easy
        return " ";
    }

    string PrintList(){
        wordNode* temp = head;
        string list;

        while (temp != NULL){
            list += temp->word + "->";
            temp = temp->next;
        }

        return list;
    }


};

int main(){

    LinkedList L;

    JsonFacade J("dict_w_defs.json");

    vector<string> list = J.getKeys();

    for (int i = 0; i < J.getSize(); i++){
        L.Insert(J.getKey(i), J.getValue(J.getKey(i)));
    }

    string link = L.PrintList();
    cout << link;

    return 0;
}