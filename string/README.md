### 문자열 (배열, 포인터)
***
```C
	char msg1[] = "Hello how are you?";
	char *pmsg2 = "fastbitlab.com";

    msg1[0] = 'b';
	pmsg2[0] = 'b';

	printf("Message is : %s\n", msg1);
	printf("Message is : %s\n", pmsg2);
	printf("Address of 'pmsg2' variable : %p\n", &pmsg2);
	printf("Value of 'pmsg2' variable = %p\n", pmsg2);
```
와 같이 문자열을 포인터로 저장한 경우 읽기 전용 메모리에 저장되기 때문에  
수정하면 안된다고 한다. 그러나 빌드할때 오류가 발생하지 않기 때문에  
(PC에서는 실행할떄 오류나고 MCU에서는 그냥 실행 되는데 아무 효과 없이 실행됨)


```C
	char msg1[] = "Hello how are you?";
	char const *pmsg2 = "fastbitlab.com";
```
위와 같이 const를 추가하라고 한다.