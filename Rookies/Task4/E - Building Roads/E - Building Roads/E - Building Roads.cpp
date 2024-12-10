#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<vector<int>> components;
    int comCount = 0;

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            components.emplace_back();
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                components.back().push_back(node);

                for (int neighbor : adj[node])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            comCount++;
        }
    }

    if (comCount == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    cout << comCount - 1 << endl;

    vector<int> represent;
    for (const auto& component : components)
        represent.push_back(component[0]);

    for (int i = 1; i < represent.size(); ++i)
        cout << represent[i - 1] << " " << represent[i] << endl;

    return 0;
}
