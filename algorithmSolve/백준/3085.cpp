#include <iostream>

using namespace std;

//풀이
//그리디로 접근하기 애매해 완전탐색을 하였다. 말 그대로 주어진 입력값들을 string 배열에 2차원으로 저장하여
//가로측으로 한번, 세로측으로 한번씩 순회하며 한번에 먹을수 있는 사탕의 양을 갱신해 나간후, 최종값을 출력한다.

string board[50];
int answer = 1;
int N;

void CalMax()
{
    int check;
    for (int i = 0; i < N; ++i)
    {
        check = 1;
        for (int j = 0; j < N - 1; ++j)
        {
            if (board[i][j] == board[i][j + 1])
            {
                ++check;
            }
            else
            {
                answer = max(answer, check);
                check = 1;
            }
        }
        answer = max(answer, check);
    }

    for (int j = 0; j < N; ++j)
    {
        check = 1;
        for (int i = 0; i < N - 1; ++i)
        {
            if (board[i][j] == board[i + 1][j])
            {
                ++check;
            }
            else
            {
                answer = max(answer, check);
                check = 1;
            }
        }
        answer = max(answer, check);
    }
}

void MakeAnswer()
{
    CalMax();

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N - 1; ++j)
            if (board[i][j] != board[i][j + 1])
            {
                swap(board[i][j], board[i][j + 1]);
                CalMax();
                swap(board[i][j], board[i][j + 1]);
            }

    for (int j = 0; j < N; ++j)
        for (int i = 0; i < N - 1; ++i)
            if (board[i][j] != board[i + 1][j])
            {
                swap(board[i][j], board[i + 1][j]);
                CalMax();
                swap(board[i][j], board[i + 1][j]);
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