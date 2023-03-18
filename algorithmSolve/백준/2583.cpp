#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 별로 어렵지도 않은 문제인데 출제자의 악의가 크게 보이는 문제이다.
// 주어진 직사각형을 배열에 1로 깔아놓고 0인 부분의 덩어리 수와 각 덩어리의 크기를 오름차순으로 정렬하여
// 출력하면 된다.

struct rect
{
    pair<int, int> from;
    pair<int, int> to;
};

vector<vector<int>> board;
vector<vector<bool>> check;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
rect rects[100];
int M, N, K, cur_sum;

void CoverRect()
{
    for (int i = 0; i < K; ++i)
    {
        for (int col = rects[i].from.first; col < rects[i].to.first; ++col)
            for (int row = rects[i].from.second; row < rects[i].to.second; ++row)
                board[col][row] = 1;
    }
}

void DFS(int y, int x)
{
    check[y][x] = true;
    ++cur_sum;
    int dy, dx;

    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[i][0];
        dx = x + rot[i][1];

        if (dy < 0 || dy >= M || dx < 0 || dx >= N || check[dy][dx] || board[dy][dx] == 1)
            continue;

        DFS(dy, dx);
    }
}

void MakeAnswer()
{
    CoverRect();

    vector<int> answer;

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j] == 0 && !check[i][j])
            {
                cur_sum = 0;
                DFS(i, j);
                answer.push_back(cur_sum);
            }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> K;
    board.resize(M, vector<int>(N, 0));
    check.resize(N, vector<bool>(N, false));
    for (int i = 0; i < K; ++i)
    {
        cin >> rects[i].from.second >> rects[i].from.first;
        cin >> rects[i].to.second >> rects[i].to.first;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}