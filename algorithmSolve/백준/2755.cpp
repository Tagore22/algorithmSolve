#include <iostream>

using namespace std;

// 풀이.
// 성탄절이라 가볍게 -브-문제만 풀려고 했는데 제대로 한방 맞았다.
// 문제 자체는 간단한데 학점 * 점수의 합을 점수의 합으로 나누어 소수점 둘째자리까지만 출력하는 문제다.
// 두가지 실수를 했는데 첫째로는 학점이 F일때를 전혀 처리하지 않았다는 것이다.
// E를 빼는것까지는 좋았으나 F가 포함되지 않았다.
// 두번째로는 precision으로 인한 반올림에 대한 것인데 실수처리를 하다보면 12.25f라고 될지라도 실제로는
// 12.24999999999999999999f일 경우가 많다. 이럴때에 소수 첫째짜리까지만 출력하면 생각하는 결과값은
// 12.25에서 둘째자리에서 반올림이 되기 때문에 12.3이지만 실제로는 위처럼 12.24999999999999f이기에
// 반올림이 되지 않아 12.2가 된다. 따라서 반올림을 하는 해당 자리에 1을 더해야 한다. 즉, 12.25f에
// 0.01을 더해서 precision()을 해주어야 원하는 답이 나오게 된다.

// 자세한 설명은 주석으로 남긴다.

int N, point = 0;
float grade = 0.0f;

void MakeAnswer()
{
    string str, gra;
    int num;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str >> num >> gra;
        point += num;
        // 상술하였듯 처리해주지 않았던 F의 처리.
        // 학점이 F라면 점수만 더해주고 학점은 건드릴수가 없다.
        if (gra == "F")
            continue;
        float now = 0.0f;
        // 학점의 처리를 해주어 최종값에 학점 * 점수의 값을 더해준다.
        now += 'E' - gra[0];
        if (gra[1] == '+')
            now += 0.3f;
        else if (gra[1] == '-')
            now -= 0.3f;
        grade += now * num;
    }

    // 최종값 answer에 학점 * 점수의 총합 / 점수의 총합으로 초기화 해준후
    // 상술한 실수의 오차범위를 메꾸기 위해 0.001f을 더한다.
    // 소수 셋째자리에서 반올림이 실시되기 때문에 0.001f를 더한다.
    float answer = grade / point;
    answer += 0.001;
    cout.precision(2);
    cout << fixed;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}