#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define oo 1000000000
#define N 1000
#define MaxSize 100007

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
void min_Heapify(PriorityQueue &pq, int i);
void build_MinHeap(PriorityQueue &pq);
KeyValuePair extractMin(PriorityQueue &pq);
void decrease_Key(PriorityQueue &pq, int position);
void insertElement(PriorityQueue &pq, KeyType key, int value);

// ================================= Bai 2 =================================
typedef int NodeType;
struct Node {
    NodeType node;
    int weight;
    Node* next;
};

typedef struct vector <Node*> AdjList;

void initList(AdjList &l, int size){
    for (int i=0; i<size+1; i++){
        Node* p = new Node;
        l.push_back(p);
        l[i]->next = NULL;
    }
}

void insertNode(AdjList &l, int from, int to, int weight){
    Node* p = new Node;
    if (p == NULL) return;

    p->node = to;
    p->weight = weight;
    p->next = l[from]->next;
    l[from]->next = p;
}

void bulidGraph(AdjList &l, int numOfNodes, int numOfEdges){
    initList(l, numOfNodes);
    int from, to, weight;

    for (int i=0; i<numOfEdges; i++){
        cin >> from >> to >> weight;
        insertNode(l, from, to, weight);
    }
}

void printAdj(AdjList l){
    cout << endl;
    for (int i=1; (unsigned) i< (unsigned) l.size(); i++){
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
    vector <int> distance;
    vector <bool> visited;
    PriorityQueue q;

    bulidGraph(l, numOfNodes, numOfEdges);
    printAdj(l);
    for (int i=0; i<= MaxSize; i++){
        distance.push_back(oo);
        visited.push_back(false);
    }
    makeNull(q);

    distance[1] = 0;
    insertElement(q, 1, 0);

    while (!isEmpty(q)){
        KeyValuePair pair = extractMin(q);
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


void makeNull(PriorityQueue &pq){
    pq.size = 0;
    // pq.key = (KeyValuePair*) malloc(MaxSize*sizeof(KeyValuePair));
    pq.key = new KeyValuePair[MaxSize];
}

bool isEmpty(PriorityQueue pq){
    return pq.size == 0;
}

void swapElement(PriorityQueue &pq ,int pos1, int pos2){
    KeyValuePair ele1 = pq.key[pos1];
    KeyValuePair ele2 = pq.key[pos2];

    pq.key[pos1] = ele2;
    pq.key[pos2] = ele1;
}

void min_Heapify(PriorityQueue &pq, int position){
    int smallest = position;
    int leftPos = 2 * position + 1;
    int rightPos = 2 * position + 2;

    if (leftPos < pq.size && pq.key[leftPos].value < pq.key[position].value)
        smallest = leftPos;
    
    if (rightPos < pq.size && pq.key[rightPos].value < pq.key[position].value)
        smallest = rightPos;
    
    if (smallest != position){
        swapElement(pq, smallest, position);
        min_Heapify(pq, smallest);
    }
}

void build_MinHeap(PriorityQueue &pq){
    for (int i=pq.size/2 - 1; i>=0; i--){
        min_Heapify(pq, i);
    }
}

KeyValuePair extractMin(PriorityQueue &pq){
    KeyValuePair min = pq.key[0];
    pq.size --;
    swapElement(pq, 0, pq.size);
    min_Heapify(pq, 0);
    return min;
}

void decrease_Key(PriorityQueue &pq, int position){
    int parentPos = (position - 1) / 2;

    while (position > 0 && pq.key[parentPos].value > pq.key[position].value){
        swapElement(pq, parentPos, position);
        position = parentPos;
        parentPos = (position - 1) / 2;
    }
}

void insertElement(PriorityQueue &pq, KeyType key, int value){
    KeyValuePair newElement = {key, value};
    // pq.key[pq.size].value = oo;
    // pq.key[pq.size].key = key;
    // pq.size++;
    // decrease_Key(pq, pq.size - 1, newElement);
    pq.key[pq.size] = newElement;
    decrease_Key(pq, pq.size);
    pq.size++;
}
