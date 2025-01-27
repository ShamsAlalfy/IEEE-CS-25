#include <bits/stdc++.h>
using namespace std;

void dfs(int node1, vector<vector<int>>& adj,vector<bool>& visited)
{
    for(int node2 : adj[node1])
    {
        if(!visited[node2])
        {
            visited[node2] =  true;
            dfs(node2,adj,visited);
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1 ; i <= n ; i++)
    {
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    vector<bool> visited(n+1);
    int count = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!visited[i])
        {
            count++;
            visited[i] = true;
            dfs(i,adj,visited);
        }
    }
    cout << count << endl;
    return 0;
}
