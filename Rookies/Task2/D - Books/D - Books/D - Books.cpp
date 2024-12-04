#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n, t;
    cin >> n >> t;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    long long left = 0, right = 0, time = 0, maxBooks = 0;
    while (right < n)
    {
        time += v[right];
        while (time > t)
        {
            time -= v[left];
            left++;
        }
        maxBooks = max(maxBooks, right - left + 1);
        right++;
    }
    cout << maxBooks;
    return 0;
}
