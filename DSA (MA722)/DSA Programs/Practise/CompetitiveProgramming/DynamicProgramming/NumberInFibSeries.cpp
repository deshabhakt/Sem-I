    #include<iostream>
    #include<map>
    using namespace std;
    long int fib(int n,map<int,long int > memo={})
    {
        if(memo.count(n))
        {
            return memo[n];
        }
        if(n<=2)
        {
            return 1;
        }
        memo[n]=fib(n-1,memo)+fib(n-2,memo);
        return memo[n];

    }
    int main()
    {
        // cout << fib(1)<<endl;
        // cout << fib(2)<<endl;
        // cout << fib(3)<<endl;
        // cout << fib(4)<<endl;
        // cout << fib(5)<<endl;
        // cout << fib(6)<<endl;
        // cout << fib(7)<<endl;
        // cout << fib(23)<<endl;
        // cout << fib(24)<<endl;
        // cout << fib(25)<<endl;
        cout << fib(39)<<endl;
        // cout << fib(50);
    }