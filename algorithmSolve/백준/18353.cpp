#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 가장 긴 수열을 만드는 LCS 문제이다. 다만 정렬이 자주 쓰던 오름차순이 아닌 내림차순이다.
// 따라서 lower_bound의 위치를 잘 생각해야했다.

vector<int> lcs;
int board[2000];
int N;

void MakeAnswer()
{
    lcs.push_back(board[0]);
    int answer = 0;
    for (int i = 1; i < N; ++i)
    {
        if (lcs.back() > board[i])
        {
            lcs.push_back(board[i]);
        }
        else
        {
            ++answer;
            int idx = lower_bound(lcs.begin(), lcs.end(), board[i], greater<int>()) - lcs.begin();
            lcs[idx] = board[i];
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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