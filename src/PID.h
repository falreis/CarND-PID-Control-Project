#ifndef PID_H
#define PID_H

class PID {
public:
  /*
   * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
   * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
   * Twiddle initalized
  */
  bool is_twiddle_initialized;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
  
  
  //Calculate Twiddle algorithm to optmize parameters
  void Twiddle(const double cte);

  //Calculate Twiddle error
  double TwiddleError(const double *p, const double *dp);
};

#endif /* PID_H */
