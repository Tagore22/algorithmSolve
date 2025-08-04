#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// Ǯ��.
// �� �� �ƴ� ������ �Ѱ��� ū �Ǽ��� �ؼ� �ð��� ��µ�, distance�� �̿���
// �� ������ �Ÿ��� ���ϴ� �κ��� �׷��ϴ�. �ڷ� �������� �л����� ����
// ������ ��ġ�κ��� �� ���������� ��� �л����� ���̱⿡ distance��
// �� ������ ������ ��ġ, �� ������ end()�ε� �Ųٷ� �� �տ��� ������
// ��ġ�� ���� answer�� ���ϰ� �־���.

// �ڼ��� ������ �ּ����� �����.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        int num, answer = 0;
        cin >> num;
        // ���ĵ� �л����� ��ġ�� �����ϴ� set.
        set<int> board;
        for (int i = 0; i < 20; ++i)
        {
            int cur;
            cin >> cur;

            // ���� �л��� ������ ��ġ�� ���ϰ� �� ��ġ���� �� ������������ �л����� 
            // ������ answer�� ���� �� set�� �߰��Ѵ�.
            answer += distance(upper_bound(board.begin(), board.end(), cur), board.end());
            board.insert(cur);
        }
        cout << num << ' ' << answer << '\n';
    }
    return 0;
}