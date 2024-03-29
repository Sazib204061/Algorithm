//sieve
const lli N = 10000005;
bitset<N+1>mark;
vector<lli>primes;
void sieve()
{
    mark[2] = 0;
    primes.push_back(2);
    for(lli i = 4; i<=N; i+=2) mark[i] = 1;
    for(lli i = 3; i<=N; i+=2)
    {
        if(mark[i]==0)
        {
            for(lli j = i*i; j<=N; j+=i*2) mark[j] = 1;
            primes.push_back(i);
        }
    }
}
