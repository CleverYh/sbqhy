#include <iomanip>
#include <iostream>
#include <vector>

#define MAXVERTEX 100

using namespace std;

typedef int VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vertexes[MAXVERTEX];
    EdgeType edges[MAXVERTEX][MAXVERTEX] = {0};
    size_t num_edges, num_vertexes, deg[MAXVERTEX] = {0};
} MyGraph;

void createGraph(MyGraph *G) {
    cout << "input number of vertexes and number of edges" << endl;
    cin >> G->num_vertexes >> G->num_edges;
    for (int i = 0; i < G->num_vertexes; i++) {
        cin >> G->vertexes[i];
    }
    for (int k = 0; k < G->num_edges; k++) {
        cout << "input the two vertexes" << endl;
        int i, j;
        cin >> i >> j;
        G->deg[i]++;
        G->deg[j]++;
        G->edges[i][j] = 1;
        G->edges[j][i] = 1;
    }
}

void printGraph(MyGraph G) {
    cout << left << setw(6) << "Vex";
    for (int i = 0; i < G.num_vertexes; i++) cout << setw(6) << G.vertexes[i];
    cout << setw(6) << "Deg" << endl;
    for (int i = 0; i < G.num_vertexes; i++) {
        cout << setw(6) << G.vertexes[i];
        for (int j = 0; j < G.num_vertexes; j++) cout << setw(6) << G.edges[i][j];
        cout << setw(6) << G.deg[i] << endl;
    }
}

int main() {
    MyGraph G;
    createGraph(&G);
    printGraph(G);
    return 0;
}