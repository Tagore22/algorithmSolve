#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = N; i > 0; --i)
    {
        for (int j = N - i; j > 0; --j)
            cout << ' ';
        for (int j = i * 2 - 1; j > 0; --j)
            cout << '*';
        cout << '\n';
    }
    return 0;
}