#include <iostream>

using namespace std;

//�� ����.
//Ǭ����� 50�� �ȵǼ� ���� �̾Ҵ� ������. Ǯ�̵� ã���� �����״� �ƿ� ������ ����ϸ鼭 Ǯ����.

//Ǯ��
//ó������ �賶���� Ǯ�� ����ϰ� ����Ž���� ���������� 2�� 50������ ����� ���귮�� �ʿ�� �ϱ⿡ �ð��ʰ��� ����.
//�ϳ� ���� ����ߴµ� �ᱹ Ǯ�̴� �� ó�� ���Һ��� ��ȸ�ϸ� ���ʷ� �ִ밪 - �ּҰ��� V�̻��� �Ǵ� ���� from���� to������ �ּ� ��������
//���ϴ� ���̾���. �ٸ�, 1�� ������ ������ Ǯ��������Ƿ� 1�� �������� from������ �Ÿ����� �߰��� ������� �Ѵ�.


int board[50];
int N, V;

void MakeAnswer()
{
    int answer = N;
    for (int i = 0; i < N; ++i) //i�� from�� �Ǿ� ���̰� V�̻��� �Ǵ� ���Ұ��� ���� ������ Ž���Ѵ�.
    {
        int plus = i == 0 ? 1 : (i - 0 - 1) / 2 + 2; //1�� �������� from������ �ּ� ������
        for (int j = i; j < N; ++j) //to�� ã�´�.
            if (abs(board[i] - board[j]) >= V)
            {
                plus += (j - i - 1) / 2 + 1;
                answer = min(answer, plus);
                break; //���� from�� to�� ã�Ҵٸ� �����Ѵ�. �� ��ȸ�ص� plus���� ������ ���� ����.
            }
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> V;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}