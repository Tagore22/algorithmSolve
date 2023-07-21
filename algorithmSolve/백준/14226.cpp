#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 처음엔 DFS와 dp로 풀려고 한참 고생하다가 알고보니 최소값을 구하는 BFS풀이라는걸 알았다.
// 어이가 없었다. 원래 최소값은 BFS의 영역이었는데;
// 풀이자체는 간단한다. 다음과 같다.

// 1. 현재값(화면값, 클립보드값)이 주어졌을때 움직일수 있는 3가지 행동중 그 조건에 맞는 모든 행동을 취하여
// 방문 여부를 체크후 큐에 집어넣는다.
// 2. 위를 반복하다가 화면값이 S일때 그 값을 출력한다.

// 자세한 설명은 주석으로 남긴다.

int S;

// 상술한 1번을 구현하는 함수.
int BFS()
{
    queue<pair<int, int>> que;
    que.push(make_pair(1, 0));
    bool visit[1001][1001];
    memset(visit, false, sizeof(visit));
    visit[1][0] = true;
    int answer = -1;

    while (!que.empty())
    {
        // 큐에 변수 3개를 넣어서 시간을 따로 체크하는 풀이도 존재했으나 복잡하게 굳이 그럴 필요가 없다.
        // 어차피 하나의 좌표값에서는 단 하나의 값만큼만 존재하기에 이렇게 매번 값을 늘려가며 대입해도 그게 그거다.
        ++answer;
        int Qsize = que.size();
        for (int iter = 0; iter < Qsize; ++iter)
        {
            int M = que.front().first;
            int C = que.front().second;
            que.pop();

            if (M == S)
                return answer;

            // 화면의 이모티콘을 클립보드에 복사하는 경우.
            if (!visit[M][M])
            {
                visit[M][M] = true;
                que.push(make_pair(M, M));
            }

            // 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 하는 경우.
            // 클립보드가 비었다면 불가능하며, 붙여넣었을때 S개의 값을 넘어선다면 굳이 행할필요가 없다.  
            if (C != 0 && M + C <= S && !visit[M + C][C])
            {
                visit[M + C][C] = true;
                que.push(make_pair(M + C, C));
            }

            // 화면의 이모티콘을 하나 삭제하는 경우.
            // 화면의 이모티콘이 아예 없다면 불가능하다.
            if (M > 0 && !visit[M - 1][C])
            {
                visit[M - 1][C] = true;
                que.push(make_pair(M - 1, C));
            }
        }
    }
}

void MakeAnswer()
{
    int answer = BFS();

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}