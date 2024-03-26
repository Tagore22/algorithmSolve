#include <iostream>
#include <map>

using namespace std;

// Ǯ��.
// �־����� Ȯ���ڵ�� �� ������ �����Ͽ� ���������� ����ϴ� �����̴�.
// map�� ���°� ���ϱ� ������ ���� ���� ������. Ȯ���ڵ��� vector�� ��� �����س���
// �����Ͽ� Ȯ���ڿ� ������ ����ϴ� ��� ���� �����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

map<string, int> board;
int N;

void MakeAnswer()
{
    for (int iter = 0; iter < N; ++iter)
    {
        string str;
        cin >> str;
        int from = 0;
        // Ȯ���ڰ� ���۵Ǵ� �ε������� ã�´�.
        for (int i = 0; i < str.size(); ++i)
            if (str[i] == '.')
            {
                from = i;
                break;
            }
        // Ȯ������ ������ map���� 1 �÷��ش�.
        ++board[str.substr(from + 1)];
    }
    // map�� ��ȸ�ϸ� Ȯ���ڿ� �� ������ ����Ѵ�.
    for (auto iter = board.begin(); iter != board.end(); ++iter)
        cout << iter->first << ' ' << iter->second << '\n';
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