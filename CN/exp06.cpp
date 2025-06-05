#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX
#define n 4
struct Router
{
    vector<int> distance;
    vector<int> nextHop;
};
void distanceVectorAlgorithm(vector<vector<int>> &graph)
{
    vector<Router> routers(n);
    for (int i = 0; i < n; i++)
    {
        routers[i].distance = graph[i];
        routers[i].nextHop.resize(n);
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != INF && i != j)
                routers[i].nextHop[j] = j;
            else
                routers[i].nextHop[j] = -1;
        }
    }
    bool updated;
    do
    {
        updated = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                for (int k = 0; k < n; k++)
                {
                    if (routers[i].distance[k] != INF && graph[k][j] != INF &&
                        routers[i].distance[k] + graph[k][j] < routers[i].distance[j])
                    {
                        routers[i].distance[j] = routers[i].distance[k] + graph[k][j];
                        routers[i].nextHop[j] = k;
                        updated = true;
                    }
                }
            }
        }
    } while (updated);
    for (int i = 0; i < n; i++)
    {
        cout << "Routing Table for Router " << i << ":\n";
        cout << "Destination\tNext Hop\tDistance\n";
        for (int j = 0; j < n; j++)
        {
            cout << j << "\t\t";
            if (routers[i].nextHop[j] == -1)
                cout << "-";
            else
                cout << routers[i].nextHop[j];

            cout << "\t\t";
            if (routers[i].distance[j] == INF)
                cout << "INF";
            else
                cout << routers[i].distance[j];
            cout << endl;
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> graph = {
        {0, 1, 4, INF},
        {1, 0, 2, 6},
        {4, 2, 0, 3},
        {INF, 6, 3, 0}};
    distanceVectorAlgorithm(graph);
}