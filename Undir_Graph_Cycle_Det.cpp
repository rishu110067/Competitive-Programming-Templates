//directed graph cycle detection
const ll N=2e5+1;
vll v[N];
bool dfs(ll x, vll &vis)
{
    vis[x]=1;
    bool ret=false;
    for(auto i:v[x])
    {
        if(vis[i]==1) 
        {
            ret=true; 
            break;
        }
        else if(vis[i]==0)
        {
            if(dfs(i,vis))
            { 
                ret=true; 
                break; 
            }
        }
    }
    vis[x]=2;
    return ret;
}

bool cycle(ll n) 
{    
	vll vis(n,0);
	bool ret=false;
	rep(i,0,n)
	{
	   	if(vis[i]==0)
	   	{
	   	    if(dfs(i,vis)) 
	   	    { 
	   	        ret=true;
	   	        break; 
	   	    }
	   	}
	}	
	return ret;
}

/*
Use dfs implemented above, don't use normal dfs. 
Normal dfs will give tle for graphs like this:
       1
    / / \ \ 
    2 3 4 5   
    \ \ / /  
       6
       7
       8
       9
       10  
*/