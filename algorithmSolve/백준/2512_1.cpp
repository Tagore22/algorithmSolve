#include <iostream>

using namespace std;

// 2512번의 이분탐색 풀이중 첫번째 풀이.
// 이분탐색은 크게 2가지로 나뉜다. 

// 1. for문을 이용하여 무조건 100번의 이분 탐색을 실시하는 풀이.
// 2. while문을 이용하여 시작점과 끝점이 어긋날때까지 탐색을 실시하는 풀이.

// 둘다 일장일단이 있지만 결과적으로 말하자면 이분 탐색이 100번이상일 경우는 1번을
// 그렇지 않을 경우는 2번을 이용하여 풀면 된다. 그래서 각각의 구현을 알아두어야 한다.
// 이번 풀이는 그중 첫번째 풀이다. 모두 같으나 그 구현만 다르다.

// 자세한 설명은 주석으로 남긴다.

int board[10000];
int N, M, cur;

bool CheckSum(int num)
{
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        ans += board[i] > num ? num : board[i];
        if (ans > M)
            return false;
    }
    return true;
}

void MakeAnswer()
{
    // for문을 이용한 구현의 경우 최초 범위가 포함되지 않는 -+1에서 시작된다.
    int left = 0;
    int right = cur + 1;
    // 100번의 무조건적인 이분 탐색.
    for (int i = 0; i < 100; ++i)
    {
        int mid = (left + right) / 2;
        // 성공과 실패시 left 혹은 right가 mid값이 될뿐 추가적인 연산은 없다.
        if (CheckSum(mid))
            left = mid;
        else
            right = mid;
    }
    // 이전 성공값이 left였다. 성공시 변화하는 값을 출력하면 된다.
    cout << left << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        cur = max(cur, board[i]);
    }
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}