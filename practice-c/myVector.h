//my_vector默认大小
#define MY_VECTOR_DEF_SIZE 5
#define ERROR -9999

typedef struct {
	int size;                  //已用的大小
	int capacity;              //数组的容量
	int *data;                 //实际的数据地址
}my_vector;

//初始化结构体
void initMyVector(my_vector *vector);

//返回当前数组元素的个数
int size(my_vector *vector);

//返回当前数组的容量
int capacity(my_vector *vector);

//判断数组是否为空， true返回1，否则返回0
int is_empty(my_vector *vector);

//在数组尾部追加成员
void push(my_vector *vector, int value);

//删除数组最后一个元素，并返回其值，如果数组为空，则返回-1
int pop(my_vector *vector);

//返回对应索引的元素，如果索引越界则报错, index>=0 && index<size
int getValue(my_vector * vector, int index);

//返回对应值在数组中第一次出现的索引，如果不存在则返回-1
int getIndex(my_vector *vector, int value);

//在指定索引插入元素，并把后面的元素右移
void insertValue(my_vector *vector, int index, int value);

//删除指定索引的元素，并把后面的元素左移
void deleteValue(my_vector *vector, int index);

//将当前的my_vector存储空间扩大一倍
void resize(my_vector *vector);

//释放资源
void freeMyVector(my_vector *vector);

//遍历数组
void traversalMyVector(my_vector *vector);




