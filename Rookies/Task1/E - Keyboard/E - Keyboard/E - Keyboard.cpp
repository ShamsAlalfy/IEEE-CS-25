#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char dir;
    cin >> dir;
    string message;
    cin >> message;
    string original = "";
    for (char c : message)
    {
        int position = keyboard.find(c);
        if (dir == 'R')
            original += keyboard[position - 1];
        else if (dir == 'L')
            original += keyboard[position + 1];
    }
    cout << original << endl;
    return 0;
}
