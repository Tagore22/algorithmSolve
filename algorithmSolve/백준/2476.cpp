#include <iostream>

using namespace std;

//�ڵ� ������ ���� �̸� �ϳ��� �ٲ����� �ʾƼ� ��ó���� ���� �ѹ� Ʋ�� ����. Ȯ���� ������

//Ǯ��
//���� 3���� �޾Ƽ� ���� ���� � �ִ����� ã�� ������. �ֻ����� 3�� �����⿡ ��������� 3���� Ȯ���ؾ��ϴµ�, �ڵ带 ����ϰ� �ϰ��� for���� ���. 
//3���� ���� ��� ���ٸ� ���� equal�� 3�� ���װ�, 2���� ���� ���ٸ� 1�� �ɰ��̴�. 2�� ����� �����Ҽ� ������ ��� �ٸ��ٸ� 0�� �ȴ�.
//�������� N���� ��� ����� �ְ� �ݾ��� ����ϸ� �ȴ�.

int dice[3];
int N;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        int equal = 0, check = 0, max_num = -1;

        for (int j = 0; j < 3; ++j)
        {
            cin >> dice[j];
            max_num = max(max_num, dice[j]);
        }

        for (int from = 0; from < 3; ++from)
            for (int to = from + 1; to < 3; ++to)
                if (dice[from] == dice[to])
                {
                    ++equal;
                    check = dice[from];
                }

        if (equal == 3)
            answer = max(answer, 10000 + check * 1000);
        else if (equal == 1)
            answer = max(answer, 1000 + check * 100);
        else
            answer = max(answer, max_num * 100);
    }
    cout << answer << '\n';
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