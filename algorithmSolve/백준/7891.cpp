#include <iostream>

using namespace std;

int main()
{
    int T, a, b;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> a >> b;
        cout << a + b << '\n';
    }
    return 0;
}