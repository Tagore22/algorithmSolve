#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ���� ����� ���� ������ ã�� ������. ������ �θ� �迭�� �̿��Ͽ� ���� ���� ���Ҹ� ����������
// ���� �ö󰡸� �ɰ� ������ �����δ� �׷��� �ʴ�. �ֳ��ϸ� ���̰� �ٸ� ��찡 �����ϱ� �����̴�.
// ���� �� ������ �θ�� ���̸� ����Ͽ� ���̰� ���������� ��� ������ ����÷��� �Ѵ�.
// �� �ĺ��ʹ� ����Ѵ�� �� ���Ҹ� �ϳ��� �θ������� ����ø��� ���������� �ݺ��ϸ� �ȴ�.
// �ٸ� �Ź� ������ �θ� �ڽ� �Է��� ������ ������ ������ �������־�� �Ѵ�.
// �� �κп��� �Ѱ��� �Ǽ��� �ߴµ� �ڽ� ������ �ʱⰪ�� �θ��� ���̰����� ���־��ٴ� ���̴�.
// �θ��� ���̰� + 1�� ���־���ϴµ� ��... �̰Ͷ����� 30���� ��ǰ� ����. 

// �ڼ��� ������ �ּ����� �����.

vector<pair<int, int>> board;
vector<int> child;
int T, N;

// �� ����� ���� ����� ���� ������ ã�� �Լ�.
void FindParent(int a, int b)
{
    while (true)
    {
        // b�� ���̰� �� ��ٸ� �Ѵܰ� ����ø���.
        if (board[a].second < board[b].second)
        {
            b = board[b].first;
        }
        // a�� ���̰� �� ��ٸ� �Ѵܰ� ����ø���.
        else if (board[a].second > board[b].second)
        {
            a = board[a].first;
        }
        // ���� ���̰� ���ٸ� �Ѵ� �θ������� ����ø���.
        else
        {
            a = board[a].first;
            b = board[b].first;
        }
        // �� ��尡 ���ٸ� ����Ѵ�.
        if (a == b)
        {
            cout << a << '\n';
            return;
        }
    }
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        // ���͸� ���� �ʱ�ȭ�Ѵ�.
        board.clear();
        child.clear();
        cin >> N;
        board.resize(N + 1, make_pair(0, 0));
        child.resize(N + 1, -1);
        int p, c;
        for (int node = 0; node < N - 1; ++node)
        {
            cin >> p >> c;
            // �� �θ�� ���� ������ �����Ѵ�.
            board[c] = make_pair(p, board[p].second + 1);
            // ���� �ڽ��� �ڽĵ��� ���̰��� �����Ѵ�.
            child[p] = c;
            int d = board[c].second + 1;
            while (child[c] != -1)
            {
                c = child[c];
                board[c].second = d;
                ++d;
            }
        }
        cin >> p >> c;
        FindParent(p, c);
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