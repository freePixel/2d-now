#pragma once

#include <math.h>

/*
    point.h define a 2d point with a template type. 
    Only allowed data types wich support arithmetic operators

*/
template <typename T>

struct p2d
{
    T x;
    T y;

    p2d()
    {
        x = (T)0;
        y = (T)0;
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
    p2d operator/(T k)
    {
        return {this->x / k , this->y / k};
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
    static float distance(p2d p1 , p2d p2)
    {
        return sqrtf((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
    }
};