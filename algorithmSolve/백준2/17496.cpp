#include <iostream>

using namespace std;

// 풀이.
// 시작이 1일이라는 것과 T의 존재에 대해 생각해야한다.
// 예를 들어 N이 3이고 T가 1일 때 3일을 수확할 수 있는 듯 싶으나
// 실제로는 1 ~ 2, 2 ~ 3으로 2일밖에 수확하지 못한다.
// 따라서 N을 1만큼 낮춰서 계산해야한다.

int main()
{
    int N, T, C, P;
    cin >> N >> T >> C >> P;
    --N;
    cout << N / T * C * P << '\n';
    return 0;
}