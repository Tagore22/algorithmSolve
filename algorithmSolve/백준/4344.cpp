#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 예전에 풀었는데 재채점되었을때 틀린 문제였다.
// 최종답의 반올림이 안되어 있던것 같은데 1000을 곱해서 반올림 후 다시 1000을 나누면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board;
int C;

void MakeAnswer()
{
    for (int iter = 0; iter < C; ++iter)
    {
        board.clear();
        int idx;
        cin >> idx;
        int sum = 0;
        for (int i = 0; i < idx; ++i)
        {
            int num;
            cin >> num;
            board.push_back(num);
            sum += num;
        }
        double aver = static_cast<double>(sum) / idx;
        int upper = 0;
        for (int i = 0; i < idx; ++i)
        {
            if (board[i] > aver)
                ++upper;
        }
        double answer = upper / static_cast<double>(idx) * 100;
        // 바로 이 부분이 틀렸던 듯하다.
        // 상술하였듯 1000을 곱해 실제로는 소수 4번째 자리가 반올림 대상이 되게끔 한다.
        answer *= 1000;
        // 4번째 자리가 반올림된다.
        answer = round(answer);
        // 다시 1000을 나누어 원래대로 되돌린다.
        answer /= 1000;
        cout.precision(3);
        cout << fixed;
        cout << answer << '%' << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> C;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}