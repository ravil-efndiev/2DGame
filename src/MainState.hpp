#pragma once

#include <RVL.hpp>

using namespace Rvl;
class MainState : public Rvl::State
{
public:
    MainState();
    ~MainState();

    void Start() override;
    void Update() override;
    void Render() override;

private:
    bool _lock;
};

