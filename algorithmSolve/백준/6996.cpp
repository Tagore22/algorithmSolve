#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �� ���ڿ��� ���ʱ׷����� Ȯ���ϴ� �����̴�.
// �� ���ڿ��� �����ϴ� �ܾ���� �ľ��ϸ� �Ǵµ� �������� Ǯ�̰� �����Ѵ�.
// �� ���ڿ��� ��ȸ�ϸ� �����ϴ� ���ڵ��� ���� �ľ��ص� �ǰ�, �Ʒ� Ǯ��ó�� �����Ͽ� ������
// Ȯ���ص� �ȴ�. �ٸ� ���� �����ϴ°� �� ���ؼ� �̷��� �Ͽ���.

// �ڼ��� ������ �ּ����� �����.


// from�� to�� ���� �� ���ڿ��� ���ʱ׷� ���ο� ���Ǵµ� ������ ���ڿ��� �ʿ��Ҷ� ���δ�.
string str1, str2, from, to;
int T;

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        cin >> str1 >> str2;

        from = str1;
        to = str2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        // �� ���ڿ��� ���� ����� ���ٸ� ���ʱ׷�, �׷��� �ʴٸ� ���ʱ׷��� �ƴϴ�.
        if (str1 == str2)
            cout << from << " & " << to << " are anagrams." << '\n';
        else
            cout << from << " & " << to << " are NOT anagrams." << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}