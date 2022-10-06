#include <iostream>
#include <queue>

using namespace std;

//단순한 큐 구현

int N;

void MakeAnswer()
{
    queue<int> que;
    for (int i = 0; i < N; ++i)
    {
        string str;
        int num;
        cin >> str;
        if (str == "push")
        {
            cin >> num;
            que.push(num);
        }
        else if (str == "pop")
        {
            if (!que.empty())
            {
                num = que.front();
                que.pop();
                cout << num << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (str == "size")
        {
            cout << que.size() << '\n';
        }
        else if (str == "empty")
        {
            cout << (que.empty() ? 1 : 0) << '\n';
        }
        else if (str == "front")
        {
            cout << (!que.empty() ? que.front() : -1) << '\n';
        }
        else
        {
            cout << (!que.empty() ? que.back() : -1) << '\n';
        }
    }
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
    MakeAnswer();
    return 0;
}