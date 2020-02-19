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
        return size;
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
        if (head != NULL){
            wordNode* temp = head;
            string data;

            data = temp->word;
            head = head->next;
            delete temp;
            temp = NULL;
            size--;

            return data;
        }
        else{
            return "Can't remove from empty list.";
        }
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

    string PrintTail(){
        string list;

        list += tail->word + ": " + tail->definition;

        return list;
    }

    void Search(string item, int & match, string& results){
        wordNode* temp = head;
        string test;

        while (temp != NULL){
            test = temp->word;
            if(item == test.substr(0, item.length())){
                match++;
                if (match <= 10){
                    results += temp->word + ", ";
                }

            }
            temp = temp->next;
        }
    }


};

/*****************************************************
 * Function Prototypes
 ****************************************************/
string GetchInput();
void LoadList(Timer& T, LinkedList& L, JsonFacade& J, double& sec, long& mill);
void PrintResults(int& match, string& results, Timer& S);

int main(){

    Timer T;                            //Timer object for loading list
    Timer S;                            //Timer object for searching
    LinkedList L;                       //Linked list object
    double Sec;                         //num of secs to load list
    long Milli;                         //num of millisecs to load list
    int match = 0;                      //used to record number of matches
    string result;                      //records first ten results from search
    string item;                        //holds what we're searching for

    JsonFacade J("dict_w_defs.json");   //Json object holding list of words

    LoadList(T, L, J, Sec, Milli);      //Loads list & times it

    item = GetchInput();

    S.Start();
    L.Search(item, match, result);
    S.End();

    PrintResults(match, result, S);
 
    return 0;
}

string GetchInput(){
    char k;             // holder for character being typed
    string word = "";   // var to concatenate letters to

    cout << "Type what you're searching for, then press enter: ";

    while ((k = getch()) != 13) {
        word += k;
        cout << k;
    }
    
    cout << endl;

    return word;
}

void LoadList(Timer& T, LinkedList& L, JsonFacade& J, double& sec, long& mill){
    T.Start();
    for (int i = 0; i < J.getSize(); i++){
        L.Insert(J.getKey(i), J.getValue(J.getKey(i)));
    }
    T.End();

    sec = T.Seconds();
    mill = T.MilliSeconds();
}



void PrintResults(int& match, string& results, Timer& S){
    cout << endl << match << " words found in " << S.Seconds() 
        << " seconds" << endl << endl;
    cout << results << endl;
}