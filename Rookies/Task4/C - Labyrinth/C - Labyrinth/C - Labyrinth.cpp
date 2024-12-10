#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<pair<int, int>, char>> directions
    {
        {{1,0},'D'},{{0,1},'R'},{{-1,0},'U'},{{0,-1},'L'}
    };

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, { -1,-1 }));
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    pair<int, int> start, dest;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A' && !visited[i][j])
                start = { i,j };
            else if (grid[i][j] == 'B')
                dest = { i,j };
        }
    }
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    bool found = false;
    while (!q.empty() && !found)
    {
        pair<int, int> front = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int x = front.first + directions[k].first.first;
            int y = front.second + directions[k].first.second;
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y])
            {
                visited[x][y] = true;
                prev[x][y] = front;
                if (grid[x][y] == 'B')
                {
                    found = true;
                    break;
                }
                q.push({ x, y });
            }
        }
    }
    if (found)
    {
        cout << "YES" << endl;
        string path = "";
        pair<int, int> current = dest;
        while (current != start)
        {
            pair<int, int> p = prev[current.first][current.second];
            for (int k = 0; k < 4; k++)
            {
                if (p.first + directions[k].first.first == current.first && p.second + directions[k].first.second == current.second)
                {
                    path += directions[k].second;
                    break;
                }
            }
            current = p;
        }
        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
