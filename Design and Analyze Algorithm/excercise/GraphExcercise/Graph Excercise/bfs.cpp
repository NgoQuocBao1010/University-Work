#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define oo 1000000007

void bfs() {
    int countries;
    cin >> countries;

    vector <int> graph[10007];
    int distance[10007];

    for (int i=1; i<=countries; i++)
        distance[i] = -1;


    for (int i=0; i< countries - 1; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int num;
    cin >> num;
    int contender[10007];

    for (int i=0; i<num; i++) {
        cin >> contender[i];
    }


    // BFS 
    queue <int> q;
    q.push(1);
    distance[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i=0; (unsigned) i < (unsigned) graph[u].size(); i++) {
            int v = graph[u][i];

            if (distance[v] == -1 || distance[v] > distance[u] + 1) {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    int min = oo;
    int ans = oo;



    for (int i=0; i < num; i++) {
        if (distance[contender[i]] < min) {
            min = distance[contender[i]];

            if (contender[i] < ans)
                ans = contender[i];
        }
    }
    cout << ans;
}

int main() {
    int test[10] = {-1};
    cout << test[1] << endl;
}