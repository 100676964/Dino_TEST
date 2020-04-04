#include "../../Dino.h"
#include <thread>
#include <fstream>
using namespace Dino;
const int windowSizeX=800;
const int windowSizeY=600;
const int pixelStretch=4;
paint::font fnthp("hp",38,{850});
bool Dino_HP_Add()
{
    try
    {
        using namespace nana;
        bool processing = true;
        Environment env(windowSizeX,windowSizeY,5);
        Dino::Dino dino(windowSizeX,windowSizeY,5);
        Animals bird(windowSizeX,windowSizeY,5);
        env.setGroundPos(env.returnYSize()*3/4+env.returnYSize()*pixelStretch/2);
        form fm{API::make_center(windowSizeX, windowSizeY)};
        fm.caption("Integration Test1");
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
            int life = 6;
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
            processing = false;
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
        fm.events().unload([&processing](const arg_unload &arg)
        { 
            if(processing)
            {
                arg.cancel = true;
                cout<<"Wait For Test To Finish"<<endl;
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
bool Dino_FALL_Death()
{
    try
    {
        using namespace nana;
        bool processing = true;
        Environment env(windowSizeX,windowSizeY,5);
        Dino::Dino dino(windowSizeX,windowSizeY,5);
        Animals bird(windowSizeX,windowSizeY,5);
        env.setGroundPos(2000);
        form fm{API::make_center(windowSizeX, windowSizeY)};
        fm.caption("Integration Test2");
        drawing dw(fm);
        dw.draw([&env,&dino](paint::graphics &graph) 
        {
            dino.autoAnimateDino(graph);
            env.drawGround(graph);
            dino.displayHP(graph,windowSizeX-25,20,fnthp);
        });
        std::thread T([&]
        {
            int duration = 0;
            while(!dino.deadOrNot() && duration < 20)
            {
                dino.updateDino(env,bird,false);
                API::refresh_window(fm);
                for(double j = 0; j < 10000000; j++);
            }
            processing = false;
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
        fm.events().unload([&processing](const arg_unload &arg)
        { 
            if(processing)
            {
                arg.cancel = true;
                cout<<"Wait For Test To Finish"<<endl;
            }
            
        });
        fm.show();
        nana::exec();
        T.join();
    }
    catch(exception)
    {

    }
}
bool Dino_Hit_Anims()//test animal(bird) collapse
{
    try
    {
        using namespace nana;
        bool processing = true;
        Environment env(windowSizeX,windowSizeY,5);
        Dino::Dino dino(windowSizeX,windowSizeY,5);
        Animals bird(windowSizeX,windowSizeY,5);
        env.setGroundPos(500);
        form fm{API::make_center(windowSizeX, windowSizeY)};
        fm.caption(L"Bench Mark Test");
        drawing dw(fm);
        dw.draw([&env,&dino,&bird](paint::graphics &graph) 
        {
            dino.autoAnimateDino(graph);
            bird.autoAnimateAnimals(graph);
            env.drawGround(graph);
            dino.displayHP(graph,windowSizeX-25,20,fnthp);
        });
        std::thread T([&]
        { 
            srand(0);
            int duration = 0;
            while(!dino.deadOrNot() && duration < 20)
            {
                while(true)
                {
                    bird.updateAnimals(env);
                    
                    if(!bird.returnAnims().empty())
                    {
                        while(bird.returnAnims().at(0).returnX()>=200)//here probably will need a change to the number to make the hit
                        {
                            bird.updateAnimals(env);
                        }
                        break;
                    }
                    API::refresh_window(fm);
                }
                if(bird.returnAnims().size() == 1)
                {   //update dino to see if the hit count, the dino will setjump in order to reach the high bird
                    for(int i = 0; i < 15; i++)
                    {
                        dino.updateDino(env,bird,false);
                        API::refresh_window(fm);   
                        for(double j = 0; j < 10000000; j++);
                    }
                    dino.setJump();
                    for(int i = 0; i < 30; i++)
                    {
                        dino.updateDino(env,bird,false);
                        bird.updateAnimals(env);
                        //env.updateEnvironment();
                        API::refresh_window(fm);   
                        for(double j = 0; j < 10000000; j++);
                    }
                }
                duration++;
            }
            processing = false;
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
        fm.events().unload([&processing](const arg_unload &arg)
        { 
            if(processing)
            {
                arg.cancel = true;
                cout<<"Wait For Test To Finish"<<endl;
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
    ofstream file;
    file.open("../TEST_Results/Integration_Test_Results");
    cout<<"Testting..."<<endl;
    file<<"HP_Test:"<<endl;
    if(Dino_HP_Add())
    {
        cout<<"pass"<<endl;
        file<<"pass"<<endl;
    }
    else
    {
        cout<<"fail"<<endl;
        file<<"fail"<<endl;
    }
    
    cout<<"Testting..."<<endl;
    file<<"FALL_Test:"<<endl;
    if(Dino_FALL_Death())
    {
        cout<<"pass"<<endl;
        file<<"pass"<<endl;
    }
    else
    {
        cout<<"fail"<<endl;
        file<<"fail"<<endl;
    }

    cout<<"Testting..."<<endl;
    file<<"FALL_Test:"<<endl;
    if(Dino_Hit_Anims())
    {
        cout<<"pass"<<endl;
        file<<"pass"<<endl;
    }
    else
    {
        cout<<"fail"<<endl;
        file<<"fail"<<endl;
    }
}   
