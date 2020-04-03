#include "AnimalTest.h"
// #include "../../../Animal.h"
// using namespace Dino;
bool animT::test_initAnimal()
{
    Animal tan(1,10,10,20);
    if(tan.returnXSize()!=16 || tan.returnYSize()!=12 || tan.returnSpeed()!=20) return false;
    return true;
}
bool animT::test_returnX()
{
    Animal bird(1,10,10,10);
    if(bird.returnX()!=10) return false;
    return true;
}
bool animT::test_returnY()
{
    Animal bird(1,10,10,10);
    if(bird.returnY()!=10) return false;
    return true;
}
bool animT::test_returnFrame()
{
    Animal bird(1,10,10,10);
    Animal bird2(1,10,10,10);
    
    for(int i=0;i<12;i++)
        for(int j=0; j<16;j++)
        {
            if(bird.returnFrame()[i][j]!=bird2.returnFrame()[i][j]) return false;
        }
    
    return true;
}

bool animT::test_updateFrame()
{
    Animal bird(1,10,10,10);
    Animal bird2(1,10,10,10);
    bird.updateFrame();
    for(int i=0;i<12;i++)
        for(int j=0; j<16; j++)
        {
            if(bird.returnFrame()[i][j]!= bird2.returnFrame()[i][j]) return true;
        }
    
    return false;
}
bool animT::test_setPos()
{
    Animal bird(1,10,10,10);
    bird.setPos(5,3);
    if(bird.returnX()!=5||bird.returnY()!=3) return false;
    return true;
}
bool animT::test_Collipse()
{
    Animal bird(1,10,10,10);
    if(bird.isCollipsed()) return false;
    bird.collipsed();
    if(!bird.isCollipsed()) return false;
    
    return true;
}