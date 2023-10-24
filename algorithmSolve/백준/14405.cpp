#include <iostream>

using namespace std;

// Ǯ��.
// ó������ set�� �̿��ұ ����������, �񱳵Ǵ� ���ڿ����� ª�� ���� ���� ������
// �׳� �ָԱ��������� �����ص� ����� ������. �ε����� 0���� �����Ͽ�
// ���� ���Ͽ� ���������� �´��� Ȯ���ϵ�, �߰��� ���� �ʴٸ� "NO"�� ����ϰ� Ż���ϸ� �ǰ�
// ������ �����Ͽ��ٸ� "YES"�� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

string str;

void MakeAnswer()
{
    int from = 0, to = str.size();
    while (from < to)
    {
        // ���� "pi"�� ���. 2ĭ �ǳʶڴ�.
        if (str[from] == 'p' && str[from + 1] == 'i')
        {
            from += 2;
        }
        // ���� "ka"�� ���. 2ĭ �ǳʶڴ�.
        else if (str[from] == 'k' && str[from + 1] == 'a')
        {
            from += 2;
        }
        // ���� "chu"�� ���. 3ĭ �ǳʶڴ�.
        else if (str[from] == 'c' && str[from + 1] == 'h' && str[from + 2] == 'u')
        {
            from += 3;
        }
        // �� �̿��� ���� ������ �Ұ����ϹǷ� "NO"�� ����� Ż���Ѵ�.
        else
        {
            cout << "NO" << '\n';
            return;
        }
    }
    // ���������� ��� �����Ҽ� �־����Ƿ� "YES"�� ����ϰ� Ż���Ѵ�.
    cout << "YES" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}