#ifndef BORUVKA_H
#define BORUVKA_H
#include "../types/graph.h"
struct BoruvkaEdge {
    int u, v, w, id;
    bool operator<(BoruvkaEdge const& other) const {
        if (w != other.w) return w < other.w;
        return id < other.id;
    }
};

long long MST_Boruvka(const Graph& g) {
    vector<BoruvkaEdge> edges;
    edges.reserve(g.edges.size());
    int cnt = 0;
    for (const Edge& e : g.edges) {
        edges.push_back({e.u, e.v, e.weight, cnt});
        cnt += 1;
    }

    int n = g.n;
    long long ans = 0;
    vector<bool> used(edges.size(), false);
    while (!edges.empty()) {
        //find local minimal edges
        vector<int> minEdge(n, -1);
        for (int i = 0; i < edges.size(); i++) {
            if (minEdge[edges[i].u] < 0 || edges[i] < edges[minEdge[edges[i].u]]) minEdge[edges[i].u] = i;
            if (minEdge[edges[i].v] < 0 || edges[i] < edges[minEdge[edges[i].v]]) minEdge[edges[i].v] = i;
        }
        //build graph with local minimal edges
        vector<vector<int>> adj(n);
        for (int x : minEdge) {
            if (x < 0) continue;
            used[edges[x].id] = true;
            adj[edges[x].u].push_back(edges[x].v);
            adj[edges[x].v].push_back(edges[x].u);
        }
        //find components
        vector<int> c(n, -1);
        int cs = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] >= 0) continue;
            vector<int> s = {i};
            c[i] = cs;
            while (!s.empty()) {
                int x = s.back();
                s.pop_back();
                for (int y : adj[x]) {
                    if (c[y] >= 0) continue;
                    c[y] = cs;
                    s.push_back(y);
            }}
            cs++;
        }
        //update
        n = cs;
        for (int i = 0; i < edges.size();) {
            edges[i].u = c[edges[i].u];
            edges[i].v = c[edges[i].v];
            if (edges[i].u == edges[i].v) {
                swap(edges[i], edges.back());
                edges.pop_back();
            } else {
                i++;
            }
        }
    }
    for (int i = 0; i < used.size(); ++i) {
        if (used[i]) ans += g.edges[i].weight;
    }
    return ans;
}
#endif