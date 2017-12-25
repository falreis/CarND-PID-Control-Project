#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->p_error = 0;
    this->i_error = 0;
    this->d_error = 0;

    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

    this->is_twiddle_initialized = false;
}

void PID::UpdateError(double cte) {
    this->d_error = cte - this->p_error;
    this->p_error = cte;
    this->i_error += cte;

    this->Twiddle(cte);
}

double PID::TotalError() {
    return - (this->Kp * this->p_error) - (this->Kd * this->d_error) - (this->Ki * this->i_error);
}

void PID::Twiddle(const double cte){
    const double tolerance = 0.1;

    double p[3] = { this->Kp, this->Ki, this->Kd };
    double dp[3] = {0, 0, 0};

    double best_err = this->TwiddleError(p, dp);
    double err = 1;

    while((dp[0] + dp[1] + dp[2]) > tolerance){
        for(int i=0; i<3; i++){
            p[i] += dp[i];
            err = TwiddleError(p, dp);

            if(err < best_err){
                best_err = err;
                dp[i] *= 1.1;
            } else{
                p[i] -= 2 * dp[i];
                err = TwiddleError(p, dp);

                if(err < best_err){
                    best_err = err;
                    dp[i] *= 1.1;
                } else{
                    p[i] += dp[i];
                    dp[i] *= 0.9;
                }
            }
        }
    }

    this->Kp = p[0];
    this->Ki = p[1];
    this->Kd = p[2];
}

double PID::TwiddleError(const double *p, const double *dp){
    return - (p[0] * dp[0]) - (p[1] * dp[1]) - (p[2] * dp[2]);
}