#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    queue<int> que;
    for (int i = 1; i <= N; ++i)
        que.push(i);
    while (que.size() > 1)
    {
        int qsize = que.size();
        for (int i = 1; i <= qsize; ++i)
        {
            int now = que.front();
            que.pop();
            if (i % 2 == 0)
                que.push(now);
        }
    }
    cout << que.front() << '\n';
    return 0;
}