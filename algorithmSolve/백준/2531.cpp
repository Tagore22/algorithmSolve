#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 최대한 집을수 있는 초밥 가짓수의 최대값을 출력하는 문제이다.
// 결과적으로 첫번째 초밥부터 맨 마지막까지 k개씩 집어서 그때마다 가짓수를 확인해야하는데
// 예전에 풀었던 누적합 비스므리한 원리로 풀었다. 우선 필요한 것은 다음과 같다.

// 1. 초밥들의 정보가 담긴 배열 board.
// 2. n번 초밥을 몇번 집었는지 확인하는 배열 check.

// 따라서 현재 초밥을 집을때 check[현재 초밥 번호]를 매번 증가시키고 감소시키며 갱신해나갈것이다.
// 또한 처리해주어야 할일이 있는데 그것은 바로 board에 내용을 추가하는 것이다.
// 회전 초밥이기 때문에 맨 마지막 N번째에서는 0번째, 1번째.... k - 2번째 초밥까지 다시 집어야하기 때문이다.
// 원형 큐같은것으로 풀어도 되지만 나는 그냥 0 ~ k - 2번값들을 board뒤에 추가함으로써 손쉽게 처리했다.

// 그럼 준비는 끝냈고 문제를 푸는 원리를 보자면 다음과 같다.

// 1. 초기에 0 ~ k - 2번값들을 미리 계산해놓는다.
// 2. 그 후 K - 1번부터 board.size() - 1까지 반복하여 최대값을 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board, check;
int N, d, k, c;

void MakeAnswer()
{
    // 초창기 K개를 집는다.
    // 배열 혹은 벡터에 현재 집은 초밥들의 개수를 체크한다.
    // 또한 현재 개수를 초기에 체크한다.
    // 쿠폰 번호의 초밥이 현재 집지 않은 상태라면 현개 개수를 1 증가시킨다.
    // 반복.

    // 원형으로 돌아야하기 때문에 0 ~ k - 2까지의 원소값을 뒤에 추가한다.
    for (int i = 0; i < k - 1; ++i)
        board.push_back(board[i]);
    int bsize = board.size();
    check.resize(d + 1, 0);

    //0 ~ k - 2의 초창기 값들을 미리 구한다.
    int cur = 0, answer = 0;
    for (int i = 0; i < k - 1; ++i)
    {
        if (check[board[i]] == 0)
            ++cur;
        ++check[board[i]];
    }

    int plus;
    // k - 1번부터 board.size() - 1까지 순회하며 앞의 값을 빼고 뒤의 값을 더하는 것을 반복한다.
    for (int i = k - 1; i < bsize; ++i)
    {
        plus = 0;
        // 이번에 집는 초밥이 새로 집는 것이라면 가짓수가 증가한다.
        if (check[board[i]] == 0)
            ++cur;
        ++check[board[i]];
        // 쿠폰으로 얻을수 있는 초밥이 새로 집는것이라면 가짓수가 증가한다.
        if (check[c] == 0)
            plus = 1;

        answer = max(answer, cur + plus);
        // 가장 최근에 집었던 초밥을 뺀다. 다만 이후에 이 종류의 초밥이 없다면 가짓수가 감소한다.
        --check[board[i - k + 1]];
        if (check[board[i - k + 1]] == 0)
            --cur;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> d >> k >> c;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        board.push_back(num);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}