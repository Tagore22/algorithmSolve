#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 생각해내면 쉬운 문제지만 생각해내지 못해서 어렵게 풀었던 문제다. 처음에는 열을 기준으로 순회를 했다.
// 당연히 que에 너무 많은 정보가 저장되어 메모리 초과가 났다. 정답은 행으로 순회하는 것이다. 예시를 잘보면
// 맨 마지막 행부터 위로 올라가면서 각 수들을 더했을때 역시 부호 행렬을 생성할수 있다. 이것을 백트래킹식으로
// 구현하면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<int> vec;
char board[10][10];
int N;
string str;

// 현재 고른 수가 올바른지 확인하는 함수.
bool CheckTrack(int idx)
{
    int sum = 0;

    // 맨 마지막 행부터 올라가며 또는 맨 뒤 숫자부터 앞으로 순회하며 부호 행렬과 실제 합이 일치한지 확인한다.
    for (int i = idx; i >= 0; --i)
    {
        // 현재 i번 행까지의 합.
        sum += vec[i];

        // 실제 부호와 값이 다르다면 false를 반환하여 맞지 않음을 알린다.
        if (board[i][idx] == '+' && sum <= 0)
            return false;
        if (board[i][idx] == '-' && sum >= 0)
            return false;
        if (board[i][idx] == '0' && sum != 0)
            return false;
    }
    // 마지막까지 순회가 끝나 성공하였음을 true를 반환하여 알린다.
    return true;
}

// 모든 경우를 확인하는 백트래킹 함수.
void BackTrack(int idx)
{
    // 마지막까지 도달하였다면 벡터에 든 값들을 출력하고 프로그램을 종료한다.
    if (idx == N)
    {
        for (auto& num : vec)
            cout << num << ' ';
        cout << '\n';
        exit(0);
    }

    // 모든 값의 범위인 -10 ~ 10까지 순회해본다.
    for (int i = -10; i <= 10; ++i)
    {
        // 반드시 여기서 먼저 벡터에 넣어야 한다. 그래야 바로 아래 CheckTrack()에 현재값이 반영되기 때문이다.
        vec.push_back(i);
        if (CheckTrack(idx))
            BackTrack(idx + 1);
        // 현재값을 빼내어 기존값으로 되돌린다.
        vec.pop_back();
    }
}

void MakeAnswer()
{
    BackTrack(0);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> str;
    int idx = -1;
    for (int i = 0; i < N; ++i)
        for (int j = i; j < N; ++j)
            board[i][j] = str[++idx];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}