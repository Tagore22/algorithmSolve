#include <iostream>
#include <algorithm>

using namespace std;

//Ǫ�� ����� �ϳ� ������ ��������. ���ʿ������� �����ϵ�, ���� ���̰� �� ������ �����ϰ�, �� ũ�ٸ� �����ϸ� �Ǿ�����,
//���� ���� ���̿��� �����ö��� ��������. �ᱹ�� ����, �����ʿ��� �ѹ��� ��ȸ�Ͽ��µ� ������ ���� ū���� ���� ���� �ݺ�������
//�ٷ� ������ ������ ������ �� �ݺ����� ���갪�� �ִ� N���� �����Ҽ� �ֱ� �����̴�.

//Ǯ��
//�� ����Ͽ��� ���ʿ��� �ѹ� �����ʿ��� �ѹ� �־��� �迭�� ��ȸ�Ѵ�. �ٸ�, ���� ���� ���̿��� ������ ���� ����, from�� �ִ� ���̸�
//����Ű�� �����϶��� ��ȸ�� ���߾ �ȴ�. ����, ���� ���� ���̰� ���ʰ� ������ �߰� ������ΰ��� 2���� �ִٰ� �ص� �� �� ������ �߰���
//������ ���õǱ� �����̴�.

pair<int, int> board[1000];
int N, max_num = -1;

void MakeAnswer()
{
    sort(board, board + N);
    int from = 0, to; //���� �ε����� ���� �ε���.
    int answer = (board[N - 1].first - board[0].first + 1) * max_num; //�ִ밪.
    for (int i = 1; i < N; ++i) //���ʺ��� ��ȸ�ϵ�, ���� ���� ���̿��� ������ ���� ����(board[from].second == max_num)��� �ݺ��� Ż��.
    {
        if (board[from].second == max_num) //���� ���� ���̿��� ������ ���� �����ΰ�?
            break;

        to = i; //���� �ε����� ����.

        if (board[from].second < board[to].second) //���� ����Ű�� ���̰� �� ũ�ٸ� ���� �κ��� �����ش�.
        {
            answer -= (board[to].first - board[from].first) * (max_num - board[from].second);
            from = i; //���� �ε����� ���� �ε���(������ ����)�� �ȴ�.
        }
    }

    from = N - 1;
    for (int i = N - 2; i >= 0; --i) //������ ��ȸ. 
    {
        if (board[from].second == max_num)
            break;

        to = i;

        if (board[from].second < board[to].second)
        {
            answer -= (board[from].first - board[to].first) * (max_num - board[from].second);
            from = i;
        }
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i].first >> board[i].second;
        max_num = max(max_num, board[i].second);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}