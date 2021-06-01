#include <iostream>
#include <queue>
#include <cstring>

#define oo 1000000007
typedef pair<int, int> KeyValue;

using namespace std;

void dijkstra() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector <pair <int, int>> graph[100007];
    int distance[100007];
    memset(distance, oo, sizeof distance);

    int from, to, weight;
    for (int i=0; i<edges; i++) {
        cin >> from >> to >> weight;
        graph[from].push_back(make_pair(to, weight));
        // graph[to].push_back(make_pair(from, weight));
    }

    priority_queue <KeyValue, vector<KeyValue>, greater<KeyValue>> q;

    distance[1] = 0;
    q.push(make_pair(0, 1));

    while (!q.empty()) {
        KeyValue top = q.top();
        q.pop();
        int node = top.second;

        for (int i=0; i < graph[node].size(); i++) {
            int v = graph[node][i].first;
            int w = graph[node][i].second;

            if (distance[v] > distance[node] + w) {
                distance[v] = distance[node] + w;
                q.push(make_pair(distance[v], v));
            }
        }
    }
    for (int i=2; i<=nodes; i++) {
        cout << distance[i] << " ";
    }
}

void calculateDistance(const char* shortestPath){
    freopen(shortestPath, "r", stdin);
    dijkstra();
}

int main() {

    return 0;
}