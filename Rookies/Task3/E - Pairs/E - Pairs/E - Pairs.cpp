#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int i = 0, j = 0, count = 0;

    while (j < n)
    {
        int d = arr[j] - arr[i];

        if (d == k)
        {
            count++;
            i++;
            j++;
        }
        else if (d < k)
            j++;
        else
            i++;
    }
    cout << count << endl;

    return 0;
}
