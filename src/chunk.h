#pragma once

#include <vector>
#include "entity.h"
#include "point.h"

#define CHUNK_SIZE 256

class chunk
{
    public:
        chunk(p2d<int> _coordinate);
    
        static std::vector<p2d<int>>& find_contained_chunks(p2d<float> position , p2d<float> size);
    private:
        p2d<int> coordinate;
        std::vector<entity*> objects;

};