#include <iostream>
#include <list>

//�Ʒ� �ļ��� �κп��� �̸��� ������ �ؼ� �ð��� �ϳ� ���� ���. �ݼ�...

//Ǯ��
//list�� queue�� ���� �Ǵ� �����ε� ���� list�� ���. �ݺ��ڸ� K-1���� ������ ���ư��� ������ ������ ���� ����ϰ� �����ϱ⸦ �ݺ��ϸ� �ȴ�.

using namespace std;

int N, K;

void MakeAnswer()
{
    list<int> board;
    for (int i = 1; i <= N; ++i)
        board.push_back(i);

    list<int>::iterator iter = board.begin();
    cout << "<"; //���� < �ϳ����� ����ϱ⿡ ' '�̵� " " �̵� ��� ����.
    while (board.size() > 1)
    {
        for (int i = 0; i < K - 1; ++i)
        {
            ++iter;
            if (iter == board.end())
                iter = board.begin();
        }

        cout << *iter << ", "; //���� �� �κп��� ������ ', '�� ��µ� �ٽ� �����غ��� ���� �ȵǴ� ���̴�. ' '�� ����Ѵٴ°� charŸ�� �ϳ��� ����Ѵٴ� ���̱⿡
                               //�� �κа��� �˸��� �ʴ�. �׷��⿡ ���ڿ� ����� " "�� ���� ���� �´�.
        iter = board.erase(iter);
        if (iter == board.end())
            iter = board.begin();
    }
    cout << *board.begin() << ">" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}