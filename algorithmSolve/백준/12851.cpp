#include <iostream>
#include <queue>

using namespace std;

const int MaxNum = 100000;
bool check[MaxNum + 1];
int n, k;

void BFS()
{
    int AnswerTime = 0;
    int AnswerNum = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(n, 0));
    while (!que.empty())
    {
        auto here = que.front();
        que.pop();

        int where = here.first;
        int time = here.second;
        check[where] = true;

        if ((where == k) && (time == AnswerTime) && (AnswerNum != 0))
            ++AnswerNum;

        if ((where == k) && (AnswerNum == 0))
        {
            AnswerTime = time;
            ++AnswerNum;
        }

        if (where - 1 >= 0 && !check[where - 1])
            que.push(make_pair(where - 1, time + 1));
        if (where + 1 <= MaxNum && !check[where + 1])
            que.push(make_pair(where + 1, time + 1));
        if (where * 2 <= MaxNum && !check[where * 2])
            que.push(make_pair(where * 2, time + 1));
    }
    cout << AnswerTime << '\n';
    cout << AnswerNum << '\n';
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    BFS();
    return 0;
}