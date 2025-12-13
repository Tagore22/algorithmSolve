#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    map<string, int> board;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        ++board[str];
    }
    pair<string, int> answer = make_pair("", -1);
    for (auto iter = board.cbegin(); iter != board.cend(); ++iter)
        answer = answer.second <= iter->second ? make_pair(iter->first, iter->second) : answer;
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}