#include <iostream>
#include <cmath>

using namespace std;

// 4779���� �� ���� Ǯ��.
// ó�� string�� ��� �������� ������ �� ��� ȣ��� ���̰� 1�� �����϶���
// �� �κ��� - ���� ��ü���ָ� �ȴ�. ���� string�� �ѹ��� ����Ѵ�.
// ��� �迭�� ���Ҹ� �ϳ��� ����ϴ� �ͺ��� string �迭�� �ѹ��� ����ϴ� ����
// �ξ� ������.

// �ڼ��� ������ �ּ����� �����.

string str;
int N;

// �ݺ��Ǵ� ��� �Լ�.
void MakeStr(int from, int to)
{
    // ���� ���̰� 1�̶�� ���� ���Ҹ� - �� �ٲٰ� Ż���Ѵ�.
    if (from == to)
    {
        str[from] = '-';
        return;
    }
    int size = (to - from + 1) / 3;
    // �պκа� �޺κи� �����Ѵ�. ��� �κ���
    // ��������� ���⿡ �����Ѵ�.
    MakeStr(from, from + size - 1);
    MakeStr(to - size + 1, to);
}

void MakeAnswer()
{
    while (cin >> N)
    {
        // �Ź� string�� �ʱ�ȭ���־�� �Ѵ�.
        str.clear();
        int num = pow(3, N);
        str.resize(num, ' ');
        MakeStr(0, num - 1);
        cout << str << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}