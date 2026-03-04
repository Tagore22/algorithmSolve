#include <iostream>
#include <stack>

using namespace std;

// 풀이.
// 처음에는 스택에 괄호를 넣는 것만을 이용하려 풀려고 했다. 예를 들어
// ()이 만나는 때에 2를 더해주는 식이다. 다만 이것으로는 부족했는데
// (()(()()(()( 같은 경우가 그 반례였다. 단서는 스택에 남은 괄호들이었다.
// 위 예시를 들면 남는 괄호는 0, 3, 8, 11번째인데 이것은 그 사이의 원소들은
// 이미 짝을 이뤘음을 뜻한다. 따라서 0 ~ 3번 사이에 2개, 3 ~ 8번 사이에 4개...
// 로 현재 짝을 이룬 괄호들의 수를 알아낼 수 있다. 다만 한가지 실수를 했는데
// 스택의 타입은 pair<int, char>로 해놓고 값을 넣는 것은 pair<char, int> 형식을
// 사용하고 있었다.

// 자세한 설명은 주석으로 남긴다.

int N;
string str;
stack<pair<char, int>> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> str;
    for (int i = 0; i < N; ++i)
    {
        if (str[i] == '(')
        {
            board.push(make_pair(str[i], i));
        }
        else
        {
            // 이 부분도 초기엔 if(!board.empty())로 잘못 구현하고 있었다.
            // 반드시 이전에 '('가 있는 경우만 삭제되어야 한다.
            if (!board.empty() && board.top().first == '(')
                board.pop();
            else
                board.push(make_pair(str[i], i));
        }
    }
    // 남는 괄호가 1개인 경우도 존재하기에 반드시 N부터 현재 괄호의
    // 위치값을 계산해나가야한다.
    int p = N, answer = 0;
    while (!board.empty())
    {
        int cur = board.top().second;
        answer = max(answer, p - cur - 1);
        p = cur;
        board.pop();
    }
    answer = max(answer, p);
    cout << answer << '\n';
    return 0;
}