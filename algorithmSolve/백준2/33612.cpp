#include <iostream>

using namespace std;

int main()
{
    pair<int, int> board[6] = { {0, 0}, {2024, 8}, {2025, 3}, {2025, 10}, {2026, 5}, {2026, 12} };
    int N;
    cin >> N;
    cout << board[N].first << ' ' << board[N].second << '\n';
    return 0;
}