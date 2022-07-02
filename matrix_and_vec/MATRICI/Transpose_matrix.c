#include <stdio.h>
#include <stdlib.h>

//rows= i%cloums;
//coloumns=i%coloumns;
//i=coloumns*rows+c;

/*
int m[4][3];
i=3r+c;
*/

//m[1][2] = *(m[1]+2); = *(*(m+1)+2);

struct mat{
	size_t rows, cols;
	double *data;
};


void mat_create(struct mat *m, size_t rows, size_t cols)
{
	m->rows=rows;
	m->cols=cols;
	m->data=malloc((rows*cols)*sizeof(double));
}

void mat_destr(struct mat *m)
{
	free(m->data);
}

struct mat *new_mat(size_t rows, size_t cols)
{
	struct mat *m = malloc(sizeof(struct mat));
	
	mat_create(m,rows,cols);
	
	return m;
}

void delete_mat(struct mat *m)
{
	mat_destr(m);
	free(m);
}

double mat_get(struct mat *m, size_t r, size_t c)
{
	return m->data[m->cols*r+c];
}

void mat_set(struct mat *m, size_t r, size_t c, double val)
{
	m->data[m->cols*r+c]=val;
}


//gestisco il printing su file, per questo passo come parametro anche il file (ovviamente puntatore a file)
void mat_print(struct mat *m, FILE *f)
{
	size_t rows= m->rows;
	size_t coloums=m->cols;
	double *data = m->data;
	
	size_t r;
	size_t c;
	
	for(r=0; r<rows; ++r)
	{
		for(c=0; c<coloums; ++c)
		{
			//fprintf(f,"%10.3f ",data[cols*r+c]); 1 metodo
			//fprintf(f,"%10.3f ",mat_get(m,r,c)); //2 metodo
			
			double elem = data[coloums*r+c];//metodo salvando in elem
			fprintf(f,"%10.3f ",elem);
		}
		//fputs("",f);//mette un a capo dopo ogni riga che scrive
		fprintf(f,"\n"); //2 metodo sempre per andare a capo
		//fputc('\n',f); 3 metodo
	}
}

void mat_zero(struct mat *m)
{
	size_t rows= m->rows;
	size_t coloums=m->cols;
	
	size_t r;
	size_t c;
	
	for(r=0; r<rows; ++r)
	{
		for(c=0; c<coloums; ++c)
		{
			mat_set(m,r,c,0.0);
		}
	}
	
}

void mat_copy(struct mat *src, struct mat *dst)
{
	size_t rows = dst->rows;
	size_t cols = dst->cols;
	
	size_t r=0;
	size_t c=0;
	
	for(r=0; r<rows; ++r)
	{
		for(c=0; c<cols; ++c)
		{
			double elem = mat_get(src, r,c);
			mat_set(dst,r,c,elem);
		}
	}
}

struct mat *mat_clone(struct mat *src)
{
	struct mat *dst = new_mat(src->rows, src->cols);
	mat_copy(src,dst);
	return dst;
}

struct mat *transCalc(struct mat *src)
{
	struct mat *tmp = new_mat(src->cols, src->rows);
	
	size_t r;
	size_t c;
	
	for(r=0; r<src->rows; ++r)
	{
		for(c=0; c<src->cols; ++c)
		{
			double elem = mat_get(src, r,c);
			mat_set(tmp,c,r,elem);
		}
	}
	
	return tmp;
	
}


int main()
{
	/*
	*****ESEMPIO 1 ALLOCAZIONE STATICA*****
	double a[]= //inizializzo la matrice
	{
		 1, 2, 3,
		 4, 5, 6,
		 7, 8, 9,
		 10, 20, 30, 
	};
	
	struct mat m = {4,3,a};
	
	mat_print(&m,stdout);
	mat_zero(&m);
	fputc('\n',stdout);
	mat_print(&m,stdout);
	*/	
	
	/*
	double a[]= //inizializzo la matrice
	{
		 1, 2, 3,
		 4, 5, 6,
		 7, 8, 9,
		 10, 20, 30, 
	};
	
	struct mat m = {4,3,a};
	*/
	/*
	NOOOO!!! ESEGUO UNA SHALLOW COPY, DEVO COPIARE ELEMENTO PER ELEMENTO (DEEP COPY QUINDI)
	struct mat *c = malloc(sizeof(struct mat));
	
	*c=m;	
	*/
	
	/*
	ESEMPIO DELLA COPIA
	struct mat *cop = new_mat(m.rows, m.cols);
	mat_copy(&m,cop);
	mat_zero(&m);
	
	mat_print(cop,stdout);
	
	delete_mat(cop);
	*/
	
	/*
	struct mat *cop = mat_clone(&m);
	mat_zero(&m);
	mat_print(cop,stdout);
	
	delete_mat(cop);
	*/
	
	struct mat *myMat = new_mat(2,3);
	mat_set(myMat,0,0,1.0);
	mat_set(myMat,0,1,2.0);
	mat_set(myMat,0,2,3.0);
	mat_set(myMat,1,0,4.0);
	mat_set(myMat,1,1,5.0);
	mat_set(myMat,1,2,6.0);
	
	mat_print(myMat,stdout);
	
	printf("\n\n");
	
	struct mat *trans=transCalc(myMat);
	mat_print(trans,stdout);
	
	return 0;
}

