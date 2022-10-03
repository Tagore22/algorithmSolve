#include <iostream>

using namespace std;

//bool ���� 2���� �̿��Ͽ� ���� ���������� ���������� Ȯ���ذ��� �迭�� ��ȸ�Ѵ�.
//�Ѵ� �ƴ� ���°� �Ǿ��� ��� mixed�� ����ϸ� ���α׷��� �����Ѵ�.

const int BOARD_NUM = 8;
int board[BOARD_NUM];

void MakeAnswer()
{
    bool asc = true; //�������ΰ�
    bool des = true; //�������ΰ�
    for (int i = 1; i < BOARD_NUM; ++i)
    {
        if (board[i - 1] < board[i])
            des = false;
        else
            asc = false;
        if (!des && !asc)
        {
            cout << "mixed" << '\n';
            return;
        }
    }
    cout << (des ? "descending" : "ascending") << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < BOARD_NUM; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}