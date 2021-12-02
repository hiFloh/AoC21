/**
 * @author Florian Gapp
 * @date 02.12.21
 *
 * header for Day 2 of AoC (https://adventofcode.com/)
 */

#ifndef AOC21_D2_H
#define AOC21_D2_H

#include <vector>
#include <string>
#include <iostream>

/**
 * @brief represents a command which can be sent to the submarine
 */
class Command{
public:
    int value;
    std::string dir;
};
/**
 * @param input
 * @param C
 * @return
 * @brief input operator to read command from file
 */
std::istream &operator>>(std::istream&input,Command&C);

/**
 * @brief submarine for task1
 */
class ship{
public:
    void execute(Command const&c);
    int getX()const;
    int getY()const;

protected:
    virtual void up(int i);
    virtual void down(int i);
    virtual void forward(int i);

    int x=0;
    int y=0;
};

/**
 * @brief submarin for task2
 */
class ship2: public ship{

protected:
    int aim =0;

    void up(int i) override;

    void down(int i) override;

    void forward(int i) override;
};

/**
 * @brief Day2
 */
class D2 {
    public:
    static int mmain(std::vector<std::string> const& args);

};



#endif //AOC21_D2_H
