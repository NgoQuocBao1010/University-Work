#include <iostream>
#include <cstdlib>
using namespace std;

#define oo 1000000000
#define N 1000
#define MaxSize 100007

typedef struct {
    int vertex;
    int weight;
}KeyType;

typedef struct{
    KeyType *key;
    int size;
} PriorityQueue;

void makeNull(PriorityQueue *Q){
    Q->size = 0;
}

int left(int i){
    return 2*i + 1;
}

int right(int i){
    return 2*i + 2;
}

int parent(int i){
    return (i - 1)/2;
}

int isEmpty(PriorityQueue Q){
    return Q.size == 0;
}

void swap(KeyType *a, KeyType *b){
    KeyType temp = *a;
    *a = *b;
    *b = temp;
}

void min_Heapify(PriorityQueue *Q, int i){
    int smallest = 0;
    int l = left(i);
    int r = right(i);
    if(l < Q->size && Q->key[l].weight < Q->key[i].weight){
        smallest = l;
    }
    else{
        smallest = i;
    }
    if(r < Q->size && Q->key[r].weight < Q->key[smallest].weight){
        smallest = r;
    }
    if(smallest != i){
        swap(&Q->key[smallest], &Q->key[i]);
        min_Heapify(Q, smallest);
    }
}

void build_MinHeap(PriorityQueue *Q){
    for(int i = Q->size/2 - 1; i >= 0; i--){
        min_Heapify(Q, i);
    }
}
     
KeyType extractMin(PriorityQueue* Q){
    KeyType min = Q->key[0];
    swap(&Q->key[0], &Q->key[Q->size - 1]);
    Q->size--;
    min_Heapify(Q, 0);
    return min;
}

void decrease_Key(PriorityQueue* Q, int i, KeyType key){
    if(Q->key[i].weight < key.weight)
        return;
    Q->key[i] = key;
    while(i > 0 && Q->key[parent(i)].weight > Q->key[i].weight){
        swap(&Q->key[parent(i)], &Q->key[i]);
        i = parent(i);
    }
}

void insert(PriorityQueue* Q, KeyType key){
    Q->size++;
    Q->key[Q->size - 1].weight = oo;
    Q->key[Q->size - 1].vertex = key.vertex;
    decrease_Key(Q, Q->size - 1, key);
}

/* ----------------------------------------
 --------------------------------------------*/
struct Node{
    int vertex;
    int weight;
    Node* Next;
};

typedef struct Node* AdjList[MaxSize + 1];

void init(AdjList* L, int size){
    for(int i = 0; i <= size; i++){
        (*L)[i] = (Node*) malloc(sizeof(Node));
        (*L)[i]->Next = NULL;
    }
}

void insertNode(AdjList L, int i, int j, int weight){
    Node *p = (Node*) malloc(sizeof(Node));
    if(p == NULL)
        return;
    
    p->vertex = j;
    p->weight = weight;
    p->Next = L[i]->Next;
    L[i]->Next = p;
}

void buildGraph(AdjList *L, int *num_of_vertex, int *num_of_edge){
    int first_vertex, second_vertex, weight;
    cin >> *num_of_vertex >> *num_of_edge;
    init(L, *num_of_vertex);
    for(int i = 1; i <= *num_of_edge; i++){
        cin >> first_vertex >> second_vertex >> weight;
        insertNode(*L, first_vertex, second_vertex, weight);
       // insertNode(*L, second_vertex, first_vertex, weight);
    }
}

bool checkAdjacent(AdjList L, int u, int v){
    Node *p = (Node*) malloc(sizeof(Node));
    p = L[u];
    while (p->Next != NULL) {
        if (p->Next->vertex == v) {
            return true;
        }
        p = p->Next;
    }
    return false;
}

//void releaseList(Node *L1){
//    Node *q = new Node;
//    Node *p = new Node;
//    p = L1;
//    while (p->Next != NULL) {
//        q = p->Next;
//        p->Next = q->Next;
//        delete q;
//    }
//}

void dijkstra(){
    AdjList L;
    int num_of_vertex, num_of_edge;
    Node *p;// = (Node*) malloc(sizeof(Node));
    int distance[MaxSize + 1];
    bool visit[MaxSize + 1];
    PriorityQueue pQ;
    KeyType k;
    buildGraph(&L, &num_of_vertex, &num_of_edge);
    for(int i = 0; i <= MaxSize; i++){
        distance[i] = oo;
        visit[i] = false;
    }
    distance[1] = 0;
    k.weight = 0;
    k.vertex = 1;
    makeNull(&pQ);
    pQ.size = 0;
    pQ.key = (KeyType*) malloc(num_of_edge*sizeof(KeyType));
    insert(&pQ, k);
    
    while (!isEmpty(pQ)) {
        k = extractMin(&pQ);
        int u = k.vertex;
        if(!visit[u]) visit[u] = true;
        p = L[u];
        while (p->Next != NULL) {
            int weight = p->Next->weight;
            int v = p->Next->vertex;
            if(distance[v] > distance[u] + weight){
                KeyType dis;
                distance[v] = distance[u] + weight;
                dis.vertex = v;
                dis.weight = distance[v];
                insert(&pQ, dis);
            }
            p = p->Next;
        }
    }
    
    for (int i = 2; i <= num_of_vertex; i++) {
        cout << distance[i] << " ";
    }
    free(pQ.key);
    //free(p);
}

void calculateDistance(const char* shortestPath){
    freopen(shortestPath, "r", stdin);
    dijkstra();

}