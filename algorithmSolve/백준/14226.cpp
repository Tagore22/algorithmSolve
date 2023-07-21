#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��.
// ó���� DFS�� dp�� Ǯ���� ���� ����ϴٰ� �˰��� �ּҰ��� ���ϴ� BFSǮ�̶�°� �˾Ҵ�.
// ���̰� ������. ���� �ּҰ��� BFS�� �����̾��µ�;
// Ǯ����ü�� �����Ѵ�. ������ ����.

// 1. ���簪(ȭ�鰪, Ŭ�����尪)�� �־������� �����ϼ� �ִ� 3���� �ൿ�� �� ���ǿ� �´� ��� �ൿ�� ���Ͽ�
// �湮 ���θ� üũ�� ť�� ����ִ´�.
// 2. ���� �ݺ��ϴٰ� ȭ�鰪�� S�϶� �� ���� ����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int S;

// ����� 1���� �����ϴ� �Լ�.
int BFS()
{
    queue<pair<int, int>> que;
    que.push(make_pair(1, 0));
    bool visit[1001][1001];
    memset(visit, false, sizeof(visit));
    visit[1][0] = true;
    int answer = -1;

    while (!que.empty())
    {
        // ť�� ���� 3���� �־ �ð��� ���� üũ�ϴ� Ǯ�̵� ���������� �����ϰ� ���� �׷� �ʿ䰡 ����.
        // ������ �ϳ��� ��ǥ�������� �� �ϳ��� ����ŭ�� �����ϱ⿡ �̷��� �Ź� ���� �÷����� �����ص� �װ� �װŴ�.
        ++answer;
        int Qsize = que.size();
        for (int iter = 0; iter < Qsize; ++iter)
        {
            int M = que.front().first;
            int C = que.front().second;
            que.pop();

            if (M == S)
                return answer;

            // ȭ���� �̸�Ƽ���� Ŭ�����忡 �����ϴ� ���.
            if (!visit[M][M])
            {
                visit[M][M] = true;
                que.push(make_pair(M, M));
            }

            // Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ� �ϴ� ���.
            // Ŭ�����尡 ����ٸ� �Ұ����ϸ�, �ٿ��־����� S���� ���� �Ѿ�ٸ� ���� �����ʿ䰡 ����.  
            if (C != 0 && M + C <= S && !visit[M + C][C])
            {
                visit[M + C][C] = true;
                que.push(make_pair(M + C, C));
            }

            // ȭ���� �̸�Ƽ���� �ϳ� �����ϴ� ���.
            // ȭ���� �̸�Ƽ���� �ƿ� ���ٸ� �Ұ����ϴ�.
            if (M > 0 && !visit[M - 1][C])
            {
                visit[M - 1][C] = true;
                que.push(make_pair(M - 1, C));
            }
        }
    }
}

void MakeAnswer()
{
    int answer = BFS();

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}