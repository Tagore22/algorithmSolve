#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ��� ���� ���̵��� �ִ� ��������. �����ؾ� ������ �и�ġ�� �ֵθ��� �ʾƵ� �Ǵ�
// ��츦 for���� ���� �����ϱ� ���� �ֵθ��� Ÿ�̹��� �� �����ؾ��ߴ�.

// �ڼ��� ������ �ּ����� �����.

// �Ź� ������ �Ǿ���ϸ� ���ҿ� �����ϱ� ������ �켱���� ť�� ����Ѵ�.
priority_queue<int> board;
int N, H, T;

void Solve()
{
    for (int iter = 0; iter <= T; ++iter)
    {
        // ��ǻ� �ٷ� �Ʒ� ù��° if�������� iter�� �ֵθ� �����̰�
        // �� ���ķδ� iter + 1�� �ֵθ� ������ �����ϴ�.
        int cur = board.top();
        board.pop();
        if (cur < H)
        {
            cout << "YES" << '\n';
            cout << iter << '\n';
            return;
        }
        // ����Ͽ��� �� �κ��� iter + 1�� �ֵθ� �Ͱ� ��ġ�ϹǷ�
        // iter�� T��° �϶����� �ݰ��� �ƴ� ������ ����ִ´�.
        if (iter != T)
            board.push(max(cur / 2, 1));
        else
            board.push(cur);
    }
    cout << "NO" << '\n';
    cout << board.top() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> H >> T;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        board.push(num);
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}