#include <iostream>
#include <map>

using namespace std;

// 풀이.
// 학점 * 과목평점들의 합을 학점의 총합으로 나눈 결과값을 출력하는 문제다.
// 각 학점(String)마다 과목평점(float)가 붙어있었으므로 map을 이용해서 매핑해야했다.
// 그 후로는 상술한대로 학점 * 과목평점들의 총합과 학점의 총합을 나누어 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 과목평점과 학점을 매핑한다.
    map<string, float> board;
    board["A+"] = 4.5;
    board["A0"] = 4.0;
    board["B+"] = 3.5;
    board["B0"] = 3.0;
    board["C+"] = 2.5;
    board["C0"] = 2.0;
    board["D+"] = 1.5;
    board["D0"] = 1.0;
    board["F"] = 0.0;

    int sum = 0;
    float mulsum = 0.0, point;
    string str, grade;
    for (int iter = 0; iter < 20; ++iter)
    {
        // 과목명, 학점, 등급을 입력받는다.
        cin >> str >> point >> grade;
        // 문제에서 제시되어 있듯이 등급이 P라면 무시한다.
        if (grade == "P")
            continue;
        // 학점과 학점 * 과목평점을 각각 더해준다.
        sum += point;
        mulsum += board[grade] * point;
    }
    // 학점 * 과목평점들의 합과 학점들의 합을 나누어 출력한다.
    cout << mulsum / sum << '\n';
    return 0;
}