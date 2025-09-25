#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 정답율이 보여주듯 어려운 문제였다. 처음에는 백트래킹으로 로직을 구현했으나
// 100개중 50개만 골라도 어마무시한 연산량이 요구되었기에 시간초과가 났다.
// 그 이후 이진탐색으로 로직을 새로 짰다. 최대값을 이진탐색으로 구한 후에
// 구슬들을 순회하며 나눌 수 있는 부분들을 구하는 방식이다. 다만, 이 이후에
// 추가적인 작업이 필요했는데 예를 들어 6, 4, 1, 1, 1, 1, 1, 1일때
// 이진탐색만으로 구하면 2, 2, 2의 세 부분으로 나누어지게 되어 제대로 된
// 답을 구할 수 없다. 1, 2, 1, 1 등으로 한번 더 M에 맞게끔 부분 수를 조절해주어야 한다.

// 자세한 설명은 주석으로 남긴다.

int N, M;
int board[300];
vector<int> cur, answer;

// 최대값 mid가 주어질 때 몇개의 그룹으로 나눌 수 있는 지
// 계산하는 함수.
bool CheckMid(int mid)
{
    cur.clear();
    int sum = 0, from = 0, num = 0;
    for (int i = 0; i < N; ++i)
    {
        if (sum + board[i] > mid)
        {
            cur.push_back(i - from);
            from = i;
            sum = 0;
            ++num;
        }
        sum += board[i];
    }
    cur.push_back(N - from);
    ++num;

    return num <= M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int sum = 0, maxval = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        sum += board[i];
        maxval = max(maxval, board[i]);
    }

    int from = maxval, to = sum;
    while (from <= to)
    {
        int mid = (from + to) / 2;
        if (CheckMid(mid))
        {
            answer = cur;
            to = mid - 1;
        }
        else
        {
            from = mid + 1;
        }
    }

    // 상술한 추가 작업.
    while (answer.size() < M)
    {
        for (int i = 0; i < answer.size(); ++i)
        {
            if (answer[i] > 1)
            {
                --answer[i];
                answer.insert(answer.begin() + i, 1);
                // 처음에는 그냥 맨 앞에 추가해주면 될 줄 알았는데
                // 논리적으로 맡게 하기 위해서는 나눈 부분 바로 앞에 추가해주어야 한다.
                break;
            }
        }
    }
    cout << to + 1 << '\n';
    for (auto& here : answer)
        cout << here << ' ';
    cout << '\n';
    return 0;
}