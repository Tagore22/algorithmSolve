#include <iostream>

using namespace std;

int n;

void calcul(int num)
{
    for (int i = 0; i < num * 4; ++i)
        cout << "_";
    cout << "\"����Լ��� ������?\"" << '\n';
    if (num == n)
    {
        for (int i = 0; i < num * 4; ++i)
            cout << "_";
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
        for (int i = 0; i < num * 4; ++i)
            cout << "_";
        cout << "��� �亯�Ͽ���." << '\n';
        return;
    }
    for (int i = 0; i < num * 4; ++i)
        cout << "_";
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
    for (int i = 0; i < num * 4; ++i)
        cout << "_";
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
    for (int i = 0; i < num * 4; ++i)
        cout << "_";
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << '\n';
    calcul(num + 1);
    for (int i = 0; i < num * 4; ++i)
        cout << "_";
    cout << "��� �亯�Ͽ���." << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
    calcul(0);
    return 0;
}