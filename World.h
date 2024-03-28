#ifndef CODE_WORLD_H
#define CODE_WORLD_H
class World{
private:
    int organism;
public:
    World();
    void makeTurn();
    void drawWorld();

    ~World();
};
#endif //CODE_WORLD_H
