#pragma once
/*
    point.h define a 2d point with a template type. 
    Only recommended numeric data types.

*/
template <typename T>

struct p2d
{
    T x;
    T y;

    p2d()
    {
        
    }
    p2d(T x , T y)
    {
        this->x = x;
        this->y = y;
    }

    p2d operator+(p2d point)
    {
        return {x + point.x , y + point.y};
    }
    void operator+=(p2d point)
    {
        x += point.x;
        y += point.y;
    }
    p2d operator-(p2d point)
    {
        return {x - point.x , y - point.y};
    }
    void operator-=(p2d point)
    {
        x -= point.x;
        y -= point.y;
    }
    p2d operator*(p2d point)
    {
        return {x * point.x , y * point.y};
    }
    p2d operator*(T k)
    {
        return {k * this->x , k * this->y};
    }
    void operator*=(p2d point)
    {
        x *= point.x;
        y *= point.y;
    }
    p2d operator/(p2d point)
    {
        return {x / point.x , y / point.y};
    }
    void operator/=(p2d point)
    {
        x /= point.x;
        y /= point.y;
    }
};