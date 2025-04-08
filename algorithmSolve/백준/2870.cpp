#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> board;
int N;

bool SortFunc(const string& lhs, const string& rhs)
{
    if (lhs.size() != rhs.size())
        return lhs.size() < rhs.size();
    return lhs < rhs;
}

void MakeAnswer()
{
    for (int iter = 0; iter < N; ++iter)
    {
        string str;
        cin >> str;
        string here = "";
        for (int i = 0; i < str.size(); ++i)
        {
            if ('0' <= str[i] && str[i] <= '9')
            {
                here = here == "0" ? "" : here;
                here += str[i];
            }
            else if (here != "")
            {
                board.push_back(here);
                here = "";
            }
        }
        if (here != "")
            board.push_back(here);
    }
    sort(board.begin(), board.end(), SortFunc);
    for (int i = 0; i < board.size(); ++i)
        cout << board[i] << '\n';
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