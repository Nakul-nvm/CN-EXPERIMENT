#include <bits/stdc++.h>
using namespace std;
void linkStateRouting(vector<pair<int, int>> adjacencyList[], int n, int source)
{
    int INF = INT_MAX;
    vector<int> distance(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        int dist = pq.top().first, u = pq.top().second;
        pq.pop();
        if (distance[u] != dist)
            continue;
        for (pair<int, int> j : adjacencyList[u])
        {
            int v = j.first, w = j.second;
            if (distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }
    cout << "Router " << source << " Shortest Paths:\n";
    cout << "Destination\tDistance\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t\t";
        if (distance[i] == INF)
            cout << "INF";
        else
            cout << distance[i];
        cout << endl;
    }
}
void inputGraph(vector<pair<int, int>> adjacencyList[], int n, int m)
{
    cout << "Enter " << m << " links (u, v, w):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjacencyList[u].push_back({v, w});
        adjacencyList[v].push_back({u, w});
    }
}
int main()
{
    int n, m, source;
    cout << "Enter number of routers: ";
    cin >> n;
    cout << "Enter number of links: ";
    cin >> m;
    vector<pair<int, int>> adjacencyList[n];
    inputGraph(adjacencyList, n, m);
    for (int src = 0; src < n; src++)
    {
        linkStateRouting(adjacencyList, n, src);
    }
}