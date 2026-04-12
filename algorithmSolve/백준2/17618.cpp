#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    ios::sync_with_stdio(false);
    cin.tie(0);

    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        int sum = 0, cur = i;
        while (cur > 0)
        {
            sum += cur % 10;
            cur /= 10;
        }
        answer = i % sum == 0 ? answer + 1 : answer;
    }
    cout << answer << '\n';
    return 0;
}