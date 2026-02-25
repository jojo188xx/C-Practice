#include<iostream>

__global__ void mykernelfunc(){};

int main()
{
    mykernelfunc<<<1,1>>>();
    std::cout<<"hello world cuda!\n";
    return 0;
}
