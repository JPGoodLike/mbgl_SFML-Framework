#include "GameObject.hpp"


namespace mbgl {
    GameObject::GameObject(std::string name)
    : name(name) {}
    GameObject::~GameObject() = default;

    void GameObject::Init() {}
    void GameObject::Shutdown() {}

    void GameObject::OnEnable() {}
    void GameObject::OnDisable() {}

    void GameObject::OnCreate() {}
    void GameObject::Update() {}
    void GameObject::FixedUpdate() {}
    void GameObject::OnDestroy() {}

    bool GameObject::IsActive() {
        return isActive;
    }
    void GameObject::SetActive(bool state) {
        isActive = state;
        if (state) {
            OnEnable();
        } else {
            OnDisable();
        }
    }
}