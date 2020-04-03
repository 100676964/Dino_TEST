#include <iostream>
#include <chrono>
#include <time.h>
#include <nana/gui.hpp>
#include <nana/gui/timer.hpp>
#include <nana/threads/pool.hpp>
#include <thread>
#include <fstream>
#include <mutex>
#include "../../Dino.h"
const int windowSizeX=800;
const int windowSizeY=600;
const int pixelStretch=4;
mutex mtx;
void bench_marking()
{
    
    using namespace nana;
    bool quit = false;
    Dino::Environment envir(windowSizeX,windowSizeY,pixelStretch);
	Dino::Animals anys(windowSizeX,windowSizeY,pixelStretch);
	Dino::Dino dino(windowSizeX,windowSizeY,pixelStretch);
    envir.setGroundPos(envir.returnYSize()*3/4+dino.returnYSize()*pixelStretch/2);
    auto fpstime=chrono::steady_clock::now();//get the time since epoch for fps counting
	int fps=0;
	int printfps=0;
	auto cfps=chrono::steady_clock::now();

    form fm{API::make_center(windowSizeX, windowSizeY)};
    fm.caption(L"Bench Mark Test");
    drawing dw(fm);
    //paint
	dw.draw([&envir, &dino, &anys, &fpstime,&fps,&printfps](paint::graphics &graph) 
    {//here we preset the method about all elements need to be paint, and set all the variable to control the paint process
		
        graph.rectangle({0,0,windowSizeX,windowSizeY},true,colors::bisque);//set the background color
		//progress drawing
		envir.drawEnvironment(graph);
		anys.autoAnimateAnimals(graph);
		dino.autoAnimateDino(graph);
        
	});
    //physics loop
    std::thread T([&]
    {
        while(!quit)
        {
            std::thread PHY([&]
            {   
                if(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now()-cfps).count()>=16)//update control for calculations/rendering, 16ms ~= 60 updates/sec
                {
                    mtx.lock();
                    if(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now()-fpstime).count()>=(1000))
                    {
                        cout<<printfps<<endl;
                        fpstime=chrono::steady_clock::now();//chrono::system_clock::to_time_t(chrono::system_clock::now());
                        printfps=fps;
                        fps=0;
                        
                    }
                    cfps=chrono::steady_clock::now();
                    // dino.reset();
                    envir.updateEnvironment();
                    dino.updateDino(envir,anys,false);
                    anys.updateAnimals(envir);
                    fps++;
                    mtx.unlock();
                }
            });
            std::thread RF([&]
            {
                API::refresh_window(fm);
            });   
            PHY.join();
            RF.join();
        }
    
    });  
    
    fm.events().unload([&quit](const arg_unload &arg)
    { 
        quit = true;    
    });
    fm.events().key_press([&dino,&envir,&anys](const arg_keyboard& ak)
    {
		if(ak.key==nana::keyboard::space)
		{
            dino.setJump();
        }
    });
    dw.update();
    fm.show();
    exec();
    T.join();
    
    
}
int main()
{
    bench_marking();
    
}
