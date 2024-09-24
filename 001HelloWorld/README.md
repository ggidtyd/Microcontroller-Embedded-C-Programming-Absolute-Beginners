### FPU warning fix

>"FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."


right click on the project -->properties -> expand C/C++ build --> Settings --> Tool settings -->MCU settings ->

![img1](./img/img1.png)

</br>

---

</br>

### printf 사용 (SWO)

</br>

1. 보드에서 SWO를 지원 하는지, 기본적으로 On 상태인지 등 확인  
(어떤 이유로든 불가하면 OpenOCD semihosting 이용)

</br>

2. 다음을 syscalls.c에 붙여넣기

</br>

```C
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//					Implementation of printf like feature using ARM Cortex M3/M4/ ITM functionality
//					This function will not work for ARM Cortex M0/M0+
//					If you are using Cortex M0, then you can use semihosting feature of openOCD
/////////////////////////////////////////////////////////////////////////////////////////////////////////


//Debug Exception and Monitor Control Register base address
#define DEMCR        			*((volatile uint32_t*) 0xE000EDFCU )

/* ITM register addresses */
#define ITM_STIMULUS_PORT0   	*((volatile uint32_t*) 0xE0000000 )
#define ITM_TRACE_EN          	*((volatile uint32_t*) 0xE0000E00 )

void ITM_SendChar(uint8_t ch)
{

	//Enable TRCENA
	DEMCR |= ( 1 << 24);

	//enable stimulus port 0
	ITM_TRACE_EN |= ( 1 << 0);

	// read FIFO status in bit [0]:
	while(!(ITM_STIMULUS_PORT0 & 1));

	//Write to ITM stimulus port0
	ITM_STIMULUS_PORT0 = ch;
}
```

</br>
  
3. syscalls.c 의 _write를 다음과 같이 수정

</br>

```C
__attribute__((weak)) int _write(int file, char *ptr, int len)
{
  (void)file;
  int DataIdx;

  for (DataIdx = 0; DataIdx < len; DataIdx++)
  {
    //__io_putchar(*ptr++);
	  ITM_SendChar(*ptr++);
  }
  return len;
}
``` 

</br>

4. 프로젝트 우클릭 -> Debug As -> Debug configurations...

    -> STM32 C/C++ Application에 현재 프로젝트 없으면 더블클릭해서 추가

    -> Debugger 탭에서 Debugger Probe ST-Link (ST-Link GDB Server) 확인

    -> interface에서 SWD 체크

    -> SWV에서 Enable 체크, MCU의 Core Clock 입력 (STM32L은 기본값 4MHz)

![img2](./img/img2.png)

</br>

---