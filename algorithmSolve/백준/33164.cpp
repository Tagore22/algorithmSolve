#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int board1[100], board2[100];
    for (int i = 0; i < N; ++i)
        cin >> board1[i];
    for (int i = 0; i < M; ++i)
        cin >> board2[i];

    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int a = board1[i], b = board2[j];
            answer += (a + b) * max(a, b);
        }
    }
    cout << answer << '\n';
    return 0;
}