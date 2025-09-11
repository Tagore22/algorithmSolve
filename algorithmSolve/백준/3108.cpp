#include <iostream>
#include <vector>

using namespace std;

// Ǯ��. 
// ���ø� ���̵��� ���Ҵ�. ������� �������ڸ�

// 1. 0, 0�� 0��° ���簢������ �ξ� for���� ����� �ִ� N�� ��ȸ�ϸ� �� ���簢������
// ���� ���θ� ����Ͽ� ���Ϳ� �ִ´�. 
// 2. 2�� for���� ���ؼ� �ִ� 50������ ��ȸ���� �� ���簢���� ���� ���θ� ���Ϳ� �ִ´�.
// 3. for���� �̿��� N���� ��ȸ�� ���� ���� �湮���� ���� ���簢������ DFS�� ȣ���Ѵ�.
// �� ��, DFS�� ȣ��� Ƚ���� �ٷ� ������ �ȴ�.

// �ٸ�, �� ���簢���� ��ħ ���θ� �����ϴ°� �ʹ� �������. �����δ� ��û �����ߴµ�
// �װ��� �̰��� �����ϱ� �����ϴ� �ļ��ϰڴ�.

// �ڼ��� ������ �ּ����� �����.

struct quad
{
    int x1;
    int y1;
    int x2;
    int y2;
};

int N;
quad board[1001];
vector<int> mov[1001];
bool visit[1001] = { false, };

bool CanMove(const quad& a, const quad& b)
{
    // ���� ���� �� ��ġ�� ���.
    if (a.x2 < b.x1 || b.x2 < a.x1 || a.y2 < b.y1 || b.y2 < a.y1)
        return false;

    // ���ο����� ��ġ�� ��� ���� (��� �� ��� ���)
    if (a.x1 < b.x1 && b.x2 < a.x2 && a.y1 < b.y1 && b.y2 < a.y2)
        return false;
    if (b.x1 < a.x1 && a.x2 < b.x2 && b.y1 < a.y1 && a.y2 < b.y2)
        return false;

    return true;
}

void DFS(int idx)
{
    visit[idx] = true;
    for (auto next : mov[idx])
    {
        if (!visit[next])
            DFS(next);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> board[i].x1 >> board[i].y1 >> board[i].x2 >> board[i].y2;

    for (int i = 1; i <= N; ++i)
    {
        if (((board[i].y1 == 0 || board[i].y2 == 0) && (board[i].x1 <= 0 && 0 <= board[i].x2)) ||
            ((board[i].x1 == 0 || board[i].x2 == 0) && (board[i].y1 <= 0 && 0 <= board[i].y2)))
            mov[0].push_back(i);
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            if (CanMove(board[i], board[j]))
            {
                mov[i].push_back(j);
                mov[j].push_back(i);
            }
        }
    }

    int answer = -1;
    for (int i = 0; i <= N; ++i)
    {
        if (!visit[i])
        {
            ++answer;
            DFS(i);
        }
    }
    cout << answer << '\n';
    return 0;
}