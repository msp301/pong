#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    Position(int x, int y);
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

private:
    int X;
    int Y;
};

#endif //POSITION_H
