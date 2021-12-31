#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n,no,avail;  
    float fcount=0;
    printf("\n ENTER THE NUMBER OF PAGES [reference string length]:\n");
    scanf("%d",&n);				 
    int ref_str[n+1];
    printf("\n ENTER THE REFERENCE STRING :\n");
    for(i=1;i<=n;i++)
        scanf("%d",&ref_str[i]);
    printf("\n ENTER THE NUMBER OF FRAMES :");
    scanf("%d",&no);
    int frame[no];
    for(i=0;i<no;i++)
        frame[i]= -1;
        
    j=0;
    printf("\n     page  \t page frames     \tHit/Fault\n");
        for(i=1;i<=n;i++)
        {
            printf("%d\t\t",ref_str[i]);
            avail=0;
            for(k=0;k<no;k++)
            {
                if(frame[k]==ref_str[i])
                {
                        avail=1;
                        for(k=0;k<no;k++)
                            printf("%d\t",frame[k]);
                        printf("H");
                }
            }
            if (avail==0)
            {
                frame[j]=ref_str[i];
                j=(j+1)%no;
                fcount++;
                for(k=0;k<no;k++)
                    printf("%d\t",frame[k]);
                printf("F");
            }
            printf("\n");
        }
    printf("Page Fault Is %.1f\n",fcount);
    cout<<"Hit ratio: "<<((n-fcount)/n)<<"\n";
    cout<<"Miss ratio: "<<(fcount/n);
    return 0;
}
