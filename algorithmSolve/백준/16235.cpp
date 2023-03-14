#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// �߿��ϴٰ� �����Ѱ� ������ ó������. �� ��ǥ�� ������ ������ �����Ҽ� �ֱ⿡ ������ ��쿡�� deque�� 3�������� ����� ó���Ͽ�����,
// �׷��� �׷��� �ϳ� ���ȴ�. �������� ���� �־��� 4������ �ൿ�� �����ϸ� �Ǿ���.

int board[10][10], provide[10][10], deadline[10][10];
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} }; //�º��� �ð�������� 8����.
deque<deque<deque<int>>> trees; // ���� ����, ����.
int N, M, K; // �迭�� ũ��, ������ ��, ��� ������.

void DeadLineClear()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            deadline[i][j] = -1;
}

void FuncSpring()
{
    DeadLineClear();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int iter = trees[i][j].size() - 1; iter >= 0; --iter)
            {
                if (board[i][j] < trees[i][j][iter])
                {
                    deadline[i][j] = iter;
                    break;
                }
                else
                {
                    board[i][j] -= trees[i][j][iter];
                    ++trees[i][j][iter];
                }
            }
}

void FuncSummer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (deadline[i][j] != -1)
                for (int iter = 0; iter <= deadline[i][j]; ++iter)
                {
                    board[i][j] += trees[i][j].front() / 2;
                    trees[i][j].pop_front();
                }
}

void FuncAutumn()
{
    int dy, dx;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int iter = 0; iter < trees[i][j].size(); ++iter)
                if (trees[i][j][iter] % 5 == 0)
                {
                    for (int r = 0; r < 8; ++r)
                    {
                        dy = i + rot[r][0];
                        dx = j + rot[r][1];

                        if (dy < 0 || dy >= N || dx < 0 || dx >= N)
                            continue;

                        trees[dy][dx].push_back(1);
                    }
                }
}

void FuncWinter()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] += provide[i][j];
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < K; ++i)
    {
        FuncSpring();
        FuncSummer();
        FuncAutumn();
        FuncWinter();
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            answer += trees[i][j].size();

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = 5;

    trees.resize(N, deque<deque<int>>(N, deque<int>()));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> provide[i][j];

    int y, x, age;
    for (int i = 0; i < M; ++i)
    {
        cin >> y >> x >> age;
        trees[y - 1][x - 1].push_back(age);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}