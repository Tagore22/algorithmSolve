#include <iostream>
#include <vector>
#include <cmath>

//정수값 K와 L이 주어지고, L보다 작은 소수중 K를 나누었을때 나머지가 0인값이 있는지를 구하는 문제이다. 중요한점은 K의 최대값이 100의
//100제곱이라는 큰수이기에 long long으로도 풀수 없다. 그래서 string으로 해결해야만 했다. 이부분에서 모듈라 연산의
//(a+b) % c == ((a%c) + (b%c)) % c 인점을 이용했다. 예를 들어 1234같은 경우에는 첫째자리가 4*1이기에 ((4%c) * (1%c)) % c와 같은 방식이다.
//다만 풀이 자체를 string으로 푸는 방식은 상술했듯이 매우 큰수이기 때문인데 그것은 (1%c)에도 연결된다. 즉 저 1이 점점 커져서 100의 100제곱
//이 될수도 있기에 저렇게 모듈라 연산을 사용하는것이지만 그 전 연산인 (4%c)은 굳이 c로 나누지 않아도 결코 20조차 넘을수 없는 작은 수이며 
//1%c도 최대 100만을 넘지 않기에 이 두 연산의 최대값 2000만이 넘지 않아 자리수에 해당 하는 4는 결국 c로 나누는 번거로움을 겪지 않아도 된다.

//2022.11.4 추가
//에라토스테네스의 체를 사용하지 않아도 답은 나오나, 그럴 경우 빅오는 최대 100만 * 100인 1억이 된다. 하지만 에라토스테네스의 체를 쓰면
//소수들의 수를 구하는데 최대 8만개가 안된다. 그래서 결과적으로 100만(소수들의 수를 구하는데 O(n) + 100 * 대략 최대 8만개가 되어 
//9백만이 넘질 않아 훨씬 빠르다.

using namespace std;

vector<int> primes;
vector<bool> board;
string K;
int L;

//주어진 L보다 작은 수들중 모든 소수값들은 구한다.

void CalEra()
{
    int sqrt_num = sqrt(L - 1); //L보다 작아야 하기에 sqrt연산의 인자는 L-1
    board[0] = board[1] = false;

    for (int i = 2; i <= sqrt_num; ++i)
        if (board[i])
            for (int j = i * i; j < L; j += i)
                board[j] = false;

    for (int i = 0; i < L; ++i)
        if (board[i])
            primes.push_back(i);
}

void MakeAnswer()
{
    CalEra();
    for (int i = 0; i < primes.size(); ++i)
    {
        int div = 0, mul = 1;
        for (int j = K.size() - 1; j >= 0; --j)
        {
            div = (div + (K[j] - '0') * mul) % primes[i]; //상술했듯이 K[j] - '0'은 굳이 primes[i]로 나누지 않아도 된다. 어차피 20을
                                                          //넘지 않으며 이상태로 곱해져도 int의 범위내에 속한다.
            mul *= 10;                                    
            mul %= primes[i];                             //하지만 mul값은 long long값을 벗어날 가능성이 있기에 반드시 나누어져야만 한다.
        }

        if (div == 0)
        {
            cout << "BAD " << primes[i] << '\n';
            return;
        }
    }
    cout << "GOOD" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> L;
    board.resize(L + 1, true);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}