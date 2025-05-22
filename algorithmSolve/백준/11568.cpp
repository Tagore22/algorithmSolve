#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// �������� LIS���µ� �� ����� ���� �ʾ� ���� ��̴�. ������ڸ�, �迭�� ��ȸ�ϵ�
// ���Ͱ� ����ų� ���� ���� ������ ���� ū������ ũ�ٸ� ������ �������� ����ְ�
// �׷��� �ʴٸ� �´� ���ĵ� ��ġ���� ã�� ����� ���̴�. ����ٴ� �κ��� �� �����
// ���� �ʾҴ�.

int N;
const int MAX = 1000;
int board[MAX];
vector<int> ans;

void Solve()
{
    for (int i = 0; i < N; ++i)
    {
        if (ans.empty() || ans.back() < board[i])
        {
            ans.push_back(board[i]);
        }
        else
        {
            int idx = lower_bound(ans.begin(), ans.end(), board[i]) - ans.begin();
            ans[idx] = board[i];
        }
    }
    cout << ans.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    Solve();
    return 0;
}