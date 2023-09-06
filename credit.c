#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count = 0, i, r, sum1 = 0, sum2 = 0, sum, arr[20], in, in2, v, vr, vq;
    unsigned long long CardNo;
    unsigned long long temp;
    printf("enter the Card No.\n");
    scanf("%llu", &CardNo);
    temp = CardNo;
    while (CardNo < 0)
    {
        printf("Invalid Card No.\n");
    }
    while (CardNo > 0)
    {
        CardNo /= 10;
        count++;
    }
    for (i = 0; i < count; i++)
    {
        r = temp % 10;
        arr[i] = r;
        temp /= 10;
    }
    for (i = 0; i < count / 2; i++)
    {
        v = 2 * arr[2 * i + 1];
        if (v > 9)
        {
            vr = v % 10;
            vq = v / 10;
            v = vr + vq;
        }
        sum1 += v;
    }
    if (count % 2 == 0)
    {
        for (i = 0; i < count / 2; i++)
        {

            sum2 += arr[2 * i];
        }
    }
    else
    {
        for (i = 0; i < (count / 2) + 1; i++)
        {

            sum2 += arr[2 * i];
        }
    }
    sum = sum1 + sum2;
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        exit(0);
    }
    if (count == 13 || count == 15 || count == 16)
    {   
        if (arr[count - 1] == 4)
        {
            printf("VISA\n");
        }
        
        else if(count==16 && arr[count-1]==5)   
        {
             if(arr[count-2]==1|| arr[count-2]==2 || arr[count-2]==3 || arr[count-2]==4 || arr[count-2]==5)
             {
                printf("MASTERCARD\n");
            }
            else{
                printf("INVALID\n");
            }
        }
        else if (arr[count - 1] == 3 && count == 15)
        {
            if (arr[count - 2] == 4 || arr[count - 2] == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        
        else
        {
          printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
