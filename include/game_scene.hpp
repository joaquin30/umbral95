#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "scene.hpp"

struct GameScene : public Scene {
    GameScene();
    state manage_events(int, float) override;
};

#endif //GAME_SCENE_HPP
