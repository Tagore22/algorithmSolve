#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 그지같은 문제답게 정답율도 30퍼였다. 따로 알고리즘을 사용하는 것이 아닌 약간 브루트포스 같은 문제인데
// 그냥 문제에서 요구하는것들을 구현하면 된다. 다만 처음에는 증가값의 반영을 N번하는 식으로 풀었는데
// 당연히 시간초과가 났다. 700, 700의 배열을 10000번 순회하기 때문이다. 따라서 초기증가값만 더한후 나중에
// 반영하는 것들 떠올리고 공책에 계산해봤는데 잘먹혔다. 따라서 바로 구현으로 옮겼다. 좌표값을 이용한 순회가
// 많아서 그런가 엄청느리다.

// 자세한 설명은 주석으로 남긴다.

int answer[700][700], p[700][700];
int M, N;

void MakeAnswer()
{
    int z, o, t;
    // 최초 증가값들을 N번 반영하여 미리 계산해놓는다.
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> z >> o >> t;
        int y = M - 1;
        int x = 0;
        for (int i = 0; i < z; ++i)
        {
            p[y][x] += 0;
            if (y == 0)
                ++x;
            else
                --y;
        }
        for (int i = 0; i < o; ++i)
        {
            p[y][x] += 1;
            if (y == 0)
                ++x;
            else
                --y;
        }
        for (int i = 0; i < t; ++i)
        {
            p[y][x] += 2;
            if (y == 0)
                ++x;
            else
                --y;
        }
    }
    // 1, 1부터 각칸의 왼쪽, 좌상단, 위쪽의 증가값중 가장 큰값을 찾는다.
    // 1, 1부터 순회해야 하는 이유는 순회시작시 오직 이곳만이 왼쪽, 좌상단, 위쪽의 증가값이
    // 모두 반영되어 있어 제대로된 값을 구할수 있기 때문이다. 이 이후 열이 아닌 행을 따라 구해야하는것도
    // 같은 이유이다.
    for (int j = 1; j < M; ++j)
        for (int i = 1; i < M; ++i)
            p[i][j] = max({ p[i][j - 1], p[i - 1][j - 1], p[i - 1][j] });
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j)
            answer[i][j] += p[i][j];

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << answer[i][j] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j)
            answer[i][j] = 1;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}