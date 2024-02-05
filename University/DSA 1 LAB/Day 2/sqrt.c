#include<stdio.h>
int main(){
     int key =25;
     int low =1;
    // int high = 25;
     int high = key;
     int mid;
     while(low<=high)
     {
         mid=(low+high)/2;

     if(mid*mid==key){
        printf("%d",mid);
        break;

     }
     else if(mid*mid>key)
     {

         high=mid-1;
     }
     else if(mid*mid<key)
     {
         low=mid+1;
     }

     }

return 0;
}
