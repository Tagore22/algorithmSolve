#include <iostream>

using namespace std;

// 풀이.
// 빨간공과 파란공을 같은색끼리 뭉치게끔 옮길때 가장 최소한의 횟수를 출력하면 된다.
// 처음에는 완전탐색을 생각했으나 최대 길이가 50만이라 불가능했다. 답은 의외로 간단했는데
// 어떤색의 공을 왼쪽, 혹은 오른쪽으로 이동시켰을때의 횟수를 비교해보면 된다.

// 1. 파란공을 왼쪽으로
// 2. 파란공을 오른쪽으로
// 3. 빨간공을 왼쪽으로
// 4. 빨간공을 오른쪽으로

// 이 4번의 비교끝에 가장 짧은 횟수를 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

string str;
int N, answer = 987654321;

// 4번의 비교전에 이미 같은색끼리 뭉쳐있는지 비교하는 함수.
bool CheckArray()
{
    int num = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        if (str[i] != str[i + 1])
            ++num;
    }

    return num <= 1;
}

// 각 공을 한쪽으로 이동시키는 함수.
void MoveBall(char first, char second, bool isFirst)
{
    int ans = 0, idx;
    // 처음부터 시작이라면 왼쪽부터 탐색한다.
    if (isFirst)
    {
        // 왼쪽부터 first를 찾는다. 이 이후의 공부터 왼쪽으로 이동시킬수 있다.
        for (int i = 0; i < N; ++i)
        {
            if (str[i] == first)
            {
                idx = i;
                break;
            }
        }
        // first 이후부터 이동가능한 공들의 수를 구한다.
        for (int i = idx + 1; i < N; ++i)
        {
            if (str[i] == second)
                ++ans;
        }
    }
    // 처음부터 시작이 아니기에 오른쪽부터 탐색한다.
    else
    {
        // 오른쪽부터 first를 찾는다. 이 이후의 공부터 오른쪽으로 이동시킬수 있다.
        for (int i = N - 1; i >= 0; --i)
        {
            if (str[i] == first)
            {
                idx = i;
                break;
            }
        }
        // first 이후부터 이동가능한 공들의 수를 구한다.
        for (int i = idx - 1; i >= 0; --i)
        {
            if (str[i] == second)
                ++ans;
        }
    }
    // 가장 최소값을 찾는다.
    answer = min(answer, ans);
}

void MakeAnswer()
{
    cin >> str;

    if (CheckArray())
    {
        cout << 0 << '\n';
        return;
    }

    // 모든 빨간공을 왼쪽으로 옮길때.
    MoveBall('B', 'R', true);
    // 모든 빨간공을 오른쪽으로 옮길때.
    MoveBall('B', 'R', false);
    // 모든 파란공을 왼쪽으로 옮길때.
    MoveBall('R', 'B', true);
    // 모든 파란공을 오른쪽으로 옮길때.
    MoveBall('R', 'B', false);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}