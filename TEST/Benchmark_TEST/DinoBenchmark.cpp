#include <iostream>
#include <chrono>
#include <time.h>
#include <nana/gui.hpp>
#include <nana/gui/timer.hpp>
#include <nana/threads/pool.hpp>
#include <thread>
#include <fstream>
#include "../../Dino.h"
const int windowSizeX=800;
const int windowSizeY=600;
const int pixelStretch=4;

void bench_marking()
{
    
    using namespace nana;
    bool quit = false;
    Dino::Environment envir(windowSizeX,windowSizeY,pixelStretch);
	Dino::Animals anys(windowSizeX,windowSizeY,pixelStretch);
	Dino::Dino dino(windowSizeX,windowSizeY,pixelStretch);
    envir.setGroundPos(envir.returnYSize()*3/4+dino.returnYSize()*pixelStretch/2);


    form fm{API::make_center(windowSizeX, windowSizeY)};
    fm.caption(L"Bench Mark Test");
    drawing dw(fm);
    //paint
	dw.draw([&envir, &dino, &anys](paint::graphics &graph) {//here we preset the method about all elements need to be paint, and set all the variable to control the paint process
		graph.rectangle({0,0,windowSizeX,windowSizeY},true,colors::bisque);//set the background color
		//progress drawing
		envir.drawEnvironment(graph);
		// anys.autoAnimateAnimals(graph);
		// dino.autoAnimateDino(graph);
	});
    //refresh loop
    std::thread T([&]{
        int duration = 0;
        while(!quit)
        {
            // dino.reset();
            // dino.updateDino(envir,anys,false);
            envir.updateEnvironment();
            // anys.updateAnimals(envir);
            API::refresh_window(fm);
            duration++;
        }
        fm.close();
    });
    fm.events().unload([&quit,&T](const arg_unload &arg)
    { 
        quit = true;    
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
