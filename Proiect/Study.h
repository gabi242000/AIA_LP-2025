#ifndef STUDY_H
#define STUDY_H
#include <unordered_map>
#include<string>

using namespace std;

class Study {
    public:
    unordered_map<string,int> studyAt={{"Kindergarden",4},{"School",7},{"Highschool",15},{"Homeschool", 19},{"University",19}};//<name,age>
    unordered_map<string,int> uniSpec ={{"engineer",8},{"medical",10},{"law",7},{"finnance",3}};//<name,inteligence>
    unordered_map<string,int> sterssLevelPerSession ={{"engineer",15},{"medical",22},{"law.txt",10},{"finnance",-5}};//<name,stress>
    unordered_map<string,int> inteligent_req={{"Engineering",80},{"Medical", 40}};//<name,intel>

    int kind=0,school=0,high=0,uni=0,intGain=0;

    void StudyHard();
    void ChooseUniversity();
    bool interviewMedical();
};



#endif //STUDY_H
