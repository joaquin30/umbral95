#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "renderer.hpp"

class Entity {
public:
    float2 pos;
    Entity(float2 p) : pos{p} {}
    virtual ~Entity() {}
    virtual void draw(Term::Renderer&) = 0;
};

#endif
