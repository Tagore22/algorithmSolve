#include <iostream>

using namespace std;

int N;

//맨 뒷자리에 4 혹은 7을 추가해가며 N에 최대한 근접만 즉, 가장 큰값을 DFS로 계산한다.

int DFS(int now)
{
    if (now > N)
        return 0;
    int ans = max(now, DFS(now * 10 + 7));
    ans = max(ans, DFS(now * 10 + 4));

    return ans;
}

void ShowAnswer()
{
    cout << DFS(0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    ShowAnswer();
    return 0;
}