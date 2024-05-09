#include <bits/stdc++.h>

using namespace std;

const int N = 20;
vector<vector<char>> image(N,vector<char>(N));
vector<vector<bool>> visited(N,vector<bool>(N));
int i_min,i_max,j_min,j_max;
int n;

void floodfill(int i,int j,char curr_color){
    if(i<i_min||i>i_max||j<j_min||j>j_max||visited[i][j]||image[i][j]!=curr_color){
        return;
    }
    visited[i][j]=true;
    floodfill(i+1,j,curr_color);
    floodfill(i,j+1,curr_color);
    floodfill(i-1,j,curr_color);
    floodfill(i,j-1,curr_color);
    return;
}

struct PCL{
    int i1,j1,i2,j2;
    bool is_inside(PCL other){
        return (i1>=other.i1&&i2<=other.i2&&j1>=other.j1&&j2<=other.j2);
    }
};

bool is_pcl(int i1,int j1,int i2,int j2){
    vector<int> region_count(26);
    i_min=i1;
    j_min=j1;
    i_max=i2;
    j_max=j2;
    for(int i=i1;i<=i2;i++){
        for(int j=j1;j<=j2;j++){
            if(!visited[i][j]){
                char curr_color=image[i][j];
                region_count[curr_color-'A']++;
                floodfill(i,j,curr_color);
            }
        }
    }
    fill(visited.begin(),visited.end(),vector<bool>(N));
    int colors=0;
    bool color_with_one_region=false;
    bool color_with_more_regions=false;
    for(int i=0;i<26;i++){
        if(region_count[i]!=0){colors++;}
        if(region_count[i]==1){color_with_one_region=true;}
        if(region_count[i]>1){color_with_more_regions=true;}
    }
    return(colors==2&&color_with_more_regions&&color_with_one_region);
}

int main(){
    freopen("where.in","r",stdin);
    freopen("where.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> image[i][j];
        }
    }
    vector<PCL> pcl_lists;
    for(int i1=0;i1<n;i1++){
        for(int j1=0;j1<n;j1++){
            for(int i2=0;i2<n;i2++){
                for(int j2=0;j2<n;j2++){
                    if(is_pcl(i1,j1,i2,j2)){
                        pcl_lists.push_back({i1,j1,i2,j2});
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<pcl_lists.size();i++){
        bool valid_pcl=true;
        for(int j=0;j<pcl_lists.size();j++){
            if(i==j){continue;}
            if(pcl_lists[i].is_inside(pcl_lists[j])){
                valid_pcl=false;
                break;
            }
        }
        ans+=valid_pcl;
    }
    cout << ans;
}