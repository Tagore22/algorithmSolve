#include <iostream>
#include <deque>

using namespace std;

// 풀이.
// 누가 만들었는지 더럽게도 못만들었다. 특히나 3번, 4번 함수등은 뭔말인지 이해하는데 한참 걸렸다.
// 어쨌든 문제 자체는 deque를 구현하는 문제다.

deque<int> board;
int N;

void MakeAnswer()
{
    int menu, num;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> menu;
        if (menu == 1)
        {
            cin >> num;
            board.push_front(num);
        }
        else if (menu == 2)
        {
            cin >> num;
            board.push_back(num);
        }
        else if (menu == 3)
        {
            if (board.size() != 0)
            {
                cout << board[0] << '\n';
                board.pop_front();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (menu == 4)
        {
            if (board.size() != 0)
            {
                cout << board[board.size() - 1] << '\n';
                board.pop_back();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (menu == 5)
        {
            cout << board.size() << '\n';
        }
        else if (menu == 6)
        {
            cout << (board.size() == 0 ? 1 : 0) << '\n';
        }
        else if (menu == 7)
        {
            cout << (board.size() == 0 ? -1 : board[0]) << '\n';
        }
        else if (menu == 8)
        {
            cout << (board.size() == 0 ? -1 : board[board.size() - 1]) << '\n';
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}