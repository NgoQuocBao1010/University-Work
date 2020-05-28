#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define oo 1000000000
#define N 1000
#define MaxSize 100007

// =================================== Priority Queue ===================================
// ===================================    Min Heap    ===================================
typedef int KeyType;
typedef struct {
    KeyType key;
    int value;
} KeyValuePair;

typedef struct{
    KeyValuePair *key;
    int size;
} PriorityQueue;

void makeNull(PriorityQueue &pq);
bool isEmpty(PriorityQueue pq);
void swapElement(PriorityQueue &pq ,int pos1, int pos2);
void sink(PriorityQueue &pq, int i);
void build_MinHeap(PriorityQueue &pq);
KeyValuePair poll(PriorityQueue &pq);
void swim(PriorityQueue &pq, int position);
void insertElement(PriorityQueue &pq, KeyType key, int value);


// ================================= Bai 2 =================================
typedef int NodeType;
struct Node {
    NodeType node;
    int weight;
    Node* next;
};

typedef struct Node* AdjList[MaxSize + 1];


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


void dijkstra(){
    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;
    AdjList l;
    Node* p;
    
    bool* visited = new bool[numOfNodes+1];
    int* distance = new int[numOfNodes+1];
    PriorityQueue q;

    bulidGraph(l, numOfNodes, numOfEdges);
    printAdj(l, numOfNodes);
    for (int i=0; i<= numOfNodes; i++){
        distance[i] = oo;
        visited[i] = false;
    }
    makeNull(q);

    distance[1] = 0;
    insertElement(q, 1, 0);

    while (!isEmpty(q)){
        KeyValuePair pair = poll(q);
        int node = pair.key;
        
        if (!visited[node]) visited[node] = true;

        p = l[node];
        while (p->next != NULL){
            int weight = p->next->weight;
            int to = p->next->node;

            if (distance[to] > distance[node] + weight){
                distance[to] = distance[node] + weight;
                insertElement(q, to, distance[to]);
            }
            p = p->next;
        }
    }

    for (int i=2; i<=numOfNodes; i++){
        cout << distance[i] << " ";
    }
}

void calculateDistance(const char* shortestPath){
    freopen(shortestPath, "r", stdin);
    dijkstra();
}


int main(){
    calculateDistance("input03.inp");
    return 0;
}

// ===================================    Queue Method    ===================================
void makeNull(PriorityQueue &q){
    q.size = 0;
    q.key = new KeyValuePair[MaxSize];
}


bool isEmpty(PriorityQueue pq){
    return pq.size == 0;
}

// swap to element in the queue by passing their positions
void swapElement(PriorityQueue &pq ,int pos1, int pos2){
    KeyValuePair ele1 = pq.key[pos1];
    KeyValuePair ele2 = pq.key[pos2];

    pq.key[pos1] = ele2;
    pq.key[pos2] = ele1;
}

// Also known as min_Heapify
// sink down an element if that element
// does not satifies heap's variant
void sink(PriorityQueue &pq, int position){
    while (true) {
        int leftPos = 2 * position + 1;
        int rightPos = 2 * position + 2;
        int smallest = leftPos;

        if (rightPos < pq.size && pq.key[rightPos].value < pq.key[leftPos].value)
            smallest = rightPos;
        
        if (leftPos >= pq.size || pq.key[position].value < pq.key[smallest].value)
            break;
        
        swapElement(pq, smallest, position);
        position = smallest;
    }
}

// a faster way build a min heap
void build_MinHeap(PriorityQueue &pq){
    for (int i=pq.size/2 - 1; i>=0; i--){
        sink(pq, i);
    }
}

// Also know as extractMin
KeyValuePair poll(PriorityQueue &pq){
    KeyValuePair min = pq.key[0];
    pq.size --;
    swapElement(pq, 0, pq.size);
    sink(pq, 0);
    return min;
}

// Also known as decreaseKey
// Swim up an element to satisfy the heap's variant
void swim(PriorityQueue &pq, int position){
    int parentPos = (position - 1) / 2;

    while (position > 0 && pq.key[parentPos].value > pq.key[position].value){
        swapElement(pq, parentPos, position);
        position = parentPos;
        parentPos = (position - 1) / 2;
    }
}


void insertElement(PriorityQueue &pq, KeyType key, int value){
    KeyValuePair newElement = {key, value};
    pq.key[pq.size] = newElement;
    swim(pq, pq.size);
    pq.size++;
}


