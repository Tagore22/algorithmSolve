#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> que;
int N, answer = 0;

void MakeAnswer()
{
    int idx = N / 3;
    for (int i = 0; i < idx; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            answer += que.top();
            que.pop();
        }
        que.pop();
    }
    while (!que.empty())
    {
        answer += que.top();
        que.pop();
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        que.push(num);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}