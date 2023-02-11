#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 2696번의 우선순위큐 생성시 정렬값을 바꿔준 풀이.
// 주어진 값은 모두 int이며 이전풀이와는 다르게 - 연산으로 인해 int값의 범위를 넘는 일이 없으므로, 
// long long타입의 우선순위큐를 만들 필요도 없다. 또한, 매번 원소값을 건드릴때 -연산을 하지 않아도 된다.
// 생성시 좀 템플릿값이 길어지긴 하나 이후가 훨씬 편하니 앞으로도 이렇게 해야겠다.

int T;

void MakeAnswer()
{
    int M;
    vector<int> answer;
    for (int i = 0; i < T; ++i)
    {
        priority_queue<int> max_top;
        priority_queue<int, vector<int>, greater<int>> min_top;
        answer.clear();
        cin >> M;
        int num;
        for (int j = 1; j <= M; ++j)
        {
            cin >> num;
            if (max_top.size() == min_top.size())
                max_top.push(num);
            else
                min_top.push(num);

            if (!max_top.empty() && !min_top.empty() && max_top.top() > min_top.top())
            {
                int from_min = min_top.top();
                min_top.pop();
                int from_max = max_top.top();
                max_top.pop();
                min_top.push(from_max);
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