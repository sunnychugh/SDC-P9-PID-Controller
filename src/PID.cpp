#include "PID.h"
#include <iostream>
#include <math.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID()
{
    prev_cte = 0;
    int_cte = 0;
}

PID::~PID() {}

void PID::Init(double _Kp, double _Ki, double _Kd)
{
    Kp = _Kp;
    Ki = _Ki;
    Kd = _Kd;
    cout << -Kp << "\t" << -Kd << "\t" << -Ki << endl;
}

double PID::UpdateError(double cte)
{
    double diff_cte = cte - prev_cte;
    int_cte += cte;
    prev_cte = cte;
    double steer = -Kp * cte - Kd * diff_cte - Ki * int_cte;
    //cout << -Kp << "\t" << -Kd << "\t" << -Ki << endl;
    //cout << -Kp * cte << "\t" << -Kd * diff_cte << "\t" << -Ki * int_cte << endl;

    return steer;
}

double PID::TotalError()
{
}
