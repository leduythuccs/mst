#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

const int INF = 2e9;  // weight INF means there is no edge
using namespace std;
struct Edge {
    int u, v, weight = INF;
    bool operator<(Edge const& other) const {
        return make_pair(weight, v) < make_pair(other.weight, other.v);
    }
};

struct Graph {
    int n;
    vector<Edge> edges;
};

struct DisjoinSet {
    Graph g;
    vector<int> parent;

    DisjoinSet(const Graph& g) : g(g) {
        parent.resize(g.n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        parent[x] = y;
    }
};

#endif