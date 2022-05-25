#include <bits/stdc++.h>

#include "algo/boruvka.h"
#include "algo/kruskal.h"
#include "algo/prim.h"
#include "types/graph.h"
using namespace std;

int main() {
    vector<Edge> edges;
    edges.push_back({0, 1, 3});
    edges.push_back({1, 2, 1});
    edges.push_back({0, 2, 1});

    cout << MST_Kruskal(Graph{3, edges}) << '\n';
    cout << MST_PrimSlow(Graph{3, edges}) << '\n';
    cout << MST_PrimFast(Graph{3, edges}) << '\n';
    cout << MST_Boruvka(Graph{3, edges}) << '\n';
}