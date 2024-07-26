#include <iostream>

using namespace std;

// 6987번의 지젼 빠른 풀이.
// 기존 풀이는 가능한 모든 경우를 만들어보기 때문에 연산량이 3의 15제곱이었다.
// 하지만 역으로 현재 값에서 - 시키는 연산을 하면 가지치기를 더 많이 할수 있다.
// 이 방법을 통하면 훨씬 더 빨리 풀수 있다. 실제로 기존 풀이는 280ms이었지만
// 이 풀이는 0ms였다.

// 자세한 설명은 주석으로 남긴다.

int w[6], d[6], l[6];
int sum;
bool isFind;

// 0에서 올라가는 순서가 아닌 현재에서 내려가는 역순으로 순회하는 백트래킹 함수.
void BackTrack(int first, int second)
{
    // first가 0이 되었다는 것은 5에서 시작하는 순회까지 무사히 마쳤다는 것이므로
    // 배열이 일치함을 뜻함.
    if (first == 6)
    {
        isFind = true;
        return;
    }

    // second가 6이라는 것은 first가 5팀과의 경기를 무사히 마쳤음을 뜻하므로
    // 다음팀이 first가 되어 순회해야함을 뜻함.
    else if (second == 6)
    {
        BackTrack(first + 1, first + 2);
    }

    // 현재 first로 시작하는 순회가 아직 끝나지 않았으므로 계속 순회를 해야함을 뜻함.
    else
    {
        // first가 이긴 경우.
        // 상술하였듯 0에서 채워가는 순회가 아닌 현재값에서 지워가는 순회이므로
        // 더 많은 가지치기를 할수 있다.
        --w[first];
        --l[second];
        // 이 if문이 바로 그 가지치기인데 지웠을때 0보다 작다면 무조건 불가능한 상황이기 때문이다.
        if (w[first] >= 0 && l[second] >= 0)
            BackTrack(first, second + 1);
        ++w[first];
        ++l[second];

        // 비긴 경우.
        --d[first];
        --d[second];
        if (d[first] >= 0 && d[second] >= 0)
            BackTrack(first, second + 1);
        ++d[first];
        ++d[second];

        // second가 이긴 경우.
        --l[first];
        --w[second];
        if (l[first] >= 0 && w[second] >= 0)
            BackTrack(first, second + 1);
        ++l[first];
        ++w[second];
    }
}

void MakeAnswer()
{
    for (int iter = 0; iter < 4; ++iter)
    {
        sum = 0;
        isFind = false;
        for (int i = 0; i < 6; ++i)
        {
            cin >> w[i] >> d[i] >> l[i];
            sum += w[i] + d[i] + l[i];
        }

        // 첫번째 가지치기. 경기의 수가 15회이기 때문에 모든 결과값의 합은 무조건 30이 되어야만 한다.
        if (sum != 30)
        {
            cout << 0 << '\n';
            continue;
        }
        BackTrack(0, 1);
        if (isFind)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}