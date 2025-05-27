#include <iostream>
#include <deque>

using namespace std;

// 풀이.
// 역으로 생각하면 쉬운 문제다. 위에서 1번부터 카드는 놓여져있고, 예제로 입력된 반대 순서로
// 카드를 놓았을때 나오는 결과값을 출력하는 것이다. 다만 앞, 뒤, 앞에서 2번째로 배열값을 
// 어떻게 집어넣을지 고민했는데 처음에는 배열로 해결하고 싶었으나 deque이 더 깔끔하게
// 풀리는 것 같았고 풀고나서 힌트를 보니 문제를 만든 이도 덱을 생각하고 만든 문제였다.

int N;
const int MAX = 1000000;
int board[MAX];
deque<int> answer;

void Solve()
{
    for (int i = N - 1; i >= 0; --i)
    {
        if (board[i] == 1)
        {
            answer.push_front(N - i);
        }
        else if (board[i] == 2)
        {
            int first = answer.front();
            answer.pop_front();
            answer.push_front(N - i);
            answer.push_front(first);
        }
        else
        {
            answer.push_back(N - i);
        }
    }
    for (auto& ans : answer)
        cout << ans << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    Solve();
    return 0;
}