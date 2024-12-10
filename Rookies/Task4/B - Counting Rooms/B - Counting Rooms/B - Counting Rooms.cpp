#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, int>> directions
    {
        {1,0},{0,1},{-1,0},{0,-1}
    };

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    int rooms = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                rooms++;
                queue<pair<int, int>> q;
                q.push({ i,j });

                visited[i][j] = true;
                while (!q.empty())
                {
                    pair<int, int> front = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int x = front.first + directions[k].first;
                        int y = front.second + directions[k].second;
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y])
                        {
                            visited[x][y] = true;
                            q.push({ x,y });
                        }
                    }
                }
            }
        }
    }
    cout << rooms;


    return 0;
}
