#include <iostream>

using namespace std;

int main()
{
    int N, idx = 0;
    cin >> N;
    for (int i = 2 * N - 1; i >= 0; i -= 2)
    {
        for (int j = 0; j < idx; ++j)
            cout << ' ';
        ++idx;
        for (int j = 0; j < i; ++j)
            cout << '*';
        cout << '\n';
    }
    idx -= 2;
    for (int i = 3; i <= 2 * N - 1; i += 2)
    {
        for (int j = 0; j < idx; ++j)
            cout << ' ';
        --idx;
        for (int j = 0; j < i; ++j)
            cout << '*';
        cout << '\n';
    }
    return 0;
}