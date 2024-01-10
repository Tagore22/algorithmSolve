#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// 2���� �迭�� ����Ͽ� �ΰ��� ������ ���̰� 2�� �ɶ����� �����ָ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<int> board[2];
string a, b;
int cur = 0;

int main()
{
    cin >> a >> b;
    // 2���� ��ȣ�� �ϳ��� �����ش�.
    for (int i = 0; i < 8; ++i)
    {
        board[cur].push_back(a[i] - '0');
        board[cur].push_back(b[i] - '0');
    }

    // ��ģ ����� ũ�Ⱑ 2�϶����� �ݺ�.
    while (board[cur].size() > 2)
    {
        // ��Ʈ����ũ �������� ������ �ε����� ��´�.
        int next = cur ^ 1;
        // ���� ������� �迭�� ����.
        board[next].clear();
        // ������ �迭�鰪�� ����Ͽ� ���ο� �迭�� �ִ´�.
        for (int i = 0; i < board[cur].size() - 1; ++i)
            board[next].push_back((board[cur][i] + board[cur][i + 1]) % 10);
        // ���� �ε����� �����Ѵ�.
        cur = next;
    }
    for (auto a : board[cur])
        cout << a;
    cout << '\n';
    return 0;
}