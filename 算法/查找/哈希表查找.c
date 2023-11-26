// 对关键字集合1,9,10,23,11，84，14，27,20哈希地址空间为[0 ..14]，若采用除留余数法构造哈希函数和线性探测再散列方法处理冲突，试画出最后得到的哈希表，并计算在等概率情况下查找成功时的平均查找长度ASL
/*首先，我们需要使用除留余数法构造哈希函数。这种方法的基本思想是取关键字被某个不大于哈希表表长m的数p除后所得的余数为哈希地址。在这个例子中，我们的哈希表长度为15，所以我们可以选择p=15。然后，我们将每个关键字除以15，取余数作为哈希地址。

然后，我们使用线性探测再散列方法处理冲突。当哈希地址hi=（H（key）+d）% m发生冲突时，我们用hi=（hi+d）% m的方法产生下一个哈希地址，其中H（key）为哈希函数，d为1，2，3，…，m-1。

现在，我们可以开始填充哈希表了。我们将关键字集合1,9,10,23,11，84，14，27,20插入到哈希表中。

```
关键字: 1, 9, 10, 23, 11, 84, 14, 27, 20
哈希地址: 1, 9, 10, 8, 11, 9, 14, 12, 5
```

由于关键字9和84有相同的哈希地址9，所以我们需要使用线性探测再散列方法处理这个冲突。我们将哈希地址加1，得到10，但是10已经被关键字10占用了，所以我们再加1，得到11，11也被关键字11占用了，我们继续加1，得到12，12被关键字27占用了，我们再加1，得到13，13没有被占用，所以我们将关键字84放在哈希地址13的位置。

最后得到的哈希表如下：

```
哈希地址: 0  1  2  3  4  5  6  7  8   9  10 11 12 13 14
关键字:   -  1  -  -  -  20 -  -  23  9  10 11 27 84 14
```

在等概率情况下查找成功时的平均查找长度ASL（Average Search Length）可以通过以下公式计算：

ASL = Σ(pi*ci) / n

其中，pi是第i个关键字的概率，ci是找到第i个关键字需要比较的次数，n是关键字的总数。

在这个例子中，每个关键字的概率都是1/9，所以我们只需要计算每个关键字需要比较的次数，然后求和，最后除以9。

```
关键字: 1, 9, 10, 23, 11, 84, 14, 27, 20
比较次数: 1, 1, 1, 1, 1, 5, 1, 1, 1
```

所以，ASL = (1+1+1+1+1+5+1+1+1) / 9 = 1.44


*/



#include <stdio.h>

#define HASHSIZE 15
#define NULLKEY -32768

typedef struct
{
    int *elem; // 数据元素存储基址，动态分配数组
    int count; // 当前数据元素个数
} HashTable;

int InitHashTable(HashTable *H)
{
    int i;
    H->count = HASHSIZE;
    H->elem = (int *)malloc(HASHSIZE * sizeof(int));
    if (!H->elem)
        return -1;
    for (i = 0; i < HASHSIZE; i++)
        H->elem[i] = NULLKEY;
    return 0;
}

// 除留余数法构造哈希函数
int Hash(int key)
{
    return key % HASHSIZE;
}

// 线性探测再散列
void InsertHash(HashTable *H, int key)
{
    int addr = Hash(key);
    while (H->elem[addr] != NULLKEY)  // 如果不为空，则冲突
        addr = (addr + 1) % HASHSIZE; // 开放定址法的线性探测
    H->elem[addr] = key;
}

int main()
{
    int arr[HASHSIZE] = {1, 9, 10, 23, 11, 84, 14, 27, 20};
    HashTable hashTable;
    InitHashTable(&hashTable);

    for (int i = 0; i < HASHSIZE; i++)
    {
        InsertHash(&hashTable, arr[i]);
    }

    for (int i = 0; i < HASHSIZE; i++)
    {
        printf("%d ", hashTable.elem[i]);
    }

    return 0;
}
