#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 백트래킹 문제이다.
// 문제에서 주어진 조건이 처음에는 뭔소린지 이해도 못했다.
// 자세히 쳐다보니 어떤 점에서 중복되지 않는 방문을 총 4번이상 할수 있는지를 확인하는 문제였다.
// 그것만 알면 그 뒤는 간단한데 DFS혹은 백트래킹을 이용하여 말 그대로 4번이상 움직일수 있는지만 확인하면 된다.

// 자세한 설명은 주석으로 남긴다.

// P.S 의외로 최적화 부분을 많이 공부할수 있는 문제였다. 다음과 같다.

// 1. 처음에는 board를 2차원 벡터로 만들어서 resize로 그 크기를 늘렸다. 그게 더 메모리를 적게 차지할거라 생각했기 때문이다.
// 하지만 아래 풀이와 같이 처음 생성시 최대 용량을 미리 잡아 놓는것이 더 빨랐다. 아마 전자의 방법이 생성과 할당이라는 두가지
// 연산을 하기에 그런 것 같다. 따라서 벡터의 벡터로 생성하여 늘리지말고 처음부터 최대 용량의 1차원 벡터로 생성하자.
// 2. 범위기반 for문의 차이이다. 예전부터 공부해서 알고는 있었으나, 그리 실감을 못느껴서인지 잘쓰지 않았었다.
// 하지만 이 문제를 대상으로 비교해본 결과 거의 20 -> 32의 차이가 났다. 가독성도 더 좋아지니 특별한 일이 없거든(1씩 증가가 아닌
// 2씩 증가라던가 하는등) 범위기반 for문을 사용하자.
// 3. BackTrack()의 첫번째 if문을 보면 단락조건으로 합쳐져 있는데 원래 2가지로 나누어져 있었다.
// 첫번째 조건은 함수 탈출만하고 isfind를 변경하지는 않았기에 일부러 나누어 놨는데 오히려 합치는게 isfind의 갱신 연산이 존재함에도
// 훨씬 빨랐다. DFS나 BFS를 돌때 비슷한 조건문을 여러개의 if문으로 나누지 않고 단락조건으로 합쳤었는데 그때도 최적화가 작동되었었나보다.
// 아마 if문 자체가 연산량을 많이 잡아먹는것 같다. 묶을수 있다면 묶어주자.

vector<int> board[2000];
bool visit[2000];
int N, M;
bool isfind = false;

// 모든 순회를 하는 백트래킹 함수. 매번 방문할수 있는 모든 정점을 단 한번씩만 이동하므로 dp가 필요없다.
// 또한 방문 순서에 따라 모든 경우가 달라지므로 dp가 아예 필요없다.
void BackTrack(int here, int move_num)
{
    // 3번에 상술하였듯 원래 나뉘어져 있었다. 하지만 묶을수 있다.
    // 묶을수 있는건 묶어주자.
    if (isfind || move_num >= 4)
    {
        isfind = true;
        return;
    }
    visit[here] = true;

    // 2번에 상술한 범위지정 for문. 속도가 훨씬 더 상승하였다.
    // 자주 애용하자.
    for (int there : board[here])
        if (!visit[there])
            BackTrack(there, move_num + 1);

    visit[here] = false;
}

void MakeAnswer()
{
    // 어떤 점에서 시작하여 4번이상 이동할수 있다면 성공.
    for (int i = 0; i < N; ++i)
    {
        BackTrack(i, 0);
        if (isfind)
        {
            cout << 1 << '\n';
            return;
        }
    }

    cout << 0 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        board[from].push_back(to);
        board[to].push_back(from);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}