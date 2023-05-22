#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 풀이.
// 예전에 종만북에서 봤던 최대힙, 최소힙과 비슷한 문제다.
// 두개의 deque를 만들어서 수들을 정렬하여 순서대로 앞과 뒤에 넣는다.
// 그리고 deque들을 순회하며 인접하는 수들의 차이의 절대값중 가장 큰값을 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[10000];
int T, N;

void MakeAnswer()
{
    deque<int> first, second;
    for (int test = 0; test < T; ++test)
    {
        first.clear();
        second.clear();
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> board[i];

        sort(board, board + N);

        // 각 수들을 순서대로(짝수일때는 first에, 홀수일때는 second에) 넣는다.
        for (int i = 0; i < N; ++i)
        {
            if (i % 2 == 0)
                first.push_back(board[i]);
            else
                second.push_front(board[i]);
        }

        // 맨처음 수와 맨 뒤의 수를 가장 최초로 비교한다.
        int answer = abs(first[0] - second[second.size() - 1]);
        // first의 두번째 수부터 맨끝까지 자신의 한칸 앞과 차이를 구한다.
        for (int i = 1; i < first.size(); ++i)
            answer = max(answer, abs(first[i] - first[i - 1]));

        // first의 맨 끝값과 second의 맨 처음 값을 계산한다.
        answer = max(answer, abs(first[first.size() - 1] - second[0]));
        // 마지막으로 second의 두번째 수부터 맨끝까지 자신의 한칸 앞과 차이를 구한다. 
        for (int i = 1; i < second.size(); ++i)
            answer = max(answer, abs(second[i] - second[i - 1]));

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