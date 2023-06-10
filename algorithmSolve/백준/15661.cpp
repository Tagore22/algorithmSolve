#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 별것 아닌 문제인데 좀 심오하게 공부했던 문제이다.
// 변별력이 있다는게 이런건지는 모르겠으나, 꽤나 중요한 문제인듯 하다.
// 문제의 큰틀은 다음과 같다.

// 1. 만들수 있는 모든 경우에 따라서 양쪽팀 능력치의 최소값을 출력한다.

// 다만 여기서 여러가지 풀이가 나올수 있다. 이 문제는 정말 다양한 방법으로 풀어봤기에
// 그중 최적이라고 생각되는 풀이 방법을 적는다.

// 1. 처음풀때에는 비트마스크로 모든 경우를 따졌었다. 그러나 매개변수를 추가한 백트래킹 형식이 더 나았는데
// 비트마스크로 모든 경우를 만들때에는 매번 N개의 원소를 순회해야 했다. 하지만 백트래킹에 매개변수를 추가한다면
// 현재 원소값만을 추가하여 갱신하면 되기에 훨씬 빠르다.(첫번째 풀이와 가장 최근 풀이를 비교해보면 된다.)

// 2. 두 팀의 능력치를 갱신할때에도 중요한데 기존에는 마지막 N번째 원소가 추가된 이후 한번에 능력치를 계산했었다.
// 이때 최대 N개에 해당하는 팀원의 수를 중첩된 2개의 for문으로 순회했었다. 하지만 이렇게 하기보다
// 아래 풀이에 나와 있듯이 아예 능력치 자체를 매개변수화하여 매번 더해준다면 단 한번의 for문으로 구할수 있다.
// 이 방법이 거의 3배 가까이 빨랐다.

// 자세한 설명은 주석으로 남긴다.

int board[20][20];
int N, answer = 987654321;
vector<int> first, second;

void BackTrack(int idx, int first_sum, int second_sum)
{
    // 마지막 원소까지 집어넣었다면 두 팀의 능력치를 비교하여 최종값을 갱신한다.
    if (idx == N)
    {
        if (!first.empty() && !second.empty())
            answer = min(answer, abs(first_sum - second_sum));
        return;
    }

    // 위 상술하였듯 능력치를 맨 마지막에 계산하지 않고 매개변수화하여 그때 그때마다 구해준다.
    int plus = 0;
    for (int i = 0; i < first.size(); ++i)
        plus += board[idx][first[i]] + board[first[i]][idx];
    first.push_back(idx);
    BackTrack(idx + 1, first_sum + plus, second_sum);
    first.pop_back();

    plus = 0;
    for (int i = 0; i < second.size(); ++i)
        plus += board[idx][second[i]] + board[second[i]][idx];
    second.push_back(idx);
    BackTrack(idx + 1, first_sum, second_sum + plus);
    second.pop_back();
}

void MakeAnswer()
{
    // 1. 백트래킹으로 idx번째 원소를 각각 첫번째, 두번째 팀에 넣어본다.
    // 2. 마지막까지 모두 넣었을때 각 팀의 능력치의 차이를 구하여 최종값을 갱신한다.
    // 3. 최소값 출력.
    BackTrack(0, 0, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}