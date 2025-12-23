#include <iostream>
#include <stack>

using namespace std;

// 풀이.
// 스택을 이용하여 현재 값을 유지하는 문제. 현재 높이에 따라 다음과 같이 나뉜다.
// 1. 스택이 비었거나, 이전보다 큰 값일때. 더 높은 새로운 건물 등장.
// 2. 이전보다 작은 값일때. 자신보다 큰 값들을 모두 지운후 반복.
// 3. 현재 높이가 0일때. 모두 리셋한다. 즉 스택을 비운다.

// 특히나 2번의 경우 지운 끝에 이전에 같은 높이가 존재했다면 그 건물과
// 같은 건물이라고 할 수 있기 때문에 이 부분이 중요하다.

// 자세한 설명은 주석으로 남긴다.

int n;
stack<int> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int answer = 0;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        // 현재 높이가 0이라는 것은 아예 건물이 없음을 예시에서
        // 알려주었다. 따라서 스택을 비워버린다.
        if (y == 0)
        {
            while (!board.empty())
                board.pop();
        }
        // 스택이 비었거나, 현재 높이가 더 클 때에는 새로운 건물이
        // 등장함을 알 수 있다.
        else if (board.empty() || board.top() < y)
        {
            ++answer;
            board.push(y);
        }
        // 그 이외의 경우에는 현재 높이 A보다 낮은 높이 B가 있었다면
        // 그보다 더 이전에 현재와 같은 높이 C가 존재했더라도 B에 의해
        // 나누어지기 때문에 A와 C가 같은 건물이라고 할 수 없다.
        // 따라서 스택을 하나씩 비워가며 A보다 낮은 높이 B가 존재하는 지를
        // 살펴보아야 한다. 존재한다면 B에 의해 나누어졌기에 새로운 건물이
        // 등장하는 것이고 스택이 텅 빌때까지 찾지 못한 경우, 즉 A가 가장 낮은
        // 높이일 때도 마찬가지다. 다만 도중에 A와 같은 높이인 C를 찾았다면
        // A와 C가 연결되어 하나의 건물이라고 여길 수 있기 때문에 무시한다.
        else
        {
            while (!board.empty() && board.top() > y)
                board.pop();
            if (board.empty() || board.top() < y)
            {
                board.push(y);
                ++answer;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}