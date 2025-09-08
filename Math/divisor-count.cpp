long long divisorCount(long long n){
    long long total = 0;
    long long i;
    for(i=1; i*i < n; i++){
        if(n % i == 0)
            total += 2;
    }
    if(i * i == n)
        total++;
    return total;   
}
