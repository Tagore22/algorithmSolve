#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ��5 ~ ��4���� �̷� �ָԱ����� ������ ������ ���Ҵ�. ó������ ������ �����ϰ� �ߴ�.
// ������ ó�� ������ ���ں��� ������ ���� ���� �ڿ������� ���� �� ũ�ų� �������� �ֱ� �����̴�.
// ���� ��� ���Ұ��� ���� ���ĺ����� �����Ͽ� �Ŀ� ���� ���Ͽ� ū���� �������� ����ߴ�.

// �ڼ��� ������ �ּ����� �����.

const int MAXNUM = 26;
int T;

void MakeAnswer()
{
    string str;
    int K, min_ans, max_ans; // ���� ���� ���� ���� ū ��. �Ź� �ʱ�ȭ���־�� �Ѵ�.
    vector<int> board[MAXNUM]; // ���ĺ����� ������ �ε��������� �����ϴ� ���� �迭. �Ź� �ʱ�ȭ���־�� �Ѵ�.
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> str >> K;
        // ����� ���� �迭�� ������ �ʱ�ȭ.
        for (int i = 0; i < MAXNUM; ++i)
            board[i].clear();
        min_ans = 10001, max_ans = -1;
        // ��� ���ڵ��� ��ȸ�ϸ� ���� ��ġ�� ���� �迭�� �����Ѵ�.
        for (int i = 0; i < str.size(); ++i)
        {
            int idx = str[i] - 'a';
            board[idx].push_back(i);
        }
        // ��� ���ĺ����� ��ȸ�ϸ� ���� ã�´�.
        for (int i = 0; i < MAXNUM; ++i)
        {
            // �ش� ���ĺ��� K������ ���� �����ߴٸ� �����Ѵ�.
            if (board[i].size() < K)
                continue;
            // j��° ��ġ���� j - K + 1��° ��ġ���� ���Ͽ� ������ �����Ѵ�. ��Ȯ�� K���� ���ԵǾ���ϹǷ�
            // board[i][j] - board[i][j - K + 1] + 1�� ��ȭ���� ����ȴ�.
            for (int j = board[i].size() - 1; j >= K - 1; --j)
            {
                min_ans = min(min_ans, board[i][j] - board[i][j - K + 1] + 1);
                max_ans = max(max_ans, board[i][j] - board[i][j - K + 1] + 1);
            }
        }
        // K���̻� ������ ���ڰ� ���� ���� ������ ���������� -1�� ����Ѵ�.
        if (min_ans == 10001)
            cout << -1 << '\n';
        // �� �ܿ��� �������� ū���� ������� ����Ѵ�.
        else
            cout << min_ans << ' ' << max_ans << '\n';
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