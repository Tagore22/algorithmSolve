#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

// 풀이.
// 오랜만에 예전에 풀지 못했던 골드 문제들을 순회하고 있는데 생각보다 쉽게 풀었다.
// 연동된 괄호쌍들을 백트래킹을 통해 골라가면서 출력에서 제외하는 문제인데 괄호들을
// 연동시킬 때 실수가 있었다. (1 + 2) 같은 경우는 (이든 )이든 괄호가 등장하는 순간
// 그 원소의 위치를 넣어주면 알아서 연동이 되지만 (1) + (2)같은 경우는 그렇지 않기
// 때문이다. 따라서 왕도대로 스택을 이용하여 따로 위치를 잡아 연동시켜줘야했다.
// 그 이후는 상술한 백트래킹을 통해 임의의 괄호쌍을 출력 혹은 미출력으로 순회하면 된다.
// 주어지는 괄호쌍이 최대 10개이기에 시간초과는 문제되지 않는다.

// 자세한 설명은 주석으로 남긴다.

string str;
vector<pair<int, int>> board;
set<string> answer;
stack<int> sta;
bool output[200] = { false, };
int vsize, ssize;

// 각 괄호쌍을 출력 혹은 미출력하는 순회 함수.
void DFS(int idx)
{
    // 괄호쌍만큼 모두 순회하였다면 문자열을 만들어 set에 넣는다.
    if (idx >= vsize)
    {
        string ans = "";
        for (int i = 0; i < ssize; ++i)
            if (!output[i])
                ans += str[i];
        answer.insert(ans);
        return;
    }

    DFS(idx + 1);
    output[board[idx].first] = true;
    output[board[idx].second] = true;
    DFS(idx + 1);
    output[board[idx].first] = false;
    output[board[idx].second] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;
    ssize = str.size();
    // 정석적인 괄호의 연동 방법. 스택을 사용한다.
    for (int i = 0; i < ssize; ++i)
    {
        if (str[i] == '(')
        {
            sta.push(i);
        }
        else if (str[i] == ')')
        {
            board.push_back(make_pair(sta.top(), i));
            sta.pop();
        }
    }
    vsize = board.size();

    DFS(0);

    // 아래 구현을 보면 첫번째 원소는 무시하고 있다. 
    // 괄호를 하나도 지우지 않은 상태이기 때문이다.
    auto cur = answer.begin();
    for (auto iter = ++cur; iter != answer.end(); ++iter)
        cout << *iter << '\n';
    return 0;
}