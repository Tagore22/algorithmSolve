#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// Ǯ��.
// �־��� ���ҵ��� ���ؼ� M�� �Ǵ� ���� ���� ����ϴ� ������.
// ��� ���Ұ��� �����ϱ⿡ �ϴ� �ϳ��� ���� �����Ǹ� �� �ֵ��� ���̻� �����Ҽ� ����.
// ������ �ָԱ��������� Ǯ� �ٽ� Ǯ����.

// �ڼ��� ������ �ּ����� �����.

int board[15000];
bool visit[15000];
int N, M;

void MakeAnswer()
{
    // ���� ã���� ���� ��� ������ �ּ�ȭ�ϱ� ���� ����.
    sort(board, board + N);
    // ó���� ��� ���õ��� �ƴ���.
    memset(visit, false, sizeof(visit));
    int answer = 0;
    // ��� ���ҵ��� ��ȸ�ϸ� �� ���� ã�ƺ���.
    for (int i = 0; i < N - 1; ++i)
    {
        // �ڱ��ڽ� ���ĺ��� ã�ƺ���.
        for (int j = i + 1; j < N; ++j)
        {
            // ���� ���Ұ� �̹� ���õ� ���Ҷ�� �����Ѵ�.
            if (visit[j])
                continue;

            // �� ������ ���� M�̶�� j��° ���Ҹ� ���� ������ answer�� 1 ������Ų�� Ż���Ѵ�.
            if (board[i] + board[j] == M)
            {
                visit[j] = true;
                ++answer;
                break;
            }
            // ���� ���� �̹� M�� �Ѿ��ٸ� ���� ã���� ���⿡ �����ϰ� Ż���Ѵ�.
            else if (board[i] + board[j] > M)
            {
                break;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}