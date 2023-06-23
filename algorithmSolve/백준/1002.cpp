#include <iostream>

using namespace std;

// Ǯ��.
// ���� 1������ Ǯ���� �����ε� �������� ������ �̻��ϰ� �ٲپ �������� Ȯ������ �����̴�.
// ���� �������� ��������. �ٸ����� �� ��Ÿ��� r1, r2�� 0�϶��� ����ٴ� ���̴�.
// �� ���� ���� ���ǹ��� �߰����ָ� �Ǿ���. ���� ������ main���� �����ļ� �ڵ��ϴ� ��Ÿ���� ����
// ��û ����غ��δ�. �����ε� ���� ���ư�����.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testNum;
    cin >> testNum;
    for (int i = 0; i < testNum; ++i)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int dis = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        int case1 = (r1 - r2) * (r1 - r2);
        int case2 = (r1 + r2) * (r1 + r2);

        if (r1 == 0 && r2 == 0)
            cout << 1 << '\n';
        else if (dis == 0)
        {
            if (r1 == r2)
                cout << -1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (dis == case1 || dis == case2)
            cout << 1 << '\n';
        else if (dis > case1 && dis < case2)
            cout << 2 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}