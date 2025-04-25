// Input:
// asteroids = [5,10,-5]
// Output:
// [5,10]
// Explanation:
// The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

vector<int> asteroidCollision(vector<int>& asteroids)
{
    vector<int>st;
    for(auto it:asteroids)
    {
        if(it>=0)
        {
            st.push_back(it);
        }
        else
        {
            while(!st.empty() && st.back()>0 && st.back()<abs(it))
                st.pop_back();
            if(!st.empty() && st.back()==abs(it))
                st.pop_back();
            else if(st.empty() || st.back()<0)
                st.push_back(it);
        }
    }
    return st;
}
