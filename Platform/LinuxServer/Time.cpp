#include "Time.hpp"

#include <functional>
#include <chrono>
#include <future>
#include <cstdio>

Time::Time()
{

}

Time::~Time()
{
}

void Time::Run()
{

}

void Time::Start1msTimer()
{
  std::thread([]() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }).detach();
}

void Time::Start1sTimer()
{
  std::thread([]() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }).detach();
}

void Time::Start1mTimer()
{
  std::thread([]() {
    std::this_thread::sleep_for(std::chrono::minutes(1));
  }).detach();
}

void Time::Start1hTimer()
{
  std::thread([]() {
    std::this_thread::sleep_for(std::chrono::hours(1));
  }).detach();
}
