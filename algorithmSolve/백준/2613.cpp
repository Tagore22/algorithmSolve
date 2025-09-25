#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �������� �����ֵ� ����� ��������. ó������ ��Ʈ��ŷ���� ������ ����������
// 100���� 50���� ��� ������� ���귮�� �䱸�Ǿ��⿡ �ð��ʰ��� ����.
// �� ���� ����Ž������ ������ ���� ®��. �ִ밪�� ����Ž������ ���� �Ŀ�
// �������� ��ȸ�ϸ� ���� �� �ִ� �κе��� ���ϴ� ����̴�. �ٸ�, �� ���Ŀ�
// �߰����� �۾��� �ʿ��ߴµ� ���� ��� 6, 4, 1, 1, 1, 1, 1, 1�϶�
// ����Ž�������� ���ϸ� 2, 2, 2�� �� �κ����� ���������� �Ǿ� ����� ��
// ���� ���� �� ����. 1, 2, 1, 1 ������ �ѹ� �� M�� �°Բ� �κ� ���� �������־�� �Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int N, M;
int board[300];
vector<int> cur, answer;

// �ִ밪 mid�� �־��� �� ��� �׷����� ���� �� �ִ� ��
// ����ϴ� �Լ�.
bool CheckMid(int mid)
{
    cur.clear();
    int sum = 0, from = 0, num = 0;
    for (int i = 0; i < N; ++i)
    {
        if (sum + board[i] > mid)
        {
            cur.push_back(i - from);
            from = i;
            sum = 0;
            ++num;
        }
        sum += board[i];
    }
    cur.push_back(N - from);
    ++num;

    return num <= M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int sum = 0, maxval = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        sum += board[i];
        maxval = max(maxval, board[i]);
    }

    int from = maxval, to = sum;
    while (from <= to)
    {
        int mid = (from + to) / 2;
        if (CheckMid(mid))
        {
            answer = cur;
            to = mid - 1;
        }
        else
        {
            from = mid + 1;
        }
    }

    // ����� �߰� �۾�.
    while (answer.size() < M)
    {
        for (int i = 0; i < answer.size(); ++i)
        {
            if (answer[i] > 1)
            {
                --answer[i];
                answer.insert(answer.begin() + i, 1);
                // ó������ �׳� �� �տ� �߰����ָ� �� �� �˾Ҵµ�
                // �������� �ð� �ϱ� ���ؼ��� ���� �κ� �ٷ� �տ� �߰����־�� �Ѵ�.
                break;
            }
        }
    }
    cout << to + 1 << '\n';
    for (auto& here : answer)
        cout << here << ' ';
    cout << '\n';
    return 0;
}