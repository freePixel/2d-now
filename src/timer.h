#pragma once

#include <chrono>
#include <iostream>
#include <thread>
#include <map>
#include <functional>


enum time_event
{
    logic = 0 ,
    graphics
};


class timer
{
    public:
                void wait();
                void startFrame();
                void endFrame();

                void newTimeEvent(int id , double duration ,  std::function<void()> function); //create a time event, which executes a given function everytime time elapsed reaches duration in milliseconds
                void removeTimeEvent(int id);
                void update_time_events();


    private:
                struct timeEvent;
                std::map<int , timeEvent> time_events;

                std::chrono::high_resolution_clock::time_point start_frame;
                std::chrono::high_resolution_clock::time_point end_frame;
                
                double minium_time_event;

                struct timeEvent
                {
                    
                    double duration;
                    double time_left;
                    timeEvent(double _duration , std::function<void()> _function)
                    {
                        function = _function;
                        duration = _duration;
                        time_left = _duration;

                    }
                    void update()
                    {
                        t2 = std::chrono::high_resolution_clock::now();
                        double dt = (t2 - t1).count() / 100000000.0;
                        time_left -= dt;
                        if(time_left < 0.0)
                        {
                            time_left = duration;
                            function();
                        }
                        t1 = std::chrono::high_resolution_clock::now();
                    }
                    std::function<void()> function;

                    private:
                        std::chrono::high_resolution_clock::time_point t1;
                        std::chrono::high_resolution_clock::time_point t2;
                };

        



};