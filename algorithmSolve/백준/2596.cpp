#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// �� ���°� ���������� ������ �������� ����� ���� Ǫ�µ� 1�ð� ������ �ɷȴ�;
// ������ü�� ���ڿ��� 6���� ������ A ~ H���� �ι��̻� Ʋ���� �ʴ� ���ڿ��� �����ϴ��� Ȯ���ϴ� �����̴�.
// for���� ������ ¥�µ� �����ɷȴ�.

string board[8] = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };
string str;
int N;

int main()
{
    cin >> N >> str;
    string answer = "";
    bool isFind, isDiff;
    for (int iter = 0; iter < N; ++iter)
    {
        for (int i = 0; i < 8; ++i)
        {
            isDiff = false;
            isFind = true;
            for (int j = iter * 6; j < iter * 6 + 6; ++j)
            {
                if (str[j] != board[i][j - iter * 6])
                {
                    if (isDiff)
                    {
                        isFind = false;
                        break;
                    }
                    isDiff = true;
                }
            }
            if (isFind)
            {
                answer += 65 + i;
                break;
            }
        }
        if (!isFind)
        {
            answer = to_string(iter + 1);
            break;
        }
    }
    cout << answer << '\n';
    return 0;
}