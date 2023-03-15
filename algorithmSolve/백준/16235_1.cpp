#include <iostream>
#include <queue>

using namespace std;

// 16235���� �� ���� Ǯ��.

// �ٸ� Ǯ�̸� ���� ���� �ڴ� ���� �Ǿ��ߴ� ���� ������ ���Ҵ�.

// 1. for�� ������ if���� �߰������ν� �� �������°�?
// 2. 3���� deque�� �����Ҷ� �����ڸ� �̿��Ͽ� ������ 1������ ��ȸ�ҽ� 1���� deque�� �����Ͽ� ��ȸ�ϸ� �� ������?

// ���� ���� �޾ �ٷδ�

// 1. �״��� ���̰� ����. �ֽô��ʿ� for������ ���ǹ��� ���ԵǾ��ֱ⿡ �� �������� ���ٰ� �����ߴµ� ���ó�����.
// 2. �ξ��� ������. ������ ���� �׼����� �����ϱ⿡ �״��� ���̰� ������ �˾����� �����غ��� ���� �׼��� ��ü�� 
// ������� ������ ��ƸԴµ� 3�����̱⿡ ����� ��ƸԾ����� ����. 1���� duque�� �����Ͽ� ����ϴ� ���ο� ���(?)�� �͵��Ͽ�
// ����� ����.

// �� ��.
// �� ������ ���ο� ������ �ڿ��� ��������, ������ �������� �ִµ� ���� �ڿ��� �־ ���� �������� ���ٶ� 52�ٿ� ���°�ó��
// deque.front�� ����ߴ�. �׷��� ������ ������ ������ ������ ��ȸ�� ������ ����� �־ back�� �ƴ� �����׼����� �����
// [idx]�� �����ϴ�. ���� �����غ������� ���̰� ������.

// ������ 4������ �����Ͱ� �̹�ó�� ��ģ���� ���̵� �״��� ������. �ֽô��� ��ȸ���� ��ȸó�� ���ϱⰡ �ƴ� ��ȸ�� ��ȸ ����
// �������� ���귮�� �þ�⿡ �׷��� �ʹ�. ���� ������ �����ڸ� ������� �ʰ� �������� �ð��ʰ��� ���µ� �ƹ����� ���� ���ÿ� ������ ����.
// �� ���� 400, ���� ���� 400 �� ��� ���ļ� �ϸ� ���������� 800���� ���귮�̴�. �� ���������� �þ�� ���귮�� �ð��ʰ��� ���ΰ���.

// ���� �߿��Ѱ� �����ڸ� �̿��� ������ �迭�� ���� ����� ������ ���� ��� ����ø��ٴ� ���̴�. ���� ����.

int board[10][10], provide[10][10];
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} }; //�º��� �ð�������� 8����.
deque<deque<deque<int>>> trees; // ���� ����, ����.
int N, M, K; // �迭�� ũ��, ������ ��, ��� ������.

void Spring_Summer()
{
    int deadline;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            deadline = -1;
            deque<int>& cur = trees[i][j];
            for (int iter = cur.size() - 1; iter >= 0; --iter)
            {
                if (board[i][j] < cur[iter])
                {
                    deadline = iter;
                    break;
                }
                else
                {
                    board[i][j] -= cur[iter];
                    ++cur[iter];
                }
            }

            for (int iter = 0; iter <= deadline; ++iter)
            {
                board[i][j] += cur.front() / 2;
                cur.pop_front();
            }
        }
}

void Autumn_Winter()
{
    int dy, dx;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            deque<int>& cur = trees[i][j];
            for (int iter = 0; iter < cur.size(); ++iter)
                if (cur[iter] % 5 == 0)
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

            board[i][j] += provide[i][j];
        }
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < K; ++i)
    {
        Spring_Summer();
        Autumn_Winter();
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
    trees.resize(N, deque<deque<int>>(N, deque<int>()));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> provide[i][j];
            board[i][j] = 5;
        }

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