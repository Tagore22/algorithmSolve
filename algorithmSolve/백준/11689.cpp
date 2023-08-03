#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// 풀이.
// 오일러의 파이 함수 알고리즘이라는 것을 이용한 풀이다.
// 생전 처음봤다. 에라토스테네스의 체를 이용한 응용 같은데 꽤나 어려웠다.

// 오일러의 파이 함수 알고리즘은 어떤수 N이 주어졌을때 1 ~ N까지의
// 서로수의 개수를 구하는 알고리즘이다. 따라서 이 문제는 이 알고리즘을 말그대로 대입만 하면 되는 간단한 문제다.
// 다만 오일러의 파이 함수 알고리즘을 몰랐을뿐..

// p1, p2등이 i번째 서로수일때 점화식은 다음과 같다.

// answer = N(1 - 1 / p1)(1 - 1 / p2).....(1 - 1 / pm)
// 이것을 대입만 해주면 된다. 다만 한가지 주의해야할점이 있는데
// 바로 연산의 순서이다. 고민해봐도 잘 모르겠다.
// 그래서 점화식을 더 풀어서 주석처리한 것으로 구현하면 순서 생각하지 않고 풀수 있다.

// 오일러의 파이함수 위키 주소.
https://ko.wikipedia.org/wiki/%EC%98%A4%EC%9D%BC%EB%9F%AC_%ED%94%BC_%ED%95%A8%EC%88%98

// 자세한 설명은 주석으로 남긴다.

long long N;

void MakeAnswer()
{
    int sqrt_num = sqrt(N);
    long long answer = N;
    // 에라토스테네스의 체의 응용답게 N의 제곱근까지만 순회하며 서로소를 찾는다.
    for (int i = 2; i <= sqrt_num; ++i)
    {
        // 서로소를 찾았을시 위 점화식을 응용한다.
        if (N % i == 0)
        {
            // 위 상술하였듯 이곳이 치명적으로 중요하다. 왠지 모르겠다.
            answer = answer / i * (i - 1);
            // 이렇게 하면 순서생각하지 않아도 된다. 점화식을 더 풀면 이런 연산으로 바뀌어진다.
            // answer -= answer / i;
        }

        // 이부분도 상당히 중요한데 다음 소인수를 찾기 위해 현재값 N을 i로 계속 줄여나간다.
        // 예를 들어 3이 소인수인 경우 6, 9등이 중복될수 있기에 이것을 삭제하는 과정이다.
        while (N % i == 0)
            N /= i;
    }

    // N이 1보다 크다면 마지막 소인수인 경우이기에 이 또한 처리해주어야 한다.
    if (N > 1)
    {
        // 이곳도 주석처리한 연산으로 바꾸면 순서에 상관없어진다.
        answer = answer / N * (N - 1);
        // answer -= answer / N;
    }

    cout << answer << '\n';
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