#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 처음에는 아무 생각 없이 for문으로 전투력 구간을 계산해서 출력하는 방식으로 구현했으나,
// 이런 경우 최대 10의 10제곱만큼의 연산량이 되어서 시간초과가 났다. 전투력 구간을 계산하는 
// 로직을 단순 for문이 아닌 lower_bound()를 사용해서 이분 탐색으로 연산량을 줄여야했다.

// 자세한 설명은 주석으로 남긴다.

// 칭호와 전투력. 정렬등을 사용하지 않아 순서가 연동된다.
string names[100000];
int power[100000];
int N, M;

void MakeAnswer()
{
    int num;
    for (int iter = 0; iter < M; ++iter)
    {
        cin >> num;
        // 이분 탐색으로 연산량을 줄인다.
        int idx = lower_bound(power, power + N, num) - power;
        cout << names[idx] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> names[i] >> power[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}