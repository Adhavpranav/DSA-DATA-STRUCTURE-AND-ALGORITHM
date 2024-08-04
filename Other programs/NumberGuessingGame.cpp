#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Solution
{
    private:
    int limit,guess_Number,user_Number;
    public:

    void random_Number()
    {
        srand(static_cast<unsigned int>(time(0)));
        guess_Number = rand() % limit + 1; 
    }
    
    void accept_Number()
    {
        repeat:
        cout<<endl<<"ENTER A NUMBER TO GUESS:";
        cin>>user_Number;
        if(user_Number<1 || user_Number>limit)
        {
            cout<<endl<<"PLZ ENTER A NUMBER BETWEEN 1 TO "<<limit;
            goto repeat;
        }
    }

    int check_Number()
    {
        if(guess_Number==user_Number)
        return 0;
        else if(guess_Number>user_Number)
        return -1;
        else
        return 1;
    }

     bool choice()
     {
        int choice;
        repeat:
        cout<<endl<<"1:PLAY AGAIN ?";
        cout<<endl<<"2:QUIT GAME ?";
        cout<<endl<<"ENTER A CHOICE:";
        cin>>choice;
        if(choice==1|| choice==2)
        return choice==1?true:false;
        else
        goto repeat;
        
     }

    Solution()
    {
        repeat:
        cout<<endl<<"ENTER A LIMIT:";
        cin>>limit;
        if(limit<=1 || limit>1000)
        {
            cout<<endl<<"PLZ ENTER A LIMIT GREATER THAN 1 & LESS THAN 1000..!";
            goto repeat;
        }
            random_Number();
            retry:
            accept_Number();
            if(check_Number()==0)
            {
            cout<<endl<<"CONGRATULATIONS YOU GUESSED THE NUMBER & THE NUMBER WAS "<<guess_Number;
            if(choice())
            goto repeat;
            else
            {
            cout<<endl<<"THANKS FOR PLAYING THE GAME! HAVE A GOOD DAY.";
            exit(0);
            }
            }
            else if(check_Number()==-1)
            {
            cout<<endl<<"NICE TRY BUT THE GUESS NUMBER IS GREATER THAN "<<user_Number<<" GUESS AGAIN..!";
            goto retry;
            }
            else
            {
            cout<<endl<<"NICE TRY BUT THE GUESS NUMBER IS LESS THAN "<<user_Number<<" GUESS AGAIN..!";
            goto retry;
            }
       }
};

int main()
{
    Solution ob;
}
