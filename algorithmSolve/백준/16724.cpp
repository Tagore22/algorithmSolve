#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 그다지 어려운것도 아닌데 마지막 부분에서 헷갈려 헤맨 문제다.
// 요점은 다음과 같다.

// 1. 순환이 이루어지는 좌표의 경우 최종값 answer을 1을 증가시키고 현재 순환을 이루는 좌표들의 값이
// 그 answer값이 된다.
// 2. 순환이 이루어지지 않은 좌표는 이동끝에 순환이 이루어지는 좌표의 값을 가지어 합쳐지게 된다.

// 이 2가지만 알면 되는 문제다.
// 자세한 설명은 주석으로 남긴다.

char board[1000][1000];
// 각 좌표의 순환값을 저장하는 배열.
int visit[1000][1000];
// 순환값 answer는 0부터 시작할수 없다. 방문하지 않음을 0으로 체크하기 때문이다.
int N, M, answer = 1;

// y, x부터 시작하여 도달할수 있는 모든 좌표들을 순회하며 각 순환값을 갱신하는 함수.
void DFS(int y, int x)
{
    // 현재 순환값 answer로 현재 좌표의 순환값을 초기화한다.
    visit[y][x] = answer;
    int cur_y = y;
    int cur_x = x;

    // 다음 이동값 계산.
    if (board[cur_y][cur_x] == 'U')
        --cur_y;
    else if (board[cur_y][cur_x] == 'D')
        ++cur_y;
    else if (board[cur_y][cur_x] == 'L')
        --cur_x;
    else
        ++cur_x;

    // 여기가 중요한 부분이다. 각 조건에 따라 갈리게 된다.
    
    // 1. 다음 좌표의 순환값이 0일때에는 아직 방문하지 않은 좌표이므로 DFS로 이동한다.
    // 2. 다음 좌표의 순환값이 0이 아닐때
    // 2-1. 다음 좌표의 순환값이 현재와 같을때에는 순환이 일어남으로 다음 순환값 answer을 1 늘리고 탈출한다.
    // 2-2. 현재와 같지 않을때에는 현재 좌표가 순환을 일으키지 않는 좌표이므로 순환을 일으키는 다음 좌표에 속해야한다.
    // 따라서 현재 순환값을 다음 순환값으로 갱신후 탈출한다.
    // 처음 잘못 풀었을때에는 2-2를 재귀적으로 갱신하지 않고 현재 단 한번만 갱신하였었기 때문에 틀렸었다.

    // 다음 순환값이 0이 아닐때.
    if (visit[cur_y][cur_x] != 0)
    {
        // 현재 순환값과 같다면 순환이 일어남으로 순환값 answer을 1 증가시킨다.
        if (visit[cur_y][cur_x] == visit[y][x])
            ++answer;
        // 그렇지 않다면 현재 좌표가 순환을 일으키지 않는 좌표이기에 순환을 일으키는 다음좌표에 속해야 하기에
        // 현재 순환값을 다음 순환값으로 갱신해주어야 한다. 하지만 if ~ else문 이후에 코드와 겹치기에 삭제되었다.
        // else
        // visit[y][x] = visit[cur_y][cur_x];
    }
    // 0이라면 아직 방문하지 않은 좌표이기에 그냥 DFS로 순회한다.
    else
    {
        DFS(cur_y, cur_x);
    }
    // 현재 좌표가 순환이 일어나든 아니든 다음값과 무조건 같아진다.
    // 1. 순환이 일어난다면 두말할것 없이 같아짐.
    // 2. 순환이 일어나지 않는다면 순환이 일어나는 어딘가에 속해야하기에 그값과 같아져야함.
    visit[y][x] = visit[cur_y][cur_x];
}

void MakeAnswer()
{
    memset(visit, 0, sizeof(visit));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (visit[i][j] == 0)
                DFS(i, j);

    // 상술하였듯 시작값이 0이 아닌 1에서 시작되기 때문에 answer - 1을 출력한다.
    cout << answer - 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}