#pragma once

#include <SFML/System/Time.hpp>

namespace GameEngine
{
    class GameState
    {
        private:

        public:
            GameState(){};
            virtual ~GameState(){};

            virtual void Init()= 0;
            virtual void ProcessInput() = 0;
            virtual void Update(sf::Time deltaTime) = 0;
            virtual void Draw() = 0;
            
    };
}