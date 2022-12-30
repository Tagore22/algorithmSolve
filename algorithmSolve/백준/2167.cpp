#include <iostream>

using namespace std;

//풀이
//주어진 배열값들을 저장한후 시작값부터 끝값까지의 수들을 모두 더하여 출력한다.
//더해진 값의 최대값이 2의 32제곱 - 1 보다 작다고 문제에 나와 있으므로 int로도 충분히 담을수 있다.

int board[300][300];
int N, M, K, from_y, from_x, to_y, to_x;

void MakeAnswer()
{
    int answer;
    for (int i = 0; i < K; ++i)
    {
        cin >> from_y >> from_x >> to_y >> to_x;
        answer = 0;

        for (int from = from_y - 1; from < to_y; ++from)
            for (int to = from_x - 1; to < to_x; ++to)
                answer += board[from][to];

        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
    cin >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}