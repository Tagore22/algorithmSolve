#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이
// 아래 주석을 보면 그리디 형식으로 풀기 위해 여러 상황을 고려해보았으나 85퍼센트에서 자꾸 틀리는걸 보면 뭔가 놓친거같다.
// 결국 풀이는 BFS를 통해 위든 아래든 갈수 있는 모든 경우를 직접 해보는것이었다. 물론 bool형 배열을 통해 중복되는 경우는
// 모두 무시해야한다. 

int F, S, G, U, D;

// 올라가야 하는 상황이라고 친다.
// 1. U가 0일때는 절대 도달할수 없다.
// 2. 올라갔을때 천장을 뚫는다.
// 2-1. 한번 D만큼 내려와서 다시 올라간다.
// 2-2. 그러나 D만큼 내려올수도 없다면 계단을 이용해야한다. 혹은 D가 0일때
// 2-3. 혹은 D가 U의 배수라면 어차피 내려간다 한듯 또다시 현재 층으로 오게 되어
// 반복되기 때문에 계단을 이용해야한다.

void BFS()
{
    bool check[1000001];
    memset(check, false, sizeof(check));
    check[S] = true;
    queue<pair<int, int>> que;
    que.push(make_pair(S, 0));

    while (!que.empty())
    {
        int cur = que.front().first;
        int cost = que.front().second;
        que.pop();

        if (cur == G)
        {
            cout << cost << '\n';
            return;
        }

        int there = cur + U;
        if (there <= F && !check[there])
        {
            check[there] = true;
            que.push(make_pair(there, cost + 1));
        }

        there = cur - D;
        if (there >= 1 && !check[there])
        {
            check[there] = true;
            que.push(make_pair(there, cost + 1));
        }
    }
    cout << "use the stairs" << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> F >> S >> G >> U >> D;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}