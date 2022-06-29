#pragma once

#include <stack>
#include <memory>
#include <GameState.hpp>

namespace GameEngine
{
class StateManager
{
private:
    std::stack<std::unique_ptr<GameState>> stateStack;
    std::unique_ptr<GameState> newState;

    bool add;
    bool replace;
    bool remove;
    
public:
    StateManager();
    ~StateManager();

    void Add(std::unique_ptr<GameState> toAdd, bool replace = false); 
    void PopCurrent();
    void ProcessStateChange();
    std::unique_ptr<GameState>& GetCurrent();
};

}