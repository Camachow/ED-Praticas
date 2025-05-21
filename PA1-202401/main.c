#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#define ALGINSERTION 1
#define ALGSELECTION 2
#define ALGQSORT 3
#define ALGQSORT3 4
#define ALGQSORTINS 5
#define ALGQSORT3INS 6
#define ALGSHELLSORT 7
#define ALGRECSEL 8

typedef struct alg
{
	int num;
	char *name;
} alg_t;

alg_t algvet[] = {
	{ALGINSERTION, "i"},
	{ALGSELECTION, "s"},
	{ALGQSORT, "q"},
	{ALGQSORT3, "q3"},
	{ALGQSORTINS, "qi"},
	{ALGQSORT3INS, "q3i"},
	{ALGSHELLSORT, "h"},
	{ALGRECSEL, "rs"},
	{0, 0}};

int name2num(char *name)
{
	int i = 0;
	while (algvet[i].num)
	{
		if (!strcmp(algvet[i].name, name))
			return algvet[i].num;
		i++;
	}
	return 0;
}

char *num2name(int num)
{
	int i = 0;
	while (algvet[i].num)
	{
		if (algvet[i].num == num)
			return algvet[i].name;
		i++;
	}
	return 0;
}

typedef struct opt
{
	int size;
	int seed;
	int alg;
} opt_t;

typedef struct sortperf
{
	int cmp;
	int move;
	int calls;
} sortperf_t;

void resetcounter(sortperf_t *s)
{
	s->cmp = 0;
	s->move = 0;
	s->calls = 0;
}

void inccmp(sortperf_t *s, int num)
{
	s->cmp += num;
}

void incmove(sortperf_t *s, int num)
{
	s->move += num;
}

void inccalls(sortperf_t *s, int num)
{
	s->calls += num;
}

char *printsortperf(sortperf_t *s, char *str, char *pref)
{
	sprintf(str, "%s cmp %d move %d calls %d", pref, s->cmp, s->move, s->calls);
	return str;
}

void initVector(int *vet, int size)
{
	for (int i = 0; i < size; i++)
	{
		vet[i] = (int)(drand48() * size);
	}
}

void printVector(int *vet, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", vet[i]);
	}
	printf("\n");
}

void swap(int *xp, int *yp, sortperf_t *s)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
	incmove(s, 3);
}

// Declaração da função median
int median(int a, int b, int c);

// Declaração da função recursiveSelectionSort
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t *s);

// Implementação da função median
int median(int a, int b, int c)
{
	if ((a <= b) && (b <= c))
		return b;
	if ((a <= c) && (c <= b))
		return c;
	if ((b <= a) && (a <= c))
		return a;
	if ((b <= c) && (c <= a))
		return c;
	if ((c <= a) && (a <= b))
		return a;
	return b;
}

// Implementação da função recursiveSelectionSort
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t *s)
{
	int min = l;
	inccalls(s, 1);
	for (int j = l + 1; j <= r; j++)
	{
		inccmp(s, 1);
		if (arr[j] < arr[min])
		{
			min = j;
		}
	}
	if (min != l)
		swap(&arr[min], &arr[l], s);

	if (l + 1 < r)
	{
		recursiveSelectionSort(arr, l + 1, r, s);
	}
}

// shellsort
void shellSort(int *A, int n, sortperf_t *s)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = A[i];
			int j;
			for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
			{
				inccmp(s, 1);
				A[j] = A[j - gap];
				incmove(s, 1);
			}
			A[j] = temp;
			incmove(s, 1);
		}
	}
}

// selection sort
void selectionSort(int arr[], int l, int r, sortperf_t *s)
{
	inccalls(s, 1); // Incrementa o número de chamadas de função
	for (int i = l; i < r; i++)
	{
		int min = i;
		for (int j = i + 1; j <= r; j++)
		{
			inccmp(s, 1);
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&arr[min], &arr[i], s);
		}
	}
}

