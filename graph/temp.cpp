#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct ALGraph {
    vector<vector<size_t>> adj;
    size_t verNum, edgeNum;
    ALGraph(int n = 0, int m = 0) : verNum(n), edgeNum(m) {
        adj.resize(n);
    }
} ALGraph;

vector<int> degreeSequence(const ALGraph &g) {
    vector<int> degree(g.verNum);
    for (int i = 0; i < g.verNum; i++) {
        degree[i] = g.adj[i].size();
    }
    sort(degree.begin(), degree.end(), greater<int>());
    return degree;
}

ALGraph mkGraph() {
    int m, n;
    cin >> m >> n;
    ALGraph g(m, n);
    for (int k = 0; k < g.edgeNum; k++) {
        int i, j;
        cin >> i >> j;
        g.adj[i].push_back(j);
        g.adj[j].push_back(i);
    }
    return g;
}

void printDeg(const vector<int> &deg) {
    for (auto &x : deg) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int test_num;
    cin >> test_num;
    while (test_num--) {
        ALGraph G;
        G = mkGraph();
        vector<int> deg;
        deg = degreeSequence(G);
        printDeg(deg);
    }
    return 0;
}