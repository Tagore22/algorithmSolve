#include <iostream>
#include <string>
#include <set>

using namespace std;

// Ǯ��.
// string�� set�� �̿��Ͽ� Ǯ������ ��Ʈ����ũ�� �̿��Ͽ� �� ������ Ǯ �� �־���.
// ��Ʈ����ũ ���� 2 ���ϸ� ��ĭ�� �ڷ� �з����� 2�� ������ ��ĭ�� ������ ������� ����
// �̿��ϸ� �Ǵ� ���̴�.

int N, M;
string train[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        train[i] = "00000000000000000000";
    for (int i = 0; i < M; ++i)
    {
        int com, num, idx;
        cin >> com >> num;
        if (com < 3)
            cin >> idx;
        if (com == 1)
        {
            train[num - 1][idx - 1] = '1';
        }
        else if (com == 2)
        {
            train[num - 1][idx - 1] = '0';
        }
        else if (com == 3)
        {
            train[num - 1] = '0' + train[num - 1];
            train[num - 1].erase(train[num - 1].size() - 1, 1);
        }
        else
        {
            train[num - 1] += '0';
            train[num - 1].erase(0, 1);
        }
    }
    set<string> answer;
    for (int i = 0; i < N; ++i)
        if (answer.find(train[i]) == answer.end())
            answer.insert(train[i]);
    cout << answer.size() << '\n';
    return 0;
}