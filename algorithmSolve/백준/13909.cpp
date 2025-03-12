#include <iostream>

using namespace std;

// 풀이.
// 창문이 열려 있기 위해서는 열고 닫은 횟수가 홀수번이여야 한다. 1 ~ N번까지 각 수의 배수에 해당하는
// 창문을 열고 닫기 때문에 어떤수 K의 열고 닫은 횟수는 K의 약수와 같다. 약수는 두 수가 짝을 이루어지므로
// 자연수의 약수는 짝수개지만, 제곱수는 가운데값이 중복되는 하나의 수이기 때문에 약수가 홀수가 된다.
// 따라서 1 ~ N까지의 모든 제곱수를 구하면 된다.

int main()
{
    int N, answer = 0;
    cin >> N;

    for (int i = 1; i * i <= N; ++i)
        ++answer;
    cout << answer << '\n';
    return 0;
}