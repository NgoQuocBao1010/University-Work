#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void dfs(vector <vector <bool>> &graph, vector <bool> &visited, int node, int numOfNodes, int &count){
    vector <int> neighbours;
    for (int i=1; (unsigned) i< (unsigned) numOfNodes+1; i++){
        if (graph[node][i]) neighbours.push_back(i);
    }

    visited[node] = true;
    count --;
    for (int i=0; (unsigned) i< (unsigned) neighbours.size(); i++){
        if (!visited[neighbours[i]]){
            dfs(graph, visited, neighbours[i], numOfNodes, count);
        }
    }
}

void fuckingMaster(){
    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;

    vector <vector <bool>> graph;
    vector <bool> visited;

    for (int i=0; i<numOfNodes+1; i++){
        vector <bool> tmp;
        for (int j=0; j<numOfNodes+1; j++){
            tmp.push_back(false);
        }
        graph.push_back(tmp);
        visited.push_back(false);
    }

    for (int i=0; i<numOfEdges; i++){
        int from, to;
        cin >> from >> to;
        graph[from][to] = true;
        graph[to][from] = true;
    }

    int master, count;
    cin >> master;
    count = numOfNodes;

    // for (int i=0; i<numOfNodes+1; i++){
    //     for (int j=0; j<numOfNodes+1; j++){
    //         cout << graph[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    // depth first search al 
    dfs(graph, visited, master, numOfNodes, count);
    // for (int i=1; i<numOfNodes+1; i++){
    //     cout << visited[i] << "\t";
    // }
    cout << count << endl;
}


int main(){
    fuckingMaster();
}