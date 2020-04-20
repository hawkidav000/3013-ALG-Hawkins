// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 


#include <iostream>

using namespace std;

const int INT_MAX = 2147483647;

// Number of vertices in the graph 
//#define V 9 

/*
int ctoi(char c){
    return (int)c-65;
}

char itoc(int i){
    return (char)i+65;
}
*/

// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int* dist, bool sptSet[],int V) 
{ 
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

// A utility function to print the constructed distance array 
// void printSolution(int* dist,int V) 
// { 
// 	printf("Vertex \t\t Distance from Source\n"); 
// 	for (int i = 0; i < V; i++){
//         cout<<i<<"\t\t"<<dist[i]<<endl;
// 		//printf("%s \t\t %d\n", itoc(i), dist[i]);
//     }
// } 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int** graph, int src, int V, int* dist) 
{ 
	//int dist[V]; // The output array. dist[i] will hold the shortest 
	// distance from src to i 

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
	// path tree or shortest distance from src to i is finalized 

	// Initialize all distances as INFINITE and stpSet[] as false 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	// Distance of source vertex from itself is always 0 
	dist[src] = 0; 

	// Find shortest path for all vertices 
	for (int count = 0; count < V - 1; count++) { 
		// Pick the minimum distance vertex from the set of vertices not 
		// yet processed. u is always equal to src in the first iteration. 
		int u = minDistance(dist, sptSet,V); 

		// Mark the picked vertex as processed 
		sptSet[u] = true; 

		// Update dist value of the adjacent vertices of the picked vertex. 
		for (int v = 0; v < V; v++) 

			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to v through u is 
			// smaller than current value of dist[v] 
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	// print the constructed distance array 
	//printSolution(dist,V); 
} 

int** Make2dArray(int width,int height){

    int** graph;

    graph = new int*[height];

    for(int i=0;i<height;i++){
        graph[i] = new int[width];
    }

    return graph;

}



// driver program to test above function 
int main() 
{ 
  int vertices, w, e;
  int s, t, src, time, numMice;

  int numCases;
  cin >> numCases;

  int** graph;
  int* distances;
  int* distToSrc;

  for (int i = 0; i < numCases; i++)
  {

    numMice = 0;

    cin >> vertices >> src >> time;
    //cout<<vertices<<endl;

    vertices = vertices + 1;

    graph = Make2dArray(vertices, vertices);

    distances = new int[vertices];
    distToSrc = new int[vertices];

    cin >> e;

    // for (int n = 0; n < vertices; n++)
    // {
    //   for (int m = 0; m < vertices; m++)
    //   {
    //     graph[n][m] = INT_MAX;
    //   }
    // }

    for(int f=0;f<e;f++){
      cin>>s>>t>>w;
      //cout<<s<<","<<t<<","<<w<<endl;
      graph[s][t] = w;
      //graph[t][s] = w;
    };

    for (int m = 0; m < vertices; m++)
    {
      distToSrc[m] = INT_MAX;
    }


    // Print the array if needed.
    // for(int i=0;i<vertices;i++){
    //     for(int j=0;j<vertices;j++){
    //         cout<<graph[i][j]<<", ";
    //     }
    //     cout<<endl;
    // }
    
    for (int n = 1; n < vertices; n++)
    {
      dijkstra(graph, n, vertices, distances);
      if (distToSrc[n] > distances[src])
      {
        distToSrc[n] = distances[src];
      }
      //cout << distToSrc[n] << ", ";
    }

    //cout << endl;


    for (int g = 1; g < vertices; g++)
    {
      if (distToSrc[g] <= time)
      {
        numMice++;
      }
    }


    cout << numMice << endl;
    if (i != numCases - 1)
    {
      cout << endl;
    }

    // for (int j = 0; j < vertices; j++)
    // {
    //   delete [] graph[j];
    // }
    
    delete [] graph;
    delete [] distances;
    delete [] distToSrc;

  }

  return 0;
} 
