#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H

#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum gameState { PRE_GAME, IN_GAME, POST_GAME };

class towerOfHanoi
{
    public:
        towerOfHanoi();
        ~towerOfHanoi();

        void run();

    private:
        // Data structure to represent the towers
        std::stack<int>* rod;
        void createRods();

        // Puzzle settings
        int numDisks, numRods, startRod, endRod, *auxRod;

        // Solve the puzzle
        void solve();
        void startRodToAuxRod();
        void startRodToEndRod();
        void auxRodToEndRod();
        void sameNumStartRodToEndRod();
        void trivialStartRodToEndRod();
        bool isInvalidRod(int rodNum, int prevDisk);
        bool isAuxiliaryRod(int rodNum);
        void placeDisk(int beginRod, int endRod, bool solving = true);

        // Solve instructions
        std::queue<std::pair<int, int>> solveData;
        std::pair<int, int> instruction;

        // Game state and events
        gameState state;
        typedef void (towerOfHanoi::*runStatePtr)();
        runStatePtr runState[3];
        void preGame();
        void inGame();
        void postGame();
        typedef void (towerOfHanoi::*eventPtr)(sf::Event event);
        eventPtr processEvent[3];
        void preGameEvent(sf::Event event);
        void inGameEvent(sf::Event event);
        void postGameEvent(sf::Event event);

        // Graphics
        sf::RenderWindow window;

        // Disk
        sf::Texture diskTexture[4];
        sf::Sprite* diskSprite;
        void loadDiskSprites();

        // Background
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;

        // Foreground
        sf::Texture foregroundTexture;
        sf::Sprite foregroundSprite;

        // Mist
        sf::Texture mistTexture[2];
        sf::Sprite mistSprite[2];
        int mistSpeed[2];
        int mistMaxAlpha, mistMinAlpha;
        void animateMist();

        // Sound
        sf::SoundBuffer sfxBuffer;
        sf::Sound sfx;

        // Text/Menu
        sf::Font font;
        sf::Text title, askEnter, askInput[2], inputText[2], userMoveCount, endMsg[3], askConfirm;
        sf::String inputStr[2];

        int focus;                          // 0 = num disks, 1 = num rods, 2 = confirmation
        bool needConfirmation, doLargeValue;

        sf::RectangleShape focusBox;
        sf::Texture arrowTexture;
        sf::Sprite arrowSprite[2];

        void incrementInputStr(int focus);
        void decrementInputStr(int focus);
        inline void incrementMoveCount()
        {
            userMoveCount.setString(std::to_string(std::stoul(userMoveCount.getString().toAnsiString())+1));
        }
        void setEndMessage();

        // Dim screen
        sf::RectangleShape dimRect;
        sf::Color defaultDimColor;
        int dimRGB[3];
        void setDim(bool on);

        // Disk animation
        bool moveInProgress;
        sf::Clock moveClock;
        sf::Time moveTime;
        void moveDisk();
        void getNextInstruction();
        int posX(int rodNum);
        int posY(int rodNum);

        // Etc
        void clearSettings();
};

#endif // TOWEROFHANOI_H
