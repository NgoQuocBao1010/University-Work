#include <iostream>

using namespace std;

#define oo 1000000000
#define N 1000
#define MaxSize 100007

// ================================== Adjacency List ==================================
typedef int NodeType;
struct Node {
    NodeType node;
    Node* next;
};

typedef struct Node* AdjList[MaxSize + 1];
void initList(AdjList &l, int size);
void insertNode(AdjList &l, int node1, int node2);
void bulidGraph(AdjList &l, int numOfNodes, int numOfEdges);
void printAdj(AdjList l, int numOfNodes);

// ================================== Bai lam ==================================
void dfs(AdjList &l, int visited[], int node, int numOfNodes, int &count){
    Node* p = new Node;
    visited[node] = true;
    count --;

    p = l[node];
    while (p->next != NULL){
        int nextNode = p->next->node;
        p = p->next;
        
        if (!visited[nextNode])
            dfs(l, visited, nextNode, numOfNodes, count);
    }
}

void fuckingMaster(){
    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;

    int* visited = new int[numOfNodes+1];

    for (int i=0; i<=numOfNodes; i++)
        visited[i] = false;
    
    AdjList graph;
    bulidGraph(graph, numOfNodes, numOfEdges);

    int master, count;
    cin >> master;
    count = numOfNodes;

    dfs(graph, visited, master, numOfNodes, count);
    cout << count << endl;

}

int main(){

}

// Initialize a adjacency list
// A list of node, each node contains it value and points to the
// node that connect with that node.
void initList(AdjList &l, int numOfNodes){
    for (int i=0; i<=numOfNodes; i++){
        Node* p = new Node;
        l[i] = p;
        l[i]->next = NULL;
    }
}


// Conenect node1 and node2 in adjacency list
void insertNode(AdjList &l, int node1, int node2){
    Node* p = new Node;
    if (p == NULL) return;

    p->node = node2;
    p->next = l[node1]->next;
    l[node1]->next = p;
    
    Node *q = new Node;
    if (q == NULL) return;
    
    q->node = node1;
    q->next = l[node2]->next;
    l[node2]->next = q;
}


// Function to build the whole list
// by specifies number of Nodes and number of Edges
// then input in pair the 2 nodes that connect
void bulidGraph(AdjList &l, int numOfNodes, int numOfEdges){
    initList(l, numOfNodes);

    int node1, node2;

    for (int i=0; i<numOfEdges; i++){
        cin >> node1 >> node2;

        insertNode(l, node1, node2);
        insertNode(l, node2, node1);
    }
}


void printAdj(AdjList l, int numOfNodes){
    for (int i=1; i<=numOfNodes; i++){
        cout << i << ": (";
        Node* p = new Node;
        p = l[i];

        if (p->next == NULL) {
            cout << "NULL)" << "\t";
            continue; 
        }

        while (p->next != NULL){
            cout << p->next->node << " ";
            p = p->next;
        }
        cout << ")" << endl;
    }
}




