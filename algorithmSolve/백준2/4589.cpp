#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    cout << "Gnomes:" << '\n';
    for (int i = 0; i < N; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if ((a < b && b > c) || (a > b && b < c))
            cout << "Unordered" << '\n';
        else
            cout << "Ordered" << '\n';
    }
    return 0;
}