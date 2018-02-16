
#include <stdio.h>
#include <time.h>
 
void delay(int seconds)//function which produces the required delay
{
    int milli_seconds = 1000 * seconds;//the seconds is converted to milliseconds 1 sec=1000 milli seconds
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
int main()
{
    int i,start,load,sensor;
    /* 'start' variable is to check the condition of the bike whether ON or OFF,
    'load'variable is to check whether any person is sitting in the bike other than driver,
    'sensor'variable is to check whether any load or person is sitting behind*/
    scanf("%d",&start);//scanfs the condition of the bike
    A:
    if(start)//if bike is started the prg enters if loop
    {
     printf("FOOTREST OPENS");//Initially footrest opens since many people climb the bike with the help of footrest
    for (i = 0; i < 10; i++)//Here in real time i<60 is given to produce a delay of 60 sec,but here it would take time for execution so we use i<10
    {
        delay(10);//if delay(400) we get exact appox. 60 sec of delay
        printf("\n%d seconds passed\n", i + 1);
        scanf("%d%d",&load,&sensor);//The load and sensor inputs are scanned
        if(load&&sensor)//if both are 1,footrest remains in open position
        {
            printf("FOOTREST STAYS OPEN");
            break;
        }
        else//else also the footrest is open because we keep the footrest open for the 10 sec
        {
            printf("FOOTREST STAYS OPEN");
        }
        if(i==9)//finally we check the last delay 
        {
           if(!(load&&sensor))//if load & sensor is not sensed then the footrest closes after 10sec time delay
         {
               printf("FOOTREST CLOSES");
               break;
         }
        }
    }
    }
    else//if the bike is in OFF state
    {
        scanf("%d%d",&load,&sensor);//senses both load &sensor if both present the footrest opens
        if(load&&sensor)
        {
            printf("FOOTREST OPENS");
        }
        else
        {
            printf("FOOTREST CLOSES");
			delay(10);//we wait for a delay of 10 sec and after 10 sec only the footrest CLOSES
 
        }
    
    }
    scanf("%d",&start);//the condition of the bike is checked again
    if(start==1)
    {
    goto A;
    }
    else
    {
        printf("FOOTREST CLOSES");
    }
    return 0;
}
