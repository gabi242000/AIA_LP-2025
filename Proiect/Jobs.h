#ifndef JOBS_H
#define JOBS_H

#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

class Jobs {
public:
    unordered_map<string,int> salaries={{"Barista",3000*12},{"Engineer",11000*12},{"Doctor",10000*12}};
    unordered_map<string,int> inteligent_req={{"Barista",20},{"Engineer_Junior",60},{"Engineer_Senior",80},{"Doctor",79}};
    unordered_map<string,int> sterssLevelPerWork = {{"Barista",1},{"Engineer",10},{"Doctor",20}};
    unordered_map<string,string> uniSpecToJob = {{"medical","Doctor"},{"engineer","Engineer"}};




    void Work();
    void GetAJob();
};



#endif //JOBS_H
