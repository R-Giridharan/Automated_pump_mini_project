void delay_ms (signed int ms)
{
    signed int i;
    for(; ms > 0; ms--)
	for(i=0;i<12000;i++);
}
