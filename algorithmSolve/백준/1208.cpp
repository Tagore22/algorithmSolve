#include <iostream>
#include <map>

using namespace std;

//N�� �ִ� 40�̹Ƿ� �ð����⵵�� 2�� 40������ �Ǿ� �ð����� �� Ǯ���� ����.
//�׷��� ������ �������� ������ 2�� 20���� * 2�� �ɸ��� �ð��� ���δ�.
//�߿��� �κ��� �Ʒ� �ּ�ó�� �� ���ε� �κм����̶� ���� �ּ� �Ѱ��� ���Ҹ� ������ �־�� �Ѵ�.
//������ �ʱⰪ�� 0�̱⿡ S�� 0�϶� ���� �κ� ������ ������ �κ� �������� ���� �ƹ� ���ҵ� ������ ������
//���� ���յǱ⿡ �� �κ��� ����� �Ѵ�.

map<int, int> sum_list;
int board[40];
int N, S;
long long answer = 0;

void LeftSide(int idx, int sum)
{
    if (idx == N / 2)
    {
        answer += sum_list[S - sum];
        return;
    }
    LeftSide(idx + 1, sum);
    LeftSide(idx + 1, sum + board[idx]);
}

void RightSide(int idx, int sum)
{
    if (idx == N)
    {
        ++sum_list[sum];
        return;
    }
    RightSide(idx + 1, sum);
    RightSide(idx + 1, sum + board[idx]);
}

void MakeAnswer()
{
    RightSide(N / 2, 0);
    LeftSide(0, 0);
    answer = S == 0 ? answer - 1 : answer; //S�� 0�̸� LeftSide, RightSide���� ���� �ƹ� ���ҵ� ������ �ʾ����� sum_list[0]�� 1�� �߰��� ���� 
    cout << answer << '\n';                //�׷��� �κ� ������ �ִ� �Ѱ��̻��� ���Ҹ� ����� ������ ���ԵǾ�� �ȵȴ�.
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}