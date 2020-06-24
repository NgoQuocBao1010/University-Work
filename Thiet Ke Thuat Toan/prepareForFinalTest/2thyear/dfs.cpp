#include <iostream>
#include <vector>

using namespace std;

int dfs(vector <vector <bool>> &graph, vector <bool> &visited, int numOfNodes, int node, int &count) {
    visited[node] = true;
    count --;

    for (int i=1; i<=numOfNodes; i++) {
        if (graph[node][i]) {
            if (!visited[i]) {
                dfs(graph, visited, numOfNodes, i, count);
            }
        }
    }
    return count;
}

void master() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector <vector <bool>> graph;
    vector <bool> visited;

    for (int i=0; i<nodes + 1; i++) {
        vector <bool> tmp;
        for (int j=0; j<nodes + 1; j++) {
            tmp.push_back(false);
        }
        graph.push_back(tmp);
        visited.push_back(false);
    }

    for (int i=0; i<edges; i++) {
        int from, to;
        cin >> from >> to;
        graph[from][to] = true;
        graph[to][from] = true;
    }

    int header;
    cin >> header;
    dfs(graph, visited, nodes, header, nodes);
}

int main() {
    return 0;
}