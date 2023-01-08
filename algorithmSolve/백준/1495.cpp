#include <iostream>
#include <cstring>

using namespace std;

//풀이
//완전탐색 + 최대 2의50제곱 + 겹치는 부분이 존재함으로 DP지만 어느 부분을 DP로 담아야할지 한참을 고민했는데,
//볼륨값을 DP로 묶으면 된다. 볼륨값의 범위는 0 ~ 1000이고 최대 곡의 수는 50이므로 총 5만이기에 충분히 시간내에 연산이 가능하다.
//배열은 2차원 배열로 [현재 곡의 인덱스][볼륨값]으로 곡의 수를 순회하며 존재하는 볼륨값에서 각각 현재 조절가능한 볼륨값으로 덧셈, 뺄셈
//연산을 해본후 가능한 범위라면 그 true로 갱신해준다. 모든 곡을 순회하며 마지막 N번째 곡에서 최대 볼륨값을 출력하면 된다.

int board[50];
bool check[51][1001];
int N, S, M;

void MakeAnswer()
{
    check[0][S] = true;

    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= M; ++j)
            if (check[i - 1][j])
            {
                if (j + board[i - 1] <= M)
                    check[i][j + board[i - 1]] = true;
                if (j - board[i - 1] >= 0)
                    check[i][j - board[i - 1]] = true;
            }

    int answer = -1;
    for (int i = 0; i <= M; ++i)
        if (check[N][i])
            answer = i;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, false, sizeof(check));

    cin >> N >> S >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}