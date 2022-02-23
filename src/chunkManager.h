#pragma once

#include "manager.h"
#include "chunk.h"


class chunkManager : public manager<p2d<int> , chunk*>
{
    public:
        bool force_load(p2d<int> id) override;
        void derived_remove(p2d<int> id) override;
        void on_set(p2d<int> id) override{};
    protected:
       
};