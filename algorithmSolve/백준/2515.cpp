#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� ��������. �����ؼ� ��� ������ ����°ͱ��� �˰ڴµ� ���ݼ��� ���̼� ��� �ؾ����� ���� ��������.
// �ᱹ ��Ʈ�� �ôµ� DP�� �̺�Ž���� �־���. ������ �ٽ� �������ߴ�. ������ڸ� ��� ���Ҹ� ��ȸ�Ѵ�.
// idx��° ���Ҹ� ��ȸ�Ҷ� idx - 1��° ���ҿ��� �Ÿ��� �ľ��ؼ� S���� ũ�ų� ���ٸ� dp[idx��° ������ ����]�� 
// dp[idx - 1��° ������ ����] + idx��° ������ ���ݰ� �������� �ִ밪�� �ȴ�. ��, �� dp�� � ���̿����� �ִ� ������ �ȴ�.
// ����, �Ÿ��� S���� �۴ٸ� ���� �ϳ��� ������ �ֱ⿡ ������ ���ؾ��ϴµ� idx��° ������ ���� - S������ ���ų� ���� �ε�����
// prev�� ���ؾ��Ѵ�. �̰��� ���ؼ� upper_bound�� ������ prev���� 1 ���ҽ�Ų��. lower_bound�� ���� ���ų� ū ù��° ���Ҹ�
// ���ϱ� ������ ������ ����Ǵ� ���Ұ��� ������ �־ �Ұ����ϴ�. �̷��� prev�� ������ dp[idx��° ������ ����]�� 
// dp[idx - 1��° ������ ����]�� dp[prev��° ������ ����] + idx��° ������ ������ �ִ밪�� �ȴ�. �̰��� ���������� ��ȸ�Ͽ�
// dp[���� ���� ����]�� ����ϸ� �ȴ�. �����Ƿ� ������ ��������.

// �ڼ��� ������ �ּ����� �����.

vector<pair<int, int>> board;
int dp[20000001];
int N, S;

void MakeAnswer()
{
    // ��ȸ�� ���ؼ���, �̺�Ž���� ���ؼ��� ������ �ؾ��Ѵ�.
    sort(board.begin(), board.end());
    // ��� ���ҵ��� ��ȸ�Ѵ�. �ٸ� 0��° ���ҿ� 0�� �־��־�� �Ѵ�. ���� ��� S�� 5�̰� ù��° ������ ���̰� 8,
    // �ι�° ������ ���̰� 10�϶� �ι�° ������ �������� 8�� �Բ� �Ҽ� ���⿡ upper_bound�� �̿��ؾ� �ϴµ� 
    // �� ��������� 8�� �����⿡ ����� �� ������ ���Ҽ� ����. ���� 0�� �� �տ� �־ �ּҰ��� �����ؾ��Ѵ�.
    for (int iter = 1; iter <= N; ++iter)
    {
        // iter��° ������ ���̿� �� ���� ������ ���̰� S���� ũ�ų� ������
        if (board[iter].first - S >= board[iter - 1].first)
        {
            // �������� �������� dp�� + ������ ������ ���Ѱ��� �ִ밪�� dp���� �ȴ�.
            dp[board[iter].first] = max(dp[board[iter].first], dp[board[iter - 1].first] + board[iter].second);
        }
        // S���� ������.
        else
        {
            // ������ ���̰� - S������ ���� ���� ū�� idx�� ���Ͽ� �������� dp�� dp[idx] + ���簪�� ���� ���� �ִ밪��
            // ���簪�� dp���� �ȴ�.
            int idx = distance(board.begin(), upper_bound(board.begin(), board.end(), make_pair(board[iter].first - S, 20000001))) - 1;
            dp[board[iter].first] = max(dp[board[iter - 1].first], dp[board[idx].first] + board[iter].second);
        }
    }
    cout << dp[board.back().first] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> S;
    board.push_back(make_pair(0, 0));
    int h, c;
    for (int i = 0; i < N; ++i)
    {
        cin >> h >> c;
        board.push_back(make_pair(h, c));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}