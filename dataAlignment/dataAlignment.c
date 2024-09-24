#include<stdint.h>
#include<stdio.h>

struct DataSet
{
	char  data1;
	char  data2;
	short data3;
	int   data4;
};

int main(void)
{
	struct DataSet data;

	data.data1  = 0x11;
	data.data2  = 0x22;
	data.data3  = 0xCCCC;
	data.data4  = 0XAABBEEEE;

	uint8_t *ptr;

	ptr = (uint8_t*)&data;

	uint32_t totalSize = sizeof(struct DataSet);

	printf("Memory address       Content \n");
	printf("==============================\n");

	for(uint32_t i = 0 ; i < totalSize ; i++)
	{
		printf("%p ,   %X\n",ptr,*ptr);
		ptr++;
	}

	printf("Total memory consumed by this struct variable = %d\n", sizeof(struct DataSet));


    getchar();

}
