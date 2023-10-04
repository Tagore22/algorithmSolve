#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �־����� ������ �ߺ��ɽ� �������� �ʰ� �ߺ����� ������ �������� ��������
// �� �÷��̾��� ���� ������ ����ϴ� ������.
// N�� 2�� �ݺ��Ǳ⿡ �� ���������� �־����� ����� �� �÷��̾��� ��� ������ �־����� ����̱⿡
// �̷��� �Ҽ��ۿ� ������.

// �ڼ��� ������ �ּ����� �����.

int board[200][3], visit[101], answer[200];
int N;

void MakeAnswer()
{
    // ��� ������ ��ȸ�Ѵ�.
    for (int j = 0; j < 3; ++j)
    {
        // �� ���� ����Ƚ���� 0���� �ʱ�ȭ�Ѵ�.
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < N; ++i)
        {
            // �� ���� ����Ƚ���� ������Ų��.
            ++visit[board[i][j]];
        }
        for (int i = 0; i < N; ++i)
        {
            // ���� ���� 1���� �����ߴٸ� �ش� �÷��̾��� ������ ������Ų��.
            if (visit[board[i][j]] == 1)
            {
                answer[i] += board[i][j];
            }
        }
    }
    // ��� �÷��̾��� ���� ������ ����Ѵ�.
    for (int i = 0; i < N; ++i)
        cout << answer[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i][0] >> board[i][1] >> board[i][2];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}