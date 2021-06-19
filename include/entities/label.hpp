#ifndef LABEL_HPP
#define LABEL_HPP

#include <string>
#include "entity.hpp"

class Label : public Entity {
    std::string str;

public:
    Label(float2, const std::string& = "");
    void set_str(const std::string&);
    void draw(Term::Renderer& rend) override;
};

#endif
