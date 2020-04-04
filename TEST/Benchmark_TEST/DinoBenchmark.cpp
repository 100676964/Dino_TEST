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
vector<int> fpss;
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
    fm.caption("Bench Mark Test");
    
    
    drawing dw(fm);
    drawing dw2(fm);
    drawing dw3(fm);
    //paint
	dw.draw([&envir, &dino, &anys, &fpstime,&fps,&printfps](paint::graphics &graph) 
    {//here we preset the method about all elements need to be paint, and set all the variable to control the paint process
		
        graph.rectangle({0,0,windowSizeX,windowSizeY},true,colors::bisque);//set the background color
		//progress drawing
		envir.drawGround(graph);
        
		
		dino.autoAnimateDino(graph);
        
	});
    dw2.draw([&envir, &dino, &anys, &fpstime,&fps,&printfps](paint::graphics &graph) 
    {
        envir.drawObstacle(graph);
    });
    dw3.draw([&envir, &dino, &anys, &fpstime,&fps,&printfps](paint::graphics &graph) 
    {
        anys.autoAnimateAnimals(graph);
    });
    //physics loop  
    int duration = 0;
    std::thread T([&]
    {   
        while(!quit && duration < 1000)
        {
            if(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now()-cfps).count()>=16)//update control for calculations/rendering, 16ms ~= 60 updates/sec
            {
                if(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now()-fpstime).count()>=(1000))
                {
                    cout<<"current FPS: "<<printfps<<endl;
                    fpstime=chrono::steady_clock::now();//chrono::system_clock::to_time_t(chrono::system_clock::now());
                    printfps=fps;
                    fps=0;
                    fpss.push_back(printfps);
                    
                }
                cfps=chrono::steady_clock::now();
                dino.reset();
                envir.updateEnvironment();
                dino.updateDino(envir,anys,false);
                anys.updateAnimals(envir);
                API::refresh_window(fm);
                fps++;
                duration++;
            }
        }
        fm.close();
    });
    fm.events().unload([&quit](const arg_unload &arg)
    { 
        quit = true;    
    });
    dw.update();
    fm.show();
    nana::exec();
    T.join();
    
}
int main(int argc, char *argv[])
{
    
    cout<<"Benchmarking!"<<endl; 
    bench_marking();
    cout<<"Benchmark End!"<<endl;
    double fpssum = 0;
    int maxfps = 0;
    int minfps = 1000;
    fstream file;
    if(argv[1] != NULL)
        file.open("TEST_Results/Benchmark_Results",ios::trunc|fstream::out);
    else
        file.open("../TEST_Results/Benchmark_Results",ios::trunc|fstream::out);
    file<<"FPS Samples:"<<endl;
    for(int i = 2; i < fpss.size(); i++)
    {
        file<<fpss.at(i)<<" ";
        fpssum += fpss.at(i);
        if(maxfps < fpss.at(i))
        {
            maxfps = fpss.at(i);
        }
        if(minfps > fpss.at(i))
        {
            minfps = fpss.at(i);
        }
    }
    file<<endl;
    double avfps = fpssum/fpss.size();
    cout<<"Average FPS:"<<avfps<<endl;
    cout<<"Max FPS:"<<maxfps<<endl;
    cout<<"Min FPS:"<<minfps<<endl;
    
    file<<"Average FPS:"<<endl;
    file<<avfps<<endl;
    file<<"Max FPS:"<<endl;
    file<<maxfps<<endl;
    file<<"Min FPS:"<<endl;
    file<<minfps<<endl;
    file.close();
}