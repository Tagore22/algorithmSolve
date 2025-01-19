#include <iostream>

using namespace std;

int main()
{
    int n, a, b, answer = 0;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)
    {
        if ((i % a == 0 && i % b != 0) || (i % a != 0 && i % b == 0))
            ++answer;
    }
    cout << answer << '\n';
    return 0;
}