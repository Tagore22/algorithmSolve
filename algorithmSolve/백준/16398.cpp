#include <iostream>

using namespace std;

// 풀이.
// 요즘 우연찮게 MST 문제가 연달아 나와서 엄청 쉽게 풀었다. 따로 적용해야할 것도 없이
// 그냥 MST를 안다면 그대로 대입하기만 해도 된 문제였다. 내가 배운 종만북의 코드가 좋았는지
// 코드도 적고 매우 빠르게 돌아가서 백준 7등에 위치했다. 1368번이 1등을 차지한것에 뒤이어
// 기분이 좋았다.

// 자세한 설명은 주석으로 남긴다.

int board[1000][1000];
int N;

// MST를 구하는 프림 알고리즘 함수. 딱히 다를것 없이
// 기본적인 구현으로 되어있다.
void Prim()
{
    int dist[1000];
    for (int i = 0; i < N; ++i)
        dist[i] = 987654321;
    dist[0] = 0;
    bool visit[1000] = { false, };
    long long answer = 0;

    for (int iter = 0; iter < N; ++iter)
    {
        int u = -1;
        for (int i = 0; i < N; ++i)
            if (!visit[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visit[u] = true;
        answer += dist[u];

        for (int i = 0; i < N; ++i)
            if (!visit[i] && board[u][i] < dist[i])
                dist[i] = board[u][i];
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    Prim();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}