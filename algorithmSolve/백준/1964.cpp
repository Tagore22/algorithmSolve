#include <iostream>

using namespace std;

int main()
{
    int N, answer = 1;
    const int DIV = 45678;
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        answer += 2 * (i + 1) + i - 1;
        answer %= DIV;
    }
    cout << answer << '\n';
    return 0;
}