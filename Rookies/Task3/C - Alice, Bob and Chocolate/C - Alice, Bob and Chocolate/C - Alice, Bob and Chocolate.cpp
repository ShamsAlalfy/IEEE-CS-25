#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int x = 0, y = 0, z = 0, m = 0, s = 0, n;
    cin >> n;
    vector<int> a(n);
    while (m < n)
        cin >> a[m++];
    while (z + s < n)
    {
        if (y < x)
        {
            y += a[n - 1 - z];
            z++;
        }
        else
        {
            x += a[s];
            s++;
        }
    }
    cout << s << " " << z;
    return 0;
}
