#pragma once

#include <chrono>
#include <iostream>
#include <thread>
#include <map>
#include <functional>




class timer
{
    public:
                timer(double fps,  double  cps);
                void start_frame();
                void end_frame();
                void wait();

                bool updateLogic();
                bool updateGraphics();

                void updateF();
                void updateL();

                void newTimeEvent(int id , double duration ,  std::function<void()> function); //create a time event, which executes a given function everytime time elapsed reaches duration in milliseconds
                void removeTimeEvent(int id);


                double elapsedTime(bool logic); //if true return elalpsed time in logic frame, graphics elapsed time otherwise

    private:
                std::chrono::high_resolution_clock::time_point last_frame;
                std::chrono::high_resolution_clock::time_point current_frame;
                void update_time_events(int64_t dt);
                struct timeEvent;
                std::map<int , timeEvent> time_events;

                double fps = 10;
                double cps = 10;
                double base;
                int f = 0;
                int l = 0;

                int64_t ti; 
                int64_t tf;

                int64_t fixed_wait_ns; //default wait time in nanoseconds (10e9 /min(fps,cps))

                struct timeEvent
                {
                double duration;
                double time_left;
                std::function<void()> function;
                };

        



};