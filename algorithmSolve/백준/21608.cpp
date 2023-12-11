#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// �� �л����� ��ġ�� �������� ������ ����ϴ� ������.
// ��ġ�� ������ ���� ���ǿ� ���� ����ȴ�.

// 1. �����ϴ� ģ������ ���� ������ ��ġ.
// 2. 1���� 2�� �̻��� ��� ���� ��ĭ�� ���� ������ ��ġ.
// 3. 2���� 2�� �̻��� ��� ���� �� ���� ��ġ��, ���� ��� ���ٸ� ���� �� ���� ��ġ.

// �� �� �������� ���ؾ� �ϴµ� �������� ������ 4ĭ���� �����ϴ� ģ������ ���� ����
// 0, 1, 10, 100, 1000���� ���Ҽ� �ִ�.

// �Ｚ ������� �����ϰ� �����Ѱ� ����.
// �ڼ��� ������ �ּ����� �����.

int fri[401][4], board[20][20];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // ����, ����, ������, �Ʒ���.
int stu[400];
int point[5] = { 0, 1, 10, 100, 1000 };
vector<pair<int, int>> points;
int N;

// 1�� ������ ã�� �Լ�.
void FindOne(int num)
{
    int max_stu = -1;
    points.clear();
    // ��� ĭ�� ��ȸ�Ѵ�.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            // �̹� ĭ�� ��ĭ�̶��
            if (board[i][j] == -1)
            {
                int cur = 0;
                // ������ 4ĭ�� ��� ��ȸ�Ѵ�.
                for (int iter = 0; iter < 4; ++iter)
                {
                    int y = i + rot[iter][0];
                    int x = j + rot[iter][1];

                    // ������ ĭ�� ����ְų� �迭�� ����ٸ� �����Ѵ�.
                    if (board[y][x] == -1 || y < 0 || y >= N || x < 0 || x >= N)
                        continue;

                    // ������ ĭ�� �����ϴ� ģ������ üũ�Ѵ�.
                    for (int k = 0; k < 4; ++k)
                    {
                        if (board[y][x] == fri[num][k])
                        {
                            ++cur;
                            break;
                        }
                    }
                }
                // �����ϴ� ģ���� ���� ������̶�� ������� �����ߴ� ��ġ���� ��� �����
                // �ٽ� �����ϰ� �ִ���� �����Ѵ�.
                if (cur > max_stu)
                {
                    max_stu = cur;
                    points.clear();
                    points.push_back(make_pair(i, j));
                }
                // �����ϴ� ģ���� ���� �ִ���� �����ϴٸ�
                // �����Ѵ�.
                else if (cur == max_stu)
                {
                    points.push_back(make_pair(i, j));
                }
            }
}

// 2�� �� 3�� ������ ã�� �Լ�.
void FindTwoAndThree(int num)
{
    // 1�� ���ǿ��� �ƹ��͵� ã�� ���ߴٸ� ��ĭ�� �ٽ� ���� ��ȸ�Ѵ�.
    if (points.empty())
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (board[i][j] == -1)
                    points.push_back(make_pair(i, j));
    }

    int max_stu = -1, idx = points.size();
    vector<pair<int, int>> answer;
    // ���� ������ ��ġ���� ��� ��ȸ�Ѵ�.
    for (int iter = 0; iter < idx; ++iter)
    {
        int cur = 0;
        // ������ 4ĭ�� ��� ��ȸ�Ѵ�.
        for (int i = 0; i < 4; ++i)
        {
            int y = points[iter].first + rot[i][0];
            int x = points[iter].second + rot[i][1];

            // ������ ��ġ�� �迭�� ����ٸ� �����Ѵ�.
            if (y < 0 || y >= N || x < 0 || x >= N)
                continue;

            // ������ ĭ�� ����ִٸ� �� ���� �����Ѵ�.
            if (board[y][x] == -1)
                ++cur;
        }
        // �����ϴ� ��ĭ�� ���� ������̶�� ������� �����ߴ� ��ġ���� ��� �����
        // �ٽ� �����ϰ� �ִ���� �����Ѵ�.
        if (cur > max_stu)
        {
            answer.clear();
            max_stu = cur;
            answer.push_back(points[iter]);
        }
        // �����ϴ� ��ĭ�� ���� �ִ���� �����ϴٸ�
        // �����Ѵ�.
        else if (cur == max_stu)
        {
            answer.push_back(points[iter]);
        }
    }
    // ������ �ʿ��� ���� �� ��ȣ�� ���� ���� ���� �� ��ȣ�� ���� ���� ĭ�̱� ������
    // �����Ͽ� �� ���� ��ġ�� ã�´�.
    sort(answer.begin(), answer.end());
    // num���� ��ġ�� �����Ѵ�.
    board[answer[0].first][answer[0].second] = num;
}

void MatchStu(int num)
{
    // 1�� ���� Ž��.
    FindOne(num);
    // 1�� ���� Ž���� ã�� ��ġ�� 1����� ������ �װ����� ��ġ��Ų��.
    if (points.size() == 1)
    {
        board[points[0].first][points[0].second] = num;
        return;
    }
    // 2�� �� 3�� ���� Ž��.
    FindTwoAndThree(num);
}

// �������� �� ���� ���ϴ� �Լ�.
void CalPoint()
{
    int answer = 0;
    // ��� ĭ�� ��ȸ�Ѵ�.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            int num = 0;
            // ������ 4ĭ�� ��ȸ�Ѵ�.
            for (int iter = 0; iter < 4; ++iter)
            {
                int y = i + rot[iter][0];
                int x = j + rot[iter][1];

                // ������ ĭ�� �迭�� ������ ����ٸ� �����Ѵ�.
                if (y < 0 || y >= N || x < 0 || x >= N)
                    continue;

                // ������ ��ġ���� �����ϴ� ģ���� ���� ���Ѵ�.
                for (int k = 0; k < 4; ++k)
                {
                    if (fri[board[i][j]][k] == board[y][x])
                        ++num;
                }
            }
            // ������ ���Ѵ�.
            answer += point[num];
        }
    cout << answer << '\n';
}

void MakeAnswer()
{
    memset(board, -1, sizeof(board));
    for (int iter = 0; iter < N * N; ++iter)
        MatchStu(stu[iter]);

    CalPoint();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N * N; ++i)
    {
        cin >> stu[i];
        for (int j = 0; j < 4; ++j)
            cin >> fri[stu[i]][j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}