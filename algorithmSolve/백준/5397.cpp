#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���ڿ��� �Է¹޾� �� ���ǿ� ���� ������ ���ڿ��� ����ϴ� ������.
// �� ������ ������ ����.

// 1. ���� ��ġ�� ����Ű�� Ŀ���� �����Ѵ�.
// 2. ���ڿ��� ���� ���ڰ� �빮��, �ҹ���, ���ڶ�� Ŀ�� ��ġ�� �߰��Ѵ�.
// 3. ȭ��ǥ��� < �϶��� Ŀ���� 1 �������� > �̶�� 1 ���������� �̵���Ų��.
// 4. - �̶�� ���� Ŀ�� ��ġ �ٷ� �� ���ڸ� �����.

// �ش� ���ǵ��� ������ �ϸ� �ȴ�. ó������ string �������� Ǯ���µ�
// �ð� �ʰ� ����. �ش� Ǯ�̸� ���� �˰����� to_string�̳� substr�� ��ȯ �Լ����� �ִµ�
// �Ź� �Է¹޴� ���ڿ��� ���̰� 100���� �����ϱ⿡ �ð��ʰ��� ���� ����.

// �ᱹ���� �������� Ǯ���µ� �� �����ϰ� Ǯ���� ����.

// �ڼ��� ������ �ּ����� �����.

int T;

void MakeAnswer()
{
    string str;
    // Ŀ���� �������� �հ� �ڿ� �ش��ϴ� ���õ�.
    stack<char> board, temp;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> str;
        // �Է¹��� ���ڿ��� ��ȸ�ϸ� ���� ���ڿ��� ����Ѵ�.
        for (int i = 0; i < str.size(); ++i)
        {
            // '<'�϶��� Ŀ���� �������� �̵���Ű�µ� �̰��� Ŀ���� ���ڸ� Ŀ�� �ڷ� �̵���Ű�°Ͱ� ����.
            // ���� Ŀ�� ���� ������� �ʴٸ� Ŀ�� �� ������ �� �� ���ڸ� Ŀ�� �� �������� �ű�� �ȴ�.
            if (str[i] == '<')
            {
                if (!board.empty())
                {
                    char here = board.top();
                    board.pop();
                    temp.push(here);
                }
            }
            // '>'�϶��� �ݴ�� Ŀ�� �� ���ڸ� Ŀ�� ������ �ű�°Ͱ� ����.
            else if (str[i] == '>')
            {
                if (!temp.empty())
                {
                    char here = temp.top();
                    temp.pop();
                    board.push(here);
                }
            }
            // '-'�� Ŀ���� �ٷ� �� ���ڸ� ����� ���̱⿡ Ŀ�� �� ������ ���� �� ���ڸ� ����������.
            else if (str[i] == '-')
            {
                if (!board.empty())
                    board.pop();
            }
            // �������� ��� �빮��, �ҹ���, �����̱⿡ ���� Ŀ�� �� ���ÿ� ����ִ´�.
            else
            {
                board.push(str[i]);
            }
        }
        // Ŀ�� �� ������ ���������� �ֱ⿡ ��� Ŀ�� �� �������� �Ű��ش�.
        while (!temp.empty())
        {
            char here = temp.top();
            temp.pop();
            board.push(here);
        }
        // ���� ������ answer�� ��� �ű��� ���������� �Ű����⿡ ������ �� ����Ѵ�.
        // ���⼭ �� ��� ���� board�� temp�� ���� ��Ƶ� ������ �ӵ����̴� ũ�� �ʾҴ�.
        string answer = "";
        while (!board.empty())
        {
            answer += board.top();
            board.pop();
        }
        reverse(answer.begin(), answer.end());
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