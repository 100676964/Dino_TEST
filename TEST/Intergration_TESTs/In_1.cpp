#include "In_1.h"
const int windowSizeX=800;
const int windowSizeY=600;
const int pixelStretch=4;
paint::font fnthp("hp",38,{850});
bool doIT::Dino_HP_Add()
{
    try
    {
        using namespace nana;
        Environment env(windowSizeX,windowSizeY,5);
        Dino::Dino dino(windowSizeX,windowSizeY,5);
        Animals bird(windowSizeX,windowSizeY,5);
        env.setGroundPos(env.returnYSize()*3/4+env.returnYSize()*pixelStretch/2);
        form fm{API::make_center(windowSizeX, windowSizeY)};
        fm.caption(L"Bench Mark Test");
        drawing dw(fm);
        dw.draw([&env,&dino](paint::graphics &graph) 
        {
            dino.autoAnimateDino(graph);
            env.drawGround(graph);
            env.drawObstacle(graph);
            dino.displayHP(graph,windowSizeX-25,20,fnthp);
        });
        std::thread T([&]
        { 
            srand(0);
            while(true)
            {
                env.updateEnvironment();
                if(!env.returnObstacles().empty())
                {
                    if(env.returnObstacles().at(0).type() == -1)
                    {
                        for(int i = 0; i < 50; i++)
                        {
                            env.updateEnvironment();
                        }
                        break;
                    }
                
                }
            }
            for(int i = 0; i < 10; i++)
            {
                for(double j = 0; j < 10000000; j++);
                dino.updateDino(env,bird,false);
                API::refresh_window(fm);
            }
            dino.setJump();
            for(int i = 0; i < 30; i++)
            {
                for(double j = 0; j < 10000000; j++);
                dino.updateDino(env,bird,false);
                env.updateEnvironment();
                API::refresh_window(fm);
            }
            int life = 5;
            while(life > 0)
            {
                while(true)
                {
                    env.updateEnvironment();
                    if(!env.returnObstacles().empty())
                    {
                        if(env.returnObstacles().at(0).type() == 1)
                        {
                            for(int i = 0; i < 55; i++)
                            {
                                env.updateEnvironment();
                            }
                            break;
                        }
                    
                    }
                    // API::refresh_window(fm);
                }
                if(env.returnObstacles().size() == 1 && env.returnObstacles().at(0).type() == 1)
                {   
                    for(int i = 0; i < 15; i++)
                    {
                        dino.updateDino(env,bird,false);
                        env.updateEnvironment();
                        API::refresh_window(fm);   
                        for(double j = 0; j < 10000000; j++);
                    }
                    life--;
                }
            }
            fm.close();
            if(dino.deadOrNot())
            {
                return false;
            } 
            else
            {
                return true;
            }  
        });
        
        fm.show();
        nana::exec();
        T.join();
    }
    catch(exception)
    {
        cout<<"crashed!"<<endl;
    }
}



bool doIT::Dino_Hit_Anims()//test animal(bird) collapse
{
    try
    {
        using namespace nana;
        Environment env(windowSizeX,windowSizeY,5);
        Dino::Dino dino(windowSizeX,windowSizeY,5);
        Animals bird(windowSizeX,windowSizeY,5);
        env.setGroundPos(env.returnYSize()*3/4+env.returnYSize()*pixelStretch/2);
        form fm{API::make_center(windowSizeX, windowSizeY)};
        fm.caption(L"Bench Mark Test");
        drawing dw(fm);
        dw.draw([&env,&dino](paint::graphics &graph) 
        {
            dino.autoAnimateDino(graph);
            env.drawGround(graph);
            env.drawObstacle(graph);
            dino.displayHP(graph,windowSizeX-25,20,fnthp);
        });
        std::thread T([&]
        { 
            srand(0);
            
            int life = 5;
            while(life > 0)
            {
                while(true)
                {
                    bird.updateAnimals(env);
                    if(!bird.returnAnims().empty())
                    {
                        if(bird.returnAnims().at(0).type() == 1)
                        {//we need to place the bird in right place to make the hit happens
                            while(bird.returnAnims().at(0).returnX()>=1)//here probably will need a change to the number to make the hit
                            {
                                bird.updateAnimals(env);
                            }
                            break;
                        }
                    
                    }
                    // API::refresh_window(fm);
                }
                if(bird.returnAnims().size() == 1)
                {   //update dino to see if the hit count, the dino will setjump in order to reach the high bird
                    for(int i = 0; i < 15; i++)
                    {
                        dino.updateDino(env,bird,false);
                        //env.updateEnvironment();
                        API::refresh_window(fm);   
                        for(double j = 0; j < 10000000; j++);
                    }
                    dino.setJump();
                    for(int i = 0; i < 30; i++)
                    {
                        dino.updateDino(env,bird,false);
                        //env.updateEnvironment();
                        API::refresh_window(fm);   
                        for(double j = 0; j < 10000000; j++);
                    }
                    life--;
                }
            }
            fm.close();
            if(dino.deadOrNot())
            {
                return true;
            } 
            else
            {
                return false;
            }  
        });
        
        fm.show();
        nana::exec();
        T.join();
    }
    catch(exception)
    {
        cout<<"crashed!"<<endl;
    }
}

int main()
{
    if(doIT::Dino_HP_Add())
    cout<<"pass"<<endl;
}
