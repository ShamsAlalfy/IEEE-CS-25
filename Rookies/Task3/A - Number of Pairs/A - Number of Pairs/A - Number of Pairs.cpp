#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long c = 0;
        long long n, l, r;
        cin >> n >> l >> r;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
            c += (upper_bound(v.begin() + i + 1, v.end(), r - v[i]) - lower_bound(v.begin() + i + 1, v.end(), l - v[i]));
        cout << c << endl;
    }
    return 0;
}
