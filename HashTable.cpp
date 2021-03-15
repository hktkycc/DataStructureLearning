#include <iostream>
using namespace std;
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768

typedef struct
{
    int* elem;
    int count;
}HashTable;

int m = 0;

HashTable* InitHashTable()
{
    HashTable* H = (HashTable*)malloc(sizeof(HashTable));
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        H->elem[i] = NULLKEY;
    }
    return H;
}

int Hash(int key)
{
    return key % m;
}

void InsertHash(HashTable* H, int key)
{
    int addr = Hash(key);
    while(H->elem[addr] != NULLKEY)
        addr = (addr + 1) % m;
    H->elem[addr] = key;
}

int SearchHash(HashTable* H, int key, int* addr)
{
    *addr = Hash(key);
    while (H->elem[*addr] != key)
    {
        *addr = (*addr + 1) % m;
        if(H->elem[*addr]==NULLKEY)
        {
            return UNSUCCESS;
        }
    }
    return SUCCESS;
}

int main()
{
    cout << "Input 12 numbers";
    int key = 0;
    HashTable* H = InitHashTable();
    int* addr = (int *)malloc(sizeof(int));
    for (int i = 0; i < m; i++)
    {
        cin >> key;
        InsertHash(H, key);
    }

    cout << "Input the number you want to find";
    cin >> key;
    if (SearchHash(H, key, addr))
    {
        cout << *addr;
    }
}
