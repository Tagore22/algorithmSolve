#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    priority_queue<int> que;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            if (!que.empty())
            {
                cout << que.top() << '\n';
                que.pop();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else
        {
            for (int j = 0; j < num; ++j)
            {
                int value;
                cin >> value;
                que.push(value);
            }
        }
    }
    return 0;
}