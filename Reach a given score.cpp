long long int ways(int curr,long long int n,vector<int>&score,vector<vector<int>>&vec)
{
    if(n==0) return 1;
    if(curr>=score.size()) return 0;
    if(vec[curr][n]!=-1) return vec[curr][n];
    long long int consider = 0;
    if(score[curr]<=n)
      consider = ways(curr,n-score[curr],score,vec);
    long long int notconsider = ways(curr+1,n,score,vec);
    return vec[curr][n]=consider+notconsider;
}
long long int count(long long int n)
{
	vector<int>score{3,5,10};
    vector<vector<int>>vec(score.size(),vector<int>(1002,-1));
	return ways(0,n,score,vec);
}
