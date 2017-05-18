#include "PID.h"

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

void PID::Init(double Kp, double Ki, double Kd)
{
    Kp = Kp;
    Ki = Ki;
    Kd = Kd;
}

double PID::UpdateError(double cte)
{
    double diff_cte = cte - prev_cte;
    int_cte += cte;
    prev_cte = cte;
    double steer = -Kp * cte - Kd * diff_cte - Ki * int_cte;
    return steer;
}

double PID::TotalError()
{
}
