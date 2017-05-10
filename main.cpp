
#include "artirellyduel.hpp"

#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    ArtirellyDuel artirellyDuel;

    // run game
    artirellyDuel.run();

    return (0);
}
