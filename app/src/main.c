#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/vector.h>

#define LED_PORT    (GPIOB)
#define LED_PIN     (GPIO3)

#define UART_PORT   (GPIOA)
#define RX_PIN      (GPIO15)
#define TX_PIN      (GPIO2)

#define CPU_FREQ      (80000000)
#define SYSTICK_FREQ  (1000)

static volatile uint64_t ticks = 0;

void sys_tick_handler(void)
{
    ticks++;
}

static uint64_t get_ticks(void)
{
    return ticks;
}

static void rcc_setup(void)
{
    rcc_clock_setup_pll(&rcc_hsi16_configs[RCC_CLOCK_VRANGE1_80MHZ]);
}

static void gpio_setup(void)
{
    rcc_periph_clock_enable(RCC_GPIOB);
    gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN);

    /* UART pins*/
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(UART_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, TX_PIN | RX_PIN);
    gpio_set_af(UART_PORT, GPIO_AF7, TX_PIN);
    gpio_set_af(UART_PORT, GPIO_AF3, RX_PIN);
}

static void systick_setup(void)
{
    systick_set_frequency(SYSTICK_FREQ, CPU_FREQ);
    systick_counter_enable();
    systick_interrupt_enable();
} 

int main(void)
{
    rcc_setup();
    gpio_setup();
    systick_setup();

    uint64_t start_time = get_ticks();
    while (1)
    {
        if (get_ticks() - start_time >= 1000)
        {
            gpio_toggle(LED_PORT, LED_PIN);
            start_time = get_ticks();
        }

        // if (uart_data_available())
        // {
        //     uint8_t data = uart_read_byte();
        //     uart_write_byte(data - 32);
        // }
    }
    return 0;
}
