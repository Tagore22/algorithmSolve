#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// cin.ignore()�� getline()�� �˾ƾ� �ϴ� �����̴�. cin >> ���� �Է¹��������� ���๮�ڸ� ������,
// getline()�� ���๮�ڱ��� ��� �Է¹޴´�. ���� cin >> ���� �Է¹����Ŀ� �ٷ� getline()�� ȣ���ϸ�
// �Է¹��ۿ� �����ִ� ���๮�ڸ� getline()�� �Է¹ް� �ٷ� ���������� ������ ����� �� ���� ������ �ʴ´�.
// ���� �� �߰��� cin.ignore()�� ȣ���Ͽ� ���๮�ڸ� ���־��Ѵ�. �ٸ� ����Ͽ��� getline()�� ���๮�ڱ���
// ��� �Է¹ޱ� ������ getline()�� �ݺ��Ǵ� ���̿� cin.ignore()�� ȣ��Ǹ� ������ ���� �Է¹��� ���ڿ��� �Ǿ���
// �����ϱ� ������ ���ǰ� �ʿ��ϴ�.

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 1; i <= N; ++i)
    {
        string str;
        getline(cin, str);
        cout << i << ". " << str << '\n';
    }
    return 0;
}