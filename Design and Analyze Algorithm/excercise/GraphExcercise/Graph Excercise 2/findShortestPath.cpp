#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define oo 1000000000
#define N 1000
#define MaxSize 100007

// ================================= Queue =================================
typedef int ElementType;
typedef struct {
    ElementType* elements;
    int size;
} Queue;
void makeNullQueue(Queue &q, int size);
void printQueue(Queue q);
bool isEmpty(Queue q);
void enqueue(Queue &q, ElementType ele);
ElementType dequeue(Queue &q);

// ================================= Adjency List =================================
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

// ================================= Bai 3 =================================
void findShortestPath(const char* filename){
    freopen(filename, "r", stdin);

    int numOfTestCases;
    cin >> numOfTestCases;

    int numOfIslands, numOfBridges;
    for (int i=0; i<numOfTestCases; i++){
        AdjList graph;
        cin >> numOfIslands >> numOfBridges;
        bulidGraph(graph, numOfIslands, numOfBridges);
        
        bool* visited = new bool[numOfIslands+1];

        for (int i=0; i<numOfIslands; i++){
            visited[i] = false;
        }

        int moveCount = 0;
        int element_left_in_layer = 1;
        int element_in_next_layer = 0;

        int endIsland = numOfIslands;

        Node* p;
        Queue q;
        makeNullQueue(q, numOfBridges);
        enqueue(q, 1);

        visited[1] = true;

        while (!isEmpty(q)){
            int island = dequeue(q);

            if (island == endIsland) {
                break;
            }

            p = graph[island];
            // cout << p->next->node << " " << island << "\t";
            while (p->next != NULL){
                int to = p->next->node;
                p = p->next;
                if (visited[to]) continue;
                enqueue(q, to);
                visited[to] = true;
                element_in_next_layer ++;
            }
            // cout << "Chao";
            element_left_in_layer--;
            if (element_left_in_layer == 0) {
                element_left_in_layer = element_in_next_layer;
                element_in_next_layer = 0;
                moveCount ++;
            }
        }
        cout << moveCount << endl;
    }
}


// ================================= Queue =================================
void makeNullQueue(Queue &q, int size){
    q.size = 0;
    q.elements = (ElementType*) malloc(size*sizeof(ElementType));
}

void printQueue(Queue q){
    if (isEmpty(q)) {
        cout << "This queue is empty!";
        return;
    }
    for (int i=0; i<q.size; i++)
        cout << q.elements[i] << "\t";
}

bool isEmpty(Queue q) {
    return q.size == 0;
}

void enqueue(Queue &q, ElementType ele){
    q.elements[q.size] = ele;
    q.size ++;
}

ElementType dequeue(Queue &q){
    if (isEmpty(q)) return 0;

    ElementType result = q.elements[0];

    for (int i=1; i<q.size; i++){
        q.elements[i - 1] = q.elements[i];
    }
    q.size --;

    return result;
}


// ================================= Adjency List =================================
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


