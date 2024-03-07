#include <iostream>

using namespace std;

// 풀이.
// char 배열을 사용함으로써 bool 배열을 대체할수 있었고 그에 따른 하나의 for문을 줄일수도 있었다.
// cin >> 으로 문자열을 입력받는 것은 거의 string이었기 때문에 char 배열을 cin >> 으로 한번에 입력받을수
// 있다는것은 사실 처음 알았다. 인생은 배움의 연속이리라.

char board[20002];
int N, K;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        if (board[i] != 'P')
            continue;
        for (int j = i - K; j <= i + K; ++j)
        {
            if (j < 0 || j >= N || board[j] != 'H')
                continue;
            ++answer;
            board[j] = 'F';
            break;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> board;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}