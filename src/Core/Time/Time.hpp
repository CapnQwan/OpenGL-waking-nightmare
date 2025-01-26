#pragma once
#include <GLFW/glfw3.h>

class Time {
private:
    float startTime;
    float currentTime;
    float deltaTime;
    float lastFrame;

public:
    Time();
    ~Time();

    void Update();
    float GetDeltaTime() const;
    float GetTime() const;

private:
    void CalculateDeltaTime();
}; 