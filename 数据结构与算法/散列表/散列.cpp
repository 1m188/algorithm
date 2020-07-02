unsigned int Hash(const char *Key, int TableSize) //按照书上打的例程，散列表,一个简单的散列函数
{
    unsigned int HashVal = 0;

    while (*Key != '\0')
    {
        HashVal += *Key++;
    }

    return HashVal % TableSize;
}

unsigned int BadHash(const char *Key, int TableSize) //一个不太好的散列函数
{
    return (Key[0] + 27 * Key[1] + 729 * Key[2]) % TableSize;
}

unsigned int GoodHash(const char *Key, int TableSize) //一个好的散列函数
{
    unsigned int HashVal = 0;

    while (*Key != '\0')
    {
        HashVal = (HashVal << 5) + *Key++;
    }

    return HashVal % TableSize;
}