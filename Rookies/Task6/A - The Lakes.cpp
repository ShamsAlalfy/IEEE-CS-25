#include <bits/stdc++.h>
using namespace std;

int dfs(int x,int y, vector<vector<bool>>& visited, const vector<vector<int>>& grid,vector<pair<int,int>> directions)
{
    visited[x][y] = true;
    int volume = grid[x][y];
    for (int i = 0 ; i < 4 ; i++ )
    {
        int xx = x + directions[i].first;
        int yy = y + directions[i].second;
        if (xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[0].size()
            && grid[xx][yy] > 0 && !visited[xx][yy])
                volume += dfs(xx,yy,visited,grid,directions);
    }
    return volume;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int,int>> directions {{-1,0},{0,1},{1,0},{0,-1}};
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> grid(n,vector<int>(m));
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0 ; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        int maxVolume = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j++)
            {
                if (grid[i][j] > 0 && !visited[i][j])
                maxVolume = max(maxVolume,dfs(i,j,visited,grid,directions));
            }
        }
        cout << maxVolume << endl;

    }



    return 0;
}
