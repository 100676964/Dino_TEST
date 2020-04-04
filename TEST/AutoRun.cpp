#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sys/wait.h>
#include <vector>
#include <nana/gui.hpp>
using namespace nana;
using namespace std;   
void test1()
{
    pid_t pid;
    pid = fork();
    if(pid != 0)
    {
        wait(NULL);
    }
    else
    {
        execl("UNIT_TESTs/RunUnitTests","RunUnitTests","1",NULL);
    }
}
void test2()
{
    pid_t pid;
    pid = fork();
    if(pid != 0)
    {
        wait(NULL);
    }
    else
    {
        execl("Intergration_TESTs/RunIntergrationTest","RunUnitTests","1",NULL);
    }
}
void test3()
{
    pid_t pid;
    pid = fork();
    if(pid != 0)
    {
        wait(NULL);
    }
    else
    {
        execl("Benchmark_TEST/RunBenchmarkTest","RunUnitTests","1",NULL);
    }
}
void load_results()
{
    paint::font fone("font",15,{800});
    string buffer;
    vector<string> Benchmark;
    vector<string> Integration;
    vector<string> Unit;
    vector<int> samples;
    vector<int> samplesYcod;
    int maxsample;
    int minsample;
    ifstream Benchmark_Results,Integration_Test_Results,Unit_Tests_Results;
    Benchmark_Results.open("TEST_Results/Benchmark_Results");
    Integration_Test_Results.open("TEST_Results/Integration_Test_Results");
    Unit_Tests_Results.open("TEST_Results/Unit_Tests_Results");
    while (getline(Benchmark_Results, buffer)) 
    {
        Benchmark.push_back(buffer);
    }
    while (getline(Integration_Test_Results, buffer)) 
    {
        Integration.push_back(buffer);
    }
    while (getline(Unit_Tests_Results, buffer)) 
    {
        Unit.push_back(buffer);
    }
    string intbuffer = "";
    for(int i = 0; i < Benchmark.at(1).length(); i++)
    {
        if(Benchmark.at(1)[i] == ' ')
        {
            // cout<<intbuffer<<endl;
            samples.push_back(stoi(intbuffer));
            intbuffer = "";
            
        }
        else
        {
            intbuffer += Benchmark.at(1)[i];  
        }
        
    }
    maxsample = stoi(Benchmark.at(5));
    minsample = stoi(Benchmark.at(7));
    int diff = maxsample - minsample;
    float scale = (float)50/(float)diff;
    // cout<<maxsample<<endl;
    // cout<<minsample<<endl;
    // cout<<diff<<endl;
    // cout<<scale<<endl;
    int gap = (int)((float)980/(float)samples.size());
    // cout<<maxsample<<" "<<minsample<<endl;
    for(int i = 0; i < samples.size(); i++)
    {
        samplesYcod.push_back(550 - samples.at(i)*scale + minsample*scale);
    } 
    form fm{API::make_center(1000,1000)};
    fm.caption("Auto Test Results");
    drawing dw(fm);
        Benchmark.push_back(buffer);
    dw.draw([&Unit,&Benchmark,&Integration,&samples,&samplesYcod,&gap,&fone](paint::graphics &graph) 
    {
        graph.rectangle({0,0,1000,1000},true,colors::black);
        graph.typeface(fone);
        graph.rectangle({10,600,470,390},false,colors::white);
        graph.rectangle({490,600,500,390},false,colors::white);
        graph.rectangle({10,10,980,250},false,colors::white);
        graph.rectangle({10,270,980,320},false,colors::white);
        
        graph.string({50,610},"Unit Tests(1 = pass/ 0 = fail)",colors::white);
        for(int i = 0; i < Unit.size(); i++)
            graph.string({50,700+(i*25)},Unit.at(i),colors::white);
        
        graph.string({530,610},"Intergration Tests",colors::white);
        for(int i = 0; i < Integration.size(); i++)
            graph.string({530,700+(i*25)},Integration.at(i),colors::white);

        graph.string({50,20},"BenchMark Results",colors::white);
        for(int i = 0; i < Benchmark.size(); i++)
            graph.string({50,50+(i*25)},Benchmark.at(i),colors::white);
        
        graph.string({50,280},"FPS Graph",colors::white);
        for(int i = 0; i < samplesYcod.size()-1; i++)
        {
            graph.string({i*gap+50,560},to_string(samples.at(i)),colors::white);
            graph.line({(i*gap)+50,samplesYcod.at(i)},{((i+1)*gap)+50,samplesYcod.at(i+1)},colors::white);
        }
        
    });
    fm.show();
    nana::exec();
}

int main()
{
    // test1();
    // test2();
    // test3();
    load_results();

}
