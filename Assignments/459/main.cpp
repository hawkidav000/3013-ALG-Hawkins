//David Hawkins
//Advanced Structures and Algorithms - Dr. Griffin
//Assignment 459

#include <iostream>
#include <queue>
#include <string>
#include <vector>
//#include <fstream> //////////////////////////////////////////////

#define endl "\n"

using namespace std;

typedef vector<int> vi;     // vector of integers
typedef pair<int, int> ii;  // pair of integers
typedef vector<ii> vii;     // vector of pairs

const int VISITED = 1;
const int UNVISITED = -1;

vi been_visited;            // container to keep track of who get visited
vector<vii> AdjList;        // AdjList stores our edge lists

/**
 * Depth First Search
 * 
 * Params:
 *  int u - starting node id
 * 
 */
void dfs(int u) {
    // In DFS we use a stack structure to keep track of who to visit next.
    // Recursive acts just like a stack so we dont need to declare any 
    // structure to keep track for us, we let the recursive calls do it for us

    been_visited[u] = VISITED;  // mark u as visited
    //cout << u << " ";           // write u to stdout

    // Loop overadjacency list looking for connections
    for (int j = 0; j < (int)AdjList[u].size(); j++) {

        // v is a pair representing a neighbor and the 
        // weight of the edge from u->v
        ii v = AdjList[u][j];

        //cout<<u<<"->"<<v.first<<" with weight "<<v.second<<endl;

        // check to see if our neighbor was visited
        if (been_visited[v.first] == UNVISITED) {
            dfs(v.first);
        }
    }
}

int main(int argc, char **argv) {
  //ofstream outfile;
  //outfile.open("out.txt");////////////////////////////////////////////////////////


  int n; //number of cases
  char m; //single letter
  int size;
  int x;    //first part of pair thats read in
  int y;    //second part of pair thats read in
  int numCases;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    if (i != 0){
      cout << endl;
    }
    numCases = 0;
    cin >> m;
    size = (int)m - 64;
    string pair = "";
    
    AdjList.resize(size + 1);
    been_visited.resize(size + 1, UNVISITED);

    getline(cin, pair); //arbitrary getline to skip the empty space
    getline(cin, pair);
    while (pair != "") {
      x = (int)pair[0] - 64;
      y = (int)pair[1] - 64;
      AdjList[x].push_back(make_pair(y, 10));
      AdjList[y].push_back(make_pair(x, 10));
      getline(cin, pair);
    }
  /*
    // To print the edges stored in the adjacency list
    cout<<"Adjacency List"<<endl;
    cout<<"U -> V  Weight"<<endl;
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < (int)AdjList[i].size(); j++) {
            cout << i << " -> " << AdjList[i][j].first << "  ["
                  << AdjList[i][j].second << "]" << endl;
        }
    }
  */
    for (int i = 1; i <= (int)been_visited.size(); i++)
    {
      if (been_visited[i] == UNVISITED)
      {
        dfs(i);
        numCases++;
        //cout << "j" << endl;
      }
    }

    //outfile << numCases << endl << endl;////////////////////////////////////////////
    cout << numCases << endl;
    been_visited.clear();
    // reset values in been_visited vector
    fill(been_visited.begin(), been_visited.end(), UNVISITED);
    for (int i = 0; i < (int)AdjList.size(); i++)
    {
      AdjList[i].clear();
    }
  }
  return 0;
}
