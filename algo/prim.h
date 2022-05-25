#ifndef PRIM_H
#define PRIM_H
#include "../types/graph.h"
struct PrimeEdge {
    int weight = INF, to = -1;
    bool operator<(PrimeEdge const& other) const {
        return make_pair(weight, to) < make_pair(other.weight, other.to);
    }
};

long long MST_PrimSlow(const Graph& g) {
    int n = g.n;
    vector<bool> selected(n, false);
    vector<PrimeEdge> min_e(n);
    min_e[0].weight = 0;

    vector<vector<int>> adj(n, vector<int>(n, INF));
    for (const Edge& e : g.edges) {
        adj[e.u][e.v] = min(adj[e.u][e.v], e.weight);
        adj[e.v][e.u] = min(adj[e.v][e.u], e.weight);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].weight < min_e[v].weight))
                v = j;
        }

        if (min_e[v].weight == INF) {
            return -1;
        }

        selected[v] = true;
        ans += min_e[v].weight;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].weight) min_e[to] = {adj[v][to], v};
        }
    }

    return ans;
}
long long MST_PrimFast(const Graph& g) {
    int n = g.n;
    long long ans = 0;
    vector<PrimeEdge> min_e(n);
    min_e[0].weight = 0;
    set<PrimeEdge> q;
    q.insert({0, 0});
    vector<bool> selected(n, false);
    vector<vector<Edge>> adj(n);
    for (const Edge& e : g.edges) {
        adj[e.u].push_back(e);
        adj[e.v].push_back({e.v, e.u, e.weight});
    }
    for (int i = 0; i < n; ++i) {
        if (q.empty()) {
            return -1;
        }

        int v = q.begin()->to;
        selected[v] = true;
        ans += q.begin()->weight;
        q.erase(q.begin());

        for (Edge e : adj[v]) {
            if (!selected[e.v] && e.weight < min_e[e.v].weight) {
                q.erase({min_e[e.v].weight, e.v});
                min_e[e.v] = {e.weight, v};
                q.insert({e.weight, e.v});
            }
        }
    }

    return ans;
}
#endif