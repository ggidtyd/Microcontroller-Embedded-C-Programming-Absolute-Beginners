### printf 사용 (OpenOCD semihosting)

1. Debug configurations -> STM32 MCU Debugging 더블클릭으로 현재 프로젝트 추가  
    -> Debugger 탭에서 Debug probe를 ST-Link (OpenOCD) 로 선택  
    -> startup 탭에서 Run Commands에 monitor arm semihosting enable 추가  
    -> 프로젝트 우클릭 -> properties -> C/C++ Build Settings  
    -> MCU/MPU GCC Linker의 Miscellaneous에서 other flags에 -specs=rdimon.specs -lc -lrdimon 추가  
    -> main.c에 다음과 같은 부분을 추가
    ```C
    #include <stdint.h>
    #include <stdio.h>

    #if !defined(__SOFT_FP__) && defined(__ARM_FP)
    #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
    #endif

    // 추가된 부분 1
    extern void initialise_monitor_handles(void);

    int main(void)
    {
        // 추가된 부분 2
        initialise_monitor_handles();

        printf("Hello World\n");
        /* Loop forever */
        for(;;);
    }
    ```
    -> syscalls.c 를 빌드에서 제외 (syscalls.c 우클릭 -> properties -> C/C++ Build 에서 Exclude resource from build에 체크)

    -> 이후 디버깅 하면 콘솔 창에서 출력 확인 가능