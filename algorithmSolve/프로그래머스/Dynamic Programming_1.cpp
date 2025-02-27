#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// 풀이.
// 프로그래머스 문제를 풀어보았는데 하도 오랜만이라 레벨3이 어느정도 난이도인지 가늠이 되지 않았다.
// 생각보다 난이도가 있었는데 단순 사칙연산이 아닌 연달아 N을 붙이는 경우도 생각해야했다. 또한 중복을
// 방지하기 위해 set을 사용해야했으나 굳이 정렬이 필요없었으므로 unordered_set이 올바른듯 했다.

// 자세한 설명은 주석으로 남긴다.

int solution(int N, int number) {
    if (N == number)
        return 1;

    // 상술했듯 중복을 방지하기 위한 set. 다만 정렬은 필요없으므로 unordered_set을 사용한다.
    vector<unordered_set<int>> Board(9);

    for (int i = 1; i <= 8; ++i)
    {
        int num = 0;
        // 사칙연산이 아닌 N에 N을 덧붙여 NN으로 만드는 경우.
        for (int j = 1; j <= i; ++j)
            num = num * 10 + N;
        Board[i].insert(num);

        // 더해서 i개가 되는 수들을 사칙연산을 통해 모든 경우를 따진다.
        for (int j = 1; j < i; ++j)
        {
            for (auto& num1 : Board[j])
            {
                for (auto& num2 : Board[i - j])
                {
                    Board[i].insert(num1 + num2);
                    Board[i].insert(num1 - num2);
                    Board[i].insert(num1 * num2);
                    if (num2 != 0)
                        Board[i].insert(num1 / num2);
                }
            }
        }
        // i번째에서 number를 만들었는가.
        if (Board[i].count(number))
            return i;
    }
    return -1;
}