#include <iostream>
#include <cstring>

using namespace std;

// 20922번을 queue가 아닌 말그대로 투포인터를 이용하여 푼 풀이.
// 이전과 큰 틀은 같으나 que가 아닌 from과 to가 사용되었다.

// 자세한 설명은 주석으로 남긴다.

int board[200000];
int visit[100001];
int N, K, from;

// from을 한칸씩 옮기면서 지나온 수가 erase일 경우 탈출한다.
void RenewQueue(int erase)
{
    while (true)
    {
        int here = board[from];
        --visit[here];
        ++from;
        if (here == erase)
            break;
    }
}

void MakeAnswer()
{
    memset(visit, 0, sizeof(visit));
    int answer = 0;
    from = 0;

    for (int to = 0; to < N; ++to)
    {
        // 0 ~ N - 1까지 순회하며 현재수 here가 K보다 더 많이 등장하였다면
        // to - from(현재수는 제외)를 최종값 answer와 비교하여 answer를 갱신후
        // from의 위치를 최초 here의 바로 다음으로 옮긴다.
        int here = board[to];
        ++visit[here];
        if (visit[here] > K)
        {
            answer = max(answer, to - from);
            RenewQueue(here);
        }
    }
    answer = max(answer, N - 1 - from + 1);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}