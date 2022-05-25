#include <bits/stdc++.h>

#include "algo/boruvka.h"
#include "algo/kruskal.h"
#include "algo/prim.h"
#include "types/graph.h"
#include "helper/timer.h"

using namespace std;
mt19937 mt(time(nullptr));

int random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(mt);
}

Graph generateGraph(int n, int m) {
    assert(n - 1 <= m);
    vector<Edge> edges;
    for (int i = 2; i <= n; ++i) {
        edges.push_back({random(0, n - 1), i - 1, random(0, INF  - 1)});
    }

    for (int i = n; i <= m; ++i) {
        edges.push_back({random(0, n - 1), random(0, n - 1), random(0, INF - 1)});
    }
    return Graph({n, edges});
}

vector<long long> handle(int n, int m, int type) {
    Graph g = generateGraph(n, m);
    Timer timer;
    cout << "handling graph with " << n << " vertices and " << m << " edges" << endl;
    // cout << "MST_Kruskal: " << MST_Kruskal(g, timer) << endl;
    // cout << "MST_PrimSlow: " << MST_PrimSlow(g, timer) << endl;
    // cout << "MST_PrimFast: " << MST_PrimFast(g, timer) << endl;
    // cout << "MST_Boruvka: " << MST_Boruvka(g, timer) << endl;

    return {type, n, m, MST_Kruskal(g, timer), MST_PrimSlow(g, timer), MST_PrimFast(g, timer), MST_Boruvka(g, timer)};
}

int main() {
    vector<vector<long long> > res;
    res = {
        handle(1000, 3000, 0),
        handle(5000, 15000, 0),
        handle(10000, 30000, 0),
        handle(50000, 150000, 0),
        handle(100000, 100000 * 3, 0),
        handle(500000, 500000 * 3, 0),
        handle(1000, 1000000, 1),
        handle(2000, 4000000, 1),
        handle(3000, 9000000, 1),
        handle(4000, 16000000, 1),
        handle(5000, 25000000, 1),
    };

    ofstream fout("data.csv");
    fout << "type,n,m,kruskal,prim_n2,prim_mlog,boruvka" << endl;
    for (auto& v : res) {
        fout << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "," << v[4] << "," << v[5] << "," << v[6] << endl;
    }
    fout.close();

    // Graph g = generateGraph(10, 20);

    // cout << MST_Kruskal(g) << '\n';
    // cout << MST_PrimSlow(g) << '\n';
    // cout << MST_PrimFast(g) << '\n';
    // cout << MST_Boruvka(g) << '\n';
}