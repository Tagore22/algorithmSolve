#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �� ���ڿ����� �κ� ���ڿ��� ã�� �����̱⿡ string::find()�� ���÷����� 
// find()�� �ð����⵵�� �ִ� O(nm)�̾���, �������� �־����� ���ڿ��� ���� �ִ� 100���� ���̸�
// ������ �־��⿡ �Ұ����ߴ�. strstr�� O(n + m)���� �����Ǿ� �־��� �����Ҽ� �־���. �� ����ص���.

int main()
{
    string s, p;
    cin >> s >> p;
    cout << (strstr(s.c_str(), p.c_str()) == nullptr ? 0 : 1) << '\n';
    return 0;
}