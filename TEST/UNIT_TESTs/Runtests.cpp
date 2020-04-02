#include "TEST_Dino/DinoTest.h"
#include "TEST_Obstacle/ObstacleTest.h"
#include "TEST_Animals/AnimalsTest.h"

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
int main()
{
    
    
    cout<<dino_results().size()<<endl;
    cout<<obstacle_results().size()<<endl;
    cout<<animals_results().size()<<endl;

}