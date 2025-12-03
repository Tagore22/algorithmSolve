#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int from = N - 1, to = N - 1;
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j <= to; ++j)
        {
            if (j == from || j == to)
                cout << '*';
            else
                cout << ' ';
        }
        ++to;
        --from;
        cout << '\n';
    }
    for (int i = 0; i < N * 2 - 1; ++i)
        cout << '*';
    cout << '\n';
    return 0;
}