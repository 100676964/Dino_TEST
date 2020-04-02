#include "AnimalsTest.h"
// #include "../../Animals.h"
// #include "../../Environment.h"
// using namespace Dino;
bool test_initAnimals()
{
    Animals tanys(10,10,1);
    if(tanys.returnPassingSpeed()!=2) return false;
    
    return true;

}
bool test_reset()
{
    Animals tanys(10,10,1);
    
    tanys.setSpeed(50);
    tanys.reset();
    if(tanys.returnPassingSpeed()!=2) return false;
    
    return true;
}

bool test_setPassingSpeed()
{
    Animals tanys(10,10,1);
    
    tanys.setSpeed(40);
    if(tanys.returnPassingSpeed()!=40) return false;
    
    return true;
}
bool test_Update()
{
    Environment en(10,10,1);
    Animals tanys(10,10,1);
    
    en.setGroundPos(100);
    
    int index=0;
    while(true)
    {
        tanys.updateAnimals(en);
        
        if(tanys.returnAnims().size()!=0) return true;
        if(index>100000) return false;
        index++;
    }
}
// int main()
// {
//     if(test_initAnimals()&&test_reset()&&test_setPassingSpeed()&&test_Update()) std::count<<"Animals Test: passed\n";
//     else std::count<<"Animals Test: failed\n";
// } 
