#ifndef INSTRUCTIONS_SCENE_HPP
#define INSTRUCTIONS_SCENE_HPP

#include "scene.hpp"

struct InstructionsScene : public Scene {
    InstructionsScene();
    state manage_events(int, float) override;
};

#endif //INSTRUCTIONS_SCENE_HPP
