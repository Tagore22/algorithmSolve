#include <iostream>
#include <vector>

using namespace std;

//Ǯ��
//1���� ���� ���ذ��� ��ȸ�� �ؾ����ٵ� ������ ��ȸ�� �ؾ����� ����ߴ� ����.
//������ �������� ������ ����������.
//������ from�� ���� to�� �ε�, �ʱ�ȭ�� ���� 1�� 2�� �Ѵ�.
//from�� ������ to�� ���� + G�� ���ϴµ�, �̶� 3������ ��찡 ���´�.
//�� ���� A�� B�� Ī�Ѵ�.

//1. A == B �϶�
//�� ��쿡�� from�� to�� 1�� �����ְ� to���� ������ answrd�� �־��ش�. �ϼ��ϰ����� from�� 1�� �����ִ� ��쿡�� 
// ������ G���� ���̰� �� �۱� ������ to�� �ᱹ�� 1�� �����ٰ��̰�, to�� �����ִ� ��쿡�� 
// G���� ���̰� ������ ũ�� ������ from�� �����ְ� �Ǿ��ִ�.
//2. A > B�϶�
//���̰� G���� ũ�� ������ ������ from�� �÷��� ���̰��� �ٿ����Ѵ�.
//3. A < B�϶� 
//���̰� G���� �۱� ������ ���� to�� �÷��� ���̰��� Ű���� �Ѵ�.

//�̷��� �������� ��ȸ�� �ϴٰ� from�� to�� �������� �ݺ����� Ż���Ѵ�. from�� to�� ���ٴ� ���� A�� B�� ���̰� G���� ��� Ŀ�� from�� ���
//�����ߴٴ� ���ε�, �� �̻� from�̳� to�� Ű���� �� ���̴� �þ�� �þ�� �پ���� �ʱ� �����̴�.
//���� �ݺ��� ��ȸ�� �������� ������ answer�� ����ִ� ���Ұ��� 1�� �̻��̶�� �װ͵��� ����ϰ�
//1���� ���ٸ� ���� ã���� ���⿡ -1�� ����Ѵ�.

int G;

void MakeAnswer()
{
    vector<long long> answer;
    long long from = 1, to = 2, now;
    while (from < to)
    {
        now = from * from + G;
        if (to * to == now)
        {
            answer.push_back(to);
            ++from;
            ++to;
        }
        else if (to * to < now)
        {
            ++to;
        }
        else
        {
            ++from;
        }
    }

    if (answer.empty())
        cout << -1 << '\n';
    else
        for (int i = 0; i < answer.size(); ++i)
            cout << answer[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> G;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}