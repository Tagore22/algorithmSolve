#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �׽�Ʈ ���̽��� �ִ� 10�����̰�, �־����� �� N�� �ִ� 100���̱⿡ �ָԱ��������� Ǯ�� ������
// �ð� �ʰ��� ���� ��Ȳ�̴�. ���� �����佺�׳׽��� ü�� �̿��Ͽ� 0 ~ 100���� ����
// Ȧ�� �Ҽ����� ��ó���� Ȯ������, �־����� �� N�� 3 ~ 100������ ��ȸ�ϸ� �ڱ� �ڽŰ�
// N - �ڱ��ڽ��� ��� Ȧ�� �Ҽ��� ù��° ��Ȳ�� ����ϸ� �ȴ�.
// �� ���� ���̰� ���� Ŭ���̹Ƿ� ����Ͽ��� ù��°�� �������� �ٷ� ����ϸ� �ȴ�.

const int MAX_NUM = 1000000;
bool check[MAX_NUM + 1];
int num;

// Ȧ�� �Ҽ����� �̸� ��ó���ϴ� �Լ�.
void Era()
{
    memset(check, true, sizeof(check));
    check[0] = false;
    check[1] = false;

    for (int i = 2; i <= 1000; ++i)
        if (check[i])
            for (int j = i * i; j <= MAX_NUM; j += i)
                check[j] = false;

    // 2�� ������ ¦�� �Ҽ��̴�. �ݵ�� ����Ҽ� �������� �ٲپ�����Ѵ�.
    check[2] = false;
}

void MakeAnswer()
{
    Era();

    bool isfind;
    while (true)
    {
        cin >> num;
        if (num == 0)
            return;

        isfind = false;
        for (int i = 3; i < MAX_NUM; i += 2)
            // �ڱ��ڽ� i�� num - i ��ΰ� Ȧ�� �Ҽ��� ù��° ��Ȳ�� ����Ѵ�.
            if (check[i] && check[num - i])
            {
                cout << num << " = " << i << " + " << num - i << '\n';
                isfind = true;
                break;
            }
        // ã�� ���ߴٸ� ���ܸ� �����.
        if (!isfind)
            cout << "Goldbach's conjecture is wrong." << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}