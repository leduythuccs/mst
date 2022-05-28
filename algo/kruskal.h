#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "../types/graph.h"
#include "../helper/timer.h"

long long _MST_Kruskal(const Graph& g) {
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

long long MST_Kruskal(const Graph& g, Timer &timer, int t = 1) {
    timer.start();
    for (int i = 1; i <= t; ++i)
        _MST_Kruskal(g);
    return timer.getRunningTime() / t;
}
#endif
