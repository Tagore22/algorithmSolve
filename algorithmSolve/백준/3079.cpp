#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 23퍼라는 정답율답게 어려운 문제였다. 애시당초 M의 크기가 최대 10억이므로 평범하게는 풀수가 없는데, 매개변수 탐색을
// 해야한다. 그럼 시간이 주어질때 그 시간안에 검사가 되는지를 알아야하는데 그건 각 심사시간들로 나눈 값들을 모두 더하여
// M보다 크거나 같을때로 알수 있었다. 다만 몇가지 실수로 인해 시간을 잡아먹었다. 이는 후술한다.

// 자세한 설명은 주석으로 남긴다.

int board[100000];
long long N, M;

// 시간 mid가 주어질때 이 시간안에 모든 심사가 끝나는지 확인하는 함수.
bool CheckMid(long long mid)
{
    long long sum = 0;
    for (int i = 0; i < N; ++i)
        // 상술한대로 mid / 각 심사별 시간을 나눈 값의 총합으로 알수있다.
        sum += mid / board[i];
    return sum >= M;
}

void MakeAnswer()
{
    sort(board, board + N);
    // 최대 범위가 문제였다. 처음에는 long long의 최대값을 넣었는데 아마 left + right 부분에서
    // 오버플로우가 나는듯 하다. 따라서 가장 심사 시간이 빠른값 * M으로 최대값을 줄수 있다. 이 값은
    // 10의 18제곱이 되는데 long long보다 한참 작기에 오버플로우를 피할수 있다. 또한 left의 초기값을
    // 0으로 잡았다. 매개 변수 탐색의 두번째 방법인 for문을 100번 돌리는것과 헷갈린듯하다. 주의하자.
    long long left = 1, right = board[0] * M, mid;
    // 여기도 실수가 있었다. mid는 left - 1 혹은 right - 1이기 때문에 마지막에는 무조건 둘의 값이 엇갈리게 된다.
    // 따라서 while문에 둘이 같을때에도 조건이 유효해야하는데 이 부분을 헷갈렸다.
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (CheckMid(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    // 이 부분도 실수했다. while문에 조건에 의하여 while문이 끝나기 마지막 상태는 left와 right가 같은 상태가 된다.
    // 이때 2가지로 나뉘게 되는데 

    // 1. 성공했을때 right는 -1이 되면서 정답 - 1이 된다. left는 변함이 없으므로 이것이 정답이다.
    // 2. 실패했을때 left는 +1이 되면서 기존에 성공했던 가장 작은 값이 된다. 그러므로 이것이 정답이다.
    cout << left << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}