#include "Core/Time/Time.hpp"

Time::Time() {
    startTime = glfwGetTime();
}

Time::~Time() {}

void Time::Update() {
    currentTime = glfwGetTime();
    deltaTime = currentTime - lastFrame;
    lastFrame = currentTime;
}   

float Time::GetDeltaTime() const {
    return deltaTime;
}

float Time::GetTime() const {
    return currentTime;
}