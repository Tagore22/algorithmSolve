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

    queue<int> que;
    while (true)
    {
        int num;
        cin >> num;
        if (num == -1)
        {
            break;
        }
        else if (num == 0)
        {
            que.pop();
        }
        else
        {
            if (que.size() < N)
                que.push(num);
        }
    }
    if (que.empty())
    {
        cout << "empty" << '\n';
        return 0;
    }
    while (!que.empty())
    {
        cout << que.front() << ' ';
        que.pop();
    }
    cout << '\n';
    return 0;
}