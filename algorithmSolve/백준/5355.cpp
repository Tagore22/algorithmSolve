#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// ������ ���� Ȥ�� �Ҽ����Ŀ� �ִ� 3���� �����ڰ� �־����µ� 1 ~ 3���� �����̱⿡ �ƿ� ���� ��ü�� �� �Է¹ޱ� ���ؼ�
// getline()�� ����Ͽ��� �ߴ�. �� ���� �� ó�� ���� float�� ĳ�����Ͽ� ������ �����ڸ� ó���ߴ�.
// ������ C���� ����ϴ� ���� �� �����ϰ� ������ ���� �ڵ��� ������ �𸣰ڴ�.

// P.S getline()���� ���� �ظ��ؼ� cin.ignore()�� ����Դµ� �̹����� �׷���. ������ �Ѱ��� �Ǽ��� �־��µ�
// cin.ignore()�� �� ��� �����ϴ� ��Ⱑ �Ǿ���. cin.ignore()�� �Ű������� �������� ������ ������ ���빰 1���� ����� �Լ���.
// �ٸ� �̹� ���۰� �������� ��쿡�� �� ���� ������ �Է°��� �� ù��°���� ����� ���� ������ �ȴ�. �׷��� cin.ignore()��
// ù��° for���� �����ϴ� getline()���� �����ϸ� �� �Ŀ� �Է¹޴� ���� �� ù��°���� ������ä�� �ԷµǴ� ���̾���.
// �� �˾Ƶ���.

string str;
int T;

void MakeAnswer()
{
    cout.precision(2);
    cout << fixed;
    cin.ignore();
    for (int iter = 0; iter < T; ++iter)
    {
        getline(cin, str);
        int pivot = 0;
        for (int i = 0; i < str.size(); ++i)
            if (str[i] == ' ')
            {
                pivot = i;
                break;
            }
        float answer = stof(str.substr(0, pivot));
        for (int i = pivot + 1; i < str.size(); ++i)
        {
            if (str[i] == '@')
                answer *= 3;
            else if (str[i] == '%')
                answer += 5;
            else if (str[i] == '#')
                answer -= 7;
        }
        cout << answer << '\n';
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