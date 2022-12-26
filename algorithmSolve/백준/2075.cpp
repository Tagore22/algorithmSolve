#include <iostream>
#include <vector>

using namespace std;

//Ǯ��
//�� ������ ��Ʈ������ �����ϸ� ���� �����ϱ� ������. N��° ū���� �˱� ���ؼ��� ���� ū������ �񱳸� �ؾ� �ߴµ� ��ħ 
//�� �迭�� �� �Ʒ��� �ִ� ������ �� �࿡�� ���� ū�����⿡ �����ߴ�. ��, �� �� ���� ��ȸ�ϸ� ���� ū���� ã�� �� ���� ������
//�� ���� ��� ���� ��ĭ�� �Ʒ��� �����ٰ� �����ϰ� ��� ���س���. ���� �̰� �����ϱ� ���� ���� ������ Ǯ��� ���̸�,
//���� Ǯ�̿����� �� ������ ���� ���� �����ϴ� �迭�� ���� ���� �� �迭�� ������ ���� �־�ξ���.

//�������ڸ� �ϳ��� �迭�� ���� ������ �� �� ��ȣ�� �־���� ���� ū������ ���ذ��� ���� ū���� �����ϴ� ���� �� ��ȣ�� �ϳ���
//�ٿ����� N��° ū���� �߰��Ѵ�.

vector<vector<int>> board;
int N;

void MakeAnswer()
{
    vector<int> idx;
    for (int i = 0; i < N; ++i)
        idx.push_back(N - 1);

    int now, iter;
    for (int i = 0; i < N; ++i)
    {
        iter = 0;
        now = board[idx[0]][0];
        for (int j = 1; j < N; ++j)
            if (now < board[idx[j]][j])
            {
                iter = j;
                now = board[idx[j]][j];
            }
        --idx[iter];
    }

    cout << now << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}