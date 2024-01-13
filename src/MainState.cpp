#include "MainState.hpp"

#include <Rendering/Renderer/Renderer.hpp>
#include <Rendering/OpenGL/GLFrameBuffer.hpp>
#include "TestScript.hpp"

MainState::MainState() : State((RenderMode)(RenderMode_3D | RenderMode_2D)) {}
MainState::~MainState() {}

void MainState::Start()
{
    _camera = UserPerspectiveCamera::New({0.f, 0.f, 0.f}, 45.f);
    
    Entity sprite = _currentScene->NewEntity(glm::vec3{5.f, 0.f, 5.f});
    sprite.Add<Sprite>("assets/textures/container.jpg", 1.f);
}

void MainState::Update()
{
    UserCamera::ToPerspective(_camera)->UpdateControls(ControllerType::InPlane, 5.f);
    
    if (Input::IsKeyPressedOnce(Keys::Key_Escape))
    {
        _lock = !_lock;
        App::GetInstance()->SetCursorLocked(_lock);
    }

    if (_lock)
        UserCamera::ToPerspective(_camera)->UpdateCursorRotation(2.f);
}

void MainState::Render()
{
    SceneRenderer::Render(_currentScene, _camera);    
}
