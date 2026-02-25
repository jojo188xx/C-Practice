```c
typedef type newname

enum color{red,blue=5,green}c;
c=green;
默认情况下，第一个名称的值为 0，第二个名称的值为 1，第三个名称的值为 2

int i=10;
float f=static_cast<float>(i);
float f=reinterpret_cast<float&>(i); // 重新解释不检查类型，
//动态转换
dynamic_cast<base&//base*>