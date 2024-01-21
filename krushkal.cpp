#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 9999999
#define V 5

int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}
};

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int findParent(int parent[], int component) {
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalMST(int numVertices, Edge edges[]) {
    sort(edges, edges + numVertices, compareEdges);

    int parent[V];
    int rank[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    cout << "Edge"
         << " : "
         << "Weight" << endl;

    int no_edge = 0;
    int i = 0;
    while (no_edge < V - 1) {
        Edge nextEdge = edges[i++];
        int u = findParent(parent, nextEdge.src);
        int v = findParent(parent, nextEdge.dest);
        if (u != v) {
            cout << nextEdge.src << " - " << nextEdge.dest << " : " << nextEdge.weight << endl;
            unionSet(u, v, parent, rank);
            no_edge++;
        }
    }
}

int main() {
    Edge edges[V * V];
    int edgeCount = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (G[i][j] != 0) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = G[i][j];
                edgeCount++;
            }
        }
    }
    kruskalMST(edgeCount, edges);

    return 0;
}
