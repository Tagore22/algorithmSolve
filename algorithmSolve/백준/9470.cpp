#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// �������� 40�۵� �ȵǴ� �ϳ� ������ �������� �������� ���� Ǯ����. ���� �� Ǯ���� �� ���� �����̴�.
// ��Ģ�� �ϳ� ������ �ִµ� � ������ ������ �� ������ �����Ҽ� �ִ� �������� �������� ���� ū ������ max��� �Ҷ�
// max�� 2�� �̻��̶�� + 1�̸� �׷��� �ʴٸ� max�� �ش� ������ ������ �ȴ�. M�� ������ ������ �ٴٷ� ���ϱ� ������
// ��������� M�� ������ ������ ���ϴ°��� �ȴ�. ������ ������ ������ ���ؾ��߱⿡ ���̷����ϰ� �������� Ǯ����ߴ�.
// �Է¶����� ������ �ݴ�� �ٲپ ������ M������ �����ؼ� ������ ���ϸ� �ȴ�. ���� �ϳ��� ������ ������ �����Ҽ� �ֱ⿡
// DP���� �Բ� �����ߴ�.

// �ڼ��� ������ �ּ����� �����.

vector<int> board[1001];
int dp[1001];
int T, K, M, P;

// idx��° ������ ������ ���ϴ� �Լ�.
int DFS(int idx)
{
    // DPó��. �ٸ� �������� -1�� �ʱ�ȭ�ϴ� ���� ���Ҵµ� �̹�����
    // ��� ������ ������ �ּ� 1�̱� ������ 0���� �ʱ�ȭ�ص� �ȴ�.
    int& ans = dp[idx];
    if (ans != 0)
        return ans;
    ans = 1;

    // ���� ��� �������� �����Ѵ�.
    vector<int> cur;
    for (auto& a : board[idx])
        cur.push_back(DFS(a));
    // �����Ҽ� �ִ� ���� ���ٸ� ���� ans�� 1�̱� ������ �״�� ��ȯ�Ѵ�.
    if (cur.empty())
    {
        return ans;
    }
    // �����Ҽ� �ִ� ���� 1������� ans�� �� ������ �����Ͽ� ��ȯ�Ѵ�. ���� ans�� �ּҰ��̱� ������
    // cur[0]���� ������ �۾��� �� ū���� ���� �����̴�.
    else if (cur.size() == 1)
    {
        return ans = cur[0];
    }
    // 2���� �̻��� ��쿡�� �ִ밪�� 2�� �̻��̿��� + 1 �� ���� ��ȯ�ؾ��Ҽ��� �ֱ⿡
    // ��� �������� ������������ �����Ͽ� 0��° ���ҿ� 1��° ���Ҹ� ���Ͽ� ans���� ������
    // ��ȯ�Ѵ�.
    else
    {
        sort(cur.begin(), cur.end(), greater<>());
        return ans = cur[0] == cur[1] ? cur[0] + 1 : cur[0];
    }
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        for (auto& a : board)
            a.clear();
        for (int j = 0; j <= M; ++j)
            dp[j] = 0;
        cin >> K >> M >> P;
        int from, to;
        for (int j = 0; j < P; ++j)
        {
            cin >> from >> to;
            board[to].push_back(from);
        }
        cout << iter + 1 << ' ' << DFS(M) << '\n';
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