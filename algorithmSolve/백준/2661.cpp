#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// ���� ��ü�� �׸� ����� �ʴ�. ��� ������ ���� ���� ���� ���� ���� ������ ����ϸ� �ȴ�.
// ��Ʈ��ŷ�� �̿��ؼ� ��� ������ ����� ���� ���� ������ �����ϴ� �Լ��� �����ϴ� ���̴�.
// �ٸ� �Ѱ��� �Ǽ��� �ߴµ� ó������ ������ ���� ����� ���� ���� ������ ã������ �ߴ�.
// �������� �־����� ������ ���̴� �ִ� 80�̱⿡ ��� ������ ������� 3�� 80�����̶�� ū ���귮�� �ʿ�� �ϴµ�
// ������ ����� ���� �������� Ȯ���� �Ϸ��� �� ���� ���� Ȯ���ؾ��Ѵ�.
// ���� �̸� ����ġ�� ������� ���� �ϳ��� �߰��ϸ鼭 ���� �����鸸�� ������ ���� ��Ʈ��ŷ���� �Ѱܾ� �ߴ�.

// �ڼ��� ������ �ּ����� �����.

int N;
bool isfind = false;

// ���� �������� Ȯ���ϴ� �Լ�.
bool CheckArray(const string& str)
{
    int size = str.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            int len = j - i;
            if (str.substr(i, len) == str.substr(j, len))
                return false;
        }
    }
    return true;
}
// ��Ʈ��ŷ�� �����ϴ� �Լ�.
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