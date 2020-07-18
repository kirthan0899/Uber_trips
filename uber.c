//C program for Uber data analysis

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float mean (int X [ ], float P_X [ ], float S)
{
    int i;
    float x=0.0;
    for(i=0; i<24; i++)
    {
        x = x+ (X[i] * P_X[i]);
    }
    return x;
}

float variance (int X [ ], float P_X [ ], float S, float mean)
{
    int i;
    float var=0.0;
    for (i=0; i<24; i++)
    {
        var = var + (pow ((X[i] - mean), 2) * P_X[i]);
    }
    return var;
}

int main ()
{
    int i;
    int X [50];
    float x, var, sd, S = 0.0, total = 0.0;
    float P_X [50];

    float data [ ] = {1.6, 1.1, 0.8, 0.5, 0.4, 0.4, 0.5, 0.8, 1.2, 1.35, 1.25, 1.2,
                      1.3, 1.3, 1.35, 1.4, 1.5, 1.75, 2, 2.2, 2.1, 2, 2, 1.9};    

    for (i=0; i<24; i++)
    {
        X[i] = i;
    }
   
    for (i=0; i<24; i++)
    {
        S = S + data[i];
    }
    
    for (i=0; i<24; i++)
    {
        P_X[i] = data[i] / S;
    }

    for (i=0; i<24; i++)
    {
        total = total + P_X[i];
    }
    
    printf ("\nProbability Distribution Table :\n\n");
    printf (" ===================\n");
    printf ("|  X  \t|  P(X)   |\n");
    printf (" ===================\n");
    
    for (i=0; i<24; i++)
    {
        printf ("|  %d \t|  %.4f |\n",X[i],P_X[i]);
    }
    
    printf (" -------------------\n");
    printf ("\nTotal : %f\n",total);
    printf ("\nSample Space : %f\n",S);

    x = mean (X, P_X, S);

    printf ("\nMean of the given probability distribution is:\n");
    printf ("µ = %.4f\n",x);
    
    var = variance (X, P_X, S, x);

    printf ("\nVariance of the given probability distribution is:\n");
    printf ("σ^2 = %.4f\n",var);

    sd = sqrt(var);

    printf ("\nStandard deviation of the given probability distribution is:\n");
    printf ("σ = %.4f\n",sd);

    return 0;
}