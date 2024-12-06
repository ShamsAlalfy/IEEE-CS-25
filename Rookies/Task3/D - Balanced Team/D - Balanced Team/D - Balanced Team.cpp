#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    int mx = 0;

    for (int i = 0, j = 0; j < n; j++)
    {
        while (a[j] > a[i] + 5)
            i++;
        mx = max(mx, j - i + 1);
    }
    cout << mx << endl;
    return 0;
}
