#include <bits/stdc++.h>

/**
 * 
*  TC : O(V + E)
*  SC : O(V + E)
* 
* 
*/

class Solution {
public:
    
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> prerequisitesOfCourse(numCourses);
    vector<int> numberOfDependentCourse(numCourses,0);
    for(auto dependency : prerequisites){
        prerequisitesOfCourse[dependency[1]].push_back(dependency[0]);
        numberOfDependentCourse[dependency[0]]++;
    }
    queue<int> courseQueue;
    for(int i=0;i<numCourses;i++){
        if(numberOfDependentCourse[i]==0){
        courseQueue.push(i);
        }
    }
    int courseStudied = 0;
    while(courseQueue.empty()==false){
        int currentCourse = courseQueue.front();
		courseQueue.pop();
        courseStudied++;
        for(auto nextCourse : prerequisitesOfCourse[currentCourse]){
            numberOfDependentCourse[nextCourse]--;
            if(numberOfDependentCourse[nextCourse]==0){
                courseQueue.push(nextCourse);
    	    }
        }
    }
    return courseStudied == numCourses;
}
};