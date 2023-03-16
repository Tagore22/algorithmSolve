#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ���� ��ü�� �����س��°� ����� �ʾҴ�. �ٸ� �̻��Ѱ����� ��̴µ� 
// �α� �̵��� �Ϸ絿�� ����ȴٴ� �� �����ߴ�. �������� (1, 1)�� (1, 2)�� ���̰� R���� Ŀ�� �α� �̵��� ��������,
// (1, 1)�� (2, 1)���� �α� �̵����� Ŀ���ٰ� ġ��. �׷� (1, 2)���� �α� �̵��� ���������°�?
// ������ �׷��� �ʴ�. (1, 1)�� (1, 2)���� �α� �̵��� �����Ѱ� ����̴�. �ٸ� �� ������ �ٸ���.
// (1, 1)�� (1, 2)�� �α� �̵��� �� ���� �̹� �Ϸ簡 ������ ������ �׳� ���Ͽ� (1, 2)���� �α� �̵��� �Ұ����ϰ�
// �׷��⿡ ��ȸ�� ���� (1, 2) ���ʿ��� (1, 1)���� DFS�� �Ұ����ϴ�. �ٸ� ���� check�� ���� �̹� �湮��
// ��ǥ���� ���� ���̰� L���� R�̶� ������ DFS�� �Ұ����ϴ�. �̷� ������ �� �����ϰ� �־���. �Ф�

int board[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
vector<vector<bool>> check;
int N, L, R, sum;
vector<pair<int, int>> country;

void DFS(int y, int x)
{
    check[y][x] = true;
    sum += board[y][x];
    country.push_back(make_pair(y, x));
    int dy, dx;

    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[i][0];
        dx = x + rot[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N || check[dy][dx] ||
            abs(board[y][x] - board[dy][dx]) < L || abs(board[y][x] - board[dy][dx]) > R)
            continue;

        DFS(dy, dx);
    }
}

void MakeAnswer()
{
    int answer = 0, csize, new_people;
    bool ismove;
    while (true)
    {
        ismove = false;
        check.assign(N, vector<bool>(N, false));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (!check[i][j])
                {
                    sum = 0;
                    country.clear();
                    DFS(i, j);

                    csize = country.size();
                    if (csize >= 2)
                    {
                        ismove = true;
                        new_people = sum / csize;
                        for (int i = 0; i < csize; ++i)
                            board[country[i].first][country[i].second] = new_people;
                    }
                }
        if (ismove)
            ++answer;
        else
            break;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R;
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