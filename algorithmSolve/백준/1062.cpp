#include <iostream>

using namespace std;

const int MAXNUM = 50;
string board[MAXNUM];
int N, K, mask;
int answer = 0;

void Calcul(int alpha, int num)
{
    if (num == K)
    {
        int check = 0;
        for (int i = 0; i < N; ++i)
        {
            bool isPlus = true;

            for (int j = 0; j < board[i].size(); ++j)
                if ((mask & (1 << (board[i][j] - 'a'))) == 0)
                {
                    isPlus = false;
                    break;
                }

            if (isPlus)
                ++check;
        }
        answer = max(answer, check);
        return;
    }
    else
    {
        for (int i = alpha; i < 26; ++i)
            if ((mask & (1 << i)) == 0)
            {
                mask |= (1 << i);
                Calcul(i + 1, num + 1);
                mask &= ~(1 << i);
            }
    }
}

void MakeAnswer()
{
    if (K < 5)
    {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < N; ++i)
        board[i] = board[i].substr(4, board[i].size() - 8);
    mask |= (1 << ('a' - 'a'));
    mask |= (1 << ('n' - 'a'));
    mask |= (1 << ('t' - 'a'));
    mask |= (1 << ('i' - 'a'));
    mask |= (1 << ('c' - 'a'));
    K -= 5;

    Calcul(0, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mask = 0;

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}