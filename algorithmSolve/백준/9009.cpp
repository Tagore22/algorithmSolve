#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 피보나치를 이용해야 할거 같지만 실제로는 +로 이진탐색까지 알아야한다.
// 큰 틀을 따져보자면

// 1. 전처리로 피보나치 배열을 미리 생성해 놓는다. 다만, 최대 10억까지의 값만 필요하다.
// 2. 최소 개수의 피보나치 수를 알기위해서는 주어진 값 num에 가장 가까우면서 작은 피보나치 값으로 감소시켜나가야 한다.

// 이것을 구현해주면 된다.
// 자세한 설명은 주석으로 남긴다.

vector<int> fibo, vec;
int T;
const int MAX_NUM = 1000000000;

// 전처리로 피보나치 배열을 생성해놓는 함수.
void CalFibo()
{
    fibo.push_back(0);
    fibo.push_back(1);

    int num;
    for (int i = 2; ; ++i)
    {
        num = fibo[i - 2] + fibo[i - 1];
        // 1번에 상술하였듯 주어지는 값이 최대 10억이기에 10억을 초과하는 값은 필요하지 않다.
        if (num > MAX_NUM)
            break;
        fibo.push_back(num);
    }
}

void FindNum(int num)
{
    vec.clear();

    while (num > 0)
    {
        // 현재수 num에 가장 가까운 피보나치 값을 벡터에 저장후 num을 감소시킨다.
        // 이것을 num이 0이 될때까지 반복한다.
        int idx = upper_bound(fibo.begin(), fibo.end(), num) - fibo.begin();
        num -= fibo[idx - 1];
        vec.push_back(fibo[idx - 1]);
    }
}

void MakeAnswer()
{
    CalFibo();
    int num;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> num;
        FindNum(num);
        // 벡터에 저장된 값들을 오름차순으로 출력한다.
        for (int i = vec.size() - 1; i >= 0; --i)
            cout << vec[i] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}