#include"method.h"
int main(){
  	menu();
    int optional;
    SqList L;
    int e;
    scanf("%d",&optional);
    while(1){
    	system("cls"); 
    	menu();
    	switch(optional){
	    	case 1:
	    		InitSqList(L);
	    		break;
    		case 2:
	    		SqListIsEmpty(L);
	    		break;
    		case 3:
	    		DestroySqList(L);
	    		break;
    		case 4:
	    		ClearSqList(L);
	    		break;
    		case 5:
	    		GetLength(L);
	    		break;
    		case 6:
  				//按位查找 
	    		SqListGetElem(L,4,e);
	    		break;
    		case 7:
    			//按值查找 
	    		SqListLocateElem(L,e);
	    		break;
   			case 8:
	    		for(int i = 1; i <= 10; i++){
	    			printf("插入之前\n");
	    			SqListPrintf(L);
		    		SqListInsert(L,i,i);
		    	}
		    	break;
    		case 9:
	    		SqListDelete(L,4);
	    		break;
    		case 10:
	    		SqListPrintf(L);
	    		break;
    		default:
    			printf("ERROR\n");
   				
	    }
	    scanf("%d",&optional);
    }
	return 0; 
}
 