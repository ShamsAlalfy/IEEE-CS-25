#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> vv(m);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
        cin >> vv[i];

    long long left = 0, right = 2e9, result = right;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        int j = 0;
        bool isCovered = true;
        for (int i = 0; i < n; i++)
        {
            while (j < m && abs(vv[j] - v[i]) > mid)
                j++;
            if (j == m)
            {
                isCovered = false;
                break;
            }
        }
        if (isCovered)
        {
            result = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << result << endl;
    return 0;
}
