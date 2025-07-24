/*Complete the functions below*/
int find(int par[], int x) {
   if(x==par[x]) return par[x];
   return par[x]=find(par,par[x]);
}

void unionSet(int par[], int x, int z) {
    int par_x=find(par,x);
    int par_y=find(par,z);
    
    if(par_x!=par_y) par[par_x]=par_y;
    
}