#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int first = N % 2 == 0 ? N / 2 : (N / 2) + 1;
        for (int j = 0; j < first; ++j)
            cout << "* ";
        cout << '\n' << ' ';
        for (int k = 0; k < N / 2; ++k)
            cout << "* ";
        cout << '\n';
    }
    return 0;
}