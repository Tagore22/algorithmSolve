#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        int c, v;
        cin >> c >> v;
        cout << "You get " << c / v << " piece(s) and your dad gets " << c % v << " piece(s)." << '\n';
    }
    return 0;
}