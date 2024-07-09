#include <iostream>

using namespace std;

// Ǯ��.
// ��� ������ �ߺ��ؼ� �湮�Ҽ��� �ִ�. ��� �ѹ����� ��Ű� ���� ��������. �����̳� �÷��̵� �˰�����
// �̿��ϴ� �����ΰ� ���Ҵµ� ������ �ߺ����� �湮�� ���� �ʱ⿡ �÷��̵� ���Ҵ�. �׷��� �� �ڰ� ��� �������� �ʾҴ�.
// ������ ������ �ߺ� �湮�� �÷��̵� �˰��� ���� �̹� �ذ�� �����̱� ������ �� �ڷδ� ��Ʈ��ŷ�� �̿��Ͽ� ���
// ��θ� Ȯ���Ͽ� �ּҰ��� ��¸� �ϸ� �Ǵ� ���̾���.

// �ڼ��� ������ �ּ����� �����.

int board[10][10];
bool check[10] = { false, };
int N, K, answer = 987654321;

// �÷��̵� �˰���. i���� j���� �ּ� �Ÿ��� ���Ѵ�.
void Floyd()
{
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

// ��� �̵� ��θ� Ȯ���غ��� �Լ�.
int BackTrack(int idx, int num)
{
    // N���� ������ ��� �湮�ߴٸ� 0�� ��ȯ�Ѵ�.
    // �������.
    if (num == N)
        return 0;

    int ans = 987654321;
    // ��� �������� ��ȸ�Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        // �̹� �湮�߰ų� idx -> idx���� �̵��� �����Ѵ�.
        if (check[i] || i == idx)
            continue;
        check[i] = true;
        ans = min(ans, BackTrack(i, num + 1) + board[idx][i]);
        check[i] = false;
    }
    // ���⸦ ��Ծ �� 2�� ��̴�.
    return ans;
}

void MakeAnswer()
{
    Floyd();
    check[K] = true;
    cout << BackTrack(K, 1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
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