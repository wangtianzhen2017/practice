//my_vectorĬ�ϴ�С
#define MY_VECTOR_DEF_SIZE 5
#define ERROR -9999

typedef struct {
	int size;                  //���õĴ�С
	int capacity;              //���������
	int *data;                 //ʵ�ʵ����ݵ�ַ
}my_vector;

//��ʼ���ṹ��
void initMyVector(my_vector *vector);

//���ص�ǰ����Ԫ�صĸ���
int size(my_vector *vector);

//���ص�ǰ���������
int capacity(my_vector *vector);

//�ж������Ƿ�Ϊ�գ� true����1�����򷵻�0
int is_empty(my_vector *vector);

//������β��׷�ӳ�Ա
void push(my_vector *vector, int value);

//ɾ���������һ��Ԫ�أ���������ֵ���������Ϊ�գ��򷵻�-1
int pop(my_vector *vector);

//���ض�Ӧ������Ԫ�أ��������Խ���򱨴�, index>=0 && index<size
int getValue(my_vector * vector, int index);

//���ض�Ӧֵ�������е�һ�γ��ֵ�����������������򷵻�-1
int getIndex(my_vector *vector, int value);

//��ָ����������Ԫ�أ����Ѻ����Ԫ������
void insertValue(my_vector *vector, int index, int value);

//ɾ��ָ��������Ԫ�أ����Ѻ����Ԫ������
void deleteValue(my_vector *vector, int index);

//����ǰ��my_vector�洢�ռ�����һ��
void resize(my_vector *vector);

//�ͷ���Դ
void freeMyVector(my_vector *vector);

//��������
void traversalMyVector(my_vector *vector);




