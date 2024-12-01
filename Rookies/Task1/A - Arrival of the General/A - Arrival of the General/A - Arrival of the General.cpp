#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> heigths(n);
    for (int i = 0; i < n; i++)
        cin >> heigths[i];
    int min = 0, max = 0;
    for (int i = 1; i < n; i++)
    {
        if (heigths[i] <= heigths[min])
            min = i;
    }
    for (int i = 1; i < n; i++)
    {
        if (heigths[i] > heigths[max])
            max = i;
    }
    int sec = max + (n - 1 - min);
    if (max > min)
        sec--;
    cout << sec << endl;

    return 0;
}
