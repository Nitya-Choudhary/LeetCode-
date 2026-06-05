#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool CourseSchedule(int numcourses,vector<vector<int>>&prerequisites){
        vector<vector<int>>adj(numcourses);
        vector<int>indegree(numcourses,0);
        for(auto it: prequisites){
            int course= it[0];
            int prereq= it[1];
            adj[prereq].push_back(course);
            indegree[course]++
        }
    }
    queue<int>q;
    for(int i=0;i<numcourses;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty()){
        int node= q.front();
        q.pop();
        count++;for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return (count==numcourses);
}
