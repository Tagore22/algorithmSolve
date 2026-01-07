#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char, string> board;
    board['M'] = "MatKor";
    board['W'] = "WiCys";
    board['C'] = "CyKor";
    board['A'] = "AlKor";
    board['$'] = "$clear";

    char c;
    cin >> c;

    cout << board[c] << '\n';
    return 0;
}