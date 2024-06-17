#include <iostream>

using namespace std;

// 15658번의 더 나은 풀이.
// 상술하였듯 set은 애시당초 필요없었고 백트래킹을 재귀호출할때마다 기존에는
// string을 사용하여 나중에 값을 계산하였는데 굳이 그럴 필요없이 매번 재귀호출할때마다
// 매개변수 자체를 계산값으로 넣으면 된다.

int board[11], oper[4];
int N, min_ans = 1000000001, max_ans = -1000000001;

void BackTrack(int num, int cur)
{
    if (num == N - 1)
    {
        max_ans = max(max_ans, cur);
        min_ans = min(min_ans, cur);
        return;
    }

    if (oper[0] > 0)
    {
        --oper[0];
        BackTrack(num + 1, cur + board[num + 1]);
        ++oper[0];
    }
    if (oper[1] > 0)
    {
        --oper[1];
        BackTrack(num + 1, cur - board[num + 1]);
        ++oper[1];
    }
    if (oper[2] > 0)
    {
        --oper[2];
        BackTrack(num + 1, cur * board[num + 1]);
        ++oper[2];
    }
    if (oper[3] > 0)
    {
        --oper[3];
        BackTrack(num + 1, cur / board[num + 1]);
        ++oper[3];
    }
}

void MakeAnswer()
{
    BackTrack(0, board[0]);
    cout << max_ans << '\n';
    cout << min_ans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    for (int i = 0; i < 4; ++i)
        cin >> oper[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}