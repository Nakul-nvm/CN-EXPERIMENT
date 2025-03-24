#include <bits/stdc++.h>
using namespace std;
void dijkstra(vector<pair<int, int>> adjacencyList[], int n, int source)
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
    cout << "Shortest Path Distance for each vertex from the source vertex " << source << " is as follows: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Vertex: " << i << " - " << "Distance: " << distance[i] << endl;
    }
}
void inputGraph(vector<pair<int, int>> adjacencyList[], int n, int m)
{
    cout << "Enter " << m << " edges (u, v, w):" << endl;
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
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<pair<int, int>> adjacencyList[n];
    inputGraph(adjacencyList, n, m);
    cout << "Enter source vertex: ";
    cin >> source;
    dijkstra(adjacencyList, n, source);
}