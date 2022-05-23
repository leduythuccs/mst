#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

using namespace std;
struct Edge {
    int u, v, w;
};

struct Graph {
    vector<int> vertexes;
    vector<Edge> edges;
};

#endif