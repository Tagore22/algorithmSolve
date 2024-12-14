#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int a, b, x;
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b >> x;
        cout << a * (x - 1) + b << '\n';
    }
    return 0;
}