#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int x, y, d, t;

void Calcul()
{
    double dist = sqrt(pow(x, 2) + pow(y, 2));
    double ans = dist; //�ִ� �Ÿ��� �׳� �ȱ�.
    int jump = dist / d; //�ִ� ��� ���� �Ҽ� �ִ°�
    dist -= jump * d;    //���� ���� ���� �Ÿ�

    if (jump == 0) // �����Ҽ� ������ �����
    {
        ans = min(ans, d - dist + t); //ù��° �񱳴���� �����Ҽ� �ִ� �Ÿ���ŭ �ڷ� ������ ������ ����.
        ans = min(ans, t * 2.0); //�ι�° ������ ��� �ι��� ������ ����.
    }
    else //���� �Ҽ� ������ �����
    {
        ans = min(ans, jump * t + dist); //������ ���� ���� ���� �Ÿ� �ȱ�
        ans = min(ans, static_cast<double>(jump + 1) * t); // ���� + 1���� ���� ������ ����.
    }

    cout << fixed;
    cout.precision(9);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> d >> t;
    Calcul();
    return 0;
}