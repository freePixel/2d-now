#pragma once

#include <chrono>
#include <iostream>
#include <thread>
#include <map>
#include <functional>
#include <vector>


#define UNDEFINED_TIME -1.0 //used in permanent time events


enum EVENTS
{
    SHOW_SCREEN_FPS = -100
};

/*
dtTimeEvent should be used when dt is undefined and should be called every frame, such as animation class movements.
*/

struct dtTimeEvent
{
    public:
    dtTimeEvent(std::function<void(double)> foo);
    void update();

    double elapsedTime = 0.0;
    
    private:
        std::chrono::high_resolution_clock::time_point t;
        std::function<void(double)> function;
        

};

/*

timeEvent is called every x ms.
Uses:   sprites

*/

struct timeEvent
{
            timeEvent(double _duration , std::function<void()> _function);
            double duration;
            double time_left;
            void update();

            std::function<void()> foo;

            private:
                std::chrono::high_resolution_clock::time_point t1;
};


class timer
{
    public:
                ~timer();
                timer(double fps , double cps);
                /*
                    warning: duration should be greater than 1000.0 / cps (ms), it may impact performance
                */
                void newTimeEvent(int id , double duration ,  std::function<void()> function); //create a time event, which executes a given function everytime time elapsed reaches duration in milliseconds
                void removeTimeEvent(int id);
                void process_time_events();

                void new_dt_function(int foo_id , std::function<void(double)> foo);
                void remove_dt_function(int foo_id);
                void update_dt_functions();
                double get_dt_elapsed_time(int foo_id);
                void reset_dt_elaped_time(int foo_id);

                double get_fps();

                void start_frame();
                void end_frame();
                void wait();

                void fpsTick();
                bool canTickFps();
                bool canTickCps();
                void cpsTick();

                


    private:
                std::map<int , timeEvent*> time_events;
                std::map<int , dtTimeEvent*> dtTime_events;
                double minium_time_event;
                
                std::chrono::high_resolution_clock::time_point start_f = std::chrono::high_resolution_clock::now();
                std::chrono::high_resolution_clock::time_point end_f = std::chrono::high_resolution_clock::now();;

                double standard_delay = 166666667.0;

                double fps = 30 , cps = 60;
                double fps_cps_ratio = fps / cps;
                int fps_tick = 1 , cps_tick = 1;

                std::vector<double> last_frames;

        



};