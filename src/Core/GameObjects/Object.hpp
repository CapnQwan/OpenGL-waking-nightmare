#pragma once
#include <atomic>
#include <string>

class Object {
private:
    static std::atomic<int> nextID;
    int id;
    std::string name;

public:
    Object(const std::string& name = "Object");
    virtual ~Object();

    int GetID() const { return id; }
    std::string GetName() const { return name; }
    void SetName(const std::string& newName) { name = newName; }
};
