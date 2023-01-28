#include <iostream>
#include <algorithm>

using namespace std;

//풀이
//내가 보강해야하는 수학적 감각을 요구하는 문제였다. 현재 무게추로 1~K까지 수를 만들수 있을때, 다음 무게추 L이 K보다 작거나 같다면
//1~K+L까지 만들수 있다. 하지만 L이 K보다 크다면 K+1부터 L-1까지의 수가 비게 된다. 이점을 이용해야하는 문제이다.

int chu[1000];
int N;

void MakeAnswer()
{
    int answer = 1; //현재 도달해야하는 수.
    sort(chu, chu + N); //정렬하여 작은수부터 시작해야 상술한 방법을 사용할수 있다. 

    for (int i = 0; i < N; ++i)
    {
        if (answer < chu[i]) //다음으로 가벼운 추가 현재 만들어야하는 수 answer보다 크다면 answer는 만들수 없다.
            break;
        answer += chu[i]; //조합할 수의 갱신.
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> chu[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}