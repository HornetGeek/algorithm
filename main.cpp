#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class graph{

    int v;  // No. of nodes 
    list<int>* T;  // Pointer to an array containing adjacency lists 

    void DFS_VISITED(int E, bool Visited[]);      // A recursive function used by DFS to Mark the current node as visited


public:
    graph(int v);   // it's constructor 
    void addEdge(int E,int w);  // function to add edge to graph
    int TablesNum(); // function to count the number of tables

};


int graph::TablesNum()
{


    bool* Visited = new bool[v]; //  it's pointer array "it's like a flage to know the visited nodes "
    int n = 0;        // number of tables
    for(int E = 0;E < v; E++) {       
        if (Visited[E] == false) {   // if not visited 
            DFS_VISITED(E,Visited);
            n += 1;
        }
    }
    return n;
}


void graph::DFS_VISITED(int E , bool Visited[])
{
    Visited[E] = true;

    list<int>::iterator i;  // i used iterator to reduce complixity and execution time of program because it's using pointers

    for(i = T[E].begin(); i!=T[E].end(); ++i)   // for all the vertices adjacent to this vertex
        if(!Visited[*i])
            DFS_VISITED(*i,Visited);

}

graph::graph(int v)
{
    this->v = v;
    T = new list<int>[v];
}

void graph::addEdge(int E,int w)
{
    T[E].push_back(w); // add w to E list 
    T[w].push_back(E);

}

int main()
{
    graph g(6);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(5,4);

    cout << "The Number of Tables are ";
    cout << g.TablesNum();
    cout << "/n"

    return 0;
}