#include <iostream>
#include <stack>

using namespace std;

// 풀이.
// 막무가내로 for문을 2개 중첩하여 풀면 최대 100만 * 100만으로 시간을 한참 넘어서기에 풀수 없다. 
// 그래서 스택을 사용하여 현재 오등큰수들을 들면서 최대 100만번을 순회하여야 한다.
// 빈 스택을 들고 맨 뒤(오른쪽)부터 순회하기 시작하는데 스택안에 든 수의 등장횟수가
// 현재 i번째 원소보다 클때까지 모두 비운다. 그리고 가장 맨 뒤 스택값이 가장 왼쪽이면서
// 등장횟수가 큰 수 즉, 오등큰수이다. 다만 스택이 비었다면 오등큰수가 존재하지 않기에
// -1을 대입해주면 된다.

int board[1000000], nums[1000001], answer[1000000];
int N;

void MakeAnswer()
{
    // 텅빈 스택을 지니고 뒤에서부터 N번만큼 순회한다.
    stack<int> sta;
    for (int i = N - 1; i >= 0; --i)
    {
        // 스택이 비거나 현 맨위 스택의 등장횟수가 현재 i번째 원소의 등장횟수보다 클때까지 비운다.
        while (!sta.empty() && nums[sta.top()] <= nums[board[i]])
        {
            sta.pop();
        }

        // 스택이 비었다면 오등큰수는 존재하지 않기에 -1을, 그렇지 않다면 오등큰수의 원소번호를 대입한다.
        answer[i] = sta.empty() ? -1 : sta.top();
        sta.push(board[i]);
    }

    for (int i = 0; i < N; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        ++nums[board[i]];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}