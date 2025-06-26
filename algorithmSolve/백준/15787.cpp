#include <iostream>
#include <string>
#include <set>

using namespace std;

// 풀이.
// string과 set을 이용하여 풀었으나 비트마스크를 이용하여 더 빠르게 풀 수 있었다.
// 비트마스크 값을 2 곱하면 한칸씩 뒤로 밀려나고 2로 나누면 한칸씩 앞으로 당겨지는 것을
// 이용하면 되는 것이다.

int N, M;
string train[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        train[i] = "00000000000000000000";
    for (int i = 0; i < M; ++i)
    {
        int com, num, idx;
        cin >> com >> num;
        if (com < 3)
            cin >> idx;
        if (com == 1)
        {
            train[num - 1][idx - 1] = '1';
        }
        else if (com == 2)
        {
            train[num - 1][idx - 1] = '0';
        }
        else if (com == 3)
        {
            train[num - 1] = '0' + train[num - 1];
            train[num - 1].erase(train[num - 1].size() - 1, 1);
        }
        else
        {
            train[num - 1] += '0';
            train[num - 1].erase(0, 1);
        }
    }
    set<string> answer;
    for (int i = 0; i < N; ++i)
        if (answer.find(train[i]) == answer.end())
            answer.insert(train[i]);
    cout << answer.size() << '\n';
    return 0;
}