#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// 2���� �Ǽ��� �־���.

// 1. string.substr()�� �Ű������� �ݺ��ڰ� �ƴ� int �����̴�. 2���� �����ε尡 �����Ͽ���. 
// int ������ �ϳ�¥���� ���ڿ��� �� ó������ n���� �̿��� �κй��ڿ��� ����� ���̰�,
// int ������ 2��¥���� n��° ���ں��� �����ؼ� m���� �̿��� �κй��ڿ��� ����� ���̴�.

// 2. stoi()�� �Ű������� string�� ���ڴ� �Ű������� ������ ����. char >> string������ ��ȯ��
// ���� �ʱ� �����̴�.

int main()
{
    string str;
    cin >> str;

    if (str.size() == 2)
    {
        cout << stoi(str.substr(0, 1)) + stoi(str.substr(1, 1)) << '\n';
    }
    else if (str.size() == 3)
    {
        if (str[1] == '0')
            cout << stoi(str.substr(0, 2)) + stoi(str.substr(2)) << '\n';
        else
            cout << stoi(str.substr(0, 1)) + stoi(str.substr(1)) << '\n';
    }
    else
    {
        cout << 20 << '\n';
    }
    return 0;
}