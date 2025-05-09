#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �������� ���������� ���ϴ� ���� �־��� �� ���Ը� �̿��Ͽ� ���� �� �ִ� ��� ���� ������ �˾ƾ��Ѵ�.
// �� �κп��� �� ������. ��������δ� �Ʒ� Ǯ��ó�� DFS Ȥ�� ��Ʈ��ŷ�� ����Ͽ� ���ϰų�, ���ų�,
// ������� �ʰ� �Ѿ�ų� �� 3������ ��� �����Ͽ� Ǫ�� ����̴�. 3���� ��찡 �ִ� 13�� �־����Ƿ�
// ���귮�� 3�� 13�������� 150���� ���� �Ѱ� �ȴ�.

vector<bool> choose(2600000);
int board[13];
int K, sum = 0, answer = 0;

void DFS(int idx, int w)
{
    if (idx == K)
    {
        if (w > 0)
            choose[w] = true;;
        return;
    }

    DFS(idx + 1, w + board[idx]);
    DFS(idx + 1, w - board[idx]);
    DFS(idx + 1, w);
}

void Solve()
{
    DFS(0, 0);

    for (int i = 1; i <= sum; ++i)
        if (!choose[i])
            ++answer;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        cin >> board[i];
        sum += board[i];
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}