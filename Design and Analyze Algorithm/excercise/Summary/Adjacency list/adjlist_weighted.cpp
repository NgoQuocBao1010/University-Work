#include <iostream>

using namespace std;

#define oo 1000000000
#define N 1000
#define MaxSize 100007

// ================================== Adjacency List ==================================
// ==================================    Weighted    ==================================
typedef int NodeType;
struct Node {
    NodeType node;
    int weight;
    Node* next;
};

typedef struct Node* AdjList[MaxSize + 1];
void initList(AdjList &l, int size);
void insertNode(AdjList &l, int node1, int node2);
void bulidGraph(AdjList &l, int numOfNodes, int numOfEdges);
void printAdj(AdjList l, int numOfNodes);

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
void insertNode(AdjList &l, int from, int to, int weight){
    Node* p = new Node;
    if (p == NULL) return;

    p->node = to;
    p->weight = weight;
    p->next = l[from]->next;
    l[from]->next = p;

    // Node* q = new Node;
    // if (q == NULL) return;

    // q->node = from;
    // q->weight = weight;
    // q->next = l[to]->next;
    // l[to]->next = q;
}


// Function to build the whole list
// by specifies number of Nodes and number of Edges
// then input in pair the 2 nodes that connect
void bulidGraph(AdjList &l, int numOfNodes, int numOfEdges){
    initList(l, numOfNodes);

    int from, to, weight;

    for (int i=0; i<numOfEdges; i++){
        cin >> from >> to >> weight;

        insertNode(l, from, to, weight);
    }
}


void printAdj(AdjList l, int numOfNodes){
    cout << endl;
    for (int i=1; i<numOfNodes ; i++){
        cout << i << ": (";
        Node* p = new Node;
        p = l[i];

        if (p->next == NULL) {
            cout << "NULL)" << "\t";
            continue; 
        }

        while (p->next != NULL){
            cout << p->next->node << " " << p->next->weight << ", ";
            p = p->next;
        }
        cout << ")" << endl;
    }
    cout << endl;
}



