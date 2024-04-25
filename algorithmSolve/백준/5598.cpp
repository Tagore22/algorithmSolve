#include <iostream>

using namespace std;

// 풀이.
// 카이사르 암호에서 다시 원래대로 되돌리려면 알파벳을 앞으로 3개씩 당기면 된다.
// 다만 이럴 경우 C부터 문제가 되는데 이 경우 A보다 작은 만큼 Z에서 다시 당기면 된다.
// 이때 뺄셈의 영향으로 3이 아닌 2를 더해주는 것도 주의해야 한다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string board, answer = "";
    cin >> board;
    for (int i = 0; i < board.size(); ++i)
    {
        if (board[i] - 3 >= 'A')
            answer += board[i] - 3;
        else
            answer += 'Z' - ('A' - board[i] + 2);
    }
    cout << answer << '\n';
    return 0;
}