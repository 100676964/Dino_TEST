#include "TEST_Dino/DinoTest.h"
vector<int> dino_results()
{
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
}