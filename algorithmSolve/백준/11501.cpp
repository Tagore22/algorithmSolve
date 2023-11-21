#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 각 일별로 주식의 가격이 주어질때 1. 그 날 주식을 사거나 2. 이전의 가진 주식을 팔거나 3. 아무것도 안할수도 있다.
// 이때 얻을수 있는 최대 이익을 구하는 문제다. 결과적으로 가격이 가장 높은 날까지 전부 샀다가 팔면 되는 문제다.

// 자세한 설명은 주석으로 남긴다.

int board[1000000];
int T, N;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        // 가격이 높은 날들을 알기 위한 우선순위 큐.
        priority_queue<pair<int, int>> que;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            // 일자별로 주식의 가격을 입력받고 우선순위 큐를 이용하여 정렬한다.
            cin >> board[i];
            que.push(make_pair(board[i], i));
        }

        int idx = 0;
        long long answer = 0;
        // 인덱스가 N보다 작은동안 계속 반복한다.
        while (idx < N)
        {
            // 현재 가장 높은 가격 num과 그 일자 here를 구한다.
            int num = que.top().first;
            int here = que.top().second;
            que.pop();

            // 현재 원소값보다 크거나 같다면 
            if (idx <= here)
            {
                // here전까지 얻을수 있는 이득들을 모두 더한다.
                for (int i = idx; i < here; ++i)
                    answer += num - board[i];

                // here에 팔것이기에 인덱스는 here + 1이 된다.
                idx = here + 1;
            }
        }

        // 현재 얻을수 있는 최대 이익을 출력한다.
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}