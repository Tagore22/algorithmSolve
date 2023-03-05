#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이
// LIS문제이다. 주어진 수열을 순회하면서 다음과 같은 조건식을 겪는다.

// 1. 최종답 배열 answer가 비어있거나 answer중 가장 큰값(back()값)보다 현재 board[i]값이 크다면 answer의 뒤에 board[i]를 넣는다.
// 2. 그렇지 않다면 board[i]의 위치를 파악하여 기존 answer[]값을 대체한다.

// N번의 순회가 끝났을때 answer안에 들어있는 값의 수가 LIS의 수와 같다.

vector<int> board, answer;
int N;

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
    {
        if (answer.empty() || answer.back() < board[i])
        {
            answer.push_back(board[i]);
        }
        else
        {
            int dis = lower_bound(answer.begin(), answer.end(), board[i]) - answer.begin();
            answer[dis] = board[i];
        }
    }

    cout << answer.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}