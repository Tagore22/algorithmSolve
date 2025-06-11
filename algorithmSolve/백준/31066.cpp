#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N, M, K;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N >> M >> K;
        int people = N, answer = 0;
        while (true)
        {
            // 창의에서 융합으로
            ++answer;
            people -= M * K;
            if (people <= 0)
            {
                cout << answer << '\n';
                break;
            }
            // 융합에서 창의로
            ++answer;
            ++people;
            if (people >= N)
            {
                cout << -1 << '\n';
                break;
            }
        }
    }
    return 0;
}