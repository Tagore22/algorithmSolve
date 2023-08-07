#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// ����� ������ �� ���� �� ������ �������� ���� ������.
// ������ ū Ʋ�� ������ ����.

// 1. 2���� �迭�� ���� �� ���� ���̿� ���� ���̸� ���Ͽ�
// ���� ��ٸ� �� ���� �����ϰ�, ���� ��ٸ� �� ���� �����Ѵ�.
// 2. ������ �� ���� �� ����Ƚ���ε� ����Ƚ���� ����� ���̸� �� ���� ���ٸ� ���� Ŭ���� ���̴�.
// 3. ������ ��ģ�� �ٽ� ���� �� ���� ���̿� ���� �� ���� ���̸� �����ϰ� �̰��� �ݺ��Ѵ�.
// 4. ���� 100���� �����ص� ���� ã���� ���ٸ� -1�� ����Ѵ�.

// �� ����Ͽ��� ���������� ������ �ƴϱ� ������ �����ϸ� �ѹ��� Ǯ�� �ִ�.
// �ڼ��� ������ �ּ����� �����.


int board[101][101];
int visit[101], len[101];
int R, C, K, row_num, col_num;

// ���� ���̿� ���� ���̸� ���Ͽ� �ѹ��� ������ �����ϴ� �Լ�.
int CalAnswer(int time)
{
    // ���� ã�Ҵٸ� �� ���� ��ȯ�Ѵ�.
    if (board[R][C] == K)
        return time;
    // 100���� �����ص� ã���� ���ٸ� -1�� ��ȯ�Ѵ�.
    if (time > 100)
        return -1;

    int max_len = 0;
    // ���� ���̰� ���� ���̺��� ũ�ų� ���ٸ� ��� ���� �����Ѵ�.
    if (col_num >= row_num)
    {
        for (int i = 1; i <= col_num; ++i)
        {
            memset(visit, 0, sizeof(visit));
            // �� ���� ��ȸ�ϸ� 0�� ������ ��� ���� ����Ƚ���� �ľ��Ѵ�.
            for (int j = 1; j <= row_num; ++j)
            {
                if (board[i][j] == 0)
                    continue;

                int cur = board[i][j];
                ++visit[cur];
            }

            // ������ �ľ��� �� ���� �� ����Ƚ���� �����Ͽ� ���� ���� ���̸� ����ϰ�
            // ����� �ִ� ���� max_len�� �����Ѵ�.
            vector<pair<int, int>> ans;
            for (int iter = 1; iter <= 100; ++iter)
                if (visit[iter] != 0)
                    ans.push_back(make_pair(visit[iter], iter));
            sort(ans.begin(), ans.end());
            len[i] = ans.size() * 2;
            max_len = max(max_len, len[i]);

            // ������ ���� ������� ���� ���� �����Ѵ�.
            for (int iter = 0; iter < ans.size(); ++iter)
            {
                board[i][iter * 2 + 1] = ans[iter].second;
                board[i][iter * 2 + 2] = ans[iter].first;
            }
        }

        // �� ����� �ִ� ���̺��� ���� ����� �ڿ� 0�� �߰����ش�.
        for (int i = 1; i <= col_num; ++i)
            for (int j = len[i] + 1; j <= max_len; ++j)
                board[i][j] = 0;
        // ���� �� ���� ���� ����.
        row_num = max_len;
    }
    // ���� ���̰� ���� ���̺��� �۴ٸ� ��� ���� �����Ѵ�.
    else
    {
        for (int j = 1; j <= row_num; ++j)
        {
            memset(visit, 0, sizeof(visit));
            // �� ���� ��ȸ�ϸ� 0�� ������ ��� ���� ����Ƚ���� �ľ��Ѵ�.
            for (int i = 1; i <= col_num; ++i)
            {
                if (board[i][j] == 0)
                    continue;

                int cur = board[i][j];
                ++visit[cur];
            }

            // ������ �ľ��� �� ���� �� ����Ƚ���� �����Ͽ� ���� ���� ���̸� ����ϰ�
            // ������ �ִ� ���� max_len�� �����Ѵ�.
            vector<pair<int, int>> ans;
            for (int iter = 1; iter <= 100; ++iter)
                if (visit[iter] != 0)
                    ans.push_back(make_pair(visit[iter], iter));
            sort(ans.begin(), ans.end());
            len[j] = ans.size() * 2;
            max_len = max(max_len, len[j]);

            // ������ ���� ������� ���� ���� �����Ѵ�.
            for (int iter = 0; iter < ans.size(); ++iter)
            {
                board[iter * 2 + 1][j] = ans[iter].second;
                board[iter * 2 + 2][j] = ans[iter].first;
            }
        }

        // �� ������ �ִ� ���̺��� ���� ������ �ڿ� 0�� �߰����ش�.
        for (int j = 1; j <= row_num; ++j)
            for (int i = len[j] + 1; i <= max_len; ++i)
                board[i][j] = 0;
        // ���� �� ���� ���� ����.
        col_num = max_len;
    }
    return CalAnswer(time + 1);
}

void MakeAnswer()
{
    row_num = col_num = 3;
    int answer = CalAnswer(0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> K;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}