#include <iostream>

using namespace std;

// Ǯ��.
// (�־��� �Ѱ� - 1 ~ 9��° å�� ��)�� ���ϸ� ������ 10��° å�� ������ �˼��ִ�. 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int sum, cur = 0;
    cin >> sum;
    for (int i = 0; i < 9; ++i)
    {
        int num;
        cin >> num;
        cur += num;
    }
    cout << sum - cur << '\n';
    return 0;
}