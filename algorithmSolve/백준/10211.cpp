#include <iostream>

using namespace std;

int T, len, num, sum, answer;

void Solve()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> len;
        sum = 0;
        answer = -1001;
        for (int i = 0; i < len; ++i)
        {
            cin >> num;
            sum += num;
            answer = max(answer, sum);
            sum = sum < 0 ? 0 : sum;
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    Solve();
    return 0;
}