#include <iostream>

using namespace std;

//체스판의 특성상 하얀색 칸의 시작점이 매번 바뀜을 주의해야했다. ex) 첫번째줄은 첫번째칸이 하얀색, 두번째줄은 두번째칸이 하얀색,
//세번째 줄은 다시 첫번째칸이 하얀색

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