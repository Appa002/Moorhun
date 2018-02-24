#include "../../Simple2DSource/header/Simple2D.h"
#include "../../Simple2DSource/header/MapManager.h"
#include <stdlib.h>
#include <time.h>

using namespace Simple2D;
class Moorhun : public Behavior{
public:
    Vec3* scale = nullptr;
    Vec3* position = nullptr;
    Vec3* velocity = nullptr;
    double oldMXPos = 0;
    double oldMYPos = 0;
    bool dead = false;

    void init() override {
        srand (time(NULL));
        float changedVel = rand() % 60 + 1;
        velocity = new Vec3((float)1/(84 + changedVel), (float)1/20, (float)0/1);
        scale = new Vec3((float)1/7, (float)1/7, (float)1/7);
        position = new Vec3(-1.0f, -1.0f, 0.0f);

        addAttribute<Vec3>("scale", scale);
        addAttribute<Vec3>("position", position);
    }

    void setup() override {
    }

    void update() override{
        if(findGameObject("Camera")->behavior->getAttribute<bool>("halt"))
            return;

        if(findGameObject(this)->name == "ReferenceHuhn")
            return;

        if(position->y < -1.0f){
            findGameObject(this)->remove();

            if(dead)
                return;

            int curLives = findGameObject("Camera")->behavior->getAttribute<int>("lives");
            findGameObject("Camera")->behavior->setAttribute<int>("lives", curLives - 1);
            return;

        }

        position->y += velocity->y;
        position->x += velocity->x;

        velocity->y -= (float)1/1100;
    }


    void onEvent(SDL_Event& e) override {
        if(findGameObject(this)->name == "ReferenceHuhn")
            return;

        if(e.type == SDL_MOUSEMOTION){
            double windowSizeX = MapManager::get()->getCurrentMap()->getWindowSizeX();
            double windowSizeY = MapManager::get()->getCurrentMap()->getWindowSizeY();
            oldMXPos = 2 * (e.motion.x / windowSizeX) - 1.0f;
            oldMYPos = -2 * (e.motion.y / windowSizeY) + 1.0f;
        } else if(e.type == SDL_MOUSEBUTTONDOWN){
            if(position->x - scale->x  / 2 < oldMXPos &&
                    position->x + scale->x / 2 > oldMXPos &&
                    position->y - scale->y < oldMYPos &&
                    position->y + scale->y > oldMYPos){
                findGameObject(this)->loadNewSprite("./Moorhun/hit.png");
                dead = true;
            }
        }
    }

    void onRemoval() override {
        delete velocity;
        deleteAttribute<Vec3>("position");
        deleteAttribute<Vec3>("scale");
    }

};

REGISTER_GAME_OBJECT(Moorhun)