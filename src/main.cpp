#include "Core/Core.hpp"

int main() {
    Core core;
    
    if (!core.Initialize()) {
        return -1;
    }

    core.Run();

    return 0;
}
