#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int minTime = INT_MAX;
    bool found = false;
    int n;
    cin >> n;
    string dir;
    cin >> dir;
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i];
    for (int i = 0; i < n - 1; i++)
    {
        if (dir[i] == 'R' && dir[i + 1] == 'L')
        {
            int time = (pos[i + 1] - pos[i]) / 2;
            minTime = min(minTime, time);
            found = true;
        }
    }
    cout << (found ? minTime : -1) << endl;
    return 0;
}
