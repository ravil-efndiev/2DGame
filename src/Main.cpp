#include <RVL/Core/EntryPoint.hpp>
#include <RVL.hpp>
#include "MainState.hpp"

class Game : Rvl::App
{
public:
    Game() : Rvl::App(1020, 800, "Game") {}
    ~Game();
private:
    void Start()
    {
        _currentState = NewPtr<MainState>();
        _currentState->Start();
    }

    void Update()
    {
        _currentState->Update();
    }
}

int main()
{
    Rvl::status_t status = Rvl::InitializeApp<Game>();
    return status;   
}
