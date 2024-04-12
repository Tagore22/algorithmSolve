#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// reverse()를 이용하면 이처럼 짧고 간결한 코드를 구현할수 있다. 굳이 벡터를 사용하지 않고
// int 배열을 사용해도 된다.

vector<int> board;
int from, to;

int main()
{
    for (int i = 1; i <= 20; ++i)
        board.push_back(i);
    for (int i = 0; i < 10; ++i)
    {
        cin >> from >> to;
        reverse(board.begin() + (from - 1), board.begin() + to);
    }
    for (auto n : board)
        cout << n << ' ';
    cout << '\n';
    return 0;
}