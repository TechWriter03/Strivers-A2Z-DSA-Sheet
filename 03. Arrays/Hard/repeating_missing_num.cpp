// Input: 
// nums = [1,2,2,4]
// Output: 
// [2,3]

vector<int> findErrorNums(vector<int>& a) 
{
      long n=a.size();
      long Sn=(n*(n+1))/2,S2n=(n*(n+1)*(2*n+1))/6,s1=0,s2=0;
      for(auto it:a)
      {
          s1+=it;
          s2+=it*it;
      }   
      long val1=s1-Sn,val2=s2-S2n;
      int x=(val1+(val2/val1))/2,y=x-val1;
      return {x,y};
  }
