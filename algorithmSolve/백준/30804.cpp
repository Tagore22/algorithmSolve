#include <iostream>

using namespace std;

// 풀이.
// 투포인터는 2가지 경우에 쓰인다. 첫째는 범위를 구할때이고, 둘째는 정렬된 상태에서의 두 값이다.
// 이 문제에는 첫째를 쓴다. 범위값 from과 to는 모두 0에서 시작하며 오른쪽으로 1칸씩 늘려간다.
// 이 때의 조건은 이미 등장한 수이거나, 현재 등장한 수의 종류가 1개일때이다. 그렇지 않다면
// from을 1씩 늘려 범위값을 줄여나가야 한다.

// 자세한 설명은 주석으로 남긴다.

int board[200000], counts[10];
int N, answer = -1;

void MakeAnswer()
{
    // 범위값 from과 to는 모두 0에서 시작하며 등장한 수의 종류인 num은 1로 시작한다.
    int from = 0, to = 0, nums = 1;
    counts[board[from]] = 1;
    // from이 to보다 커질일은 절대 없으며, to가 N과 같거나 커질때까지 반복한다.
    while (to < N)
    {
        // 오른쪽값이 이미 등장한 수이거나, 현재 등장한 수의 종류가 1개일때에는 to를 1 증가시켜
        // 범위값을 늘린다.
        if (counts[board[to + 1]] >= 1 || nums < 2)
        {
            ++to;
            ++counts[board[to]];
            nums = counts[board[to]] == 1 ? nums + 1 : nums;
        }
        // 그렇지 않을 경우 from을 1 증가시켜 범위값을 줄여간다.
        else
        {
            answer = max(answer, to - from + 1);
            --counts[board[from]];
            nums = counts[board[from]] == 0 ? nums - 1 : nums;
            ++from;
        }
    }
    // 만약 같은 1개가 여러번 등장하면 answer는 -1에서 변하지 않는다.
    answer = answer == -1 ? N : answer;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}