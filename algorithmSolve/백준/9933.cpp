#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �־��� ���ڿ����� �ݵ�� �� �ϳ��� ���������� ���� ���ڿ��� �����ִ�.
// �̰��� ���̿� ��� ���ڸ� ����ϴ� ������.
// ó������ set�� ����ؼ� �߰� ��� ��ȯ�ϴ� �������� Ǯ�� �����߾�����
// �׷��� �Ѵٸ� �Է��� �� ���� ���ϰ� ������ ��찡 ���ܼ� �Ұ����ߴ�.
// �ᱹ 100 * 100 = 1���� ��츦 ��� ��ȸ�ϴ� �Ʒ� Ǯ�̷� Ǯ����.
// �Ѱ��� Ʋ������ �־��µ� cur�� �ʱ�ȭ�ϴ� �������� ó������ �����ڷ� �߾��µ�
// �׷��� �ڿ� reverse()�� �Ͽ����� ������ �ٲ� Ʋ������ ���Դ�.

// �ڼ��� ������ �ּ����� �����.

string board[100];
int N;

void MakeAnswer()
{
    // ��� ���ڿ����� ��ȸ�Ͽ� �������� ���� ���ڿ��� �����ϴ��� Ȯ���Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        string cur = board[i];
        reverse(cur.begin(), cur.end());
        for (int j = 0; j < N; ++j)
        {
            // ���ٸ� ���ڿ��� ���̿� ��� ���ڸ� ����Ѵ�.
            if (cur == board[j])
            {
                cout << cur.size() << ' ' << cur[cur.size() / 2] << '\n';
                return;
            }
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}