#include <iostream>

using namespace std;

// Ǯ��.
// ������ ������. ���� ���� ���ϴ� ģ���� ���� �� ������ ���� �ʰ� ��ϴ� ģ���� ��� ��
// ������ �ȴ�. ó���� �Է¹��� ������ �����Ͽ� �����Ͽ�����, ���� �׷� �ʿ� ���� �Է� �ܰ迡��
// ���� ���� �� �ð��� ���� ���� � �ð��� ���ϸ� �ȴ�.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, s = 0, e = 100001;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int from, to;
        cin >> from >> to;
        s = max(s, from);
        e = min(e, to);
    }
    int answer = s - e <= 0 ? 0 : s - e;
    cout << answer << '\n';
    return 0;
}