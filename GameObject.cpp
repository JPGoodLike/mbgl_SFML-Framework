#include "GameObject.hpp"


namespace mbgl {
    GameObject::GameObject(std::string name)
    : name(name) {}
    GameObject::~GameObject() = default;

    void GameObject::Init() {}
    void GameObject::Shutdown() {}

    void GameObject::OnCreate() {}
    void GameObject::Update() {}
    void GameObject::FixedUpdate() {}
    void GameObject::OnDestroy() {}
}