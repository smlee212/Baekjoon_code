#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;

int main() {

    int R;
    scanf("%d", &R);
    double pi, Su, St;
    pi = M_PI;
    Su = R * R * pi;
    St = R * R * 2.0;
    printf("%.6f\n%.6f\n", Su, St);
    return 0;
}