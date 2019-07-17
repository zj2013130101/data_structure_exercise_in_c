//
// Created by joan on 19-7-9.
//

#include "hash_function.h"


int NextPrime(int TableSize)
{
    int divisor=0;
    for(divisor = TableSize/2; TableSize%divisor!=0; --divisor);

    if(divisor == 1)
        return TableSize;
    else
        return NextPrime(TableSize+1);
}

/**
 * 一个简单的散列函数
 *
 * */
Index Hash(const char *key, int TableSize)
{
    unsigned int HashVal = 0;

    while( *key != '\0')
        HashVal += *key++;

    return HashVal % TableSize;
}


/**
 * 另一种可能的散列函数：只用到字符串的前三个字符
 *  （该函数不太好——因为英文字符不是随机的，导致分布不均匀，增大冲突）
 *
 * @return
 */
Index Hash2(const char* key, int TableSize)
{
    return (key[0] + 27*key[1] + 729*key[2]) % TableSize;  //*27
}

/**
 *
 * 一个好的散列函数
 *
 * @return
 */
Index Hash3(const char *key, int TableSize)
{
    unsigned int HashVal = 0;
    while(*key != '\0')
        HashVal = (HashVal << 5) + *key++;     //*32

    return HashVal % TableSize;
}


Index Hash4(int key, int TableSize)
{
    return key%TableSize;
}

