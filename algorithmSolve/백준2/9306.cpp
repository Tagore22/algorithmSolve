#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int iter = 1; iter <= T; ++iter)
    {
        string second, first;
        cin >> second >> first;
        cout << "Case " << iter << ": " << first << ", " << second << '\n';
    }
    return 0;
}