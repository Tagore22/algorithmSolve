#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// �ΰ��� �Ǽ� �ƴ� �Ǽ��� �ߴµ� ù°�δ� �־����� ���� ���ڸ��϶����� ��ȯ�� �Ͼ�� �ʴ´�.
// �ִ� 100���ڸ��� ���� �Է¹ޱ⿡ string Ÿ���� �̿��Ͽ��µ� ��� �����̵� int���� ��ȯ��
// �Ͼ�⿡ �Ǽ��ߴ�. �ι�°�� ios::sync_with_stdio(false)�� �ؾ���. ���ڿ� �ϳ��̱� ������
// �����ߴµ� ����ߵ� �ִ� 100���ڸ� �Է��� �޴´�.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    if (str.size() == 1)
    {
        int cur = str[0] - '0';
        cout << 0 << '\n';
        cout << ((cur % 3 == 0) ? "YES" : "NO") << '\n';
        return 0;
    }
    int answer = 0, cur;
    while (true)
    {
        ++answer;
        int ssize = str.size();
        cur = 0;
        for (int i = 0; i < ssize; ++i)
            cur += str[i] - '0';
        if (cur < 10)
            break;
        str = to_string(cur);
    }
    cout << answer << '\n';
    cout << ((cur % 3 == 0) ? "YES" : "NO") << '\n';
    return 0;
}