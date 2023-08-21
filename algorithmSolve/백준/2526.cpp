#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// 풀이.
// 처음에 풀때에는 너무 마구잡이로 풀었다. 싸이클을 돌다보면 언젠가부터 반복되는 부분이 생기는데
// 이것이 반드시 N * N % P, 즉 두번째 나누기부터일리는 없기 때문이다.
// 이 풀이는 만들어지는 값 L을 벡터에 하나씩 추가하며 bool배열로 해당 수의 등장여부를 체크한다.
// 싸이클을 순회하다가 이미 등장한 수가 또 등장한다면 벡터에서 그 수의 순서를 찾아
// 등장한 수에서 현재 수의 등장 순서를 빼서 최종값을 구한다.
// 다만 굳이 필요없는 것들이 꽤나 많았다. 최적화된 풀이는 다음 풀이에 추가한다.

// 자세한 설명은 주석으로 남긴다.

bool board[97];
int N, P;

void MakeAnswer()
{
    // 어떤 수 i가 등장했는지의 대한 여부를 저장하는 bool 배열.
    memset(board, false, sizeof(board));
    board[N] = true;
    // 여태까지 등장한 수들을 저장하는 벡터.
    vector<int> ans;
    ans.push_back(N);
    int cur = N;
    int answer;
    // 무한대로 싸이클을 순회하다가 이미 등장한 수가 또 등장할경우
    // 현재 등장한 수들의 합 - 현재 수의 등장 순서를 출력한다.
    while (true)
    {
        cur = cur * N % P;
        if (board[cur])
        {
            for (int i = 0; i < ans.size(); ++i)
                if (ans[i] == cur)
                {
                    answer = i;
                    break;
                }
            break;
        }
        else
        {
            ans.push_back(cur);
            board[cur] = true;
        }
    }
    answer = ans.size() - answer;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> P;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}