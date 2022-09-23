#include<stdio.h>
#include <math.h>


int main (){
	int x1,x2,y1,y2,mov=0,a,b;
	while(mov==0){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if((x1<1)||(x1>8)||(x2<1)||(x2>8)||(y1<1)||(y1>8)||(y2<1)||(y2>8)){
			return 0;
	    }
		else{
			a=abs(x2-x1);
			b=abs(y2-y1);
			if((a==b)&&(a!=0)){
				mov+=1;
				printf("%d\n",mov);						
	        }
	        else{
	        	if(x1!=x2){
				mov+=1;
				}
				if(y1!=y2){
				mov+=1;
				}
				printf("%d\n",mov);
	       	}
			mov=0;			
		}
	}
}
	
