#include <iostream>

using namespace std;

//크게 어렵진 않으나, 많은 조건들이 달려있었다. 여학생이 스위치를 조작할 경우라던가, 출력의 방식등등. 상술하였듯이 크게 어렵지 않기에
//침착하게 푼 문제다.

int board[100];
int switches, students;

void ControlMan(int num)
{
    for (int i = num - 1; i < switches; i += num)
        board[i] ^= 1;
}

void ControlWoman(int num)
{
    board[num - 1] ^= 1;
    int dis = 2, idx;
    for (int i = num; i < switches; ++i)
    {
        idx = i - dis;
        if (idx < 0 || board[i] != board[idx])
            return;
        board[i] ^= 1;
        board[idx] ^= 1;
        dis += 2;
    }
}

void MakeAnswer()
{
    int gen, num;
    for (int i = 0; i < students; ++i)
    {
        cin >> gen >> num;
        if (gen == 1)
            ControlMan(num);
        else
            ControlWoman(num);
    }

    for (int i = 0; i < switches; ++i)
    {
        if (i > 0 && i % 20 == 0)
            cout << '\n';
        cout << board[i] << ' ';
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> switches;
    for (int i = 0; i < switches; ++i)
        cin >> board[i];
    cin >> students;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}