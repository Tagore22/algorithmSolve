#include <iostream>
#include <cstring>

using namespace std;

// 1. 배열이 각 순서에 의해 회전되었을때 최소값을 구한다.
// 2. 순서에 따르기 때문에 idx + 1이 시작값이 아님.
// 3. bool 배열을 이용해서 현재 순서가 이미 진행되었는지 체크해야함.
// 4. 시작값은 계속 0부터. 구한 개수가 K개라면 최소값 계산시작.

// 풀이. 
// 생각보다 복잡한 문제였다. 중복이 주어지는 백트래킹과 배열을 한칸씩 이동하는것 모두 구현해야했다.
// 다만 그것뿐이다. 어렵진 않으나 좌표값등 복잡한게 많았다. 문제의 큰틀은 다음과 같다.

// 1. 백트래킹과 bool 배열을 이용하여 모든 회전들의 조합을 만든다.
// 2. 각 조합별로 배열을 회전시킨뒤 각 행의 합을 더해 최소값을 구한다.
// 3. 모든 회전이 끝났을때 가장 작은 최소값 answer을 출력한다.

// 자세한 설명은 주석으로 남긴다.

// P.S 약간 아쉬운점은 겹치는 연산들이 존재한다는 것이다. 예를 들어 회전이 1, 2, 3번째 3가지가 존재한다면
// 모든 조합은 {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1} 이렇게 6개가 존재한다.
// 아래 풀이로는 {1, 2, 3}일때와 {1, 3, 2}에서 1번째 회전을 2번 회전한다. 그렇지 않고 1번을 회전한 상태에서
// 2번, 혹은 3번을 회전하는 형태라면 연산량을 조금더 줄일수 있을것 같았다. 다만 그렇게 하러면 BackTrack()에서
// 현재 배열 상태를 알아야 한다. 이것은 2가지로 구현할수 있는데

// 1. 회전된 배열 temp를 전역 변수로 둔다.
// 2. BackTrack()의 매개변수로 둔다.

// 이렇게 2가지 경우가 있는데 각각 매우 치명적인 단점이 있다. 
// 1번째 경우에는 AllRotateArray()에서 후술하듯이 이번에 적용된 회전을 재귀 함수를 탈출하기전에 
// 복구시켜야 한다는 것이다. 이 부분에서 많은 연산량을 필요로 한다.
// 2번째 경우에는 말그대로 매번 재귀함수를 호출할때 마다 2차원 배열을 생성 및 복사해야한다는 것이다.
// 참고로 매번 값이 복사되어 연동되면 안되기에 포인터나 참조자 역시 사용할수 없다. 

// 이러한 크나큰 단점이 존재하기에 결국엔 아래 풀이대로 풀었다. 복잡하고 귀찮은 문제였으나 이것저것 생각하게 되는
// 나름 좋은 문제였던것 같다.

int board[101][101], temp[101][101], r_board[6][3];
int rot[6];
bool visit[6];
int N, M, K, answer = 987654321;

// 배열을 회전시키는 함수.
void RotateArray(int r, int c, int s)
{
    // 이부분이 제일 복잡했다. 시작점을 구하는 것과 4번의 이동중
    // 어디까지 도달해야하는지 구하는게 꽤 오래걸렸다.
    // 정답은 s에 존재하였다. s를 하나씩 줄여가면 모든게 해결되었다.
    for (int iter = s; iter > 0; --iter)
    {
        int from = temp[r - s][c - s];
        for (int i = r - s; i < r + s; ++i)
            temp[i][c - s] = temp[i + 1][c - s];
        for (int j = c - s; j < c + s; ++j)
            temp[r + s][j] = temp[r + s][j + 1];
        for (int i = r + s; i > r - s; --i)
            temp[i][c + s] = temp[i - 1][c + s];
        for (int j = c + s; j > c - s + 1; --j)
            temp[r - s][j] = temp[r - s][j - 1];

        // temp[r - s][c - s]는 맨처음에 변경되었음으로 여기서 그대로 변경하면
        // 답이 나오질 않는다. 처음에 복사해둔 from을 대입해야한다.
        temp[r - s][c - s + 1] = from;
        // s를 줄이는 이 연산만 있으면 간단하게 구현가능하다.
        --s;
    }
}

// 모든 회전을 실행한뒤 각 행의 최소값을 구하는 함수.
void AllRotateArray()
{
    // 실제 배열값 board를 회전시키면 다시 원상태로 돌리가가 까다롭기 때문에
    // 복사값 temp를 이용해야한다.
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            temp[i][j] = board[i][j];

    // 주어진 조합의 순서대로 배열을 회전시킨다.
    for (int i = 0; i < K; ++i)
    {
        int idx = rot[i];
        int r = r_board[idx][0];
        int c = r_board[idx][1];
        int s = r_board[idx][2];

        RotateArray(r, c, s);
    }

    // 각 행별로 최소값들을 찾아본다.
    for (int i = 1; i <= N; ++i)
    {
        int ans = 0;
        for (int j = 1; j <= M; ++j)
            ans += temp[i][j];
        answer = min(answer, ans);
    }
}

// 모든 조합을 만드는 함수. 모든 조합을 만들어야 하기에 bool 배열을 이용하여
// 이전에 사용된 회전인지 확인해가며 나아가야 한다.
void BackTrack(int num)
{
    // K개의 회전을 모두 골랐다면.
    if (num == K)
    {
        // 여기서 현재 배열의 최소값 계산.
        AllRotateArray();
        return;
    }

    // 모든 회전들을 순회한다.
    for (int i = 0; i < K; ++i)
    {
        // 아직 사용하지 않은 회전이라면 이번 순서에 집어넣고 다음으로 넘어간다.
        if (!visit[i])
        {
            visit[i] = true;
            rot[num] = i;
            BackTrack(num + 1);
            visit[i] = false;
        }
    }
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));
    BackTrack(0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];

    for (int i = 0; i < K; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> r_board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}