#include <iostream>
#include <vector>
#include <queue>

using namespace std; //시작부터 A와 B가 같은경우(연산이 0번인 경우)는 존재하지 않는다.

vector<bool> isExist;
int A, B;

long long Calcul(int CalNum, long long now)
{
    if (CalNum == 0)
        return now * 2;
    else
        return now * 10 + 1;
}

void BFS()
{
    int answer = 1;
    isExist.assign(B, false);
    queue<int> que;
    que.push(A);
    while (!que.empty())
    {
        ++answer;
        int Qsize = que.size();
        for (int i = 0; i < Qsize; ++i)
        {
            int now = que.front();
            que.pop();

            for (int j = 0; j < 2; ++j)
            {
                long long trans = Calcul(j, now);
                if (trans == B)
                {
                    cout << answer << '\n';
                    return;
                }
                if (trans < B && !isExist[trans])
                {
                    que.push(trans);
                    isExist[trans] = true;
                }
            }
        }
    }
    cout << -1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;
}

int main()
{
    Input();
    BFS();
    return 0;
}