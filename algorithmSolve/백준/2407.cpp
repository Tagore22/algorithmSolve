#include <iostream>
#include <string>

//���� ũ�Ⱑ �ʹ� Ŀ�� long long���ε� �� ���� ���ϱ⿡ string�� ����ߴ�. �̻��� ������ �ð��� ���� ��ƸԾ��µ� �� ���ڿ��� ���ϴ�
//�Լ����� �� ���ڿ��� ���̸� ���߱� ���� ª�� �� �տ� ��� 0�� �����ش�. �� ���ڿ��� ũ�⸦ ���ذ��� �Ȱ����� ���� ��� �����ִµ�
//�̰��� �ʱ⿡ Asize, Bsize�� ��Ƴ��� �� ���� ������Ű�� ���� ä�� while���� ������ �� �ð��ʰ��� ���� ��� �����ϰ� �־���. �Ф�

using namespace std;

const int MAX_NUM = 100 + 1;
string board[MAX_NUM][MAX_NUM];
int n, m;

string AddStr(string a, string b)
{
    if (a.size() > b.size()) //������ Asize, Bsize �ΰ��� ������ ��â�� ���� ���� ��Ƴ��� while���� ������ �־���.
        while (a.size() != b.size())
            b = '0' + b;
    else
        while (a.size() != b.size())
            a = '0' + a;

    string add = "";
    int check = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        check += (a[i] - '0') + (b[i] - '0');
        add = to_string(check % 10) + add;

        check = check >= 10 ? 1 : 0; //�� ���ڿ��� ���� ���Ұ��� �������� 10�̻� �Ͻ� ���� ���۰��� 1�� ������.
    }

    if (check == 1) //������ �ڸ�(���ڿ����� �ε���0��)���� ������ 10�� �ʰ��Ұ�� �Ǿ��ڸ� 1�� �߰�.
        add = '1' + add;

    return add;
}

void MakeAnswer()
{
    board[0][0] = "1";
    board[1][0] = "1";
    board[1][1] = "1";

    for (int i = 2; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
        {
            if (i == j || j == 0) //n,m���� ���ų� m���� 0�̸� ����� ���� 1.
                board[i][j] = "1";
            else
                board[i][j] = AddStr(board[i - 1][j], board[i - 1][j - 1]);
        }

    cout << board[n][m] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}