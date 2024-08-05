#include <iostream>
#include <vector>

using namespace std;

// 16437���� �ٸ� Ǯ��.
// �־����� �ڷᰡ �������� ������, ������ ��, ����� ���� �̷��� ���ε�
// ù��° �ڷ�� ���߿��� �ʿ䰡 ����. ���� �̰� ���ְ� board�� �ڷ����� ���� ����ü����
// pair<int, int>�� �����Ͽ� Ǯ��Ҵ�. �ӵ��� ���ݴ� ������ ������ ������ �� ���� ������
// �޸𸮿� �ڵ���� �پ���. board�� ���� �̿ܿ��� ������ �����ϴ�.

pair<int, int> board[123457];
vector<int> child[123457];
int N;

long long DFS(int idx)
{
    if (child[idx].size() == 0)
        // ���̻� animal�� �������� �ʰ� ���� �����Ѵ�. ������� ����, ������ ���̴�.
        return board[idx].first <= 0 ? 0 : board[idx].first;

    long long ans = 0;
    for (auto& n : child[idx])
        ans += DFS(n);

    ans += board[idx].first;

    return ans >= 0 ? ans : 0;
}

void MakeAnswer()
{
    cout << DFS(1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    char a;
    int b, c;
    for (int i = 2; i <= N; ++i)
    {
        cin >> a >> b >> c;
        if (a == 'W')
            b *= -1;
        board[i] = make_pair(b, c);
        child[c].push_back(i);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}