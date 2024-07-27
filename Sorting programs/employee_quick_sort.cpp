#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
class emp 
{
public://pranav
    int eno, sal;
    char ename[20];
    int partition(emp ob[], int lb, int ub) 
    {
        int i, j;
        char pivot[20];
        emp temp;
        i = lb;
        j = ub;
        strcpy(pivot, ob[j].ename);
        while (i < j) {
            while (strcmp(ob[i].ename, pivot) < 0 && i <= ub - 1)
                i++;
            while (strcmp(ob[j].ename, pivot) > 0 && j >= lb + 1)
                j--;
            if (i < j) 
            {
                temp = ob[i];
                ob[i] = ob[j];
                ob[j] = temp;
            }
        }
        temp = ob[i];
        ob[i] = ob[j];
        ob[j] = temp;
        return j;
    }

    void quicksort(emp ob[], int lb, int ub) 
    {
        if (lb < ub) {
            int j = partition(ob, lb, ub);
            quicksort(ob, lb, j - 1);
            quicksort(ob, j + 1, ub);
        }
    }
};

int main() 
{
    emp ob[100];
    FILE *f1;
    int i = 0, n;
    f1 = fopen("nothing.txt", "r");
    if (f1 == NULL) 
    {
        cout << "FILE IS NOT FOUND";
        return 1;
    }
    while (!feof(f1)) 
    {
        fscanf(f1,"%d\t%s\t%d",&ob[i].eno,&ob[i].ename,&ob[i].sal);
        i++;
    }
    fclose(f1);
    int limit = i;
    emp sorter;
    sorter.quicksort(ob, 0, limit - 1);
    cout << "SORTING RECORDS BY EMP NAMES:";
    for (i = 0; i< limit; i++) 
    {
        cout<< endl<<ob[i].eno <<" "<< ob[i].ename<<" "<<ob[i].sal;
    }
    return 0;
}
