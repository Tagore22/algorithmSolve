#include <iostream>
#include <set>

using namespace std;

// Ǯ��.
// �ָԱ�����(?) Ǯ��. set�� A �迭�� ����ְ� �ٽ� B �迭��ŭ�� �����Ѵ�. �� ���� �����ִ�
// ������ ����Ѵ�. �ٸ� ���� �����̳ʸ� ����ϴ¸�ŭ �ſ� ���ȴ�.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n1, n2;
    cin >> n1 >> n2;
    set<int> board;
    int num;
    for (int i = 0; i < n1; ++i)
    {
        cin >> num;
        board.insert(num);
    }
    for (int i = 0; i < n2; ++i)
    {
        cin >> num;
        board.erase(num);
    }
    cout << board.size() << '\n';
    for (auto& ans : board)
        cout << ans << ' ';
    cout << '\n';
    return 0;
}