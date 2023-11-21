#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// �� �Ϻ��� �ֽ��� ������ �־����� 1. �� �� �ֽ��� ��ų� 2. ������ ���� �ֽ��� �Ȱų� 3. �ƹ��͵� ���Ҽ��� �ִ�.
// �̶� ������ �ִ� �ִ� ������ ���ϴ� ������. ��������� ������ ���� ���� ������ ���� ��ٰ� �ȸ� �Ǵ� ������.

// �ڼ��� ������ �ּ����� �����.

int board[1000000];
int T, N;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        // ������ ���� ������ �˱� ���� �켱���� ť.
        priority_queue<pair<int, int>> que;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            // ���ں��� �ֽ��� ������ �Է¹ް� �켱���� ť�� �̿��Ͽ� �����Ѵ�.
            cin >> board[i];
            que.push(make_pair(board[i], i));
        }

        int idx = 0;
        long long answer = 0;
        // �ε����� N���� �������� ��� �ݺ��Ѵ�.
        while (idx < N)
        {
            // ���� ���� ���� ���� num�� �� ���� here�� ���Ѵ�.
            int num = que.top().first;
            int here = que.top().second;
            que.pop();

            // ���� ���Ұ����� ũ�ų� ���ٸ� 
            if (idx <= here)
            {
                // here������ ������ �ִ� �̵���� ��� ���Ѵ�.
                for (int i = idx; i < here; ++i)
                    answer += num - board[i];

                // here�� �Ȱ��̱⿡ �ε����� here + 1�� �ȴ�.
                idx = here + 1;
            }
        }

        // ���� ������ �ִ� �ִ� ������ ����Ѵ�.
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}