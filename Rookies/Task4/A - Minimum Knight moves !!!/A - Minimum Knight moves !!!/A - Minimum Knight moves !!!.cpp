#include <iostream>
#include <vector>
#include <queue>
using namespace std;
pair<int, int> ConvertTo8x8(string position)
{
    return pair<int, int> {position[0] - 'a', position[1] - '1'};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, int>> directions
    {
        {1,2} , {-1,2} ,
        {-2,-1} , {-2,1},
        {2,1} ,{2,-1},
        {1,-2}, {-1,-2}
    };
    int t;
    cin >> t;
    while (t--)
    {
        string s, d;
        cin >> s >> d;
        if (s == d)
        {
            cout << 0 << endl;
            continue;
        }
        pair<int, int> start = ConvertTo8x8(s);
        pair<int, int> dest = ConvertTo8x8(d);
        queue<pair<pair<int, int>, int>> q;
        q.push({ start,0 });
        bool visited[8][8] = { false };
        visited[start.first][start.second] = true;
        bool found = false;
        while (!q.empty() && !found)
        {
            pair<pair<int, int>, int> front = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int x = front.first.first + directions[i].first;
                int y = front.first.second + directions[i].second;
                if (x == dest.first && y == dest.second)
                {
                    front.second++;
                    cout << front.second << endl;
                    found = true;
                    break;
                }
                if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && !visited[x][y])
                {
                    visited[x][y] = true;
                    q.push({ {x,y},front.second + 1 });
                }
            }
        }
    }

    return 0;
}
