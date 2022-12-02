#include <iostream>

using namespace std;

//�������� ��Ʈ��ŷ ������ �� �򰥸� ���� ���� �ʾ� �־���. ������ �� �츱��.

//Ǯ��
//���� Ư���� � ���Ҵ� ���ϰ� � ���Ҵ� �����ϴ� ������ ��� ����� ���� Ȯ���غ����Ѵ�. ����, N�� ũ�Ⱑ �ִ� 20���� �����Ƿ� ����� ��Ʈ��ŷ���� �����ϴ�.
//���������� ���� �׷��µ�, ������ ���ҿ� �����ϱ� ���� S�� ���� sum���� ���Ƶ� answer�� �����ϸ� �ȵȴٴ� ���̴�. 3 0 0 0 0�� �ݷʷ� Ȯ�������� ����Ѱ�ó��
//Ǯ�� �ƹ��͵� �ȴ��ϰ� 2��°���� �ϳ� ���ѰͰ� �� ���� ���������� �ƹ��͵� ������ ���� ���� ��������� ���� ���� �Ǿ� ������� ���Ĺ�����. �׷��⿡ �� ������ ���ҿ�
//�����Ҷ����� ����ϴٰ� Ȯ���� �������� �� �ѹ� �ؾ��Ѵ�.

int board[20];
int N, S, answer = 0;

void CalAnswer(int sum, int idx, int num)
{
    if (idx > N)
        return;
    if (sum == S && num >= 1 && idx == N)
        ++answer;
    CalAnswer(sum, idx + 1, num); //���� ���Ҹ� ������ �ʾ��� ���.
    CalAnswer(sum + board[idx], idx + 1, num + 1); //���� ���Ҹ� ������ ���.
}

void MakeAnswer()
{
    CalAnswer(0, 0, 0);
    cout << answer << '\n';
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