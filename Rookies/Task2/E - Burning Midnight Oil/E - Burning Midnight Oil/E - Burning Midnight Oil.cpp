#include <iostream>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long left = 1, right = n, result = n;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        long long total = 0;
        long long current = mid;
        while (current > 0)
        {
            total += current;
            current /= k;
            if (total >= n)
                break;
        }
        if (total >= n)
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
