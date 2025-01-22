#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ��ƴٱ� ���ٴ� Ǯ�� ��ü�� �����ߴ�. ��� ��ġ idx���� ����� �ִ� ��� ���ڿ��� ������ �ִ� 
// �ּ����� ��ȯ������ dp�� �̿��Ͽ� ���ϸ� �ȴ�. �����ϱ� �����Ͽ� �ּ����� �����.

// �ڼ��� ������ �ּ����� �����.

string board[50];
string str;
int dp[50];
int N;
const int MAXNUM = 51;

// �ΰ��� ���ڿ��� �־����� ��ȯ���� ���ϴ� �Լ�.
int CalCost(string next, string cur)
{
    // �� ���ڿ��� ���̰� �ٸ��ٸ� ������ ��ȯ�Ҽ� ����.
    if (next.size() != cur.size())
        return MAXNUM;

    string first = next, second = cur;
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    // �� ���ڿ��� �����Ѱ��� �ٸ��ٸ� ������ ��ȭ�Ҽ� ����.
    if (first != second)
        return MAXNUM;

    int ans = 0;
    for (int i = 0; i < next.size(); ++i)
        if (next[i] != cur[i])
            ++ans;
    return ans;
}

// ���� ���ڿ� next�� ��� �ܾ���� ���Ͽ� ������ �ִ� �ּ����� ��ȯ���� ��ȯ�Ѵ�.
int MinCost(string next)
{
    int ans = MAXNUM;
    for (int i = 0; i < N; ++i)
        ans = min(ans, CalCost(next, board[i]));
    return ans;
}

int FindMin(int idx)
{
    // ������ ���Ұ����� ���ߴٸ� 0�� ��ȯ�ϰ� Ż���Ѵ�.
    if (idx == str.size())
        return 0;
    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    ans = MAXNUM;
    for (int i = idx; i < str.size(); ++i)
    {
        // ���� ��ġ���� 1���� �÷����� �κ� ���ڿ��� ����� �ִ� �ּҰ��� ���Ѵ�.
        string next = str.substr(idx, i - idx + 1);
        int cur = MinCost(next);
        // ���Ҽ� ���ٸ� �����Ѵ�.
        if (cur == MAXNUM)
            continue;
        ans = min(ans, cur + FindMin(i + 1));
    }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < MAXNUM; ++i)
        dp[i] = -1;
    int answer = FindMin(0);
    cout << (answer == MAXNUM ? -1 : answer) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> str >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}