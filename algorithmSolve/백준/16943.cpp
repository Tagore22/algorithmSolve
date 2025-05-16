#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 만들 수 있는 모든 순열값들중 B보다 작으면서 0으로 시작하지 않는 가장 큰 값을 구하는 문제다.
// 각 자리를 백트래킹이나 DFS를 통해서 직접 구할 수도 있으나 예전에 STL을 공부할 때 봤던 
// next_permutation()이 생각났고 더 간결하게 코드를 짤 수 있을 것이므로 사용해보았다.

vector<int> board;
int A, B;

int main()
{
    cin >> A >> B;
    while (A > 0)
    {
        board.push_back(A % 10);
        A /= 10;
    }
    sort(board.begin(), board.end());
    int answer = -1;
    while (next_permutation(board.begin(), board.end()))
    {
        int sum = 0;
        for (int i = 0; i < board.size(); ++i)
            sum = sum * 10 + board[i];
        if (board[0] == 0 || sum >= B || sum <= answer)
            continue;
        answer = sum;
    }
    cout << answer << '\n';
    return 0;
}