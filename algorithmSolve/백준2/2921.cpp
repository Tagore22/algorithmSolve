#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int answer = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= i * 2; ++j)
            answer += j;
    cout << answer << '\n';
    return 0;
}