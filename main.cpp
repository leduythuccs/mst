#include <bits/stdc++.h>

#include "algo/boruvka.h"
#include "algo/kruskal.h"
#include "algo/prim.h"
#include "types/graph.h"
using namespace std;

int main() {
    vector<int> v(3);
    iota(v.begin(), v.end(), 1);
    vector<Edge> edges;
    edges.push_back({1, 2, 1});
    edges.push_back({2, 3, 1});

    cout << MST_Kruskal(Graph{v, edges}) << '\n';
    cout << MST_Prim(Graph{v, edges}) << '\n';
    cout << MST_Boruvka(Graph{v, edges}) << '\n';
}