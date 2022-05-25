#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "../types/graph.h"

long long MST_Kruskal(const Graph& g) {
    vector<Edge> edges = g.edges;
    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) { return a.weight < b.weight; });

    DisjoinSet ds(g);
    long long ans = 0;
    for (const Edge& e : edges) {
        if (ds.find(e.u) != ds.find(e.v)) {
            ans += e.weight;
            ds.merge(e.u, e.v);
        }
    }
    return ans;
}
#endif