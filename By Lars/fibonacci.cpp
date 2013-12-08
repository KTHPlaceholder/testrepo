#include <string>
#include <sstream>

std::string fibonacci(int n)
{
        using namespace std;
        std::ostringstream oss;
        if(n == 0){
                oss << "The Fibonacci number 0 is: 0\n";
        }else if (n == 1 ){
                oss << "The Fibonacci number 1 is: 1\n";
        }else{
                int fiba = 0;
                int fibb = 1;
                int fib = 0;
                for(int i = 2; i <= n; i++){
                        fib = fiba + fibb;
                        fiba = fibb;
                        fibb = fib;
                }
                oss << "The Fibonacci number ";
                oss << n;
                oss << " is: ";
                oss << fib;
                oss << " \n";
        }

        return oss.str();
}