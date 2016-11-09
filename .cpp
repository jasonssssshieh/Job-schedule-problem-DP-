//
//  main.cpp
//  Weighted Job Problem
//
//  Created by Zijian Xie on 2016/11/9.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//

//Give you the time schedule of each job and value respectively, find out the largest value in the time interval
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

class JobWeight{
private:
    vector<pair<int, int>> time;
    vector<int> value;
public:
    JobWeight(vector<pair<int, int>>& times, vector<int>& values){
        time = times;
        value = values;
    }
    
    int DP(){
        sort(time.begin(), time.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        });
        
        vector<int> dp = value;
        for(int i = 0; i < value.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(time[j].second <= time[i].first){
                    dp[i] = max(dp[i], value[i] + dp[j]);
                }else{
                    dp[i] = max(dp[i], dp[j]);
                }
            }
        }
        cout<<"The max profit is "<<dp[value.size()-1]<<". "<<endl;
        return dp[value.size()-1];
    }
};


int main(int argc, const char * argv[]) {
    vector<pair<int,int>> times = {{1,3},{2,5},{4,6},{6,7},{5,8},{7,9}};
    vector<int> values = {5,6,5,4,11,2};
    JobWeight* test = new JobWeight(times,values);
    test->DP();
    return 0;
}
