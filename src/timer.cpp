#include "timer.h"




timer::timer(double fps , double cps)
{
    this->fps = fps;
    this->cps = cps;
    fps_cps_ratio = fps / cps;
    if(fps < cps)
    {
        standard_delay = (int64_t)(1000000000.0 / fps);
    }
    else{
        standard_delay = (int64_t)(1000000000.0 / cps);
    }
}

void timer::newTimeEvent(int id , double duration , std::function<void()> function) //duration below 1000.0/cps not recommended. It may have an impact on performance.
{

    timeEvent* time_event = new timeEvent(duration , function);
    time_events[id] = time_event;
    if(duration < minium_time_event)
    {
        minium_time_event = duration;
    }
    else{
        if(minium_time_event == 0.0) minium_time_event = duration;
    }

}



void timer::remove_dt_function(int foo_id)
{
    delete dtTime_events[foo_id];
    dtTime_events.erase(foo_id);
}

void timer::new_dt_function(int foo_id , std::function<void(double)> foo)
{
    dtTimeEvent* event = new dtTimeEvent(foo);
    dtTime_events[foo_id] = event;
}

void timer::update_dt_functions()
{
    for(auto iter : dtTime_events)
    {
        iter.second->update();
    }
}

void timer::removeTimeEvent(int id)
{
    //find lowest duration
    if(time_events[id]->duration <= minium_time_event)
    {
        double min = time_events[0]->duration;
        for(auto iter : time_events)
        {
            if(iter.second->duration < min) min = iter.second->duration;
        }
        minium_time_event = min;
    }
    //delete object & erase from map
    delete time_events.at(id);
    time_events.erase(id);
}

void timer::process_time_events()
{
    for(auto iter = time_events.begin() ; iter != time_events.end() ; iter++)
    {
        iter->second->update();
    }
}

void timer::start_frame()
{
    start_f = std::chrono::high_resolution_clock::now();
}

void timer::fpsTick()
{
    fps_tick++;
}
void timer::cpsTick()
{
    cps_tick++;
}

bool timer::canTickCps()
{
   if(((double)fps_tick / cps_tick) >= fps_cps_ratio) return true;
    else{
        return false;
    }
}

bool timer::canTickFps()
{
    if(((double)cps_tick / fps_tick) >= fps_cps_ratio) return true;
    else{
        return false;
    }
}

void timer::end_frame()
{
    end_f = std::chrono::high_resolution_clock::now();
}

void timer::wait()
{
    auto diff = standard_delay - (end_f - start_f).count();
    std::this_thread::sleep_for(std::chrono::nanoseconds(diff));
}

timer::~timer()
{
    //delete timeEvent / dtTimeEvent map objects
    for(auto iter : time_events)
    {
        delete iter.second;
    }
    time_events.clear();
    for(auto iter : dtTime_events)
    {
        delete iter.second;
    }
    dtTime_events.clear();
}

//return the total elapsed time of a dtTimeEvent in ms
double timer::get_dt_elapsed_time(int foo_id)
{
    return dtTime_events[foo_id]->elapsedTime;
}

