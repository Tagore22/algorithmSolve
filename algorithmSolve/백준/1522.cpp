#include <iostream>

using namespace std;

// Ǯ��.
// ó���� b�� ��ġ�� �ű�� ���� �پ��ִ� b�� ������ �ִ� b�� ����ϴ� �� �ʹ� ��ư� �����ߴ�.
// ���� Ǯ�̴� �׳� �־��� ���ڿ��� �پ� �ִ� a���� ����� ���� �����̵� �������� ������ �̿��Ͽ�
// a�� �����鸸ŭ 2�� ��ȸ�Ͽ� b�� �ּҰ��� ���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    int ssize = str.size(), anum = 0;
    // a���� ������ ���Ѵ�.
    for (int i = 0; i < ssize; ++i)
        if (str[i] == 'a')
            ++anum;
    // ���� �迭ó�� �յڰ� ����Ǿ� �ִٰ� ������ ���õǾ� �ֱ⿡ ���ڿ��� �ι� �ݺ��Ͽ�
    // �����Ѵ�.
    str += str;

    int answer = 1000001;
    // �� ó������ ���������� ��ȸ�ϸ� a������ŭ�� ���̸� ���� �� ���ڿ��� b�� �����ϴ� �ּҰ��� ���Ѵ�.
    for (int i = 0; i < ssize; ++i)
    {
        int bnum = 0;
        for (int j = 0; j < anum; ++j)
        {
            if (str[i + j] == 'b')
                ++bnum;
        }
        answer = min(answer, bnum);
    }

    cout << answer << '\n';
    return 0;
}