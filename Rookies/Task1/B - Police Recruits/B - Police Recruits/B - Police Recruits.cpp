#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int officers = 0;
    int crimes = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num == -1)
        {
            if (officers > 0)
                officers--;
            else
                crimes++;
        }
        else
        {
            officers += num;
        }
    }
    cout << crimes << endl;
    return 0;
}
