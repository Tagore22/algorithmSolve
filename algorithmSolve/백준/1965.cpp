#include <iostream>

using namespace std;

//Ǯ��
//0��° ���Һ��� idx-1���� ��ȸ�ϸ� idx���� ������ ������ �ִ� ���ڰ� ���� ���� �� now�� ã���� idx�� ������ �ִ� �ִ� ���ڰ��� now+1�� �ȴ�.
//�̰� 1��° ���Һ��� ��� ��ȸ�Ͽ� �� ���Һ� �ִ밪�� ã��, ���������� �ٽ� ��� ���Ҹ� ��ȸ�Ͽ� ���� ���� ū �ִ밪�� ã�� ����Ѵ�.
//���귮�� 1~999�̹Ƿ� 49�� ���� �ȴ�.

int board[1000], cashe[1000];
int n;

void MakeAnswer()
{
    cashe[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        int now = 0;
        for (int j = 0; j < i; ++j)
            if (board[j] < board[i] && cashe[j] > now)
                now = cashe[j];
        cashe[i] = now + 1;
    }

    int answer = 0;
    for (int i = 0; i < n; ++i)
        answer = max(answer, cashe[i]);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}