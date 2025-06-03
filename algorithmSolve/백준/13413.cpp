#include <iostream>
#include <cmath>

using namespace std;

// Ǯ��.
// ó�� ������ �����鼭 ������ ������ ��Ʈ��ŷ ���� ���� �����غ��� ������ ����������
// ���ڿ��� ���̰� �ִ� 10���̶�� �� ���� �����ߴ�. ��������� ��ȭ���� �ϳ� �����س´µ�
// ������ ����.

// (�� ���ڿ��� ���̼�(X��� Ī��) - B Ȥ�� W�� ������ ���̼�(Y��� Ī��)) / 2 + B Ȥ�� W�� ������ ���̼�

// �� ���ڿ��� �ѹ��� ��ȸ�ϸ� X�� �� ���ڿ��� B�� ������ ���� �� abs()�� ���� B�� ���̼��� Y��
// ���� �� �ִ�. �� ���� ���� ��ȭ���� �̿��ϸ� O(N)���� ���� ���� �� �ִ�.

// �ڼ��� ������ �ּ����� �����.

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        int ssize;
        string from, to;
        cin >> ssize >> from >> to;

        // ���� �� ���ڿ��� ���̼�, �ʱ� ���ڿ��� B�� ����, ��ǥ ���ڿ��� B�� ����
        int dif = 0, fromB = 0, toB = 0;
        for (int i = 0; i < ssize; ++i)
        {
            dif = from[i] != to[i] ? dif + 1 : dif;
            fromB = from[i] == 'B' ? fromB + 1 : fromB;
            toB = to[i] == 'B' ? toB + 1 : toB;
        }
        // abs()�� ���� �� ���ڿ��� B�� ���̼��� ���Ѵ�.
        // �� ���ڿ��� ��� ���ڿ����� B�� �� ������ �� �� ���⿡ abs()�� ����ߴ�.
        int difB = abs(fromB - toB);
        // ����� ��ȭ���� �̿��Ͽ� ���� ���س���.
        cout << (dif - difB) / 2 + difB << '\n';
    }
    return 0;
}