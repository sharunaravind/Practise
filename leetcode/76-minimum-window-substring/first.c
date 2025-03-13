#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#define letter(a) ((a >= 97) ? (a - 97) : (a - 65 + 26))

char* minWindow(char* s, char* t) 
{
    long slen = strlen(s);
    long tlen= strlen(t);
    int freq[52],sumarr[52],sum=tlen,min=-1,max=0,minEle,finalMin,finalMax,window=INT_MAX,tempWindow,queue[slen],front=-1,back=-1;
    for(int i=0;i<52;i++)
    {
        freq[i]=0;
        sumarr[i]=0;
    } 
    for(int i=0;i<tlen;i++)
    {
        freq[letter(t[i])]++;
    }
    for(int i=0;i<slen;i++)
    {
        int currLetter = letter(s[i]);
        if(freq[currLetter]>0)
        {
            sumarr[currLetter]++;   
            queue[++back] = i;
            if (front == -1) front = 0;
            if(sumarr[currLetter]<=freq[currLetter])
            {
                sum--;
            }
            if(min==-1)
            {
                min=i;
                minEle=currLetter;
            }
            else if(currLetter==minEle && sumarr[currLetter]>freq[currLetter])
            {
                // for(int j=min;j<slen;j++)
                // {
                //     int currLetter2 = letter(s[j]);
                //     if(freq[currLetter2]>0)
                //     {
                //         if(sumarr[currLetter2]<=freq[currLetter2])
                //         {
                //             min=j;
                //             minEle=currLetter2;
                //             break;
                //         }
                //         else{
                //             sumarr[currLetter2]--;
                //         }
                //     }
                // }
                while (front <= back) {
                    int j = queue[front];  // Get the front index from the queue
                    
                    int currLetter2 = letter(s[j]);
                    
                    if (freq[currLetter2] > 0) {
                        if (sumarr[currLetter2] <= freq[currLetter2]) {
                            min = j;
                            minEle = currLetter2;
                            break;
                        } else {
                            sumarr[currLetter2]--;
                        }
                    }
                    
                    front++;  // Remove from queue
                }
            }
            max=i;
            if(sum==0)
            {
                tempWindow=max-min+1;
                if(tempWindow<window)
                {
                    window=tempWindow;
                    finalMax=max;
                    finalMin=min;
                }
            }
        }
    } 
    if(sum==0)
    {
        char* result = (char*)malloc((window+1)*sizeof(char));
        int a;
        for(a=0;a<window;a++)
        {
            result[a]=s[finalMin+a];
        }
        result[a] = '\0'; 
        return result;
    }   
    else
    {
        return "";
    } 
    
}

int main()
{
    char* s="bba";
    char* t="ab";
    // printf("%ld\n",strlen(s));
    printf("%s\n",minWindow(s,t));
    return 0;
}