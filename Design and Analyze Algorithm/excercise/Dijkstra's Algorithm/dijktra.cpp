#include <iostream>
#include <stdio.h>
using namespace std;

#define MaxSize 10000
#define MINVALUE -32768
#define MAXVALUE 1000000

typedef int KeyType;
typedef int NodeType;

typedef struct {
    KeyType key;
    int value;
}KeyValuePair;


bool compareLess(KeyValuePair i, KeyValuePair j){
    return i.value < j.value;
}


typedef struct {
    KeyValuePair keys[MaxSize];
    int size;
}PriorityQueue;

bool isEmpty(PriorityQueue pq);
void printQueue(PriorityQueue pq);
void swapElement(PriorityQueue &pq, int pos1, int pos2);
void clear(PriorityQueue &pq);
KeyValuePair peek(PriorityQueue pq);
KeyValuePair poll(PriorityQueue &pq);
bool contains(PriorityQueue pq, KeyType key);
void addElement(PriorityQueue &pq, KeyType key, int value);
void increaseKey(PriorityQueue &pq, int position);
void decreaseKey(PriorityQueue &pq, int position);
bool compareElementLess(PriorityQueue pq, int pos1, int pos2);
KeyValuePair removeAt(PriorityQueue &pq, int position);
int getIndexOfNode(NodeType node);
void findShortestDistance(const char* fileName);


bool isEmpty(PriorityQueue pq){
    return pq.size == 0;
}


void printQueue(PriorityQueue pq){
    if (isEmpty(pq)) {
        cout << "The queue is empty!";
        return;
    }

    for (int i=0; i < pq.size; i++){
        cout << "(" << pq.keys[i].key << ", " << pq.keys[i].value << ")" << "\t";
    }
}


void swapElement(PriorityQueue &pq, int pos1, int pos2){
    KeyValuePair ele1 = pq.keys[pos1];
    KeyValuePair ele2 = pq.keys[pos2];

    pq.keys[pos1] = ele2;
    pq.keys[pos2] = ele1;
}


void clear(PriorityQueue &pq){
    for (int i=0; i < pq.size; i++){
        pq.keys[i].key = MINVALUE;
        pq.keys[i].value = MINVALUE;
    }
    
    pq.size = 0;
}


KeyValuePair peek(PriorityQueue pq){
    KeyValuePair result = {MINVALUE, MINVALUE};
    if (isEmpty(pq)) return result;

    result = pq.keys[0];
    return result;
}


KeyValuePair poll(PriorityQueue &pq){
    KeyValuePair result = {MINVALUE, MINVALUE};
    if (isEmpty(pq)) return result;

    return removeAt(pq, 0);
}


bool contains(PriorityQueue pq, KeyType key) {
    for (int i=0; i < pq.size; i++){
        if (pq.keys[i].key == key) return true;
    }
    return false;
}


void addElement(PriorityQueue &pq, KeyType key, int value){
    KeyValuePair element = {key, value};

    pq.keys[pq.size] = element;

    increaseKey(pq, pq.size);
    pq.size ++;

}


bool compareElementLess(PriorityQueue pq, int pos1, int pos2){
    return compareLess(pq.keys[pos1], pq.keys[pos2]);
}


void increaseKey(PriorityQueue &pq, int position){
    int parentPos = (position - 1) / 2;

    while(position > 0 && compareElementLess(pq, position, parentPos)){
        swapElement(pq, parentPos, position);
        position = parentPos;
        parentPos = (position - 1) / 2;
    }
}


void decreaseKey(PriorityQueue &pq, int position){
    while (true){
        int leftChild   = 2 * position + 1;
        int rightChild  = 2 * position + 2;
        int smallest    = leftChild;

        if (rightChild < pq.size && compareElementLess(pq, rightChild, leftChild))
            smallest = rightChild;
        
        if (leftChild >= pq.size || compareElementLess(pq, position, smallest))
            break;
        
        swapElement(pq, smallest, position);
        position = smallest;

    }
}


KeyValuePair removeAt(PriorityQueue &pq, int position){
    pq.size --;
    KeyValuePair removedData = pq.keys[position];

    swapElement(pq, position, pq.size);

    pq.keys[pq.size].key = MINVALUE;
    pq.keys[pq.size].value = MINVALUE;

    if (position == pq.size) return removedData;

    KeyValuePair element = pq.keys[position];

    decreaseKey(pq, position);

    if (pq.keys[position].key == element.key && pq.keys[position].value == element.value){
        increaseKey(pq, position);
    }

    return removedData;
}


int getIndexOfNode(NodeType node){
    return node - 1;
}


void findShortestDistance(const char* fileName){
    int numOfNodes, numOfEdges;
    freopen(fileName, "r", stdin);

    cin >> numOfNodes;
    cin >> numOfEdges;

    int graph[numOfNodes][numOfNodes];

    for (int i=0; i<numOfNodes; i++){
        for (int j=0; j<numOfNodes; j++)
            graph[i][j] = MAXVALUE;
    }

    for (int j=0; j<numOfEdges; j++){
        NodeType from, to;
        int distance;

        cin >> from >> to;
        cin >> distance;

        int fromIndex, toIndex;

        fromIndex = getIndexOfNode(from);
        toIndex = getIndexOfNode(to);

        graph[fromIndex][toIndex] = distance;
    }

    // Dijkstra Algorithm 
    int startIndex = 0;

    bool* visited = new bool[numOfNodes];
    int*  dist = new int[numOfNodes];

    for (int i=0; i<numOfNodes; i++){
        visited[i] = false;
        dist[i] = MAXVALUE;
    }

    dist[0] = 0;

    PriorityQueue pq = {{}, 0};
    addElement(pq, 1, 0);

    while (!isEmpty(pq)) {
        KeyValuePair kv = poll(pq);

        NodeType nodeName = kv.key;
        int nodeIndex = getIndexOfNode(nodeName);
        int minDist = kv.value;

        visited[nodeIndex] = true;

        if (dist[nodeIndex] < minDist) continue;
        
        for (int i=0; i<numOfNodes; i++){
            int edgeDistance = graph[nodeIndex][i];
            if (edgeDistance == MAXVALUE) continue;
            
            int edgeIndex = i;
            if (visited[edgeIndex]) continue;
            
            int newDist = dist[nodeIndex] + edgeDistance;

            if (newDist < dist[edgeIndex]) {
                dist[edgeIndex] = newDist;
                addElement(pq, edgeIndex + 1, newDist);
            }
        }
    }

    for (int i=1; i<numOfNodes; i++){
        cout << dist[i] << "\t";
    }
}


int main(){
    // findShortestDistance("input02.inp");
    PriorityQueue p = {{}, 0};
    addElement(p, 5, 6);
    printQueue(p);
}