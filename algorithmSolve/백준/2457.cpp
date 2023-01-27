#include <iostream>

using namespace std;

//Ǯ��
//���� ������ ���� �Ǵ� �� cur_from�� ���� �� cur_to�� �����ذ���, ���� �迭�� ��ȸ�س�����.
//���� ���� �Ǵ³����� �� �����ǰų� ������ �Ǹ鼭, ���� ���� ���� ������ �� �Ǵ� ���� �����ϸ� �ȴ�.
//�ٸ�, �迭 ��ȸ�� cur_from�� cur_to�� ���ٴ� ���� �ƹ� �ɵ� ���� �����ٴ� ���̱⿡
//cur_to�� 11�� 30�Ϻ��� ���ų� ���������� 0�� ����ؾ��Ѵ�.
//�������� cur_to�� 11�� 30�Ϻ��� Ŀ���� ��� ��ȸ�� ��ģ��.

struct flower
{
    pair<int, int> from;
    pair<int, int> to;
};

flower board[100000];
int N;

bool CompareMin(pair<int, int> a, pair<int, int> b) //�� pair<>�� �񱳹�. �� pair<>�� ���Ƶ� ����.
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
        return a.second <= b.second;
    else
        return false;
}

bool CompareMax(pair<int, int> a, pair<int, int> b) //�� pair<>�� �񱳹�. �� pair<>�� ������ ������ ����.
{
    if (a.first > b.first)
        return true;
    else if (a.first == b.first)
        return a.second > b.second;
    else
        return false;
}

void MakeAnswer()
{
    int answer = 0;
    pair<int, int> cur_from, cur_to = make_pair(3, 1);
    while (true)
    {
        cur_from = cur_to; //���� ���� ���� ������ �� ���� �ǰų� ���³��� ���ÿ� �����.
        for (int i = 0; i < N; ++i)
            if (CompareMin(board[i].from, cur_from) && CompareMax(board[i].to, cur_to))
                cur_to = board[i].to;

        ++answer;

        if (cur_from == cur_to) //���� ã�� ���ߴ�.
        {
            cout << 0 << '\n';
            return;
        }

        if (CompareMax(cur_to, make_pair(11, 30))) //11�� 30�ϱ��� �Ǵ� ���� ã�Ҵ�.
            break;
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
        cin >> board[i].from.first >> board[i].from.second >> board[i].to.first >> board[i].to.second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}