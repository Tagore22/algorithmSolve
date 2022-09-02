#include <iostream>

using namespace std;

int board[1000];
int from, to;

//기존 풀이법은 from이 1일때, 즉 수열의 맨처음을 가르킬때 인덱스값이 -1로 배열에서 벗어난다.
//그냥 배열로 풀때는 운좋게 맞았으나, 인덱스 값이 벗어나는걸 확인하는 벡터로 풀면 컴파일조차 되지 않는다.
//주의할것.

void MakeBoard()
{
    int idx = 1;
    int count = 0;
    int num = 0;
    for (int i = 0; i < to; ++i)
    {
        if (count == idx)
        {
            ++idx;
            count = 0;
        }
        num += idx;
        ++count;
        board[i] = num;
    }
}

void MakeAnswer()
{
    MakeBoard();
    if (from > 1)
        cout << board[to - 1] - board[from - 2] << '\n';
    else
        cout << board[to - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}