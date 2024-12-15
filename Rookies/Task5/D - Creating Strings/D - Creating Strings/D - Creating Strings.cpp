#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void getAllStrings(string str, int l, int r, set<string>& strings)
{
    if (l == r)
    {
        strings.insert(str);
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(str[l], str[i]);
        getAllStrings(str, l + 1, r, strings);
        swap(str[l], str[i]);
    }
}

int main() {
    string input;
    cin >> input;

    set<string> strings;
    getAllStrings(input, 0, input.size() - 1, strings);
    vector<string> sorted(strings.begin(), strings.end());

    cout << sorted.size() << endl;
    for (string s : sorted)
    {
        cout << s << endl;
    }

    return 0;
}