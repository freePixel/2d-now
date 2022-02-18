#include "chunk.h"

chunk::chunk(p2d<int> _coordinate)
{
            coordinate = _coordinate;
}

std::vector<p2d<int>>& chunk::find_contained_chunks(p2d<float> position , p2d<float> size)
{
    std::vector<p2d<int>>* v1 = new std::vector<p2d<int>>();
    p2d<int> pos = p2d<int>((int)position.x , (int)position.y);
    p2d<int> siz = p2d<int>((int)size.x , (int)size.y);

    p2d<int> top_left_chunk = pos / CHUNK_SIZE;
    p2d<int> bottown_right_chunk = (pos + siz) / CHUNK_SIZE;

    for(int i=top_left_chunk.x;i<=bottown_right_chunk.x; i++)
    {
        for(int j=top_left_chunk.y; j >= bottown_right_chunk.y ; j--)
        {
            v1->push_back(p2d<int>(i , j));
        }
    }
    return *v1;
}

p2d<int> chunk::find_chunk(p2d<float> position)
{
    return p2d<int>((int)position.x / CHUNK_SIZE , (int)position.y / CHUNK_SIZE);
}

