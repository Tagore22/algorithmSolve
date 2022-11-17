#include <iostream>

using namespace std;

//ü������ Ư���� �Ͼ�� ĭ�� �������� �Ź� �ٲ��� �����ؾ��ߴ�. ex) ù��°���� ù��°ĭ�� �Ͼ��, �ι�°���� �ι�°ĭ�� �Ͼ��,
//����° ���� �ٽ� ù��°ĭ�� �Ͼ��

string board[8];

void MakeAnswer()
{
    int answer = 0, white = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = white; j < 8; j += 2)
            if (board[i][j] == 'F')
                ++answer;
        white ^= 1;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 8; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}