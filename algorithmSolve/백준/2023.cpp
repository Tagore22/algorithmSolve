#include <iostream>
#include <cmath>

using namespace std;

// 풀이.
// 소수가 등장했기에 처음에는 에라토스테네스의 체를 이용한 정수론 풀이를 생각했었다.
// 하지만 곧바로 메모리 초과가 떴는데 자세히 보니 허용 메모리가 고작 4mb였다.
// 제대로 된 풀이는 백트래킹을 사용하는 것이다. 만들수 있는 모든 수를 만들어가며
// 그 수가 소수인지를 확인해간다. 그 수가 N자리가 되었다면 그것을 출력해주면 된다.
// 0 ~ 9 순서로 대입하기 때문에 굳이 오름차순 순서를 생각하지 않아도 된다.
// 다만 주의해야할것이 하나 있는데 모든 수가 소수여야 하기에 1로는 시작할수 없다는 것이다.

// 자세한 설명은 주석으로 남긴다.

int N;

// 해당 수가 소수인지 확인하는 함수.
// 2부터 현재수 num까지 확인해도 되지만 정수론에 의거하여
// sqtr(num)까지만 확인해도 되기에 성능 좋게 구현할수 있다.
bool CheckPrime(int num)
{
    int sqrt_num = sqrt(num);
    for (int i = 2; i <= sqrt_num; ++i)
        if (num % i == 0)
            return false;

    return true;
}

// 만들수 있는 모든 수를 만들어가는 함수.
void BackTrack(int num, int idx)
{
    // 현재수가 소수가 아니라면 무시한다.
    if (!CheckPrime(num))
        return;

    // 현재수가 소수가 아니며 N자리까지 도달하였다면 찾던 수이므로 출력한다.
    if (idx == N)
    {
        cout << num << '\n';
        return;
    }

    // 0 ~ 9를 마지막 자리에 대입한다.
    for (int i = 0; i < 10; ++i)
        BackTrack(num * 10 + i, idx + 1);
}

void MakeAnswer()
{
    // 위 상술하였듯 1자리씩 제외하며 확인했을때 모든 수가 소수여야한다.
    // 즉 맨 앞자리 한자리도 소수여야 하기에 1이 아닌 2부터 시작해야한다.
    // ex) 111이 현재수일때 111, 11은 소수지만 1은 소수가 아니다.
    for (int i = 2; i < 10; ++i)
        BackTrack(i, 1);
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