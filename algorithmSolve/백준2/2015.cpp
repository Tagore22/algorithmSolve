#include <iostream>
#include <unordered_map>

using namespace std;

// 풀이.
// 언젠가 풀었던 누적합과 map을 이용한 문제다. 등장하는 누적합의 개수는
// N과 같은 최대 20만개지만 각 누적합의 범위가 -20억 ~ 20억이기 때문에
// 평범한 배열로는 불가능하여 map을 사용해야만 한다. 문제의 로직은
// i ~ j의 누적합의 점화식은 sum[j] - sum[i - 1]이다. 이 값이 K라는 것은 
// sum[j] - sum[i - 1] = K이고, sum[i - 1] = sum[j] - K가 된다.
// 즉, 현재 원소까지의 누적합 - K의 개수를 구하면 되는 것이다. 
// sum[j]가 아닌 sum[i - 1]을 이용하는 이유는 이전의 값은 명확하지만
// 앞으로의 값은 알 수 없기 때문이다.또한, 부분 누적합의 개수가 
// N * (N + 1) / 2인데 N이 최대 20만이기에 int값을 벗어난다. 
// long long 타입을 사용해야만 한다.

// 자세한 설명은 주석으로 남긴다.

int N, K, sum = 0;
unordered_map<int, long long> board;
long long answer = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    board[0] = 1;

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        sum += num;
        // 기존에는 단순히 if(board[sum - K])를 사용했는데 이것은
        // board[sum - K]값이 존재하지 않을때 무조건 새로운 값을
        // 생성하기에 매우 느리고 용량도 엄청 잡아먹는다.
        // 따라서 count() 혹은 find()를 이용하여 체크해야한다.
        if (board.count(sum - K))
            answer += board[sum - K];
        ++board[sum];
    }
    cout << answer << '\n';
    return 0;
}