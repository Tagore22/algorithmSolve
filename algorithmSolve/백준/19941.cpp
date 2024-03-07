#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 첫 풀이이다. 다시 되돌아보면 한번에 순회할수 있는 곳도 2개의 for문으로 나누는듯
// 엄청 난잡하게 구현했다. 원리 자체는 직관적인데 단순히 사람의 위치에서 왼쪽 오른쪽으로
// 최대 K만큼의 범위를 왼쪽에서부터 차례대로 찾아보는 것이다.

string str;
bool board[20000];
int N, K;

void MakeAnswer()
{
    memset(board, false, sizeof(board));
    int answer = 0;

    for (int i = 0; i < N; ++i)
        if (str[i] == 'H')
            board[i] = true;

    for (int i = 0; i < N; ++i)
    {
        if (str[i] == 'H')
            continue;
        bool isFind = false;
        for (int j = K; j > 0; --j)
            if (i - j >= 0 && board[i - j])
            {
                board[i - j] = false;
                isFind = true;
                break;
            }
        if (isFind)
        {
            ++answer;
        }
        else
        {
            for (int j = 1; j <= K; ++j)
                if (i + j < N && board[i + j])
                {
                    board[i + j] = false;
                    isFind = true;
                    break;
                }
            if (isFind)
                ++answer;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}