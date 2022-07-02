#include "html.h"

int main()
{
	char filein[] = "file1.html";
	char fileout[] = "ORA.txt";

	int result = rimuovi_html(filein, fileout);

	return 0;
}