#include <iostream>

using namespace std;

// 풀이.
// 왼쪽과 오른쪽, 즉 배열의 앞과 뒤에서 보이는 트로피의 수를 각각 출력하면 된다.

int main()
{
    int N;
    int board[50];

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    int answer = 1, maxnum = board[0];
    for (int i = 1; i < N; ++i)
    {
        if (board[i] > maxnum)
        {
            ++answer;
            maxnum = board[i];
        }
    }
    cout << answer << '\n';
    answer = 1, maxnum = board[N - 1];
    for (int i = N - 2; i >= 0; --i)
    {
        if (board[i] > maxnum)
        {
            ++answer;
            maxnum = board[i];
        }
    }
    cout << answer << '\n';
    return 0;
}