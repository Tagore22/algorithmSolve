#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        int V, E;
        cin >> V >> E;
        cout << 2 + E - V << '\n';
    }
    return 0;
}