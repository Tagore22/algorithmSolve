#include <iostream>

using namespace std;

int main()
{
    int N, a, b;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        cout << (a >= b ? "MMM BRAINS" : "NO BRAINS") << '\n';
    }
    return 0;
}