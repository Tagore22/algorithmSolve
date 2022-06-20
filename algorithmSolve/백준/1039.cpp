#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

string StrN = "";
int N, K;

void MakeGraph()
{
    while (N > 0)
    {
        StrN += N % 10 + '0';
        N /= 10;
    }
    reverse(StrN.begin(), StrN.end());
}

int CalculMax(string here)
{
    int trans = 0;
    for (int i = 0; i < here.size(); ++i)
        trans = trans * 10 + (here[i] - '0');
    return trans;
}

void ShowAnswer()
{
    MakeGraph();
    if (StrN.size() == 1 || (StrN.size() == 2 && StrN[1] == '0'))
    {
        cout << -1 << '\n';
        return;
    }
    int answer = 0;
    queue<string> que;
    que.push(StrN);
    int NowK = 0;
    while (!que.empty() && NowK < K)
    {
        set<string> Strset;
        int Qsize = que.size();
        for (int k = 0; k < Qsize; ++k)
        {
            string here = que.front();
            que.pop();

            for (int i = 0; i < here.size() - 1; ++i)
                for (int j = i + 1; j < here.size(); ++j)
                {
                    if (i == 0 && here[j] == '0')
                        continue;
                    swap(here[i], here[j]);
                    if (Strset.find(here) == Strset.end())
                    {
                        que.push(here);
                        Strset.insert(here);

                        if (NowK == K - 1)
                            answer = max(answer, CalculMax(here));
                    }
                    swap(here[i], here[j]);
                }
        }
        ++NowK;
    }
    cout << (NowK == K ? answer : -1) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    ShowAnswer();
    return 0;
}