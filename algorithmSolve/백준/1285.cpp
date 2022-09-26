#include <iostream>

using namespace std;

//����Ž������ �� ��� �� ���� �����´� �ȵ����´ٸ� Ȯ���Ϸ��� 2�� 40�����̹Ƿ� 10���� ��½ �پ�Ѿ������.
//�׷��� ��Ʈ����ũ�� ��� ������ �����´ٴ� �����Ͽ� �� ���� ���������� ������ �ʾ������� T�� ������ Ȯ���Ͽ�
//���� �ּҰ��� ��ȯ�Ѵ�.
//��� ���� �����ؾ��ϱ⿡ 2�� 20������ �ʿ��ϸ� �� ������ N�� ������ŭ ���� ��ȸ�ϱ⿡ �ð����⵵��
//O(2^N * N^2)

string board[20];
int N;

//� ������ �̸� �������ٴ� �����Ͽ� ��� ���� ��ȸ�ϸ� �ش� ���� ������������ �������� �ʾ������� T�� ������ �ּҰ��� ��ȯ�Ѵ�.

int CalMinTail(int bit)
{
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        int tail_num = 0;
        for (int j = 0; j < N; ++j)
        {
            bool isTail = board[i][j] == 'T';
            if ((bit & (1 << j)) != 0)
                isTail ^= 1;
            if (isTail)
                ++tail_num;
        }
        ans += min(tail_num, N - tail_num);
    }
    return ans;
}

//bit�� 0���� N���� ��� 1�μ����� ���ԵǾ�����. �� ���� �������� �ȵ��������� ����

void MakeAnswer()
{
    int answer = 987654321;
    for (int i = 0; i < (1 << N); ++i) 
        answer = min(answer, CalMinTail(i));

    cout << answer << '\n';
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