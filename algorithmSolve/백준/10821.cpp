#include <iostream>

using namespace std;

// Ǯ��.
// �־����� ���ڿ��� ������ �������� �ʾ����Ƿ� getline()�� �ʿ䰡 ������.
// ���� �ϳ��� ���ڿ��� �Է¹޾����� �Ǿ���, �� ó���� �������� ���ڷ� Ȯ���Ǿ�����
// ���ڿ��� �����ϴ� �޸��� ���� Ȯ���Ͽ� + 1�� ����ϸ� �ȴ�.

int main()
{
    string str;
    cin >> str;
    int answer = 0;
    for (auto& c : str)
        if (c == ',')
            ++answer;
    cout << answer + 1 << '\n';
    return 0;
}