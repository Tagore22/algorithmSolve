#include <iostream>
#include <set>
#include <string>

using namespace std;

// 풀이.
// 15658번의 조금 주먹구구식 문제 풀이다. 결과적으로 백트래킹을 이용해 모든 결과를 도출해보는 것인데
// 중복된 값을 처리하기 위해서 set<>을 사용하였다. 하지만 애시당초 주어진 N이 최대 11이기 때문에
// 오히려 set을 사용하는것이 더 느려지게 만든것 같다. 또한 불필요한 연산들이 너무 많다.
// 위층인지 어디서 공사하는데 귀아파 죽겠다. 개짜증남 -_-
// 그래도 어떻게 풀어야할지 몰라서 넘겼던 문제인데 스스로 풀어서 다행이다.

int board[11], oper[4];
int N, min_ans = 1000000001, max_ans = -1000000001;
set<string> check;

void CalMinMax(string cur)
{
    int ans = board[0];
    for (int i = 0; i < cur.size(); ++i)
    {
        if (cur[i] == '0')
            ans += board[i + 1];
        else if (cur[i] == '1')
            ans -= board[i + 1];
        else if (cur[i] == '2')
            ans *= board[i + 1];
        else
            ans /= board[i + 1];
    }
    min_ans = min(min_ans, ans);
    max_ans = max(max_ans, ans);
}

void BackTrack(string cur)
{
    if (cur.size() == N - 1)
    {
        if (check.find(cur) == check.end())
        {
            CalMinMax(cur);
            check.insert(cur);
            return;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        if (oper[i] > 0)
        {
            --oper[i];
            BackTrack(cur + to_string(i));
            ++oper[i];
        }
    }
}

void MakeAnswer()
{
    BackTrack(string(""));
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