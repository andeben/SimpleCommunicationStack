#ifndef TIME_HPP
#define TIME_HPP


class Time {
public:
  Time();
  ~Time();
  void Run();

private:
  void Start1msTimer();
  void Start1sTimer();
  void Start1mTimer();
  void Start1hTimer();
  int  GetTime();

  bool m1msElapsed = false;
  bool m1sElapsed  = false;
  bool m1mElapsed  = false;
  bool m1hElapsed  = false;


};



#endif //TIMERS_HPP
