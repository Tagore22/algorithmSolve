#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// 4���� ���ڿ� s1, s2, s3, s4�� �־����� ���� s1�� s2, s3�� s4�� ������
// �� ���ڿ��� long longŸ������ ��ȯ�Ͽ� ���� ����Ѵ�.
// �� ���ڿ����� �ִ� 100���� ���������� int�� ��ȯ�� �����÷ο찡 �߻��ϱ� ������
// int�� �ƴ� long long���� ��ȯ�Ͽ��� �Ѵ�.

int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    cout << stol(s1 + s2) + stol(s3 + s4) << '\n';
    return 0;
}