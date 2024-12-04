#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long d;
    cin >> n >> d;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    long long r = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k < n && v[k] - v[i] <= d)
            k++;
        long long counter = k - i - 1;
        if (counter >= 2)
            r += (counter * (counter - 1)) / 2;
    }
    cout << r << endl;
    return 0;
}