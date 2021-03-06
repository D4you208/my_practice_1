#define max_glen 256
struct gapbuf
{
	char buff[max_glen];
	int g_start;
	int g_end;
	
	gapbuf()
	{
		g_start = 0;
		g_end = max_glen - 1;
		for( int i = 0 ; i < max_glen ; i++)
			buff[i] = '\0';
	}
};
bool gapbuf_full( gapbuf *gbuf )
{
	if(gbuf->g_start == gbuf->g_end)
		return true;
	return false;
}
bool gapbuf_empty( gapbuf *gbuf )
{
	if( gbuf->g_end - gbuf->g_start == (max_glen - 1 ) )
		return true;
	return false;
} 
void forward( gapbuf *gbuf)
{
	if( gapbuf_full( gbuf ))
		return;
	gbuf->buff[gbuf->g_end--] = gbuf->buff[gbuf->g_start++];	
}
void backward( gapbuf *gbuf)
{
	if( gapbuf_full( gbuf ))
		return;
	gbuf->buff[gbuf->g_start++] = gbuf->buff[gbuf->g_end--];	
}
void insert ( gapbuf *gbuf , char ch )
{
	if( gapbuf_full( gbuf ) )
		return;
	gbuf->buff[gbuf->g_start++] = ch;
}
char delete_char( gapbuf *gbuf )
{
	if( gapbuf_empty ( gbuf ))
		return '\0';
	gbuf->buff[--gbuf->g_start] = '\0';
}

#include <iostream>
using namespace std;
int main()
{
	gapbuf* gbuf = new gapbuf();
	insert (  gbuf , 'D');
	insert (  gbuf , 'E');
	insert (  gbuf , 'E');
	insert (  gbuf , 'P');
	insert (  gbuf , 'A');
	insert (  gbuf , 'K');
	
	cout << gbuf->buff;
	while ( 1 );
}
