#include <iostream>
// #include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// 풀이.
// 수학적 접근 문제였기에 명확하지 않았다. 그래도 주어진 범위가 꽤나 작기 때문에 해보았고 성공했다.
// 요약하자면 어떤 수 A를 최소공배수로 가지는 수들은 모두 A의 약수가 되고, 어떤 수 B를 최대공약수를 가지는 수는
// 모두 B의 배수가 된다. 하지만 A의 약수들의 범위가 B의 배수들보다 확연히 적기에 이걸 이용해야했다. 따라서
// A의 모든 약수들을 vector에 저장하고, 이 수들중 2개를 중복되지 않게 골라 최대공약수와 최소공약수를 확인하여
// 두 수의 값이 가장 작은 값들을 출력한다. 하나 주의해야할점은 최소공배수를 구할때 두 수를 곱하는데 입력되는 수의
// 최대값이 1억이기 때문에 int값을 벗어날수 있어 long long으로의 캐스팅이 필요하다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board;
int A, B;

// 최대공약수를 구하는 함수.
int GCD(int l, int r)
{
    if (r == 0)
        return l;
    return GCD(r, l % r);
}

// 최소공배수를 구하는 함수. 상술한대로 int값을 벗어날수 있기 때문에 첫번째 값을
// long long으로 받는다. 근데 GCD의 호출이 중복되기에 밑에서는 그냥 두수의 곱 / 최대공약수로 했다.
// 이거 왜 구현했지.
int LCM(long long l, int r)
{
    return l * r / GCD(l, r);
}

int main()
{
    cin >> A >> B;
    // 에라토스테네스의 체를 응용하여 B의 모든 약수를 조금더 빠르게 구한다.
    int sqrtnum = sqrt(B);
    for (int i = 1; i <= sqrtnum; ++i)
    {
        if (B % i == 0)
        {
            board.push_back(i);
            board.push_back(B / i);
        }
    }
    // 기존에는 정렬을 넣었었다. 다시 생각해보면 어차피 모든 순회를 해야하기에 정렬은 필요없다.
    // sort(board.begin(), board.end());
    // 두 수의 최소값을 구해야하기에 무지막지하게 큰수로 최종답 answer를 초기화한다.
    pair<int, int> answer = make_pair(100000000, 100000000);
    // 모든 조합을 순회하며 최소공배수와 최대공약수가 일치하는 가장 작은 조합을 찾는다.
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = i; j < board.size(); ++j)
        {
            // 최대공약수.
            int g = GCD(board[i], board[j]);
            // 최소공배수. 상술한대로 두수의 곱은 int값을 벗어날수 있기에 첫번째 수를 long long으로 캐스팅함.
            int l = static_cast<long long>(board[i]) * board[j] / g;
            if (g == A && l == B && board[i] + board[j] < answer.first + answer.second)
            {
                int first = min(board[i], board[j]);
                int second = max(board[i], board[j]);
                answer = make_pair(first, second);
            }
        }
    }
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}