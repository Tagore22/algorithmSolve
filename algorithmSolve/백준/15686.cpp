#include <iostream>
#include <vector>

using namespace std;

// 풀이
// 어떤 집과 가장 가까운 치킨집의 거리를 치킨거리라고 하였을때 모든 집의 치킨거리를 더한것이 도시의 치킨거리다.
// 이때 치킨집을 최대 M개만 남겼을때 최소한의 도시의 치킨거리를 구하는 문제이다.
// 문제의 핵심은 어떤 치킨집을 몇개를 남길 것인가인데 그리디로 풀기도 어려우며 또한 예시가 적으니 완전탐색으로 풀어야한다.

// 쉬운것부터 차근차근 풀어보자면 치킨거리를 구하는 것은 문제에 제시되어 있듯이 좌표를 y, x라고 할때
// abs(집의 y - 치킨집의 y)  + abs(집의 x - 치킨집의 y)이다. 하지만 그중 가장 작은값을 구해야하기에 
// 어떤 집의 치킨거리는 치킨집의 개수만큼 순회하며 현재 집과의 거리를 비교하여 가장 적은것이 된다.

// 치킨집이 K개일때는 bool배열을 따로 만들어 현재 존재하는 치킨집을 true로 갱신하여 구현하였고
// 현재 존재하는 치킨집의 개수를 구하기 위해 for문을 순회하며 true의 개수를 반환하는 함수를 구현하였다.

// 이제 모든 치킨집을 존재하느냐 존재하지 않느냐의 경우를 따져야하는데 이는 백트래킹으로 구현하였다.
// 현재 존재하는 치킨집의 개수 num을 위 상술한 함수로 구하고 num이 M보다 크다면 무시한다.
// 그렇지 않다면 num개의 치킨집이 존재할때의 도시의 치킨거리를 구하되 그중 최소값을 갱신한다.
// 그 후, 현재 치킨집 다음의 치킨집들을 또다시 하나씩 true로 변환하여 다시 도시의 치킨거리를 갱신한다.

vector<pair<int, int>> house, chicken; // 세로, 가로
vector<int> answer;
vector<bool> check;
int N, M;
const int MAX_NUM = 987654321;

// num번째 집의 치킨거리를 구하는 함수. 현재 존재하는 치킨집과의 거리만을 구한다.
int HouseLength(int num)
{
    int from_house = MAX_NUM;
    for (int i = 0; i < chicken.size(); ++i)
        if (check[i])
            from_house = min(from_house, abs(house[num].first - chicken[i].first) +
                abs(house[num].second - chicken[i].second));

    return from_house;
}


// 현재 K개의 치킨집이 존재할때 도시의 치킨거리를 구하는 함수. vector<bool> 타입의 check와 연동된다.
int TotalLength()
{
    int total = 0;
    for (int i = 0; i < house.size(); ++i)
        total += HouseLength(i);

    return total;
}


// 현재 존재하는 치킨집의 개수를 구하는 함수. for문을 순회하며 true인 개수(존재하는 개수)의 총합을 반환한다.
int ChickenNum()
{
    int num = 0;
    for (int i = 0; i < check.size(); ++i)
        if (check[i])
            ++num;

    return num;
}


// 모든 치킨집들이 true 혹은 false인 상황을 시뮬레이션 하는 함수.
void CalAnswer(int from)
{
    int num = ChickenNum();
    if (num > M)
        return;

    if (from != -1)
        answer[num] = min(answer[num], TotalLength()); // 여기서 거리를 구한다.

    for (int i = from + 1; i < chicken.size(); ++i)
    {
        check[i] = true;
        CalAnswer(i);
        check[i] = false;
    }
}


// 최종결과값을 구하는 함수. 여러개의 도시의 치킨거리가 존재할때 그 최소값을 출력하고 마친다.
void MakeAnswer()
{
    CalAnswer(-1);
    int ans = MAX_NUM;
    for (int i = 1; i <= M; ++i)
        ans = min(ans, answer[i]);

    cout << ans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    answer.resize(M + 1, MAX_NUM);
    int cur;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> cur;
            if (cur == 1)
                house.push_back(make_pair(i, j));
            else if (cur == 2)
                chicken.push_back(make_pair(i, j));
        }
    check.resize(chicken.size(), false);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}