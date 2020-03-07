#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32678
int main()
{
    int a[31][51];
    char fagure[90][150];
    int i, j, m, k1, k2, n;
    char line[MAX], aux;

    /*FILE *f, *g;
    f = fopen("in.txt", "r");
    g = fopen("out.txt", "w");
    if ((f == NULL) || (g == NULL))
    {
        printf("Error");
        exit(0);
    }*/
    while (fgets(linie, MAX, stdin) != NULL) { 
	if(line[0] == '\n') break;
	// nr of cells
        m = 0; 
        int nr = 0;
        int max = strlen(line) - 1;
	    
        if ((line[max] >= '0') && (line[max] <= '9'))
		max = strlen(linie) - 1;
        else
        	{ 
        		if ((line[max] == 'C') || (line[max] == 'R'))
				max = strlen(line) - 1;
 			else 
        			{
        				if((line[max] < '0') && (line[max] > '9')) 
						max = strlen(linie) - 1;
        				else { 
        					max = max -1 ;
        					if((line[max] != 'C') && (line[max] != 'R'))
							max = strlen(line) - 1;
        	                                else max = strlen(line) - 2;
					}
				}
	        }
        max = max + 1;
        
        for (i = 0; i < max; i++) {
            if ((line[i] == 'R') || (line[i] == 'C'))
                break;
            else
                if (line[i] != ' ') {
                    k1 = 0;
                    while(line[i] != ' ') {
                        k1 = k1 * 10 + (line[i] - '0');
                        i++;
                    }
                    if (k1 > m)
                        m = k1;
                    for (j = 0; j < k1; j++)
                        a[j][nr] = 1; 
                        nr++;
                }
        }
        n = nr;
        aux = linie[i]; // R or C
        i = i + 2; 
        while (i < max ) {  
        	k1 = 0;
        	while ((line[i] != ' ') && (i < max ) && (line[i] != '\n')) {
        		k1 = k1 * 10 + (line[i] - '0');
        		i++;
        	}
        	i++;
        	k2 = 0;
        	while ((line[i] != ' ') && (i < max ) && (line[i] != '\n')) {
        		k2 = k2 * 10 + (line[i] - '0');
        		i++;
        	}
            	a[k2-1][k1-1] = 2; // we have the Queen
            	i++;
        }

        if (aux == 'C') {
            for (i = 0; i <= m * 2 + 1; i++)
                for (j = 0; j <= n * 2 + 1; j++)
                    honeycomb[i][j] = ' ';
            for (j = 0; j < n; j = j + 2) {
                for (i = 0; i < m; i++) {
                    if (a[i][j] > 0) {
                        honeycomb[i * 2 + 1][j * 2 + 1] = '_';
                        honeycomb[i * 2 + 3][j * 2 + 1] = '_';
                        honeycomb[i * 2 + 2][j * 2] = '/';
                        honeycomb[i * 2 + 3][j * 2] = '\\';
                        honeycomb[i * 2 + 2][j * 2 + 2] = '\\';
                        honeycomb[i * 2 + 3][j * 2 + 2] = '/';
                    }
                    if (a[i][j] == 2) 
                        honeycomb[i * 2 + 2][j * 2 + 1]= 'Q';
                }
	    }
            for (j = 1; j < n; j = j + 2) {
                for (i = 0; i < m; i++) {   
                    if (a[i][j] > 0) {
                        honeycomb[i * 2][j * 2 + 1] = '_';
                        honeycomb[i * 2 + 1][j * 2] = '/';
                        honeycomb[i * 2 + 1][j * 2 + 2] = '\\';
                        honeycomb[i * 2 + 2][j * 2 + 1] = '_';
                        honeycomb[i * 2 + 2][j * 2] = '\\';
                        honeycomb[i * 2 + 2][j * 2 + 2] = '/';
                    }
                    if (a[i][j] == 2)
                        honeycomb[i * 2 + 1][j * 2 + 1] = 'Q';
                }
             
                for (i = 0; i <= m * 2 + 1; i++) {
                	for (j = 0; j <= n * 2 + 1; j++) {
                    		printf("%c", honeycomb[i][j]);
                		printf("\n");
            		}
		}
        }
        if(aux == 'R') {
        	for (i = 0; i <= m * 2 + 1; i++) {
                	for (j = 0; j <= n * 2 + 1; j++) {
                    		honeycomb[i][j] = ' ';
			}
		}
             for (j = 0; j < n; j = j + 2) {
                for (i = 0; i < m ; i++) {
                    if (a[i][j] > 0) {
                    	honeycomb[i * 2][j * 2 + 1] = '_';
                        honeycomb[i*2 + 2][j*2 + 1] = '_';
                        honeycomb[i*2 + 1][j*2] = '/';
                        honeycomb[i*2 + 1][j*2 + 2] = '\\';
                        honeycomb[i*2 + 2][j*2] = '\\';
                        honeycomb[i*2 + 2][j*2 + 2] = '/';
                    }
                    if (a[i][j] == 2)
                        honeycomb[i*2 + 1][j*2+1]= 'Q';

                }
	     }
            for (j = 1; j < n; j = j+2) {
                for (i = 0; i < m; i++)
                {
                    if (a[i][j] > 0) {
                        honeycomb[2 * i + 1][2 * j + 1] = '_';
                    	honeycomb[2 * i + 3][2 * j + 1] = '_';
                    	honeycomb[2 * i + 2][2 * j] = '/';
                    	honeycomb[2 * i + 3][2 * j] = '\\';
                    	honeycomb[2 * i + 2][2 * j + 2] = '\\';
                    	honeycomb[2 * i + 3][2 * j + 2] = '/';

                    }
                     if (a[i][j] == 2) 
                        honeycomb[i * 2 + 2][j * 2 + 1] = 'Q';
                 }
	    }
            for (i = 0; i <= m * 2 + 1; i++) {
                for (j = 0; j <= n * 2 + 1; j++) {
                    printf("%c", honeycomb[i][j]);
                	printf("\n");
		}
            }
        }
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                a[i][j] = 0; 
    }

    // fclose(f);
    // fclose(g);

    return 0;
}
