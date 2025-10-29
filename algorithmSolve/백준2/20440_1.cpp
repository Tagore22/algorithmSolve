#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Ǯ��.
// ���� ����� ��������. �� / ��ǥ �����̶�� �����̾��µ� ��ǥ���� �ʹ� ū ��쿡
// ���Ǿ���. ���������� �ð��� �ִ� 21���̶�� ū ���̱� ������ ���� �迭��
// ���� �� ���µ� �� ��, ���� ���� �迭�� ����� �̰��� ���������� ���� ����־�
// ��ġ map ó�� ����Ѵ�. ������ �����̱⿡ �ּ��� �� �� �ڼ��� ���� �� ���ϴ�.

// �ڼ��� ������ �ּ����� �����.

// ���� �Է°�.
pair<int, int> board[1000000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    // ���� �迭.
    vector<int> trans;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i].first >> board[i].second;
        // ���� �迭�� ���� ������ �ִ´�.
        trans.push_back(board[i].first);
        trans.push_back(board[i].second);
    }
    // 2�� �޺��ε� ���� ��, �ߺ��� �����.
    sort(trans.begin(), trans.end());
    trans.erase(unique(trans.begin(), trans.end()), trans.end());
    // �ִ� ������ �˱� ���� ������ �迭. ��ġ ���� �迭 Ʈ���� ����ϴ�.
    // �ٸ� �������� �ݿ��� ������ �����߱⿡ l, r�� ���� �� --[r + 1]�� �ƴ�
    // --[r]�� �Ǿ�� �Ѵ�.
    vector<int> sum(trans.size());
    for (int i = 0; i < N; ++i)
    {
        int from = board[i].first;
        int to = board[i].second;
        // ���� ��ġ������ ã�Ƴ���.
        int fidx = lower_bound(trans.begin(), trans.end(), from) - trans.begin();
        int tidx = lower_bound(trans.begin(), trans.end(), to) - trans.begin();
        // ������ �� ��ġ������ �̿��Ͽ� ���� �迭 Ʈ���� ����Ѵ�.
        ++sum[fidx];
        --sum[tidx];
    }
    int ans = sum[0];
    // �ڼ��� ���� ���������� ���� �迭���� ���ϴ� ������ ���µ�
    // �̴� ���� �迭���� ��â�� ���� 0�̱� ������ ���� ������ �ʾƵ� ������� �����̴�.
    for (int i = 1; i < sum.size(); ++i)
    {
        sum[i] += sum[i - 1];
        ans = max(ans, sum[i]);
    }
    bool isgreater = false;
    pair<int, int> answer = make_pair(-1, -1);
    for (int i = 0; i < sum.size(); ++i)
    {
        // �� ó�� �ִ밪�� ������ ��ġ�� �ٷ� ���� ���� ������ �����̴�.
        if (!isgreater && ans == sum[i])
        {
            answer.first = i;
            isgreater = true;
        }
        // �ִ밪�� ���� ���� ���� ù°�� �ִ밪�� �ƴ� ������ ������ ���� ������ �κ��̴�.
        if (isgreater && sum[i] < ans)
        {
            answer.second = i;
            break;
        }
    }
    cout << ans << '\n';
    cout << trans[answer.first] << ' ' << trans[answer.second] << '\n';
    return 0;
}