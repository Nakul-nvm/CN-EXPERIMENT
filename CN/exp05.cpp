#include <bits/stdc++.h>
using namespace std;
class DSU
{
    int n;
    vector<int> parent;
    vector<int> size;

public:
    DSU(int x) : n(x), parent(x), size(x)
    {
        for (int i = 0; i < n; i++)
            makeSet(i);
    }
    void makeSet(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }
    int findSet(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = findSet(parent[v]);
    }

    void unionSet(int a, int b)
    {
        a = findSet(a);
        b = findSet(b);
        if (a != b)
        {
            if (size[a] < size[b])
            {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
void Krushkal(vector<vector<int>> edges, int n, int m)
{
    DSU d(n);
    sort(edges.begin(), edges.end(), [](vector<int> &x, vector<int> &y)
         { return x[2] < y[2]; });
    int minCost = 0;
    cout << "Edges in Minimum Spanning Tree:" << endl;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        if (d.findSet(u) != d.findSet(v))
        {
            cout << u << " - " << v << endl;
            minCost += w;
            d.unionSet(u, v);
        }
    }
    cout << "Minimum Spanning Tree Cost = " << minCost << endl;
}

void inputGraph(vector<vector<int>> &edges, int n, int m)
{
    cout << "Enter " << m << " edges (u, v, w):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
}
int main()
{
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<int>> edges;
    inputGraph(edges, n, m);
    Krushkal(edges, n, m);
}