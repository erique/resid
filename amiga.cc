#if defined(__amigaos__)

#include <new>
#include <stdint.h>
#include "sid.h"

extern "C"
{
void sid_constructor(register SID* sid __asm("a0"))
{
    new (sid) SID();
}
void sid_set_chip_model(register SID* sid __asm("a0"),
                        register uint32_t model __asm("d0"))
{
    sid->set_chip_model((chip_model)model);
}
void sid_enable_filter(register SID* sid __asm("a0"),
                        register bool enable __asm("d0"))
{
    sid->enable_filter(enable);
}
void sid_enable_external_filter(register SID* sid __asm("a0"),
                                register bool enable __asm("d0"))
{
    sid->enable_external_filter(enable);
}
bool sid_set_sampling_parameters(register SID* sid __asm("a0"),
                                register uint32_t clock_freq __asm("d0"),
                                register uint32_t method __asm("d1"),
                                register uint32_t sample_freq __asm("d2"))
{
    double clock_freq_double = (double)clock_freq;
    double sample_freq_double = (double)sample_freq;
    return sid->set_sampling_parameters(clock_freq_double, (sampling_method)method, sample_freq_double);
}
int sid_clock_fast(register SID* sid __asm("a0"),
                register cycle_count delta_t __asm("d0"),
                register short* buf __asm("a1"),
                register int n __asm("d1"))
{
    // clock_fast is private; assume sampling mode is set to fast..
    return sid->clock(delta_t, buf, n);
}
void sid_reset(register SID* sid __asm("a0"))
{
    sid->reset();
}
reg8 sid_read(register SID* sid __asm("a0"),
                register reg8 offset __asm("d0"))
{
    return sid->read(offset);
}
void sid_write(register SID* sid __asm("a0"),
                register reg8 offset __asm("d0"),
                register reg8 value __asm("d1"))
{
    sid->write(offset, value);
}

}
#endif
