#pragma once

#include "manager.h"
#include "entity.h"

class entity;

class entityManager : public manager<int , entity*>
{
    public:
        bool force_load(int id) override;
        void derived_remove(int id) override;
    protected:
        void on_set(int id) override;


};