#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���ڿ����� ������ �ƴ� �ܾ���� ������ ������ ����ϴ� ������.
// ������� ��� �Է¹޾ƾ��ϱ⿡ <string>�� getline()�� ����ϸ� ������
// �Ѱ��� ������ �߻��Ѵ�. �׽�Ʈ���̽��� �Է¹����� �� �ٲ� �Է±��� �ް� �Ǵµ�
// �ٷ� getline()�� ����ϸ� �� �� �ٲ� �Է��� ���� �Է½�Ʈ���� ���� �־�
// �װ��� �Է¹޴� ���̴�. ���� �׽�Ʈ���̽� �Է� ���Ŀ� �Է½�Ʈ���� ���� ����
// �ǹ̾��� getline() Ȥ�� cin.ignore()���� �̸� ó�����־�� �Ѵ�.
// ����� cin.ignore()�� �ܼ� �Է½�Ʈ���� ���⸸ �ϴ°��̱⿡ �� ������.

// �ڼ��� ������ �ּ����� �����.

string str;
int T;

void ReverseStr()
{
    int from = 0;
    int Ssize = str.size();
    for (int i = 0; i < Ssize; ++i)
    {
        if (str[i] == ' ')
        {
            reverse(str.begin() + from, str.begin() + i);
            from = i + 1;
        }
    }
    // ���� ������ ������ �� for���� �ƿ� �õ����� ���� �ʴ´�. ���� �� ������ ó���� �ʿ��ϴ�.
    reverse(str.begin() + from, str.end());
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        getline(cin, str);
        ReverseStr();

        cout << str << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    // �� ����� �׽�Ʈ���̽��� �Է¹������� �� �ٲ� �Է��� ����ִ� �ܰ�.
    // getline()�̵�, cin.ignore()�� ����� ������ ���ڰ� �� ������.
    getline(cin, str);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}