#include <RVL/Core/EntryPoint.hpp>
#include <RVL.hpp>
#include "MainState.hpp"

class Game : public Rvl::App
{
public:
    Game() : Rvl::App(1280, 820, "Game") {}
    ~Game() {}
private:
    void Start()
    {
        SetClearColor({0.3, 0.7, 0.4});
        _currentState = NewPtr<MainState>();
        _currentState->Start();
    }

    void Update()
    {
        _currentState->Update();
    }
};

int main()
{
    Rvl::status_t status = Rvl::InitializeApp<Game>();
    return status;   
}
