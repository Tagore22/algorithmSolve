#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// 풀이.
// 만들수 있는 모든 조합을 오름차순으로 출력하는 문제이다.
// 전형적인 백트래킹 문제로써 모든 조합들을 순회하면 된다.
// 다만 bool 배열을 하나 두어서 중복으로 사용되는 것을 막아야 한다.
// 속도가 조금 느린감이 없지 않아 있어 여러가지 풀이로 풀어보고 찾아보았으나,
// 늘 그렇듯 시기에 따라 속도 차이가 있는 것 같았다. 그냥 신경쓰지말자.

// 자세한 설명은 주석으로 남긴다.

int board[8];
bool visit[8];
vector<int> ans;
int N, M;

// 모든 조합을 순회해보는 함수.
void BackTrack()
{
    // 벡터에 들어간 수의 개수가 M개라면 출력한다.
    if (ans.size() == M)
    {
        for (auto n : ans)
            cout << n << ' ';
        cout << '\n';
        return;
    }

    // 가장 작은 수부터 집어넣을수 있는지 확인한다.
    for (int i = 0; i < N; ++i)
    {
        // 이전에 쓰이지 않았던 수라면 사용한다.
        if (!visit[i])
        {
            ans.push_back(board[i]);
            visit[i] = true;
            BackTrack();
            ans.pop_back();
            visit[i] = false;
        }
    }
}

void MakeAnswer()
{
    // 가장 작은수부터 만드려면 가장 작은수부터 사용해야 하기에 오름차순으로 정렬한다.
    sort(board, board + N);
    memset(visit, false, sizeof(visit));
    BackTrack();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}