#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//풀이
//1번부터 N번까지 이동하는 트럭으로 택배를 배송할때 실어야할 택배의 우선순위는 다음과 같다.
//1. 최대한 많이 내려야 최대한 많이 실을수 있으므로 빨리 내릴수 있는것(도착 장소가 1번에서 가까운것)
//2. 위와 마찬가지로 최대한 빨리 내려야함으로 다른말로 표현하면(실은 장소가 도착장소와 가까운것)
//이 2가지이다.

//위 2가지 조건에 의해 주어지는 택배들을 정렬하되 그 방식은 다음과 같다.
//1. 받는 장소가 오름차순으로 정렬될것. (위 조건에 1번에 부합)
//2. 받는 장소가 같을때 실은 장소가 빠른 것이 더 앞에 올것. (위 조건에 2번에 부합)

//이렇게 정렬이 끝나면 모든 택배들을 순회하며 각 도시에서 실을수 있는 무게를 구하고 총 무게값에 그 값을 더해준다.
//택배를 실는 곳인 from부터 배송하는 곳 - 1인 to까지 다시 순회하며 각 도시에서의 현재 최대 무게를 구한다.
//그리고 현 택배의 무게와 최대 무게(C) - 현재 최대 무게를 뺀값중 최소값이 from부터 to까지 통틀어 추가할수 있는 무게 now_capa다.
//이 값을 from부터 to까지 모두 더해 주며 또한 출력해야할 총값 answer에 더해줌으로써 순회의 일부를 완성한다.
//이 순회가 끝난후 최종값 answer을 반환한다.

struct box
{
    int from;
    int to;
    int num;
};

int capa[10001];
box board[10000];
int N, C, M;

bool ComposeFunc(const box& first, const box& second)
{
    if (first.to != second.to)
        return first.to < second.to;
    else
        return first.from < second.from;
}

void MakeAnswer()
{
    int answer = 0;
    sort(board, board + M, ComposeFunc);

    for (int i = 0; i < M; ++i)
    {
        int max_capa = 0;
        for (int iter = board[i].from; iter < board[i].to; ++iter)
            max_capa = max(max_capa, capa[iter]);

        int now_capa = min(board[i].num, C - max_capa);

        answer += now_capa;
        for (int iter = board[i].from; iter < board[i].to; ++iter)
            capa[iter] += now_capa;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(capa, 0, sizeof(capa));

    cin >> N >> C >> M;
    for (int i = 0; i < M; ++i)
        cin >> board[i].from >> board[i].to >> board[i].num;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}