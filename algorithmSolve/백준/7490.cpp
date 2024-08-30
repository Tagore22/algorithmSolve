#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// �⺻�� ����� �������鼭 ������ ��������. �Ƹ��� ���ڿ����� �������� ��ȯ������ Ȯ���ϰ��� �ϴ�
// ���������� �ʹ�. ���� ��ü�� �׸� ����� �ʴ�. �����Ҽ� �ִ� ��� ��ȣ���� �����Ͽ� N���� �����Ͽ�����
// ��ȭ���� ���� 0�̸� ��ȭ���� ����ϴ� ���̴�. �ٸ�, ���� ���ļ����� ����ؾ� �ϱ� ������ ����, +, - ������
// �����ؾ��Ѵ�. ����, �� ��ȭ���� ����ϴ°��� �ſ� �����ߴ�. ��... �ѹ��� �¾Ƽ� �����̴�.

// �ڼ��� ������ �ּ����� �����.

int T, N;

// ���� ��ȭ���� ����� �ϴ� �Լ�.
bool IsZero(string str)
{
    int first = 0, second = 0, sum = 0;
    char sign;
    bool isfind = false;
    // ��� ���ڵ��� ��ȸ�Ѵ�.
    for (int i = 0; i < str.size(); ++i)
    {
        // ���� ���ڰ� ��ȣ�϶�.
        if (str[i] == '+' || str[i] == '-')
        {
            // ù��°�� ���� ��ȣ��� ��ȣ�� ����ϰ� isfind�� �� ���� ��ȣ��
            // �ι�°�� ���� ���� �����Ѵ�.
            if (!isfind)
            {
                isfind = true;
                sign = str[i];
            }
            // �ι�°�� ���� ��ȣ��� ���������� ����ϰ� �Ѿ�� �Ѵ�.
            else
            {
                // ���� ��ȣ�� ���� ��갪�� �ٲ��.
                if (sign == '+')
                    sum = first + second;
                else
                    sum = first - second;
                // ���±����� ������ ù��° ���� �ȴ�.
                first = sum;
                // �ι�°���� 0���� �ʱ�ȭ���ش�.
                second = 0;
                // ��ȣ�� ����.
                sign = str[i];
            }
        }
        // ���� ���ڰ� �����̶�� �����Ѵ�. ������ �������� ���ڸ� ������� �˾Ƽ�
        // �̾����� �����Ǿ��� �����̴�.
        else if (str[i] == ' ')
        {
            continue;
        }
        else
        {
            // ���� ��ȣ�� ������ ������ ��� ù��° ���� �����Ѵ�.
            if (!isfind)
            {
                first *= 10;
                // ���� �� �κе� �߿��ߴ�. stoi()�� char���� ���������� �ƽ�Ű���� ��ȯ�Ǿ���.
                first += stoi(to_string(str[i])) - 48;
            }
            // ��ȣ�� ������ ��� �ι�° ���� �����Ѵ�.
            else
            {
                second *= 10;
                second += stoi(to_string(str[i])) - 48;
            }
        }
    }
    // �ָԱ��������� Ǯ����� ������ �˼� ������ �� ���������� first, second, ��ȣ�� ������ä
    // ���� sum���� ������ ����ä�� ������ �ȴ�. ���� �� �������� �ѹ� �� ����Ѵ�.
    if (!isfind)
        return false;
    if (sign == '+')
        sum = first + second;
    else
        sum = first - second;
    return sum == 0;
}

// ��� ��츦 �����غ��� �Լ�.
void FindAnswer(int idx, string str)
{
    // idx�� �� �������� �������� ��� ��ȭ���� ���� ����غ���.
    if (idx == N)
    {
        if (IsZero(str))
            cout << str << '\n';
        return;
    }

    // ����Ͽ��� ���� ���ļ����� ����ؾ��ϱ� ������ ����, +, - ������ �����غ���.
    FindAnswer(idx + 1, str + " " + to_string(idx + 1));
    FindAnswer(idx + 1, str + "+" + to_string(idx + 1));
    FindAnswer(idx + 1, str + "-" + to_string(idx + 1));
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;

        FindAnswer(1, "1");
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}