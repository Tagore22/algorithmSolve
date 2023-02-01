#include <iostream>
#include <vector>

using namespace std;

//풀이
//1부터 수를 더해가며 순회를 해야할텐데 어디까지 순회를 해야할지 고민했던 문제.
//정답은 시작점과 끝점이 같을때였다.
//시작점 from과 끝점 to를 두되, 초기화는 각각 1과 2로 한다.
//from의 제곱과 to의 제곱 + G를 비교하는데, 이때 3가지의 경우가 나온다.
//각 값을 A와 B로 칭한다.

//1. A == B 일때
//이 경우에는 from과 to를 1씩 더해주고 to값을 최종답 answrd에 넣어준다. 하술하겠으나 from만 1을 더해주는 경우에는 
// 어차피 G보다 차이가 더 작기 때문에 to도 결국엔 1을 더해줄것이고, to만 더해주는 경우에는 
// G보다 차이가 무조건 크기 때문에 from을 더해주게 되어있다.
//2. A > B일때
//차이가 G보다 크기 때문에 시작점 from을 올려서 차이값을 줄여야한다.
//3. A < B일때 
//차이가 G보다 작기 때문에 끝점 to을 올려서 차이값을 키워야 한다.

//이러한 조건으로 순회를 하다가 from과 to가 같아지면 반복문을 탈출한다. from과 to가 같다는 것은 A와 B의 차이가 G보다 계속 커서 from이 계속
//증가했다는 것인데, 이 이상 from이나 to를 키워도 그 차이는 늘어나면 늘어났지 줄어들진 않기 때문이다.
//따라서 반복문 순회를 마쳤을때 최종답 answer에 들어있는 원소값이 1개 이상이라면 그것들을 출력하고
//1개도 없다면 답을 찾을수 없기에 -1을 출력한다.

int G;

void MakeAnswer()
{
    vector<long long> answer;
    long long from = 1, to = 2, now;
    while (from < to)
    {
        now = from * from + G;
        if (to * to == now)
        {
            answer.push_back(to);
            ++from;
            ++to;
        }
        else if (to * to < now)
        {
            ++to;
        }
        else
        {
            ++from;
        }
    }

    if (answer.empty())
        cout << -1 << '\n';
    else
        for (int i = 0; i < answer.size(); ++i)
            cout << answer[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> G;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}