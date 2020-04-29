#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Sudoku
{
	int mat[9][9];
}sudoku;

int is_distinct(int mat[9])
{
	int i, flag = 0, count[9] = {0};
	for(i = 0 ; i < 9 ; i++)
		{
			count[mat[i]-1]++;
		}
	
	for(i = 0 ; i < 9 ; i++)
		{
			if(count[i] == 1)
				flag = 1;
			else
				return 0;
		}
	return 1;
}

int validate_rows(int mat[9][9])
{
	int i, j, sum = 0, flag = 0, row[9] = {0};
	for(i = 0 ; i < 9 ; i++)
		{
			sum = 0;
			for(j = 0 ; j < 9 ; j++)
				{
					sum += mat[i][j];
					row[j] = mat[i][j];
				}
		
			if(sum == 45 && is_distinct(row))
				flag = 1;
			else
				{
					printf("Row %d doesn't contain all the digits 1-9\n", i+1);
					return 0;
				}
		}
	return 1;
}

int validate_cols(int mat[9][9])
{
	int i, j, sum = 0, flag = 0, col[9] = {0};
	for(i = 0 ; i < 9 ; i++)
		{
			sum = 0;
			for(j = 0 ; j < 9 ; j++)
				{
					sum += mat[j][i];
					col[j] = mat[j][i];
				}
			if(sum == 45 && is_distinct(col))
				flag = 1;
			else
				{
					printf("Col %d doesn't contain all the digits 1-9\n", i+1);
					return 0;
				}
		}
	return 1;
}

int validate_mat(int mat[9][9])
{
	int i = 0, j = 0, k = 0 , l = 0, sum = 0, flag = 0, check_distinct[9] = {0}, index = 0;
	 while(k < 7)
	 	{
			l = 0;
			while(l < 9)
			{
				sum = 0;
				index = 0;
				for(i = k ; i < k+3 ; i++)
					{
						for(j = l ; j < l+3 ; j++)
							{
								sum += mat[i][j];
								check_distinct[index++] = mat[i][j];
							}
					}
					if(sum == 45 && is_distinct(check_distinct))
						flag = 1;
					else
						{
							printf("Failed for cube starting with row = %d, col = %d\n", i-3+1, j-3+1);
							return 0;
						}
				l = j;
		 	}
			k = i;
		 }
	return 1;
}

int validate_sudoku(int sudo[9][9])
	{
		return (validate_rows(sudo) && validate_cols(sudo) && validate_mat(sudo));
	}

void check_format(FILE *source)
{
	char ch, line[23];
	while(ch != EOF)
		{
			ch  = fgetc(source);
			if(ch == '|')
			{
				ch = getc(source);
			    if(ch == '|')
				{
					printf("Error: Format error in matrix\n");
					exit(0);
				}
				else if(ch == ' ')
				{
					ch = getc(source);
					if(ch == '|' || ch == ' ')
						{
							printf("Error: Format error in matrix\n");
							exit(0);
						}
				}
				else
					continue;
			}
			else
				continue;
		}

	fseek(source, 0, SEEK_SET);
	while(!feof(source))
		{
			fgets(line, 23, source);
			if(line[0] == '-')
			{
				for(int i = 0 ; i < 20 ; i++)
					{
						if(line[i] == '-')
							{
								continue;
							}
						else
						{
							printf("Error: Format error in matrix\n");
							exit(0);
						}
					}
				if(line[21] == '-')
					{
						printf("Error: Format error in matrix\n");
							exit(0);
					}
				fgets(line, 23, source);
				if(line[0] == '-')
					{
						printf("Error: Format error in matrix\n");
							exit(0);
					}
			}
		}
	}

int main(int argc, char** argv)
{
	sudoku sudo;
	FILE *source, *copy;
	int i = 0, j = 0, n;
	char ch;
	source = fopen(argv[1], "r");

	check_format(source);

	fseek(source, 0, SEEK_SET);

	copy = fopen("copy.txt", "w");

	while(!feof(source))
	{
		ch = fgetc(source);
		if(ch == '|')
			{
				ch = fgetc(source);
			}
		else if(ch == '-')
			{
				ch = fgetc(source);
				while(ch == '-')
					ch = fgetc(source);
				fputc(ch, copy);
			}
		else
		{
			fputc(ch, copy);
		}
	}

	fclose(source);
	fclose(copy);

	copy = fopen("copy.txt", "r");
	i = 0 ; j = 0;
	while(i < 9)
		{
			j = 0;
			while(j < 9)
			{
					fscanf(copy, "%d", &n);
				if(n > 0 && n <= 9)
					{
						sudo.mat[i][j] = n;
						j++;
					}
				else if(n > 9)
					{
						printf("\nDigit %d is out of range\n", n);
						exit(0);
					}
			}
			i++;
		}

	// for(i = 0 ; i < 9 ; i++)
	// 	{
	// 		for(j = 0 ; j < 9 ; j++)
	// 		printf("%d", sudo.mat[i][j]);
	// 	printf("\n");
	// 	}
	int res = validate_sudoku(sudo.mat);
	if(res)
		printf("Sudoku Matrix Verification SUCCESS\n");
	else
		printf("Sudoku Matrix Verification FAILED\n");
	return 0;
}