// insertion sort
void insertionSort(int v[], int l, int r, sortperf_t *s)
{
	inccalls(s, 1); // Incrementa o número de chamadas de função
	for (int i = l + 1; i <= r; i++)
	{
		int key = v[i];
		int j = i - 1;

		// Movimentação da chave inicial para fora do array
		incmove(s, 1); // Movimentação inicial ao pegar o key

		while (j >= l && v[j] > key)
		{
			inccmp(s, 1); // Comparação no loop
			v[j + 1] = v[j];
			incmove(s, 1); // Movimentação no loop
			j--;
		}
		inccmp(s, 1); // Comparação final que falhou no while
		v[j + 1] = key;

		// Movimentação da chave de volta ao array
		incmove(s, 1); // Movimentação final para colocar a chave, independente se j + 1 == i
	}
}

void partition(int *A, int l, int r, int *i, int *j, sortperf_t *s)
{
	*i = l;
	*j = r;
	int pivot = A[(l + r) / 2]; // Escolhe o pivô como o elemento do meio

	printf("Partição iniciada: l = %d, r = %d, pivot = %d\n", l, r, pivot);

	do
	{
		while (A[*i] < pivot)
		{
			inccmp(s, 1); // Conta a comparação
			(*i)++;
		}
		while (pivot < A[*j])
		{
			inccmp(s, 1); // Conta a comparação
			(*j)--;
		}
		if (*i <= *j)
		{
			swap(&A[*i], &A[*j], s);
			(*i)++;
			(*j)--;
		}
	} while (*i <= *j && *i <= r && *j >= l);

	printf("Partição concluída: i = %d, j = %d\n", *i, *j);
}

void quickSort(int *A, int l, int r, sortperf_t *s)
{
	if (l < r)
	{
		int i, j;
		partition(A, l, r, &i, &j, s);

		if (l < j)
		{
			inccalls(s, 1);
			quickSort(A, l, j, s);
		}
		if (i < r)
		{
			inccalls(s, 1);
			quickSort(A, i, r, s);
		}
	}
}

// quicksort with median of 3
void partition3(int *A, int l, int r, int *i, int *j, sortperf_t *s)
{
	*i = l;
	*j = r;
	int mid = (l + r) / 2;
	int pivot = median(A[l], A[mid], A[r]);
	do
	{
		while (A[*i] < pivot)
		{
			(*i)++;
			inccmp(s, 1);
		}
		while (pivot < A[*j])
		{
			(*j)--;
			inccmp(s, 1);
		}
		if (*i <= *j)
		{
			swap(&A[*i], &A[*j], s);
			(*i)++;
			(*j)--;
		}
	} while (*i <= *j);
}

// quicksort with median of 3
void quickSort3(int *A, int l, int r, sortperf_t *s)
{
	int i, j;
	inccalls(s, 1);
	if (l < r)
	{
		partition3(A, l, r, &i, &j, s);
		if (l < j)
			quickSort3(A, l, j, s);
		if (i < r)
			quickSort3(A, i, r, s);
	}
}

// quicksort with insertion for small partitions
void quickSortIns(int *A, int l, int r, sortperf_t *s)
{
	if (r - l < 10)
	{
		insertionSort(A, l, r, s);
	}
	else
	{
		int i, j;
		inccalls(s, 1);
		partition(A, l, r, &i, &j, s);
		if (l < j)
			quickSortIns(A, l, j, s);
		if (i < r)
			quickSortIns(A, i, r, s);
	}
}

// quicksort with insertion and median of 3
void quickSort3Ins(int *A, int l, int r, sortperf_t *s)
{
	if (r - l < 10)
	{
		insertionSort(A, l, r, s);
	}
	else
	{
		int i, j;
		inccalls(s, 1);
		partition3(A, l, r, &i, &j, s);
		if (l < j)
			quickSort3Ins(A, l, j, s);
		if (i < r)
			quickSort3Ins(A, i, r, s);
	}
}

