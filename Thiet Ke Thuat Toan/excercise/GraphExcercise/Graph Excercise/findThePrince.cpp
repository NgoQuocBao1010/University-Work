#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXSIZE 1000
#define MAXVALUE 100000


typedef int ElementType;
typedef struct {
    ElementType Elements[MAXSIZE];
    int size;
} Queue;

bool isEmpty(Queue q) {
    return q.size == 0;
}


void enqueue(Queue &q, ElementType ele){
    q.Elements[q.size] = ele;
    q.size ++;
}


ElementType dequeue(Queue &q){
    if (isEmpty(q)) return 0;

    ElementType result = q.Elements[0];

    for (int i=1; i<q.size; i++){
        q.Elements[i - 1] = q.Elements[i];
    }
    q.size --;

    return result;
}

void merge(int arr[], int low, int mid, int high){
    int size1, size2;

    // Seperate current arr into 2 parts 
    // from the mid position
    size1 = mid - low + 1;
    size2 = high - mid;

    int* part1 = new int[size1];
    int* part2 = new int[size2];

    for (int i=0; i < size1; i++){
        part1[i] = arr[low + i];
    }
    for (int i=0; i < size2; i++){
        part2[i] = arr[mid + 1 + i];
    }


    // Merge and sorted 2 parts 
    int i = 0;
    int j = 0;
    int k = low;
    while (i < size1 && j < size2){
        if (part1[i] <= part2[j]){
            arr[k] = part1[i];
            i++;
        }
        else {
            arr[k] = part2[j];
            j++;
        }
        k++;
    }

    while (i < size1){
        arr[k] = part1[i];
        i++;
        k++;
    }

    while (j < size2){
        arr[k] = part2[j];
        j++;
        k++;
    }
    delete[] part1;
    delete[] part2;
}

void mergeSort(int arr[], int low, int high){
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}


// ==========================  Adjacency List  ========================== 
#define oo 1000000000
#define N 1000
#define MaxSize 100007

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


void findThePrince(){
    int numOfNations;
    cin >> numOfNations;
    
    AdjList l;
    bulidGraph(l, numOfNations, numOfNations-1);
    
    int numOfContenders;
    cin >> numOfContenders;

    int* contendersNations = new int[numOfContenders];

    for (int i=0; i<numOfContenders; i++)
        cin >> contendersNations[i];
    
    mergeSort(contendersNations, 0, numOfContenders - 1);

    // Bredth First Search Algorithm
    bool* visited = new bool[numOfNations+1];
    int* moves = new int[numOfNations+1];

    for (int i=0; i<=numOfNations; i++){
        visited[i] = false;
        moves[i] = MAXVALUE;
    }

    int moveCount = 1;
    int element_left_in_layer = 1;
    int element_in_next_layer = 0;



    Queue qu = {{}, 0};
    enqueue(qu, 1);

    visited[1] = true;
    
    Node* p;
    
    while (!isEmpty(qu)){
        int nation = dequeue(qu);
        p = l[nation];
        
        while (p->next != NULL){
            int to = p->next->node;
            p = p->next;
            if (visited[to]) continue;
            enqueue(qu, to);
            visited[to] = true;
            element_in_next_layer ++;
            moves[to] = moveCount;
        }

        element_left_in_layer --;

        if (element_left_in_layer == 0) {
            element_left_in_layer = element_in_next_layer;
            element_in_next_layer = 0;
            moveCount ++;

            bool foundNations = false;

            for (int i=0; i<numOfContenders; i++){
                if (visited[contendersNations[i]]){
                    foundNations = true;
                    break;
                }
            }

            if (foundNations) break;
        }
    }

    for (int i=0; i<numOfContenders; i++){
        if (moves[contendersNations[i]] != MAXVALUE) {
            cout << contendersNations[i];
            return;
        }
    }
}

int main(){
    findThePrince();
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

void bulidGraph(AdjList &l, int numOfNodes, int numOfEdges){
    initList(l, numOfNodes);

    int node1, node2;

    for (int i=0; i<numOfEdges; i++){
        cin >> node1 >> node2;

        insertNode(l, node1, node2);
        // insertNode(l, node2, node1);
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



