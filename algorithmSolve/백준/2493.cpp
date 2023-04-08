#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

// 풀이.
// 스택을 사용하는 문제다. 뒤에서부터 높이와 원소 번호를 저장하여
// 스택에 저장된 높이보다 크다면 그 번호가 바로 수신받는 번호임을 이용하면 된다.

int board[500000], answer[500000];
int N;

void MakeAnswer()
{
    stack<pair<int, int>> sta; // 높이, 번호.
    for (int i = N - 1; i >= 0; --i)
    {
        while (!sta.empty() && board[i] > sta.top().first)
        {
            answer[sta.top().second] = i + 1;
            sta.pop();
        }
        sta.push(make_pair(board[i], i));
    }

    for (int i = 0; i < N; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(answer, 0, sizeof(answer));

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}