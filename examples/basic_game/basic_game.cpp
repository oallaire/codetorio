#include <game/ICodetorioGame.h>

using namespace codetorio;

int main() {
    ICodetorioGame &game = getICodetorioGame();
    game.tick();
    return 0;
}
