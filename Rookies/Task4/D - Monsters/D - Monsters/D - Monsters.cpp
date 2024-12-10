#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<char>> direction(rows, vector<char>(cols));
    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols));
    vector<vector<int>> playerTime(rows, vector<int>(cols, -1));
    vector<vector<int>> monsterTime(rows, vector<int>(cols, -1));

    int startX = -1, startY = -1;
    vector<pair<int, int>> monsterPos;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                startX = i;
                startY = j;
            }
            else if (grid[i][j] == 'M') {
                monsterPos.push_back({ i, j });
            }
        }
    }

    vector<pair<pair<int, int>, char>> directions = {
        {{-1, 0}, 'U'},
        {{1, 0}, 'D'},
        {{0, -1}, 'L'},
        {{0, 1}, 'R'}
    };

    queue<pair<int, int>> monsterQueue;
    for (auto& monster : monsterPos) {
        monsterQueue.push(monster);
        monsterTime[monster.first][monster.second] = 0;
    }

    while (!monsterQueue.empty()) {
        auto current = monsterQueue.front();
        monsterQueue.pop();
        int x = current.first, y = current.second;

        for (auto& dir : directions) {
            int newX = x + dir.first.first, newY = y + dir.first.second;
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] != '#' && monsterTime[newX][newY] == -1) {
                monsterTime[newX][newY] = monsterTime[x][y] + 1;
                monsterQueue.push({ newX, newY });
            }
        }
    }

    queue<pair<int, int>> playerQueue;
    playerQueue.push({ startX, startY });
    visited[startX][startY] = true;
    playerTime[startX][startY] = 0;

    while (!playerQueue.empty()) {
        auto current = playerQueue.front();
        playerQueue.pop();
        int x = current.first, y = current.second;

        if (x == 0 || x == rows - 1 || y == 0 || y == cols - 1) {
            cout << "YES\n";
            string path = "";
            while (!(x == startX && y == startY)) {
                path += direction[x][y];
                auto prev = parent[x][y];
                x = prev.first;
                y = prev.second;
            }
            reverse(path.begin(), path.end());
            cout << path.length() << "\n" << path << "\n";
            return 0;
        }

        for (auto& dir : directions) {
            int newX = x + dir.first.first, newY = y + dir.first.second;
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] != '#' && !visited[newX][newY] &&
                (playerTime[x][y] + 1 < monsterTime[newX][newY] || monsterTime[newX][newY] == -1)) {
                visited[newX][newY] = true;
                direction[newX][newY] = dir.second;
                parent[newX][newY] = { x, y };
                playerTime[newX][newY] = playerTime[x][y] + 1;
                playerQueue.push({ newX, newY });
            }
        }
    }

    cout << "NO\n";
    return 0;
}
