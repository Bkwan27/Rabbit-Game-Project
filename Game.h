#ifndef GAME
#define GAME

#include <string>
class Arena;

int computeDanger(const Arena& a, int r, int c);
bool recommendMove(const Arena& a, int r, int c, int& bestDir);

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nRabbits);
    ~Game();

    // Mutators
    void play();

private:
    Arena* m_arena;

    // Helper functions
    std::string takePlayerTurn();
};
#endif 