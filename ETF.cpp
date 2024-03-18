/*---------------------------------------------*/
//ETF
int phi[5000006];
//ulli prefix_phi[5000006];
void ETF(lli n)
{
    lli i, j;
    for(i = 1; i<=n; i++)
    {
        phi[i] = i;
    }
    phi[1] = 1;

    for(i = 2; i<=n; i++)
    {
        if(phi[i]==i)
        {
            for(j = i; j<=n; j+=i)
            {
                phi[j] -= (phi[j]/i);
            }
        }
    }
    /*
    //prefix if this need then use other wise remove
    prefix_phi[1] = 0;
    for(lli i = 2; i<=5000000; i++)
    {
        prefix_phi[i] = (ulli)phi[i]*(ulli)phi[i]+prefix_phi[i-1];
    }
    */
}

//call main function:
//ETF(5000000);

