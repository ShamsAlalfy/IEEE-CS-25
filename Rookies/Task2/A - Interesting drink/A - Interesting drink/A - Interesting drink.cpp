#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    long long q;
    cin >> q;
    while (q--)
    {
        long long x;
        cin >> x;
        int index = upper_bound(v.begin(), v.end(), x) - v.begin();
        cout << index << endl;
    }
    return 0;
}
