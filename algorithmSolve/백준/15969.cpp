#include <iostream>

using namespace std;

// 풀이.
// 주어진 수들중 가장 큰 수와 가장 작은 수의 차이를 출력하는 문제다. 이 풀이에서는 매번 입력받을때마다
// 기존의 가장 큰 수, 작은 수와 비교하였으나 배열을 하나 만들어서 정렬하는 풀이도 있다. 다만 후자가 좀더 길고
// #include <algorithm>이 필요하다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, num, max_num = 0, min_num = 1000;
    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> num;
        max_num = max(max_num, num);
        min_num = min(min_num, num);
    }
    cout << max_num - min_num << '\n';
    return 0;
}