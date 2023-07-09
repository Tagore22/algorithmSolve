#include <iostream>

using namespace std;

// 풀이.
// string 배열이 주어졌을때 열을 먼저 순회하는 것이 아닌
// 행을 먼저 순회하여 각 행별 문자가 같은지 확인하는 문제.

// 자세한 설명은 주석으로 남긴다.

int N;
string board[50];

void MakeAnswer()
{
    string answer;
    bool isfind;
    int Ssize = board[0].size();

    // 각 열별로 순회한다.
    for (int i = 0; i < Ssize; ++i)
    {
        isfind = true;
        char cur = board[0][i];
        // 각 행별로 순회하여 모든 글자가 같다면 그 글자를 최종답에 추가하고 그렇지 않다면
        // '?'을 추가한다.
        for (int j = 0; j < N; ++j)
        {
            if (board[j][i] != cur)
            {
                isfind = false;
                break;
            }
        }
        if (isfind)
        {
            answer += cur;
        }
        else
        {
            answer += '?';
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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