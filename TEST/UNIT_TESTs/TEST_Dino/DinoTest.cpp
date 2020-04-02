#include "../../../Dino.h"
using namespace Dino;
bool test_reset()
{
    Dino::Dino dinoT(10,10,1);
    dinoT.setDead();
    dinoT.reset();
    if(dinoT.deadOrNot() == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool test_setStretch()
{
    int windowX = 50;
    int windowY = 6;
    int strech = 5;
    Animals bird(windowX,windowY,1);
    Environment env(windowX,windowY,1);
    env.setGroundPos(999);
    Dino::Dino dinoA(windowX,windowY,1);
    int before = env.returnPassingSpeed();
    dinoA.setStretch(strech);
    for(int i = 0; i < 2000; i++)
    {
        dinoA.updateDino(env,bird,false);
    }
    int after = env.returnPassingSpeed();
    if(after == before+strech)
        return true;    
    else
        return false;
}
bool test_returnDino()
{
    Dino::Dino dinoA(10,10,1);
    Dino::Dino dinoB(10,10,1);
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if(dinoA.returnDino()[i][j] == dinoB.returnDino()[i][j])
                continue;
            else
                return false;
            
        }
    }
    return true;
}
bool test_returnCurrentFrame()
{
    Dino::Dino dinoA(10,10,1);
    Dino::Dino dinoB(10,10,1);
    int framecout = 0;
    bool increase = true;
    while(framecout < 100)
    {
        for(int i = 0; i < 19; i++)
        {
            for(int j = 0; j < 19; j++)
            {
                if(dinoA.returnCurrentFrame()[i][j] == 1)
                    cout<<"#"<<" ";
                else 
                    cout<<"  ";
                if(dinoA.returnCurrentFrame()[i][j] == dinoB.returnCurrentFrame()[i][j])
                    continue;
                else
                    return false;
                
            }
            cout<<endl;
        }
        dinoA.autoFrameChange();
        dinoB.autoFrameChange(); 
        for(double i = 0; i < 1000000; i++)
        ;
        framecout++;
        system("clear");
    
    }
    
    return true;
}
bool test_increaseFrame()
{
    Dino::Dino dinoA(10,10,1);
    Dino::Dino dinoB(10,10,1);
    dinoA.increaseFrame();
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if(dinoA.returnCurrentFrame()[i][j] == dinoB.returnCurrentFrame()[i][j])
                continue;
            else
                return true;
            
        }
    }
    return false;
}
bool test_decreaseFrame()
{
    Dino::Dino dinoA(10,10,1);
    Dino::Dino dinoB(10,10,1);
    dinoA.increaseFrame();
    bool br = false;
    for(int i = 0; i < 19 && br == false; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if(dinoA.returnCurrentFrame()[i][j] == dinoB.returnCurrentFrame()[i][j])
                continue;
            else
            {
                br = true;
                break;
            }
        }
    }
    dinoA.decreaseFrame();
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if(dinoA.returnCurrentFrame()[i][j] == dinoB.returnCurrentFrame()[i][j])
                continue;
            else
                return false;
            
        }
    }
    return true;
}
bool test_setDead()
{
    Dino::Dino dinoA(10,10,1);
    if(dinoA.deadOrNot() == false)
        ;
    else
        return false; 
    dinoA.setDead();
    if(dinoA.deadOrNot() == true)
        return true;
    else
        return false;  
}
bool test_deadOrNot()
{
    Dino::Dino dinoA(10,10,1);
    if(dinoA.deadOrNot() == false)
        ;
    else
        return false; 
    dinoA.setDead();
    if(dinoA.deadOrNot() == true)
        return true;
    else
        return false;  
}
bool test_autoFrameChange()
{
    Dino::Dino dinoA(10,10,1);
    Dino::Dino dinoB(10,10,1);
    int framecout = 0;
    bool increase = true;
    while(framecout < 100)
    {
        for(int i = 0; i < 19; i++)
        {
            for(int j = 0; j < 19; j++)
            {
                if(dinoA.returnCurrentFrame()[i][j] == 1)
                    cout<<"#"<<" ";
                else 
                    cout<<"  ";
                if(dinoA.returnCurrentFrame()[i][j] == dinoB.returnCurrentFrame()[i][j])
                    continue;
                else
                    return true;
                
            }
            cout<<endl;
        }
        dinoA.autoFrameChange();
        // dinoB.autoFrameChange(); 
        for(double i = 0; i < 1000000; i++)
        ;
        framecout++;
        system("clear");
    
    }
    return false;
}
bool test_setJump()
{
    Dino::Dino dinoA(10,10,1);
    try
    {
        for(int i = 0; i < 10000; i++)
            dinoA.setJump();
    }
    catch(exception)
    {
        return false;
    }
    return true;
    
}
bool test_calculateGravity()
{
    Dino::Dino dinoA(50,6,1);
    Environment env(50,6,1);
    env.setGroundPos(999);
    try
    {
        int x = 0;
        while(x < 100)
        {
            for(int i = 0; i < 50; i++)
                dinoA.calculateGravity(env);
            dinoA.setJump();
            for(int i = 0; i < 50; i++)
                dinoA.calculateGravity(env);
            x++;
        }
    }
    catch(exception)
    {
        return false;
    }
    return true;
    
}
bool test_calculateCollipse()
{
    Dino::Dino dinoA(800,600,5);
    Environment env(800,600,5);
    Animals bird(800,600,5);
    env.setGroundPos(999);
    for(int i = 0; i < 10000; i++)
    {
        dinoA.updateDino(env,bird,false);
        bird.updateAnimals(env);
        if(dinoA.calculateCollipse(env,bird) > 0 && !bird.returnAnims().empty())
            return true;
        // cout<<dinoA.deadOrNot()<<endl;
    }
    return false;
    
}
bool test_calculateHp()
{
    Dino::Dino dinoA(800,600,5);
    Environment env(800,600,5);
    Animals bird(800,600,5);
    env.setGroundPos(999);
    int safty = 0;
    while(!dinoA.deadOrNot())
    {
        dinoA.updateDino(env,bird,false);
        bird.updateAnimals(env);
        env.updateEnvironment();
        dinoA.calculateHp(env,bird);
        if(safty > 10000)
            return false;
        safty++;
    }
    return true;
}
bool test_returnYSize()
{
    Dino::Dino dinoA(800,600,5);
    if(dinoA.returnYSize() == 19)
        return true;
    else
        return false;
}
bool test_returnXSize()
{
    Dino::Dino dinoA(800,600,5);
    if(dinoA.returnXSize() == 19)
        return true;
    else
        return false;
}
bool test_returnHScore()
{
    int Tscore = 100;
    Dino::Dino dinoA(800,600,5);
    dinoA.setHScore(Tscore);
    if(Tscore ==  dinoA.returnHScore())
        return true;
    else
        return false;
}
bool test_setHScore()
{
    int Tscore = 100;
    Dino::Dino dinoA(800,600,5);
    dinoA.setHScore(Tscore);
    if(Tscore ==  dinoA.returnHScore())
        return true;
    else
        return false;
}
