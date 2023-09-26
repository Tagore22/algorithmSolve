#include <iostream>
#include <string>

using namespace std;

// 2661���� ���ݴ� ���� Ǯ��.
// ���� �Լ��� Ȯ���ϴ� �Լ��� ���ݴ� �����غ� ����̴�.
// �������� ��� ���Ҹ� ��ȸ�ϸ� �� ���� ���Ŀ� ���� ���Ұ� �����Ѵٸ�
// �κ� ������ Ȯ���غ��� �����̾��ٸ� �̹����� �ڿ��� �Ѱ��� �߰��ϴ� ����̱⿡
// ���ڿ��� ũ�� / 2������ Ȯ���غ��� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int N;
bool isfind = false;

// ���� �������� Ȯ���ϴ� �Լ�. �ִ� ���ڿ��� ũ�� / 2������ Ȯ���ϸ�
// �ڿ������� 1 ~ ���ڿ��� ũ�� / 2������ Ȯ���� ������.
bool CheckArray(const string& str)
{
    int limit = str.size() / 2;
    for (int i = 1; i <= limit; ++i)
    {
        int from = str.size() - i;
        int to = from - i;
        if (str.substr(from, i) == str.substr(to, i))
            return false;
    }
    return true;
}

void BackTrack(const string str)
{
    if (isfind)
        return;

    if (str.size() == N)
    {
        cout << str << '\n';
        isfind = true;
        return;
    }

    for (int i = 1; i <= 3; ++i)
    {
        string next = str + to_string(i);
        if (CheckArray(next))
            BackTrack(next);
    }
}

void MakeAnswer()
{
    BackTrack(string(""));
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}