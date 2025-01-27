#include <bits/stdc++.h>
using namespace std;

int dfs(int node,int parent,vector<vector<pair<int,int>>>& tree)
{
    int cost = 0;
    for(auto& it: tree[node])
    {
        int n = it.first;
        int c = it.second;
        if (n != parent)
            cost = max(cost, c + dfs(n,node,tree));
    }
    return cost;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<pair<int,int>>> friends(n);
    int x = n-1;
    while(x--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        friends[a].push_back(make_pair(b,c));
        friends[b].push_back(make_pair(a,c));
    }
    cout << dfs(0,-1,friends) << endl;

    return 0;
}

