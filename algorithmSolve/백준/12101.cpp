#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 백트래킹 문제다. 사전순으로 정렬하였을때 K번째이기에, 1, 2, 3순으로 뺄수 있는지 확인해보고 가능하다면 재귀호출한다.

// 자세한 설명은 주석으로 남긴다.

vector<int> vec;
int N, K, answer = 0;
bool isfind = false;

void BackTrack(int num)
{
    // K번째 답을 이미 찾았다면 무시한다.
    if (isfind)
        return;

    // 현재 answer번째 식이 완료되었을때.
    if (num == 0)
    {
        ++answer;
        // K번째 식에 도달하였다면 현재까지 포함된 수들을 모두 출력하고 답을 찾았음을 갱신하며 탈출한다.
        if (answer == K)
        {
            for (int i = 0; i < vec.size() - 1; ++i)
                cout << vec[i] << '+';
            cout << vec[vec.size() - 1] << '\n';
            isfind = true;
        }
        return;
    }

    // 상술하였듯 사전순으로 정렬된 순서로 식을 구하기 때문에 1, 2, 3번 순으로 계산한다.
    for (int i = 1; i <= 3; ++i)
    {
        if (num >= i)
        {
            vec.push_back(i);
            BackTrack(num - i);
            vec.pop_back();
        }
    }
}

void MakeAnswer()
{
    // 여기서 백트래킹.
    BackTrack(N);

    // 만약 K번째 식이 존재하지 않을 경우, -1을 출력한다.
    if (answer < K)
        cout << -1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}