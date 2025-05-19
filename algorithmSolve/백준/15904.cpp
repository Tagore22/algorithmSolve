#include <iostream>
#include <string>

using namespace std;

const int MAX = 4;
char board[MAX] = { 'U', 'C', 'P', 'C' };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    getline(cin, str);
    int piv = 0;
    for (int i = 0; i < str.size(); ++i)
        if (str[i] == board[piv])
            ++piv;
    cout << (piv == MAX ? "I love UCPC" : "I hate UCPC") << '\n';
    return 0;
}