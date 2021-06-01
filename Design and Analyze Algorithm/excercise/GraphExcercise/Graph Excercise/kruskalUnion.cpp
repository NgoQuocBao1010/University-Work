#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXSIZE 10000007

typedef int NodeType;
typedef struct {
    int weight;
    NodeType from;
    NodeType to;
} Edge;

bool compareEdge(Edge a, Edge b){
    return (a.weight < b.weight);
}

typedef struct {
    NodeType *parent = new int[MAXSIZE];
    Edge *graph = new Edge[MAXSIZE];
    Edge *mst = new Edge[MAXSIZE];
    int numOfNodes;
    int numOfEdges;
} Graph;

void makeNullGraph(Graph &g, int numOfNodes){
    g.numOfNodes = numOfNodes;
    g.numOfEdges = 0;

    for (int i=1; i<g.numOfNodes+1; i++){
        g.parent[i] = i;
    }
}

void addEdge(Graph &g, int weight, NodeType from, NodeType to){
    Edge tmp = {weight, from, to};
    g.graph[g.numOfEdges] = tmp;
    g.numOfEdges++;
}

NodeType findSet(Graph &g, NodeType node){
    if (node == g.parent[node]) return node;

    return findSet(g, g.parent[node]);
}

void unionSet(Graph &g ,NodeType a, NodeType b){
    g.parent[a] = g.parent[b];
}

void kruskal(Graph &g){
    int result = 0;
    NodeType root1, root2;
    sort(g.graph, g.graph + g.numOfEdges, compareEdge);

    for (int i=0; i<g.numOfEdges; i++){
        root1 = findSet(g, g.graph[i].from);
        root2   = findSet(g, g.graph[i].to);
        // cout << from - 1 << "\t" << to - 1 << endl;
        if (root1 != root2){
            result += g.graph[i].weight;
            unionSet(g, root1, root2);
            // cout << g.parent[from] << "\t" << g.parent[to] << endl;
            // g.parent[from] = g.parent[to];
            // cout << g.parent[from] << "\n" << endl;
        }
    }
    cout << result << endl;
}


void findCost(const char* fileName){
    int numOfCities, numOfRoads;
    freopen(fileName, "r", stdin);

    cin >> numOfCities >> numOfRoads;

    Graph g;
    makeNullGraph(g, numOfCities);
    // unionSet(g, 1, 4);

    // for (int i=1; i<g.numOfNodes+1; i++){
    //     cout << g.parent[i] << " ";
    // }

    for (int i=0; i<numOfRoads; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        addEdge(g, cost, from, to);
    }

    kruskal(g);
}


int main(){
    // Edge a = {4, 2, 3};
    // Edge b = {2, 2, 3};
    // Edge c = {5, 2, 3};
    // Edge test[3] = {a, b, c};
    // sort(test, test+2, compareEdge);
    // for (int i=0; i<3; i++){
    //     cout << test[i].weight << endl;
    // }
    findCost("kruskal01.inp");

	return 0; 
}


