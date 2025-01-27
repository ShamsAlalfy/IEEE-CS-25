#include <bits/stdc++.h>
using namespace std;

int dfs(int node,int parent,int m,int c,vector<int>& cats,vector<vector<int>>& adj)
{
    if(cats[node] == 1)
        c++;
    else
        c = 0;
    if(c > m)
        return 0;
    bool isleaf = true;
    int count = 0;
    for(int x : adj[node])
    {
        if(x != parent)
        {
            isleaf = false;
            count += dfs(x,node,m,c,cats,adj);
        }
    }
    if (isleaf == true)
        return 1;
    return count;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<int> cats(n);
    vector<vector<int>> adj(n);
    for(int i = 0 ; i < n ; i++)
        cin >> cats[i];
    for(int i = 0 ; i < n - 1; i++)
    {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << dfs(0,-1,m,0,cats,adj) << endl;
    return 0;
}
