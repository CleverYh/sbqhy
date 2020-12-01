// shortest_path.cpp
#include <iostream>
#include <map>
#include <vector>

#define INFINITY 2147483647

using namespace std;

typedef int Vertex;
typedef int Weight;
typedef vector<vector<Weight>> Graph;

// A function which constructs the graph
Graph mkGraph() {
    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum;
    vector<Weight> initVec(nodeNum, INFINITY);
    Graph adjGraph(nodeNum, initVec);

    Vertex u, v;
    Weight w;
    for (size_t i = 0; i < edgeNum; i++) {
        cin >> u >> v >> w;
        adjGraph[u - 1][v - 1] = w;
    }
    return adjGraph;
}

// A function which computes all the shortest paths
vector<Weight> dijkstra(Graph g, Vertex source) {

    int n = g.size();

    vector<Weight> dist(n, INFINITY);
    vector<bool> known(n, false);

    for (size_t i = 0; i < n; i++)
        dist[i] = g[source - 1][i];

    dist[source - 1] = 0;
    known[source - 1] = true;

    for (size_t i = 0; i < n; i++) {
        Vertex v = -1;
        int m = INFINITY;

        for (size_t i = 0; i < n; i++) {
            if (!known[i] && dist[i] < m) {
                v = i;
                m = dist[i];
            }
        }

        if (v == -1) break;

        known[v] = true;
        for (size_t i = 0; i < n; i++) {
            if (!known[i] && (g[v][i] < INFINITY)) // or dist + cvw will overflow
                if (dist[v] + g[v][i] < dist[i]) dist[i] = dist[v] + g[v][i];
        }
    }
    return dist;
}

// A print function which prints the result as required
void print(vector<Weight> d, Vertex source) {
    for (size_t i = 0; i < d.size(); i++)
        if (d[i] < INFINITY)
            cout << source - 1 << "-" << (i + 1) << ":" << d[i] << endl;
}

void shortest_path() {
    int sourceVertex;
    Graph g = mkGraph();
    cin >> sourceVertex;
    vector<Weight> d = dijkstra(g, sourceVertex);
    print(d, sourceVertex);
}

int main() {
    int T;
    cin >> T;
    while (T--) shortest_path();
    return 0;
}
