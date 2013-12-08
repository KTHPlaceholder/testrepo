#include <string>

std::string fibonacci(int n)
{
        using namespace std;
        std::string result;
        if(n == 0){
                result.append("The Fibonacci number 0 is: 0\n");
        }else if (n == 1 ){
                result.append("The Fibonacci number 1 is: 1\n");
        }else{
                int fiba = 0;
                int fibb = 1;
                int fib = 0;
                for(int i = 2; i <= n; i++){
                        fib = fiba + fibb;
                        fiba = fibb;
                        fibb = fib;
                }
                result.append("The Fibonacci number "+to_string(n)+" is: "+to_string(fib)+" \n");
        }

        return result;
}