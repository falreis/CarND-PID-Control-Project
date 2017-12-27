# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program


[//]: # (Image and Video References)
[video_p_controller]: ./videos/p_controller.mp4
[video_pd_controller]: ./videos/pd_controller.mp4
[video_pi_controller]: ./videos/pi_controller.mp4
[video_pid_controller]: ./videos/pid_controller.mp4


## Theory

PID controller is a type of control loop feedback mechanism. This type of control uses a pre-defined information to adjusts its values based in the output value of the system. In other words, the output is used to set the control's input values.

PID is an acronyn for Proportional-Integral-Derivative. PID controller uses Proportional-Integral-Derivative operations to keep the values between a defined range of values predicted to the system. 

Proportional term is used to adjust the output value based on the error feedback, returned by the system. The response of this controller is proportional to the error. Proportional controllers can be very reactive or less reactive. Very reactive controllers can react quick to an small variation, but tends to overshoot the error. Less reactives controllers spends more time to revert an error and also overshoot, but with a small value.

Integral term is used to adjust the output based in all (or a set of) values over time. This type of mechanism is used to predict the behavior of the system based in previous values. Integral term is used to reduce the error, bring the error to zero and decrease the overshoot. Integral term helps to reduce the steady-state error, accelerating the process.

Derivative term is used to predict the system behavior based on the changes of the system. The derivative term helps to keep the stability of the system.

For more reference, view [PID Controller at Wikipedia](https://en.wikipedia.org/wiki/PID_controller). 

### Controllers in pratice

The results in this section is based on PID controller. The different controllers shown here is just an adjustment of the PID controller to ignore the derivative or integral controllers and present the results. No tunning process was made to increase the performance of the controller shown in this section.

#### Proportional (P) Controller

Above is the result of the implementation of P controller, without integral and derivative methods.

Here's a [link](./videos/p_controller.mp4) to my P controller video example.

P Controller worked good when the track had no difficult and the curve had a big radius. When P controller had to change its direction quick, it became instable, the car overshoots and lost the track, crashing in the bridge.


#### Proportional-Derivative (PD) Controller

Above is the result of the implementation of PD controller, without integral method.

Here's a [link](./videos/pd_controller.mp4) to my PD controller video example.

PD Controller worked good, better than P controller, when the track had no difficult and the curve had a big radius. It also was good at the bridge, where P controller crashed. But, in a curve with a small radius, the response was no quick enough to avoid the car get out the track, became instable and dangerous. The car returned to the path, but can't be considered safe for humans.


#### Proportional-Integral (PI) Controller

Above is the result of the implementation of PI controller, without derivative method.

Here's a [link](./videos/pi_controller.mp4) to my PI controller video example.

PI Controller worked really bad. The car with PI controller can't drive over the track for even an small distance. The car was totally unstable, just trying to keep on track, but driving in circles. I believe that PI controller needs an adjustment in the parameters just to keep on track and it can drive as good as P controller. But, as this section, has no parameter tunning, the PI controller had a really, really bad performance.

#### Proportional-Integral-Derivative (PID) Controller

Above is the result of the implementation of PID controller.

Here's a [link](./videos/pid_controller.mp4) to my PID controller video example.

PID Controller worked well. The car complete the track without any fault and in a safe speed.


## PID Controller Parameter Tunning

All controller parameter was defined using manual tuning. I started with hyperparameters showed in the PID classes. Then, I tuned them to increase the performance and keep the car on track.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).
