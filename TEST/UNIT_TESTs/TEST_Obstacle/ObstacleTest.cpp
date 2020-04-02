#include "../../../Obstacle.h"
using namespace Dino;
bool test_returnSizeX()
{
    Obstacle ob(1);
    int val=ob.returnSizeX();
    if(val!=9) return false;
    
    Obstacle ob2(2);
    int val=ob2.returnSizeX();
    if(val!=12) return false;
    
    Obstacle ob3(-1);
    int val=ob3.returnSizeX();
    if(val!=6) return false;
    
    return true;
}
bool test_returnSizeY()
{
    Obstacle ob(1);
    int val=ob.returnSizeY();
    if(val!=12) return false;
    
    Obstacle ob2(2);
    int val=ob2.returnSizeY();
    if(val!=23) return false;
    
    Obstacle ob3(-1);
    int val=ob3.returnSizeY();
    if(val!=6) return false;
    
    return true;
}

bool test_setPos()
{
    Obstacle ob(1);
    ob.setPos(2,5);
    if(ob.returnPosX()!=2) return false;
    if(ob.returnPosY()!=5) return false;
    
    return true;
}
bool test_collipse()
{
    Obstacle ob(1);
    if(ob.isCollipsed()!=false) return false;
        
    ob.collipsed();
    if(ob.isCollipsed()!=true) return false;
    
    return true;
}
// int main()
// {
//     if(test_returnSizeX()&&test_returnSizeY()&&test_setPos()&&test_collipse()) std::cout<<"Obstacle test: passed\n";
//     else  std::cout<<"Obstacle test: failed\n";
    
// }
