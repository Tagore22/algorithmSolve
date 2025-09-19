#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ��ȯ ������ �̿��� �׸��� ������.
// ��ȯ �����̶� ������ ����.

// �� �۾� A, B�� ���� ��, A�� ���� �ϴ� �Ͱ� B�� ���� �ϴ� �� �� ��� ���� �� �������� ���غ���

// A ���� : A�� ��� = t_A �� s_A, B�� ��� = (t_A + t_B) �� s_B
// B ���� : B�� ��� = t_B �� s_B, A�� ��� = (t_B + t_A) �� s_A

// A�� ���� �ϴ� ���� �����Ϸ��� :
// t_A �� s_A + (t_A + t_B) �� s_B < t_B �� s_B + (t_A + t_B) �� s_A
// �̸� �����ϸ� : t_A �� s_B < t_B �� s_A. ��, t_A / s_A < t_B / s_B

// �׷��⿡ �ᱹ t / s�� ���� ������ �����Ͽ� �� �ε������� ����ϸ� �ȴ�.

int N;
pair<double, int> board[1001];

bool SortFunc(const pair<double, int>& lhs, const pair<double, int>& rhs)
{
    if (lhs.first == rhs.first)
        return lhs.second < rhs.second;
    else
        return lhs.first < rhs.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int iter = 1; iter <= N; ++iter)
    {
        int t, s;
        cin >> t >> s;
        board[iter].first = static_cast<double>(t) / s;
        board[iter].second = iter;
    }
    sort(board + 1, board + N + 1, SortFunc);
    for (int iter = 1; iter <= N; ++iter)
        cout << board[iter].second << ' ';
    cout << '\n';
    return 0;
}