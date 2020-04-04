#include "TEST_Dino/DinoTest.h"
#include "TEST_Obstacle/ObstacleTest.h"
#include "TEST_Animals/AnimalsTest.h"
#include "TEST_Animal/AnimalTest.h"
#include "TEST_Environment/EnvironmentTest.h"
#include <fstream>
vector<int> animal_results()
{   
    using namespace animT;
    vector<int> v;
    v.push_back(test_initAnimal());
    v.push_back(animT::test_returnX());
    v.push_back(animT::test_returnY());
    v.push_back(animT::test_returnFrame());
    v.push_back(animT::test_updateFrame());
    v.push_back(animT::test_setPos());
    v.push_back(test_Collipse());  
    return v;
}
vector<int> animals_results()
{   
    using namespace aniT;
    vector<int> v;
    v.push_back(test_initAnimals());
    v.push_back(aniT::test_reset());
    v.push_back(test_setPassingSpeed());
    v.push_back(test_Update());
    return v;
}
vector<int> obstacle_results()
{
    using namespace obsT;
    vector<int> v;
    v.push_back(test_returnSizeX());
    v.push_back(test_returnSizeY());
    v.push_back(test_setPos());
    v.push_back(test_collipse());
    return v;
}
vector<int> dino_results()
{
    using namespace dinoT;
    vector<int> v;
    v.push_back(test_reset());
    v.push_back(test_setStretch());
    v.push_back(test_returnDino());
    v.push_back(test_returnCurrentFrame());
    v.push_back(test_increaseFrame());
    v.push_back(test_decreaseFrame());
    v.push_back(test_setDead());
    v.push_back(test_deadOrNot());
    v.push_back(test_autoFrameChange());
    v.push_back(test_setJump());
    v.push_back(test_calculateGravity());
    v.push_back(test_calculateCollipse());
    v.push_back(test_calculateHp());
    v.push_back(test_returnYSize());
    v.push_back(test_returnXSize());
    v.push_back(test_returnHScore());
    v.push_back(test_setHScore());
    return v;
}
vector<int> environment_results()
{
    using namespace ENVI;
    vector<int> v;
    v.push_back(test_stopAll());
    v.push_back(test_setPassingSpeed());
    v.push_back(test_updateEnvironment());
    v.push_back(test_returnGroundPos());
    v.push_back(test_returnYSize());
    v.push_back(test_returnSizeX());
    v.push_back(test_returnPassingSpeed());
    return v;
}
int main(int argc, char *argv[])
{
    fstream resultfile;
    if(argv[1] != NULL)
        resultfile.open("TEST_Results/Unit_Tests_Results",ios::trunc|fstream::out);
    else
        resultfile.open("../TEST_Results/Unit_Tests_Results",ios::trunc|fstream::out);
    cout<<"Start Unit Tests"<<endl;
    cout<<"Performing tests on Dino..."<<endl;
    vector<int> dino = dino_results();
    
    cout<<"Performing tests on Obstacle..."<<endl;
    vector<int> obstacle = obstacle_results();
    
    cout<<"Performing tests on Animals..."<<endl;
    vector<int> animals = animals_results();
    
    cout<<"Performing tests on Animal..."<<endl;
    vector<int> animal = animal_results();

    cout<<"Performing tests on Environment..."<<endl;
    vector<int> Environment = environment_results();
    cout<<"All Unit Tests are done!"<<endl;
    
    resultfile<<"Dino_Test_Results:"<<endl;
    for(int i = 0; i < dino.size(); i++)
        resultfile<<dino.at(i)<<" ";
    resultfile<<endl;
    
    resultfile<<"Obstacle_Test_Results:"<<endl;
    for(int i = 0; i < obstacle.size(); i++)
        resultfile<<obstacle.at(i)<<" ";
    resultfile<<endl;
    
    resultfile<<"Animals_Test_Results:"<<endl;
    for(int i = 0; i < animals.size(); i++)
        resultfile<<animals.at(i)<<" ";
    resultfile<<endl;
    
    resultfile<<"Animal_Test_Results:"<<endl;
    for(int i = 0; i < animal.size(); i++)
        resultfile<<animal.at(i)<<" ";
    resultfile<<endl;

    resultfile<<"Environment_Test_Results:"<<endl;
    for(int i = 0; i < Environment.size(); i++)
        resultfile<<Environment.at(i)<<" ";
    resultfile<<endl;
    
    
    resultfile.close();

}