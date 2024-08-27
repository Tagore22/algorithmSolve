#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 예전에 엄청 풀어봤던 LIS 문제다. 하지만 오랜만이라 그런가 전혀 생각이 안나 예전 풀이를 봤다.
// 결과적으로는 하나의 vector안에 맨 처음 원소부터 넣어보면서 vector의 가장 큰 원소보다 현재 넣으려고 하는
// 원소가 더 크다면 그대로 넣고 그렇지 않다면 lower_bound()를 이용하여 새로운 위치를 잡아 덮어씌우는 형식이다.
// 그렇게 vector의 길이가 LIS의 길이가 되는데 N에서 이것을 빼주면 된다. 왜냐하면 LIS에 포함되는 원소들은
// 이미 위치가 잡혀져있기 때문에 건드릴 필요가 없고 나머지 원소들을 최소 한번씩은 움직여주어야 하기 때문이다.
// LIS의 길이뿐만 아니라 그 원소들을 알아야하는 풀이는 14003에 있다. 살짝만 기술하자면 하나의 vector 이외에
// pair<int, int> 형식의 vector를 생성하여 같이 집어넣어주되, 첫번째 int에 인덱스값을 넣어준다. 모든 삽입 이후
// 맨 뒤부터 다시 순회하며 LIS의 순서와 일치하는 원소들을 최종값 answer에 넣어준다. 이것들이 바로 LIS가 된다.

// 자세한 설명은 주석으로 남긴다.

vector<int> answer;
int board[200000];
int N;

void MakeAnswer()
{
    // 맨 첫번째 원소는 비교가 불가능하기에 무조건 집어넣어준다.
    answer.push_back(board[0]);
    for (int iter = 1; iter < N; ++iter)
    {
        // 현재 가지고 있는 수들중 가장 큰 원소보다 현재 넣으려고 하는 원소가 더 크다면
        // 그냥 집어넣는다.
        if (answer.back() < board[iter])
        {
            answer.push_back(board[iter]);
        }
        // 그렇지 않다면 lower_bound()를 이용하여 그 위치를 찾아 덮어씌워준다.
        // 이것이 핵심이다.
        else
        {
            int idx = lower_bound(answer.begin(), answer.end(), board[iter]) - answer.begin();
            answer[idx] = board[iter];
        }
    }
    // 상술한대로 LIS의 원소들을 이미 위치가 잡혔다고 가정하고 그 이외의 것들은 최소한 한번씩은 이동을 해주어야
    // 하기에 N - LIS의 길이를 출력한다.
    cout << N - answer.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int cur;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}