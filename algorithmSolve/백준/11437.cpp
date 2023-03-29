#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// LCA������ ó������ �밭�� ������ �����ؾ��ߴ�.
// https://4legs-study.tistory.com/121

// LCA�� �⺻���� ������ �̷��ϴ�.

// 1. �� ������ �θ� �������� �÷����� �� ������ ������ �ٷ� �� ������ �ּ� ���� �θ��̴�.
// 2. �ٸ� ���� �� ������ ���̰� �ٸ��� �ּ� ���� �θ� ã���� ���⿡ ���̸� �����־�� �Ѵ�.
// (���� �������� �θ� �������� �ø��� �� ������ ���̸� ����.)

// ������ü�� ������ ��� Ǯ��ôµ� �ڲ� �ð��ʰ��� ������.
// ������ �ǿܷ� �����ߴµ� ������ ���ÿ��� ������ ������ �̾����� ���·� ���ο� ������
// �־������� �׷��� ���� ���� �־���. ���� ��� 1 ~ 4���� ��尡 �ִµ� ����
// 1 - 2, 2 - 3, 3 - 4�� �̾� ������ 1 - 2, 3 - 4, 2 - 3������ ������°� �־����ٸ�
// �߰��� 3 - 4�� ���¸� ����ϰԴ� �˾Ƴ��� ������.

// �׷��� ����� ��� �������� �����Ͽ� �θ� �ƴ϶�� �����ϰ� �׷��� �ʴٸ�
// �����ϴ� ������ Ʈ���� ¥�� �ߴ�.

// �ڼ��� ���� �ּ����� ����� LCA�� ����� �ʾƼ� �����̴�.

vector<vector<int>> board;
int parent[50001], level[50001];
int N, M, lhs, rhs;

// Ʈ���� �����ϴ� �Լ�. ����Ͽ��� ����ϰ� �����ؼ��� ������ �����.
// ���� 0���� �߰��Ǿ� �Ǿ��Ҽ� ������, �������� ��Ʈ�� 1���̶�� ���� �ֱ⿡
// 0���� ����� ������ ������ ����. �׷��⿡ 0���� �����ص� ����� ����.
void MatchParent(int c, int p)
{
    parent[c] = p;
    level[c] = level[p] + 1;

    // ����� ��� �������� �ڽ��� �Ʒ��� �����Ѵ�. �ٸ� �θ�� �����Ѵ�.
    for (int i = 0; i < board[c].size(); ++i)
    {
        int cur = board[c][i];
        if (cur == p)
            continue;

        MatchParent(cur, c);
    }
}

// ������ ���̰� �����ҽ� ����� �θ� ã�� ���������⿡ 
// ���̸� �����.
void FindAnswer()
{
    // ���� ���̰� �ٸ��� ���� �������� �θ� �������� �ö󰡸� ���̸� �����.
    while (level[lhs] != level[rhs])
    {
        if (level[lhs] > level[rhs])
            lhs = parent[lhs];
        else
            rhs = parent[rhs];
    }

    // �θ� �������� �ö󰡸� �� ������ �����ҽ� ���� �θ� �ȴ�.
    while (lhs != rhs)
    {
        lhs = parent[lhs];
        rhs = parent[rhs];
    }

    cout << lhs << '\n';
}

void MakeAnswer()
{
    MatchParent(1, 0);
    for (int i = 0; i < M; ++i)
    {
        cin >> lhs >> rhs;
        FindAnswer();
    }
}

void Input() // Ʈ���� ������� ���� ���·� �־������� �ִ�.
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    parent[0] = 0;
    level[0] = 0;

    cin >> N;
    board.resize(N + 1, vector<int>());
    for (int i = 1; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}