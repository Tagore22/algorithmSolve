#include <iostream>

using namespace std;

// 27172���� �� ���� Ǯ��. ���� Ǯ�̰� �������� �̿��Ͽ��ٸ� �Ʒ� Ǯ�̴� ������ �̿��Ͽ���.
// ó���� �����ϱ�δ� �������� �Ҷ����� �������� ���� ������ ������ �ִ� 1000�̶� �� ������ �˾Ҵ���
// �����̾���. ����Ѵ�� �������� ������� �Ͽ��� ������ ������ �� ���ȴ�. �� ���ҵ��� �ִ밪 maxnum�� ������
// ��� ���ҵ��� ��ȸ�ϸ� 2�̻���� ���������� �÷����� maxnum���ϱ��� �����ش�. ���� �� ���� �����Ѵٸ� 
// +-1 ������ �Ѵ�. ���������� ���������꺸�� �����ٴ°� �Ӹ��δ� �˰� ������ ������ �ȵǾ���. �ٽ� �ѹ� ����ص���.

// �ڼ��� ������ �ּ����� �����.

int board[100000], answer[1000001];
int N, maxnum = -1;

void MakeAnswer()
{
    // �� ��� ���ҵ��� ��ȸ�ϸ� 2�̻���� maxnum���ϱ��� ���������� �����ش�.
    // �̶� ���� ���� �����Ѵٸ� +-1 ������ �Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        for (int j = 2; j * board[i] <= maxnum; ++j)
        {
            if (answer[j * board[i]] != -987654321)
            {
                ++answer[board[i]];
                --answer[j * board[i]];
            }
        }
    }
    for (int i = 0; i < N; ++i)
        cout << answer[board[i]] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 1000000; ++i)
        answer[i] = -987654321;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        answer[board[i]] = 0;
        maxnum = max(maxnum, board[i]);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}