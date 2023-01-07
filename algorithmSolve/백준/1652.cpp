#include <iostream>

using namespace std;

//Ǯ��
//���ο� ���η� string�迭�� ��ȸ�ϵ�, '.'�� �������� 2���̻� ������ ��츦 ��� ����.
//���������� '.'�� �������� 2���� ������ 3���� ������ 2�� �̻��̶�� ��� �Ѱ��� ������� ���� �ϱ� ������
//���� ������ �ξ Ȯ���ؾ��Ѵٴ� ���̴�.
//ex) ..x.. �� 2���� ����̸�, ....x�� �Ѱ��� ����̴�.

string board[100];
int N;

void MakeAnswer()
{
    pair<int, int> answer = make_pair(0, 0);
    int o;
    for (int i = 0; i < N; ++i)
    {
        o = 0;
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j] == '.')
            {
                ++o; // '.'�� �������� ��� ���������� ����.
                if (o == 2) //'.'�� �������� 2���̻� ���Դٸ� �װ� ��� �Ѱ��� ������� ����.
                    ++answer.first;
            }
            else
            {
                o = 0; //�������� ���� '.'�� ���� �ʱ�ȭ�Ѵ�.
            }
        }
    }

    for (int j = 0; j < N; ++j)
    {
        o = 0;
        for (int i = 0; i < N; ++i)
        {
            if (board[i][j] == '.')
            {
                ++o;
                if (o == 2)
                    ++answer.second;
            }
            else
            {
                o = 0;
            }
        }
    }

    cout << answer.first << ' ' << answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}