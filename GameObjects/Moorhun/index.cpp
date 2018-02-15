#include "../../Simple2DSource/header/Simple2D.h"
#include "../../Simple2DSource/header/MapManager.h"

using namespace Simple2D;
class Moorhun : public Behavior{
public:

    Vec3* scale = nullptr;
    Vec3* position = nullptr;
    Vec3* velocity = nullptr;

    void init() override {
        velocity = new Vec3((float)1/64, (float)1/8, (float)0/1);
        scale = new Vec3((float)1/8, (float)1/8, (float)1/8);
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
            int curLives = findGameObject("Camera")->behavior->getAttribute<int>("lives");
            findGameObject("Camera")->behavior->setAttribute<int>("lives", curLives - 1);
            findGameObject(this)->remove();
            return;

        }

        position->y += velocity->y;
        position->x += velocity->x;

        velocity->y -= (float)1/265;
    }

    void onRemoval() override {
        delete velocity;
        deleteAttribute<Vec3>("position");
        deleteAttribute<Vec3>("scale");
    }
};

REGISTER_GAME_OBJECT(Moorhun)