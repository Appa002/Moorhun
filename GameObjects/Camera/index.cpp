#include "../../Simple2DSource/header/Simple2D.h"

using namespace Simple2D;
class Camera : public Behavior{
public:

    unsigned int count = 0;
    unsigned int moorCount = 0;

    int* lives;
    bool* halt;

    void init() override {
        lives = new int(3);
        halt = new bool(false);
        addAttribute<int>("lives", lives);
        addAttribute<bool>("halt", halt);
    }

    void setup() override {
        auto o = findGameObject("Moorhun");
        cloneGameObject(findGameObject("Moorhun"),"ReferenceHuhn");
        findGameObject("ReferenceHuhn")->loadNewSprite("");
    }

    void update() override {

        if(*halt)
            return;

        if(*lives != 3 && *lives > -1){
            findGameObject("Lives_" + std::to_string(*lives))->loadNewSprite("");
        }

        if(*lives == -1){
            std::cout << "[GAME OVER]" << std::endl;
            *halt = true;
        }
        if(count == 50){
            count = 0;
            moorCount++;
            cloneGameObject(findGameObject("ReferenceHuhn"), "Moorhun_" + std::to_string(moorCount));
        }
        count++;
    }
};

REGISTER_GAME_OBJECT(Camera)