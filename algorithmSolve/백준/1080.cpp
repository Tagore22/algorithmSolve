#include <iostream>

using namespace std;

//풀이
//기존값 board와 바뀌는값 check를 비교해가며 순회를 하되, 그 비교는 현재보다 1칸 좌상단값 [i-1][j-1]을 비교하여 다를 경우
//뒤집는다. 좌상단을 제외한 나머지 값들은 이후에 바뀔 가능성이 있기에 지금 바꾸어봤자 소용이없기 때문이다.
//그 후, 다시 board와 check를 비교하여 변화를 거친 지금도 다른 부분이 있다면 -1을 출력한다.

int board[50][50], check[50][50];
int N, M;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 1; i < N - 1; ++i)
        for (int j = 1; j < M - 1; ++j)
            if (board[i - 1][j - 1] != check[i - 1][j - 1])
            {
                for (int a = i - 1; a <= i + 1; ++a)
                    for (int b = j - 1; b <= j + 1; ++b)
                        board[a][b] ^= 1;
                ++answer;
            }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != check[i][j])
            {
                cout << -1 << '\n';
                return;
            }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j] - '0';
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            check[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}