#include <iostream>
#include <algorithm>

using namespace std;

const int MAXNUM = 500000;
pair<int, int> board[MAXNUM];
int N;

//ó���� �ܼ��� �ٷ� �� ���ڰ� �� ���ں��� ũ�ٸ� �� �ڷ� �з����� ���������� ������ ����
//�� ���� ũ�� answer + 1 �� �Ͽ����� �ٽ� �����غ��� 1,5,6,2 ���� ���� �ι� ������ �Ǿ���Կ���
//�ٷ� �ռ��� ū ���� 6,2,�ۿ� ���� Ʋ�� �˰����� �Ǿ���.
//��¥ ������ �������Ľ� �ռ��� ũ�� �޼��� �ռ��� ��ġ�� �ű�°� ��, ������ ��ĭ �и��°� �̿��ϴ°ǵ�
//������ �з����°� �� ���Ľ� ���ѹ��ۿ� �������� �ʱ� �����̴�.
//�̷��� ������ �̿��Ͽ� ���� ���ĵ� �迭�� ���ĵ��� ���� �迭�� ���� ��ġ�� ���Ͽ� ���� ���� �и� ��+1��
//������ �ȴ�.

void MakeAnswer()
{
    sort(board, board + N);
    int answer = 0;
    for (int i = 0; i < N - 1; ++i)
        answer = max(answer, board[i].second - i);
    cout << answer + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        board[i] = make_pair(a, i);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}