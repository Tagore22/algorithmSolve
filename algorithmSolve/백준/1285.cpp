#include <iostream>

using namespace std;

//완전탐색으로 각 행과 각 열을 뒤집는다 안뒤집는다를 확인하려면 2의 40제곱이므로 10억을 훌쩍 뛰어넘어버린다.
//그래서 비트마스크로 어떠한 열들을 뒤집는다는 가정하에 각 행을 뒤집을때와 뒤집지 않았을때의 T의 개수를 확인하여
//그중 최소값을 반환한다.
//모든 열을 가정해야하기에 2의 20제곱이 필요하며 각 가정당 N의 제곱만큼 행을 순회하기에 시간복잡도는
//O(2^N * N^2)

string board[20];
int N;

//어떤 열들이 미리 뒤집힌다는 가정하에 모든 행을 순회하며 해당 행이 뒤집혔을때와 뒤집히지 않았을때의 T의 개수중 최소값을 반환한다.

int CalMinTail(int bit)
{
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        int tail_num = 0;
        for (int j = 0; j < N; ++j)
        {
            bool isTail = board[i][j] == 'T';
            if ((bit & (1 << j)) != 0)
                isTail ^= 1;
            if (isTail)
                ++tail_num;
        }
        ans += min(tail_num, N - tail_num);
    }
    return ans;
}

//bit는 0부터 N까지 모두 1인수까지 대입되어진다. 각 열을 뒤집느냐 안뒤집느냐의 가정

void MakeAnswer()
{
    int answer = 987654321;
    for (int i = 0; i < (1 << N); ++i) 
        answer = min(answer, CalMinTail(i));

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