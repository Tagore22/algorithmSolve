#include <iostream>

using namespace std;

int catchnum[51];

int main()
{
    int N, M, L, answer = -1, cur = 1;
    cin >> N >> M >> L;

    while (true)
    {
        ++catchnum[cur];
        ++answer;
        if (catchnum[cur] >= M)
            break;
        if (catchnum[cur] % 2 == 0)
            cur = (cur + N - L) % N;
        else
            cur = (cur + L) % N;
    }
    cout << answer << '\n';
    return 0;
}