#include <iostream>

using namespace std;

// 이분 탐색의 두번째 풀이. for문이 아니라 while문을 사용한다.

// 1. while문을 이용한 풀이는 시작점과 끝점이 엇갈려야 끝나기에
// mid로의 변환 이후 추가적인 연산이 필요함.
// 2. 그러므로 초기 범위의 연산이 필요하지 않음.
// 3. for문은 무조건 100번을 실시한후 탈출하기에 mid로의 변환 이후 추가적인 연산이 필요없음.
// 4. 그러므로 초반 범위의 -1, +1의 추가적이 연산이 필요함.

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
    // 범위는 for문과 다르게 모두 포함되어 있는 상태에서 시작한다.
    int left = 0;
    int right = cur;
    // left와 right가 엇갈릴때까지 실시함.
    while (left <= right)
    {
        int mid = (left + right) / 2;
        // 엇갈려야 하기에 mid로의 변환 이후 추가적인 연산이 있다.
        if (CheckSum(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    // 가장 최근 정답이 mid 였고 left는 mid + 1이었으므로 left - 1이 가장 최근 정답이다.
    cout << left - 1 << '\n';
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