#include <iostream>

using namespace std;

int main()
{
    int board[6];
    int N, T, P, answer = 0;
    cin >> N;
    for (int i = 0; i < 6; ++i)
        cin >> board[i];
    cin >> T >> P;
    for (int i = 0; i < 6; ++i)
    {
        answer += board[i] / T;
        answer = board[i] % T != 0 ? answer + 1 : answer;
    }
    cout << answer << '\n';
    cout << N / P << ' ' << N % P << '\n';
    return 0;
}