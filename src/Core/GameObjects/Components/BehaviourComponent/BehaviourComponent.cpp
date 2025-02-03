#include "BehaviourComponent.hpp"

BehaviourComponent::BehaviourComponent(GameObject* gameObject)
    : Component(gameObject)
{}

BehaviourComponent::~BehaviourComponent() {}

void BehaviourComponent::HandleAwake() {
    Awake();
}

void BehaviourComponent::HandleStart() {
    if (isStarted || !isEnabled || !isActive) {
        return;
    }
    isStarted = true;
    Start();
}

void BehaviourComponent::HandleUpdate() {
    if (isEnabled && isActive) {
        Update();
    }
}

// Base implementations—these can be overridden in derived classes.

// The Awake function is intended to be used to initialize the component.
// This means setting up any arrays or classes that are needed for the component.
void BehaviourComponent::Awake() {
    // Base initialization logic (if any)
}

// The Start function is intended to be used to initialize the component.
// As all other components should now be initilized, this component can not interact
// with other components and elements in those components.
void BehaviourComponent::Start() {
    // Additional startup logic could go here.
}

// The Update function is intended to be used to update the component.
// This means updating the component's state or performing any actions that need
//to be done every frame.
void BehaviourComponent::Update() {
    // Base update logic (if any)
}

