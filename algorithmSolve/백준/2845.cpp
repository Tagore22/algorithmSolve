#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, p;
    cin >> l >> p;
    int compare = l * p;
    for (int i = 0; i < 5; ++i)
    {
        int x;
        cin >> x;
        cout << x - compare << ' ';
    }
    cout << '\n';
    return 0;
}