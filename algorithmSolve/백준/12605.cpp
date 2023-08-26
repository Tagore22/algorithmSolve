#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// �ϳ��� ���ڿ����� ������ ���������� �ܾ ����ϸ� �ȴ�.
// ���� �ִ� ���ڿ��� �Է¹ޱ� ���� getline()�� ����Ͽ��µ� �� �Լ����� �����ؾ������� �ϳ� �ִ�.
// �ٷ� ������� ���� ���鸶�� �Է¹޴´ٴ� ���̴�. ���� ��� �������� ó�� N�� �Է��ϰ� �Ǿ�
// 3�� �Է��� ���͸� ġ�� �� ���Ͱ� �Է½�Ʈ���� �� �ִ´�. ���� getline()�� ȣ���ϸ� �� ���Ͱ�
// ����ǰ� �ȴ�. �̰��� �ذ��ϱ� ���� ����� 2������ �ִ�.

// 1. getline()�� �ٽ� ȣ���Ͽ� ������ ���͸� ������ä ���� �Է¹޴´�.
// 2. cin.ignore()�� ȣ���Ͽ� ���� �Է½�Ʈ�� �ȿ� �ִ� �͵��� �����Ѵ�.

// �� �ص� ����� ������ cin.ignore()�� �� ������.

// �ڼ��� ������ �ּ����� �����.

string str;
int N;

void MakeAnswer()
{
    for (int iter = 0; iter < N; ++iter)
    {
        getline(cin, str);
        int ssize = str.size();
        int space = ssize;
        cout << "Case #" << iter + 1 << ": ";
        // ��� ���ڸ� ��ȸ�ϸ� ������ �������� ���� ������ �ܾ ����Ѵ�.
        for (int i = ssize - 1; i >= 0; --i)
        {
            if (str[i] == ' ')
            {
                for (int j = i + 1; j < space; ++j)
                    cout << str[j];
                cout << ' ';
                space = i;
            }
        }
        // ������ �ܾ ����Ѵ�.
        for (int i = 0; i < space; ++i)
            cout << str[i];
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin.ignore();
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}