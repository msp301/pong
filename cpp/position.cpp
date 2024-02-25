#include "position.h"

std::string Position::toString() const {
    return std::to_string(X) + ", " + std::to_string(Y);
}