void uso()
{
	fprintf(stderr, "sortperf\n");
	fprintf(stderr, "\t-z <int>\t(vector size)\n");
	fprintf(stderr, "\t-s <int>\t(initialization seed)\n");
	fprintf(stderr, "\t-a <s|i|q|q3|qi|q3i|h|rs>\t(algorithm)\n");
	fprintf(stderr, "\t    s\tselection\n");
	fprintf(stderr, "\t    i\tinsertion\n");
	fprintf(stderr, "\t    q\tquicksort\n");
	fprintf(stderr, "\t    q3\tquicksort+median3\n");
	fprintf(stderr, "\t    qi\tquicksort+insertion\n");
	fprintf(stderr, "\t    q3i\tquicksort+median3+insertion\n");
	fprintf(stderr, "\t    h\theapsort\n");
	fprintf(stderr, "\t    rs\trecursive selection\n");
}

void parse_args(int argc, char **argv, opt_t *opt)
{
	extern char *optarg;
	extern int optind;

	int c;

	opt->seed = 1;
	opt->size = 10;
	opt->alg = 1;

	while ((c = getopt(argc, argv, "z:s:a:h")) != EOF)
	{
		switch (c)
		{
		case 'z':
			opt->size = atoi(optarg);
			break;
		case 's':
			opt->seed = atoi(optarg);
			break;
		case 'a':
			opt->alg = name2num(optarg);
			break;
		case 'h':
		default:
			uso();
			exit(1);
		}
	}
	if (!opt->alg)
	{
		uso();
		exit(1);
	}
}

void clkDiff(struct timespec t1, struct timespec t2,
			 struct timespec *res)
{
	if (t2.tv_nsec < t1.tv_nsec)
	{
		res->tv_nsec = 1000000000 + t2.tv_nsec - t1.tv_nsec;
		res->tv_sec = t2.tv_sec - t1.tv_sec - 1;
	}
	else
	{
		res->tv_nsec = t2.tv_nsec - t1.tv_nsec;
		res->tv_sec = t2.tv_sec - t1.tv_sec;
	}
}

int main(int argc, char **argv)
{
	sortperf_t s;
	int *vet;
	char buf[200];
	char pref[100];
	opt_t opt;
	struct timespec inittp, endtp, restp;

	parse_args(argc, argv, &opt);

	vet = (int *)malloc((opt.size + 1) * sizeof(int));

	resetcounter(&s);
	srand48(opt.seed);
	initVector(vet, opt.size);
	vet[opt.size] = vet[0];

	clock_gettime(CLOCK_MONOTONIC, &inittp);

	switch (opt.alg)
	{
	case ALGINSERTION:
		insertionSort(vet, 0, opt.size - 1, &s);
		break;
	case ALGSELECTION:
		selectionSort(vet, 0, opt.size - 1, &s);
		break;
	case ALGQSORT:
		quickSort(vet, 0, opt.size - 1, &s);
		break;
	case ALGQSORT3:
		quickSort3(vet, 0, opt.size - 1, &s);
		break;
	case ALGQSORTINS:
		quickSortIns(vet, 0, opt.size - 1, &s);
		break;
	case ALGQSORT3INS:
		quickSort3Ins(vet, 0, opt.size - 1, &s);
		break;
	case ALGSHELLSORT:
		shellSort(vet, opt.size, &s);
		break;
	case ALGRECSEL:
		recursiveSelectionSort(vet, 0, opt.size - 1, &s);
		break;
	}
	clock_gettime(CLOCK_MONOTONIC, &endtp);
	clkDiff(inittp, endtp, &restp);

	sprintf(pref, "alg %s seed %d size %d time %ld.%.9ld",
			num2name(opt.alg), opt.seed, opt.size, restp.tv_sec, restp.tv_nsec);

	printsortperf(&s, buf, pref);
	printf("%s\n", buf);

	free(vet);
	return 0;
}
