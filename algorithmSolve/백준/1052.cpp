#include <iostream>
#include <vector>

//풀이 방법을 떠올리는데 꽤나 오래걸렸던 문제. 한번에 큰그림을 그리지말고 조금씩 그려나가자.

//풀이
//이 문제를 푸는데 중요하다고 생각했던건 물의 양이 맞지 않아 합치지 못하고 남은 물들의 양과 수를 추적하는것이다. 비어있지 않은 즉, 물이 담긴 물병들의 수를 줄이기 위해서는
//물이 적은 물병부터 비워야하기 때문. 그래서 물병의 수를 2씩 나누어 가되, 현 물병의 수가 홀수라면 현재 물의 수를 벡터에 포함시켜가며 물병의 수가 1개일때(더이상 줄일수 없을
//때)까지 줄여나간다. 그러면 만들수 있는 모든 물의 수와 양이 주어지는데 이상태에서 가장 적은 물병과 두번째로 적은 물병의 수를 최종 답에 더해준다. 그러면 두번째로 적은 
//물병의 양은 가장 적었던 물병의 양과 합쳐서 2배가 된다. 이걸 물병의 수가 K가 될때까지 반복하면 된다.

using namespace std;

vector<int> cups;
int N, K;

void MakeAnswer()
{
    int water = 1; //초기 물의 양
    while (N > 1)
    {
        if (N % 2 == 1) // 현재 물병의 수가 홀수라면 반드시 하나는 합치지 못하고 남게 된다. 
            cups.push_back(water); //이 물의 양을 저장한다.
        N /= 2; //모든 물병들은 합쳐서 반이 되고,
        water *= 2; //각 물병의 양은 합쳐서 2배가 된다.
    }
    cups.push_back(water); //마지막 남은 물병에 담긴 물의 양

    int c_size = cups.size(); //물을 추가하지 않고 처음 만든 물병의 수
    int answer = 0, idx = 1;
    while (c_size > K) //물병의 수가 K가 될때까지 반복
    {
        answer += cups[idx] - cups[idx - 1]; //물병을 줄이기 위해선 현재 물의 양이 가장 작은 물병을 없애야 한다.
        cups[idx] *= 2; //그럼 두번째로 적었던 물병의 양이 가장 적은 물병의 양과 더해서 2배가 된다.
        --c_size; //물병의 수는 하나가 줄었다.
        ++idx;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
}

int main()
{
    Input();
    MakeAnswer();
}