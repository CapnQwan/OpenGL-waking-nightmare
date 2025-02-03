#pragma once

#include <unordered_map>
#include <memory>
#include "../GameObjects/GameObjects/GameObject.hpp"

// The GameObjectManager handles the lifetime of GameObjects.
// It stores them in an unordered_map keyed by their unique IDs.
class GameObjectManager {
private:
    // Using unique_ptr to manage the lifetime of game objects automatically.
    std::unordered_map<int, std::unique_ptr<GameObject>> gameObjects;

public:
    GameObjectManager() = default;
    ~GameObjectManager() = default; // Unique pointers automatically clean up.

    // Creates a new game object of type T (which should be a subclass of GameObject),
    // stores it, and returns a raw pointer for immediate use.
    // Usage:
    //    MyCustomGameObject* obj = manager.CreateGameObject<MyCustomGameObject>(/* constructor args */);
    template<typename T, typename... Args>
    T* CreateGameObject(Args&&... args) {
        // Construct the game object with forwarded arguments.
        auto gameObject = std::make_unique<T>(std::forward<Args>(args)...);
        int id = gameObject->GetID();
        T* rawPtr = gameObject.get(); // Save raw pointer for returning.
        gameObjects.emplace(id, std::move(gameObject));
        return rawPtr;
    }

    // Adds an already-created game object to the manager.
    // The manager takes ownership of the object.
    void AddGameObject(std::unique_ptr<GameObject> gameObject) {
        if (gameObject) {
            int id = gameObject->GetID();
            gameObjects.emplace(id, std::move(gameObject));
        }
    }

    // Removes a game object by its unique ID.
    // The game object will be destroyed when its unique_ptr is removed.
    void RemoveGameObject(int id) {
        gameObjects.erase(id);
    }

    // Retrieves a pointer to a game object by ID.
    // Returns nullptr if no object with that ID exists.
    GameObject* GetGameObject(int id) {
        auto it = gameObjects.find(id);
        return (it != gameObjects.end()) ? it->second.get() : nullptr;
    }

    // Returns a const reference to the container of game objects.
    // This can be useful for iterating over all game objects.
    const std::unordered_map<int, std::unique_ptr<GameObject>>& GetAllGameObjects() const {
        return gameObjects;
    }

    // Example update function.
    // If your GameObject class (or its components) have an update method,
    // you can iterate and update each game object.
    void Update(float deltaTime) {
        for (auto& [id, gameObject] : gameObjects) {
            // If you add an Update method to GameObject, you could call it here:
            // gameObject->Update(deltaTime);
        }
    }

    // Example render function.
    // Similarly, if your GameObject class has a render method,
    // you can iterate and render each game object.
    void Render() {
        for (auto& [id, gameObject] : gameObjects) {
            // If you add a Render method to GameObject, you could call it here:
            // gameObject->Render();
        }
    }
};
