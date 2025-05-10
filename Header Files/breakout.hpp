#pragma once
#include <iostream>

class Breakout {
    public:
        Breakout();
        ~Breakout();
        
        // Game control methods
        void startGame();
        void stopGame();
        void pause();
        void resume();
        void reset();

    private:
        bool isRunning;
}; 