#include "StateManager.hpp"

GameEngine::StateManager::StateManager() : add(false), replace(false), remove(false) 
{

}

GameEngine::StateManager::~StateManager()
{

}

    void GameEngine::StateManager::Add(std::unique_ptr<GameState> toAdd, bool replace_)
    {
        add = true;
        newState = std::move(toAdd);

        replace = replace_;
    }
    void GameEngine::StateManager::PopCurrent()
    {
        remove = true;
    }
    void GameEngine::StateManager::ProcessStateChange()
    {
        if(remove && (!stateStack.empty()))
        {
            stateStack.pop();
            remove = false;
        }

        if(add)
        {
            if(replace  && (!stateStack.empty()))
            {
                stateStack.pop();
                replace = false;
            }

            stateStack.push(std::move(newState));
            stateStack.top()->Init();
            add = false;
        }
    }
    std::unique_ptr<GameEngine::GameState> &GameEngine::StateManager::GetCurrent()
    {
        return stateStack.top();
    }