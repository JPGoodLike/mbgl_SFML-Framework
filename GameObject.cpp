#include "GameObject.hpp"


namespace mbgl {
    GameObject::GameObject(std::string name)
    : name(name) {}
    GameObject::~GameObject() = default;

    void GameObject::Start() {}
    void GameObject::Update() {}
    void GameObject::FixedUpdate() {}
    void GameObject::Render() {}
    void GameObject::OnDestroy() {}
}