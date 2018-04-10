#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/container/vector.hpp>
#include <boost/function.hpp>



struct A
{
    template <int... args>
    void fun()
    {
        boost::container::vector<int> nums{args...};
        for(auto item : nums)
        {
            std::cout << item << std::endl;
        }
    }
};

int main(int argc,char** argv)
{
    A a;
    a.fun<1,2,3,4,5,6,7>();
    return 0;
}