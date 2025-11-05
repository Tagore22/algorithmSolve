#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 처음에는 무게와 가격 2가지 정보 때문에 조금 헷갈렸다. 그래서 가격을 기준으로 정렬하여
// 누적합을 이용해 이전 고기와 가격이 같으냐 아니냐에 따라 계산을 했더니 영 시원치 않았다.
// 2 10 5 1 6 1 같은 경우가 그 예시였다. 진짜 풀이는 조금 더 세심하게 로직을 짜야 했는데
// 가격이 같을 경우 무게가 큰 고기가 앞으로 나와야한다. 예를 들어 같은 가격의 고기를 2개
// 사야할 경우 무조건 무게가 큰 것으로 골라사야하기 때문이다. 정렬 이후 금액을 측정할때
// 앞에 고기와 가격이 다르다면 현재 가격이 최대값이 되고, 같다면 두 가격을 더해야한다.
// 문제에서 주어지듯 가격이 싼 경우에만 덤으로 얻을 수 있기 때문이다. 또한, 기존에는
// M을 넘어서는 경우가 있다면 그냥 for문을 탈출하였는데 제대로 N - 1까지 순회를 해야한다.
// 5 30 5 1 6 2 10 3 11 3 20 4를 보면 알 수 있듯 뒤에 나오는 가격이 비싼 고기 하나를
// 사면 해결이 될 수도 있기 때문이다.

// 자세한 설명은 주석으로 남긴다.

int N, M;
pair<int, int> meat[100000];

// 정렬에 사용되는 비교함수. 가격이 다르다면 가격을 기준으로 오름차순,
// 같다면 무게를 기준으로 내림차순으로 정렬한다.
bool Compare(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    if (lhs.first != rhs.first)
        return lhs.first < rhs.first;
    else
        return lhs.second > rhs.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> meat[i].second >> meat[i].first;
    sort(meat, meat + N, Compare);
    int sum = 0;
    // 무게와 가격의 합이 int의 최대값인데 answer의 초기화를 더 큰 값으로
    // 해야 했기에 long long으로 구현하였다.
    long long money = 0, answer = 12147483647;
    for (int i = 0; i < N; ++i)
    {
        sum += meat[i].second;
        // 만약 이전 고기의 가격과 현재 고기의 가격이 같을 경우 이전 고기를
        // 덤으로 얻을 수 없기에 금액을 추가한다.
        if (i != 0 && meat[i - 1].first == meat[i].first)
            money += meat[i].first;
        else
            money = meat[i].first;
        // 최소값 계산.
        if (sum >= M)
            answer = min(answer, money);
    }
    cout << (answer == 12147483647 ? -1 : answer) << '\n';
    return 0;
}