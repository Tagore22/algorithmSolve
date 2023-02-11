#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 풀이
// 2개의 우선순위큐를 생성한다. max_top은 M/2개중 작은수들을 가지는 쪽이고, min_top은 큰수들을 가지는 쪽이다.
// M개의 수를 max_top부터 넣되, 큰수들중 가장 작은 min_top.top()이 작은수들중 가장 큰수인 max_top.top()보다 크다면
// 두개를 교환해준다. 이것을 M번 반복하며 홀수번마다 현재 중앙값 즉, max_top.top()을 최종값 answer에 저장해주고
// M번의 순회가 끝나면 answer의 크기와 원소값들을 출력해주면 된다.

// 이 풀이는 우선순위큐를 생성시 정렬값을 건드리지 않고 삽입과 반환때 -연산을 해주어 처리했는데, 주어지는 입력값이
// 매우 크거나 작을때 -연산을 하니 int에서 범위가 벗어났었다. 매번 -연산도 해야하고 범위값을 벗어날 경우도 있으니,
// 그냥 생성시 좀더 길어도 정렬값을 바꿔주어야겠다.

int T;

void MakeAnswer()
{
    int M;
    vector<long long> answer;
    for (int i = 0; i < T; ++i)
    {
        priority_queue<long long> max_top, min_top;
        answer.clear();
        cin >> M;
        long long num;
        for (int j = 1; j <= M; ++j)
        {
            cin >> num;
            if (max_top.size() == min_top.size())
                max_top.push(num);
            else
                min_top.push(-num);

            if (!max_top.empty() && !min_top.empty() && max_top.top() > -min_top.top())
            {
                long long from_min = -min_top.top();
                min_top.pop();
                long long from_max = max_top.top();
                max_top.pop();
                min_top.push(-from_max);
                max_top.push(from_min);
            }

            if (j % 2 != 0)
                answer.push_back(max_top.top());
        }

        cout << answer.size() << '\n';
        for (int i = 0; i < answer.size(); ++i)
        {
            if (i != 0 && i % 10 == 0)
                cout << '\n';
            cout << answer[i] << ' ';
        }
        cout << '\n';
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