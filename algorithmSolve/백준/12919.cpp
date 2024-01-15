#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �־��� ��Ģ�� ���� a�� b�� ��ȯ�� ���������� ã�� �����̴�.
// b�� ���̰� �ִ� 50�̱� ������ a�� 1�̶�� 1���� 2�� ������ ��� Ž���ҽ�
// �ִ� 2�� 50������ ���귮�� �ʿ�� �ϱ� ������ �ð����� Ǯ�� ����.
// ���� �ݴ�� b���� a�� �ٿ������ٸ� ���յ��� �ʴ� ���ǵ��� �ɷ�����
// ���귮�� ���ϼ� �ִ�.

// �ڼ��� ������ �ּ����� �����.

string a, b;
bool isFind = false;

void BackTrack(string& str)
{
    // �̹� ����� �ִٸ� �ٸ� ��� ��츦 �����Ѵ�.
    // ���⼭ 1�� ����ϰ� exit(0)���� Ż���ص� �����ϴ�.
    if (isFind)
        return;
    // ���� ���ڿ��� a�� ���̰� ������
    if (str.size() == a.size())
    {
        // ���� ���ٸ� ��ȯ����.
        if (str == a)
            isFind = true;
        return;
    }
    // �ǵڰ� A��� A�� �������� �� �������� ������.
    if (str[str.size() - 1] == 'A')
    {
        string temp(str.begin(), str.end() - 1);
        BackTrack(temp);
    }
    // �Ǿ��� B��� B�� ����� ������ �� �������� ������.
    if (str[0] == 'B')
    {
        string temp(str.begin() + 1, str.end());
        reverse(temp.begin(), temp.end());
        BackTrack(temp);
    }
}

void MakeAnswer()
{
    BackTrack(b);
    cout << (isFind ? 1 : 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}