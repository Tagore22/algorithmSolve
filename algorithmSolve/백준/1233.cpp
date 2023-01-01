#include <iostream>
#include <cstring>

using namespace std;

//Ǯ��
//�� ���� �յ��� ��� ������ �̸� ����Ѵ�. �� 3���� ������ �տ� ���� ���Ұ��� 1�� �������Ѱ��� ����Ѵ�.
//�� �� �յ��� ���� �迭���� ��ȸ�ϸ� ���� ��찡 ũ��, ���� ���� ���� ���� ã�� ����Ѵ�.
//3���� ���� �ִ� ũ�Ⱑ ���� 20, 20, 40�̸�, ��� ���� 16000�� �ش��Ѵ�. �׷��⿡ �ƹ��� ���Ƶ�
//���귮�� 16000 + 16000���� �ð����� ����� ��갡���ϴ�.

//P.S board�� ĭ�� ���� 16000�� �ʿ䰡 ����. 3���� ���� ���� �ִ�ũ��� �ᱹ 20 + 20 + 40�̱⿡ 81���ε� ����ϴ�.

int board[81];
int s1, s2, s3;

void Init()
{
    for (int i = 1; i <= s1; ++i)
        for (int j = 1; j <= s2; ++j)
            for (int k = 1; k <= s3; ++k)
                ++board[i + j + k];
}

void MakeAnswer()
{
    Init();

    int sum = 0;
    int answer;
    for (int i = 0; i <= s1 + s2 + s3; ++i)
        if (sum < board[i])
        {
            sum = board[i];
            answer = i;
        }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, 0, sizeof(board));

    cin >> s1 >> s2 >> s3;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}