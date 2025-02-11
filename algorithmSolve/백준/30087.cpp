#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string, string> board;
    board.insert(make_pair("Algorithm", "204"));
    board.insert(make_pair("DataAnalysis", "207"));
    board.insert(make_pair("ArtificialIntelligence", "302"));
    board.insert(make_pair("CyberSecurity", "B101"));
    board.insert(make_pair("Network", "303"));
    board.insert(make_pair("Startup", "501"));
    board.insert(make_pair("TestStrategy", "105"));

    int N;
    cin >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        cout << board[str] << '\n';
    }
    return 0;
}