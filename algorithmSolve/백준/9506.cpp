#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 이른바 어렵지 않으나 귀찮은 문제였다.
// 매번 주어지는 N의 약수들을 모두 더해 N인지 아닌지 확인하는 문제인데
// 말 그대로 N이 매번 달라지기 때문에 dp 같은 것으로 묶을수도 없었다.
// 따라서 매번 1 ~ N - 1까지 순회하며 모든 약수들을 구해 더한후 비교하는 수밖에 없었다.
// 또한 문제에서 주어진 출력 형태가 매우 귀찮았다. 하지만 어렵지 않으니 집중하면 한번에 풀수 있다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board;
int N;

// 1 ~ N - 1까지 순회하며 약수들을 모두 더해보고 N과 비교하는 함수.
bool MakeSum()
{
    // 약수들을 저장해둘 벡터를 초기화해야한다.
    board.clear();
    int ans = 0;
    for (int i = 1; i < N; ++i)
        if (N % i == 0)
        {
            ans += i;
            // 혹여나 현재 약수들의 합이 N을 넘어간다면 이 이상의 순회는 무의미하므로 바로 false를 반환하며 탈출한다.
            if (ans > N)
                return false;
            board.push_back(i);
        }
    return ans == N;
}

void MakeAnswer()
{
    while (true)
    {
        cin >> N;
        if (N == -1)
            break;

        // 여기서 값을 구해 N과 비교한다.
        bool answer = MakeSum();

        if (answer)
        {
            cout << N << " = ";
            for (int i = 0; i < board.size() - 1; ++i)
                cout << board[i] << " + ";
            cout << board[board.size() - 1] << '\n';
        }
        else
        {
            cout << N << " is NOT perfect." << '\n';
        }
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}