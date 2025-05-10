#pragma once
#include <iostream>
#include <string>

class Breakout {
    public:
        bool startGame();
        void stopGame();
    private:
        Breakout();
        ~Breakout();
        void pause();
        void resume();
        void reset();

}