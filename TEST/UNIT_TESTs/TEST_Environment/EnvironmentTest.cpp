#include "../../../Environment.h"
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace nana;
using namespace std;
using namespace Dino;

//test the continueAll() function as well
bool test_stopAll()
{
    Environment env(50,6,1);
    int num=0;
    bool res1=true;
    bool res2=false;
    while(num<100)
    {
        vector<point> before_stop = env.returnGrounds();
        
        env.stopAll();
        env.updateEnvironment();
        
        vector<point> after_stop = env.returnGrounds();
        
        for (int i=0;i<before_stop.size();i++){
            
                if(before_stop.at(i).y!=after_stop.at(i).y)
                    res1=false;
                else
                  continue;  
            
        }
        
        
        env.continueAll();
        env.updateEnvironment();
        
        vector<point> after_continue=env.returnGrounds();
        
        for (int i=0;i<after_stop.size();i++){
            
                if(after_stop.at(i).y==after_continue.at(i).y)
                    continue;
                else if(after_stop.at(i).y!=after_continue.at(i).y)
                    res2=true;  
            
        }
        
        
        
        
        num++;
    }
    return res1&&res2;
}
bool test_setPassingSpeed()
{
    Environment env(10,10,1);
    env.setPassingSpeed(5);
    return env.returnPassingSpeed()==5;
}
//test for generating all obstacles in specific environment
bool test_updateEnvironment()
{
    int windowX = 50;
    int windowY = 6;
    int strech = 5;
    Environment env(windowX,windowY,strech);
    env.setGroundPos(0);
    
    //hegiht of the ground
    bool res=true;
    int num=0;
    while(num<100)
    {
        
        env.updateEnvironment();
        vector<point> temp;
        //cout<<env.returnGroundPos()<<endl;
        temp=env.returnGrounds();
        for (int i=0;i<temp.size();i++)
        {
            
            // the ground will not surpass the window to the outside
            if(temp.at(i).y>windowY || temp.at(i).y<0 )
                
                res=false;
            //except for the cliff pos
            else if(temp.at(i).y==10000000)
                continue;
            else
                continue;
        }
         
        
        
        num++;
    }
    
    return res;

}

bool test_returnGroundPos()
{
    
    Environment env(10,10,1);
    env.setGroundPos(20);
    return env.returnGroundPos()==20;

}

bool test_returnYSize()
{
    Environment e(50,6,5);
    return e.returnYSize() == 6;
}

bool test_returnSizeX()
{
    
    Environment env(20,10,1);
    return env.returnXSize()==20;
}

bool test_returnPassingSpeed()
{
    Environment e(10,10,1);
    e.setPassingSpeed(5);
    return e.returnPassingSpeed()==5;
}



