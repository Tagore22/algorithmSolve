#include <iostream>

using namespace std;

//Ǯ��
//������ �迭�� �߽ɿ��� �����ؼ� �����¿�� n���� �̵��ϸ� Ǯ����. �ٸ� �̵��ϴ� Ƚ�� n�� ù��° �̵��� ������������ �̵����� 1 �۰� �̵��ؾ��Ѵ�.
//���� �̵�Ƚ�� n�� ������ Ǯ��� �˰����� 2���� 2�� �����ؼ� N���� �۾ƾ��Ѵ�. �������� �ܼ��� ����� ������ �����ϸ� �ȴ�.

int board[999][999];
int N, find_num;

void MakeAnswer()
{
    pair<int, int> cur = make_pair(N / 2, N / 2); //���ۺκ��ӿ� ���ÿ� �迭�� �߽�.
    pair<int, int> answer = cur; //ã�ƾ� �ϴ� ��ǥ�� �ʱ�ȭ.
    int num = 0; //��ǥ�� ���� ���밪.
    board[cur.first][cur.second] = ++num;
    if (num == find_num) //�� �κ��� ���� ������������ ���밪�� ���Ҷ����� �� �� ���ǹ��� �����ߴ�. �ٸ� Ǯ�̷� ���� �ʴ´ٸ� ��¿���� ����.
        answer = make_pair(cur.first, cur.second);

    for (int i = 2; i < N; i += 2)
    {
        board[--cur.first][cur.second] = ++num; //�ʱ� ���� ��ĭ �̵�.
        if (num == find_num)
            answer = make_pair(cur.first, cur.second);
        for (int j = 0; j < i - 1; ++j) //���������� �̵�. n�� 1 �۴�.
        {
            board[cur.first][++cur.second] = ++num;
            if (num == find_num)
                answer = make_pair(cur.first, cur.second);
        }
        for (int j = 0; j < i; ++j) //�Ʒ��� �̵�.
        {
            board[++cur.first][cur.second] = ++num;
            if (num == find_num)
                answer = make_pair(cur.first, cur.second);
        }
        for (int j = 0; j < i; ++j) //�������� �̵�
        {
            board[cur.first][--cur.second] = ++num;
            if (num == find_num)
                answer = make_pair(cur.first, cur.second);
        }
        for (int j = 0; j < i; ++j) //���� �̵�.
        {
            board[--cur.first][cur.second] = ++num;
            if (num == find_num)
                answer = make_pair(cur.first, cur.second);
        }
    }

    for (int i = 0; i < N; ++i) //�迭�� ��ȸ�ϸ� ���밪�� ���.
    {
        for (int j = 0; j < N; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }

    cout << answer.first + 1 << ' ' << answer.second + 1 << '\n'; //��ǥ�� ���.
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> find_num;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}