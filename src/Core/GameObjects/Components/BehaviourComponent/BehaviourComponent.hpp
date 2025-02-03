#pragma once
#include "../Component.hpp"

class BehaviourComponent : public Component {
private:
    bool isEnabled = true;
    bool isActive = true;
    bool isStarted = false;
public:
    BehaviourComponent(GameObject* gameObject);
    virtual ~BehaviourComponent();

    void Enable() { isEnabled = true; }
    void Disable() { isEnabled = false; }
    bool IsEnabled() const { return isEnabled; }
    void SetActive(bool active) { isActive = active; }
    bool IsActive() const { return isActive; }

    void HandleAwake() override;
    void HandleStart() override;
    void HandleUpdate() override;

private:    
    //Virtual function for initilizating the component
    virtual void Awake();
    //Virtual function for starting the component
    virtual void Start();
    //Virtual function for updating the component
    virtual void Update();
};
