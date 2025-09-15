#include <iostream>

using namespace std;

int main()
{
    int N, answer = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = i; i * j <= N; ++j)
            ++answer;
    cout << answer << '\n';
    return 0;
}