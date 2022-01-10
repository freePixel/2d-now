#include "timer.h"

void timer::newTimeEvent(int id , double duration , std::function<void()> function)
{
    time_events[id] = timeEvent{duration , duration  , function};
    
}

void timer::removeTimeEvent(int id)
{
    time_events.erase(id);
}

timer::timer(double fps , double cps)
{
    this->fps = fps;
    this->cps = cps;
    if(fps < cps){
        base = fps;
    }
    else{
        base = cps;
    }
    fixed_wait_ns = (int64_t)(1000000000.0 / base);
    
}

void timer::updateF(){f++;}
void timer::updateL(){l++;}

void timer::start_frame()
{
    current_frame = std::chrono::high_resolution_clock::now();

}

void timer::end_frame()
{
    double dt = (std::chrono::high_resolution_clock::now() - current_frame).count() 1000000.0;
    update_time_events(dt);
    last_frame = std::chrono::high_resolution_clock::now();
}


void timer::wait()
{
    auto diff = last_frame - current_frame;
    int64_t dt = diff.count();
    if(dt > fixed_wait_ns)
    {
        return; //when fps/cps can't be achieved
    }
    else{
        int64_t wait_time = fixed_wait_ns - diff.count();
        std::this_thread::sleep_for(std::chrono::nanoseconds(wait_time));
    }
}

void timer::update_time_events(double dt)
{
    for (auto iter : time_events)
    {
        iter.second.time_left -= dt_ms;
        if(iter.second.time_left < 0.0)
        {
            iter.second.time_left = iter.second.duration + iter.second.time_left;

            iter.second.function(); //execute function
        }
    }
}

bool timer::updateLogic()
{

    return true;
}

bool timer::updateGraphics()
{
    return true;
}

double timer::elapsedTime(bool logic)
{
    if(logic)
    {
        return 0.0f;
    }
    else{
        return 0.0f;
    }
}