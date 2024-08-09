#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 문제가 어렵다기 보다는 문제를 어떻게 받아들이냐가 어려웠던 문제다. 다만 그 부분에서
// 깨달은 점이 많았던 문제이기도 하다. 처음에는 주먹구구식으로 3중 for문을 생각했다.
// 당연히 N의 3제곱인 10억이기에 시간초과가 난다. 결국 다른 풀이를 보았는데 이 3중 for문을
// 나누어버렸다. 즉 한번에 3개의 수들의 합이 아닌 2개의 수의 합을 구해 다시 2중 for문을 통해
// 비교하는 것이다. 이러면 최대 연산량은 1000 * 1000 + 1000 * 1000 * log1000이 되어
// 시간초과를 피할수 있게 된다. 잘 기억해두어야겠다. 또한, 잘 안써먹었던 STL의 함수 binary_search를
// 사용하였는데 매개변수는 각각 범위의 시작, 범위의 끝, 찾을 값이다. 범위내에 찾을 값이 있는지에 대한
// 여부를 이분탐색하여 bool값으로 반환한다. 이것도 잘 기억해두자.

// 자세한 설명은 주석으로 남긴다.

int board[1000];
vector<int> sum;
int N;

// a, b, c의 합인 d가 배열안에 존재해야함.
// 즉 a + b를 구해놓은후 배열안의 어떠한 두 수 y - x가 
// a + b와 같다면 y가 가장 큰수가 된다.

void MakeAnswer()
{
    // 3개의 수들의 합중 2개의 수의 합만 구한다. 연산량은 최대 1000 * 1000으로 100만.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            sum.push_back(board[i] + board[j]);

    // 가장 큰수부터 대입해보기 위해 정렬한다.
    sort(board, board + N);
    // 이분탐색을 위해 정렬한다.
    sort(sum.begin(), sum.end());

    // a - b의 값이 기존에 구해놓은 두 값의 합이라면 마지막 세번째 값은 b가 되고 
    // 세 수의 합은 a가 된다. 따라서 제일 큰 수 a를 구하기 위해 정렬하여 가장 큰수부터
    // 확인하며 내려간다.
    for (int i = N - 1; i >= 0; --i)
        for (int j = i; j >= 0; --j)
            // 두수 board[i] - board[j]가 이미 구해놓은 두 수의 합이라면 세번째 수는 board[j]가 되며
            // 세 수의 합은 board[i]가 된다.
            if (binary_search(sum.begin(), sum.end(), board[i] - board[j]))
            {
                cout << board[i] << '\n';
                return;
            }
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