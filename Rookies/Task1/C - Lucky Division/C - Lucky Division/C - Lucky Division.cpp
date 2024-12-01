#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool lucky(int num)
{
    string number = to_string(num);
    for (char c : number)
    {
        if (c != '4' && c != '7')
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> luckies;
    for (int i = 4; i < 1000; i++)
    {
        if (lucky(i))
            luckies.push_back(i);
    }
    int num;
    cin >> num;
    for (int luckyNum : luckies)
    {
        if (num % luckyNum == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
