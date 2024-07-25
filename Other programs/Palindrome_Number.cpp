#include<iostream>
#include<math.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x) {
        if(reverse_Number(x)==x)
        return true;
        else
        return false;
    }
private:
    int reverse_Number(int x)
    {
            int digit,reverse=0;
            while(abs(x)!=0)
            {
            digit=x % 10;
            reverse=reverse*10+digit;
            x=x/10;
            }
            return reverse;
    }   
};

int main()
{
    Solution ob;
    int number;
    cout<<"Enter a number:";
    cin>>number;
    if(ob.isPalindrome(number))
    cout<<number<<" IS A PALINDROME NUMBER";
    else
    cout<<number<<" IS NOT A PALINDROME NUMBER";
}
