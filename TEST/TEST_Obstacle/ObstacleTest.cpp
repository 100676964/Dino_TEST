#include "../../Animal.h"
using namespace Dino;
bool test_returnX()
{
    Obstacle ob(1);
    std::cout<<ob.returnX();

}
bool test_returnY()
{
    Obstacle ob(1);
    std::cout<<ob.returnY();
}

bool test_setPos()
{
    Obstacle ob(1);
    ob.setPos(2,5);
    std::cout<<ob.returnX();
    std::cout<<ob.returnY();
}
bool test_collipse()
{
    Obstacle ob(1);
    std::cout<<ob.collipsed();
    ob.isCollipsed();
    std::cout<<ob.collipsed();
}
int main()
{
    
}
