#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 처음에는 M번의 DFS()를 사용했다. 즉, 칭찬이 발생할때마다 최초 번호부터 시작해서 DFS()를 실행하게 했었다.
// 하지만 한번에 DFS()마다 최대 10만의 노드를 지나가고 그것이 최대 1000번 반복되기에 시간초과가 난다.
// 여기서 머리를 조금만 쓰면 되는데, 칭찬때마다 DFS순회를 하지 않고 최초의 칭찬때 그 칭찬값을 모두 더한상태에서
// 단 한번의 DFS순회로 답을 구할수 있기 때문이다. 어떤 노드가 칭찬을 받아 값이 증가하면 그 자식 노드들은 무조건
// 같은 값만큼 증가하기 때문에 칭찬 받을때마다 DFS 순회를 하던 모든 값을 증가후 순회를 하던 상관이 없는 것이다.
// 오늘도 조금 아쉽긴 했지만 뭐.. 내일은 더 힘내보자!

// 자세한 설명은 주석으로 남긴다.

vector<int> board[100001];
int answer[100001];
int N, M;

// DFS 순회를 구현하는 함수.
void Comp(int idx)
{
    // idx번째 노드의 모든 자식들을 순회하며 칭찬값을 증가하고 재귀 호출한다.
    for (auto& a : board[idx])
    {
        answer[a] += answer[idx];
        Comp(a);
    }
}

void MakeAnswer()
{
    Comp(1);
    for (int i = 1; i <= N; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        answer[i] = 0;
    int a;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a;
        if (a != -1)
            board[a].push_back(i);
    }
    int b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        answer[a] += b;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}