#include "timer.h"

void timer::newTimeEvent(int id , double duration , std::function<void()> function)
{
    time_events[id] = timeEvent(duration * 1000000, function);
    if(duration < minium_time_event)
    {
        minium_time_event = duration * 10000000;
    }
    
}

void timer::removeTimeEvent(int id)
{
    if(time_events[id].duration <= minium_time_event)
    {
        double min = time_events[0].duration;
        for(auto iter : time_events)
        {
            if(iter.second.duration < min) min = iter.second.duration;
        }
        minium_time_event = min;
    }
    time_events.erase(id);
}

void timer::startFrame()
{
    start_frame = std::chrono::high_resolution_clock::now();
}

void timer::endFrame()
{
    end_frame = std::chrono::high_resolution_clock::now();
}



void timer::wait()
{
    int64_t diff = (end_frame - start_frame).count();
    int64_t sleep_time = minium_time_event - (int64_t)diff;
    if(sleep_time < 0)
    {
        return;
    }
    else{
        std::this_thread::sleep_for(std::chrono::nanoseconds(sleep_time));
    }
}

void timer::update_time_events()
{
    for (auto iter : time_events)
    {
        iter.second.update();
    }
}