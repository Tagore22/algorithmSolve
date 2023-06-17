#include <iostream>
#include <queue>
#include <set>

using namespace std;

// 풀이.
// 두 순서들이 있을때 순서가 역전되는 상황을 파악하는 문제이다.
// map으로 풀어도 되지만 나는 queue와 set을 이용해서 풀어봤다.

// 자세한 설명은 주석으로 남긴다.

queue<string> first, second;
set<string> check;
int N;

// 1. 둘이 다를때
// 1-1. 첫번째가 이미 지나간 차일수도 있고 두번째가 추월한것일수도 있다.
// 1-2. 첫번째가 지나간지 확인하고 지나간것이라면 첫번째를 넘기고
// 그렇지 않다면 두번째를 지나간것이라고 체크하고 값을 1 늘린후, 두번째를 넘긴다.
// 2. 둘이 같을때 지나간것 체크하고 둘다 넘어간다.

void MakeAnswer()
{
    int answer = 0;
    string from, to;
    while (!first.empty() && !second.empty())
    {
        from = first.front();
        to = second.front();

        if (from != to)
        {
            if (check.find(from) != check.end())
            {
                first.pop();
            }
            else
            {
                ++answer;
                check.insert(to);
                second.pop();
            }
        }
        else
        {
            check.insert(from);
            first.pop();
            second.pop();
        }
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        first.push(str);
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        second.push(str);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}