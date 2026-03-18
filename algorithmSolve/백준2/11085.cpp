#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 조금만 더 생각해보면 매우 간단한 문제인데 오래 걸렸다. 시작점에서 도달점까지의
// 여러 경로들중 최소 너비가 가장 큰 값을 출력해야한다. 따라서 모든 너비들을 
// 내림차순으로 정렬하여 큰 순서대로 두 정점을 합친다. 이것을 반복하며 주어진 시작점과
// 도달점의 부모값이 동일해진 순간 즉, 연결된 순간의 너비가 바로 최소 너비들중 가장 큰
// 너비이다. 간선을 하나씩 골라 연결한다는점에서 크루스칼과 매우 비슷했다.

struct pos
{
    int from;
    int to;
    int len;
};

int p, w, from, to;
vector<pos> board;
int parent[1000];

int Find(int num)
{
    if (parent[num] == num)
        return num;
    return parent[num] = Find(parent[num]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b)
        parent[a] = b;
}

bool SortFun(const pos& lhs, const pos& rhs)
{
    return lhs.len > rhs.len;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> p >> w >> from >> to;
    for (int i = 0; i < w; ++i)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        board.push_back(pos{ a, b, cost });
    }

    sort(board.begin(), board.end(), SortFun);

    for (int i = 0; i < p; ++i)
        parent[i] = i;

    for (auto& here : board)
    {
        Union(here.from, here.to);

        if (Find(from) == Find(to))
        {
            cout << here.len << '\n';
            break;
        }
    }
    return 0;
}