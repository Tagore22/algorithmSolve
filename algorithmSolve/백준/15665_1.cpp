#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// 15665번의 다른 풀이.
// 기존의 내 풀이가 다른 사람들의 풀이보다 느려서 다시 풀어봤다.
// 재귀가 너무 많이 호출되는 건가 싶어서 이번에는 아예 입력받을때
// 중복을 없애버렸다. 결과는 같은 속도였다;;

vector<int> board;
int answer[7];
bool visit[10001];
int N, M;

void BackTrack(int idx)
{
    if (idx == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < board.size(); ++i)
    {
        answer[idx] = board[i];
        BackTrack(idx + 1);
    }
}

void MakeAnswer()
{
    sort(board.begin(), board.end());
    BackTrack(0);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(visit, false, sizeof(visit));

    cin >> N >> M;
    int cur;
    for (int i = 0; i < N; ++i)
    {
        cin >> cur;
        // 이미 저장된 수들을 체크하는 visit을 이용하여 똑같은 수를 여러번 저장하지 않는다.
        if (!visit[cur])
        {
            visit[cur] = true;
            board.push_back(cur);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}