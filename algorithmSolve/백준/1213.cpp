#include <iostream>
#include <map>

using namespace std;

map<char, int> board;
string palin;

char PullFromBoard()
{
    char now = board.begin()->first;
    --board[now];
    if (board[now] == 0)
        board.erase(board.begin());
    return now;
}

bool FirstCheck()
{
    if (palin.size() % 2 == 0)
    {
        for (auto iter = board.begin(); iter != board.end(); ++iter)
            if (iter->second % 2 == 1)
                return false;
    }
    else
    {
        bool isodd = false;
        for (auto iter = board.begin(); iter != board.end(); ++iter)
            if (iter->second % 2 == 1)
            {
                if (!isodd)
                    isodd = true;
                else
                    return false;
            }
        if (!isodd)
            return false;
    }
    return true;
}

void DevineAlpha()
{
    for (int i = 0; i < palin.size(); ++i)
        ++board[palin[i]];
}

char ReturnCenter()
{
    for (auto iter = board.begin(); iter != board.end(); ++iter)
        if (iter->second % 2 == 1)
        {
            --iter->second;
            char now = iter->first;
            if (iter->second == 0)
                board.erase(iter);
            return now;
        }
}

void MakeStr()
{
    string answer(palin.size(), ' ');
    if (palin.size() % 2 == 1)
        answer[palin.size() / 2] = ReturnCenter();
    int head = 0;
    int tail = palin.size() - 1;
    for (int i = 0; i < palin.size() / 2; ++i)
    {
        answer[head] = PullFromBoard();
        answer[tail] = PullFromBoard();
        ++head;
        --tail;
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    DevineAlpha();
    if (!FirstCheck())
    {
        cout << "I'm Sorry Hansoo" << '\n';
        return;
    }
    MakeStr();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> palin;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}