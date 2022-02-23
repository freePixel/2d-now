#pragma once

#include <vector>
#include "point.h"

#define CHUNK_SIZE 256

class chunk
{
    public:
        chunk(p2d<int> _coordinate);
        std::vector<int>& get_objects();
        static void find_contained_chunks(p2d<float> position , p2d<float> size , std::vector<p2d<int>>& vec);
        static p2d<int> find_chunk(p2d<float> position);

        void add_entity(int id);
        void remove_entity(int e_id);
        
    private:
        p2d<int> coordinate;
        std::vector<int> objects; //entity ids

};

