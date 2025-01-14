#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 허무할정도로 간단한 문제였다. N개중 몇개를 고르는 문제인데 몇개인지 알수 없었고, N이 최대 15밖에 안되기에
// 냅색 알고리즘을 사용하기로 했다. 각 식재료를 고르느냐 고르지 않느냐 2개의 선택지로 나누어 구현후
// 맨 마지막까지 골랐을때 최소 영양분을 얻었는지, 금액이 더 적은지, 고른 식재료의 번호가 사전순으로 더 앞서는지
// 확인하여 매번 값을 갱신하면 된다. 너무 쉽게 떠올라서 약간 불안했지만 정답이었다. 자신감을 가지자.

// 자세한 설명은 주석으로 남긴다.

vector<int> answer;
int board[16][5];
const int MAXNUM = 10000;
int N, mp, mf, ms, mv, sum = MAXNUM;

// 냅색 알고리즘 함수.
void Nap(int a, int b, int c, int d, int s, vector<int> cur, int idx)
{
    // 가지치기. 현재 가격이 이미 최소값보다 크다면 무시한다.
    if (s > sum)
        return;
    // 마지막까지 방문했을때 현재값이 최소값인지 확인한다.
    if (idx > N)
    {
        // 최소 영양분을 확보했는가, 고른 식재료들이 사전순으로 앞서는가 확인하고 값을 갱신한다.
        // 가격은 이미 매번 가지치기로 확인하므로 신경쓰지 않아도 된다.
        if ((a >= mp && b >= mf && c >= ms && d >= mv) && (answer.empty() || cur < answer))
        {
            answer = cur;
            sum = s;
        }
        return;
    }
    // 현재 식재료를 고르지 않았을 경우.
    Nap(a, b, c, d, s, cur, idx + 1);
    // 현재 식재료를 골랐을 경우.
    cur.push_back(idx);
    Nap(a + board[idx][0], b + board[idx][1], c + board[idx][2], d + board[idx][3], s + board[idx][4], cur, idx + 1);
}

void MakeAnswer()
{
    Nap(0, 0, 0, 0, 0, vector<int>(), 1);
    // 이 부분을 깜빡해서 한번 틀렸다.
    // 마지막까지 답을 고를수 없었을 경우 -1을 출력한다.
    if (sum == MAXNUM)
    {
        cout << -1 << '\n';
        return;
    }
    cout << sum << '\n';
    for (auto& num : answer)
        cout << num << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> mp >> mf >> ms >> mv;
    for (int i = 1; i <= N; ++i)
        cin >> board[i][0] >> board[i][1] >> board[i][2] >> board[i][3] >> board[i][4];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}